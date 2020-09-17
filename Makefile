#install lm4flash for flashing the .axf file to the board
CC=arm-none-eabi-gcc
CPU=cortex-m4
CFLAGS=-c -mcpu=$(CPU) -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -ffunction-sections -fdata-sections -Os

LINKER=arm-none-eabi-ld
LINKER_SCRIPT=backup/linker.ld
LFLAGS=--gc-section -T $(LINKER_SCRIPT)

ICDI=/dev/ttyACM0

flash: exec.axf
	lm4flash -E -S $(ICDI) $^

main.o: src/main.c
	$(CC) $(CFLAGS) $^ -o $@

startup.o: src/startup.c
	$(CC) $(CFLAGS) $^ -o $@

exec.axf: main.o startup.o
	$(LINKER) $(LFLAGS) $^ -o $@

clean:
	rm *.o exec.axf