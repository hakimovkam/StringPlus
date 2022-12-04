CC = gcc
CFLAGS = -c -Wall -Werror -Wextra
CFLAGS_WC = -Wall -Werror -Wextra

all: s21_string

s21_string: s21_string.o string.o s21_sprintf.o
	$(CC) $(CFLAGS_WC) s21_string.o string.o s21_sprintf.o -o s21_string

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) s21_string.c

string.o: string.c
	$(CC) $(CFLAGS) string.c

s21_sprintf.o: s21_sprintf.c
	$(CC) $(CFLAGS) s21_sprintf.c

clean: 
	rm -rf *.o *.out s21_grep

rebuild: clean all