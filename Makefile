CC=arm-none-eabi-gcc
CPU=cortex-m4
OUT=output
INCLUDE=inc
OBJECT_FILES=objs
LIBS=libs
CFLAGS=-c -mcpu=$(CPU) -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -ffunction-sections -fdata-sections -Os -I$(INCLUDE)
LINKER=arm-none-eabi-ld
LINKER_SCRIPT=.compilation_scripts/TM4C123GH6PM.ld
LFLAGS=--gc-section -T $(LINKER_SCRIPT)
ICDI=/dev/ttyACM0
#ICDI=0E22F2D3
all: $(OUT)/blink.bin
flash: $(OUT)/blink.bin
	lm4flash -S $(ICDI) $^

$(OBJECT_FILES)/main.o: src/blink.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJECT_FILES)/startup.o: $(LIBS)/startup.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJECT_FILES)/gpio.o: $(LIBS)/gpio.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@	

$(OUT)/blink.elf: $(OBJECT_FILES)/main.o $(OBJECT_FILES)/startup.o $(OBJECT_FILES)/gpio.o
	@mkdir -p $(@D)
	$(LINKER) $(LFLAGS) $^ -o $@
	rm $^

$(OUT)/blink.bin: $(OUT)/blink.elf
	arm-none-eabi-objcopy -O binary $^ $@

clean:
	rm -rf $(OUT)
	rm -rf $(OBJECT_FILES)
