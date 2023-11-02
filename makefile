# KAMUS
CC = gcc
CFLAGS = -Wall -Werror -std=c11

.PHONY: all clean test
%.o: %.c
 $(CC) $(CFLAGS) -c -o $@ $<


# # UNTUK PROGRAM UTAMA
SRC_MAIN = main.c
OBJ_MAIN = $(SRC_MAIN:.c=.o)

# compile 
all: main_program mfoo   
main_program: $(OBJ_MAIN) $(OBJ_FOO)
 $(CC) $(CFLAGS) -o $@ $^

# hapus file compile
clean:
 rm -f main_program mfoo $(OBJ_MAIN) $(OBJ_FOO) $(OBJ_TEST) $(TEST_RESULTS)

# run + compile
run: main_program
 ./main_program


# # UNTUK SETIAP ADT, contoh awal Stack
SRC_STACK = ADT/STACK/stack.c
OBJ_STACK = $(SRC_STACK:.c=.o)

allStack: Stack_program mfoo
Stack_program: $(OBJ_STACK)
 $(CC) $(CFLAGS) -o $@ $^

runStack: Stack_program 
 ./Stack_program

cleanStack:
 rm -f main_program mfoo $(OBJ_STACK) $(OBJ_FOO) $(OBJ_TEST) $(TEST_RESULTS)
 rm -f Stack_program mfoo $(OBJ_STACK) $(OBJ_FOO) $(OBJ_TEST) $(TEST_RESULTS)