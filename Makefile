CC ?= cc
CFLAGS ?= -std=c11 -O2 -Wall -Wextra -Wpedantic
CPPFLAGS += -Iinclude
BUILD=build
SRC=$(wildcard src/*.c) $(wildcard runtime/*.c)
ifeq ($(shell uname -m),x86_64)
ASM=$(wildcard asm/x86_64/*.S)
else ifeq ($(shell uname -m),aarch64)
ASM=$(wildcard asm/arm64/*.S)
else ifeq ($(shell uname -m),riscv64)
ASM=$(wildcard asm/riscv64/*.S)
else
ASM=
endif
SRC_OBJS=$(patsubst %.c,$(BUILD)/obj/%.o,$(SRC))
ASM_OBJS=$(patsubst %.S,$(BUILD)/obj/%.o,$(ASM))
LIB=$(BUILD)/libvpu.a
TOOLS=vpu-run vpu-info vpu-dump vpu-debug
EXAMPLES=basic compute vector task
TESTS=test_core test_memory test_alu test_vector test_decoder test_scheduler test_runtime
all: build
build: $(LIB) $(TOOLS:%=$(BUILD)/%) $(EXAMPLES:%=$(BUILD)/example-%) $(TESTS:%=$(BUILD)/%) $(BUILD)/vpu-as
$(BUILD)/.dir:
	mkdir -p $(BUILD)/obj

	touch $@
$(BUILD)/obj/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
$(BUILD)/obj/%.o: %.S
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
$(LIB): $(SRC_OBJS) $(ASM_OBJS) | $(BUILD)/.dir
	ar rcs $@ $(SRC_OBJS) $(ASM_OBJS)
$(BUILD)/vpu-%: tools/vpu-%.c $(LIB) | $(BUILD)/.dir
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -Wl,--whole-archive $(LIB) -Wl,--no-whole-archive -o $@
$(BUILD)/example-%: examples/%.c $(LIB) | $(BUILD)/.dir
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -Wl,--whole-archive $(LIB) -Wl,--no-whole-archive -o $@
$(BUILD)/test_%: tests/test_%.c $(LIB) | $(BUILD)/.dir
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -Wl,--whole-archive $(LIB) -Wl,--no-whole-archive -o $@
$(BUILD)/vpu-as: assembler/assembler.c assembler/lexer.c assembler/parser.c assembler/encoder.c | $(BUILD)/.dir
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@
test: build
	@for t in $(TESTS); do ./$(BUILD)/$$t; done
clean:
	rm -rf $(BUILD)
.PHONY: all build test clean
