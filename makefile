DRIVERS := $(wildcard modules/*/driver_*.c)
MODULES := $(filter-out $(DRIVERS), $(wildcard modules/*/*.c))
OBJECTS := $(patsubst %.c,%.o, $(MODULES))
DRIVERS_EXE := $(patsubst %.c, %.exe, $(DRIVERS))

all: $(OBJECTS) $(DRIVERS) main

driver: $(DRIVERS)

%.o : %.c
 gcc -c $< -o $@

driver_%.c: $(OBJECTS)
 gcc $(OBJECTS) $@ -o $(patsubst %.c, %.exe, $@)

main: $(OBJECTS) main.c
 gcc $(OBJECTS) main.c -o $@.exe

clean:
 rm modules/*/*.o *.exe modules/*/*.exe