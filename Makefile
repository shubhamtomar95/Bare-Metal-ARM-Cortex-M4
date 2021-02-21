# include makefile.conf
# NAME=blink
# STARTUP_DEFS=-D__STARTUP_CLEAR_BSS -D__START=main

# LDSCRIPTS=-L. -L$(BASE)/ldscripts -T .compilation_scripts/linker.ld
# LFLAGS=$(USE_NANO) $(USE_NOHOST) $(LDSCRIPTS) $(GC) $(MAP)

# $(NAME)-$(CORE).axf: src/$(NAME).c $(STARTUP)
# 	$(CC) $^ $(CFLAGS) $(LFLAGS) -o $@

# clean: 
# 	rm -f $(NAME)*.axf *.map *.o

CC=arm-none-eabi-gcc
CPU=cortex-m4
CFLAGS=-c -mcpu=$(CPU) -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -ffunction-sections -fdata-sections -Os
OUT=output
LINKER=arm-none-eabi-ld
LINKER_SCRIPT=.compilation_scripts/linker.ld
LFLAGS=--gc-section -T $(LINKER_SCRIPT)

ICDI=/dev/ttyACM0
#ICDI=0E22F2D3

all: $(OUT)/blink.bin

flash: $(OUT)/blink.bin
	lm4flash -S $(ICDI) $^

main.o: src/blink.c
	$(CC) $(CFLAGS) $^ -o $@

startup.o: src/startup.c
	$(CC) $(CFLAGS) $^ -o $@

$(OUT)/blink.elf: main.o startup.o
	@mkdir -p $(@D)
	$(LINKER) $(LFLAGS) $^ -o $@
	rm $^

$(OUT)/blink.bin: $(OUT)/blink.elf
	arm-none-eabi-objcopy -O binary $^ $@

clean:
	rm -rf $(OUT)
