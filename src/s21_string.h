#ifndef S_21_STRING_H
#define S_21_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>


#define ERR_MIN 0
#define unsignedInt 4294967295


typedef unsigned long int s21_size_t;
#define s21_NULL ((void*)0)

s21_size_t s21_strlen(const char* str);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
int s21_strstrHelper(const char* haystack, const char* needle);
char *s21_strtok(char *str, const char *delim);
void init_errors();
char* s21_strerror(int errnum);
char* s21_sprintf(char* str, const char* format, ...);
char* intToString(int d);
char* doubleToString(double d, char* str);
char* intToHexadecimalInteger(long int d, int registerLabel);
void reverseString(int j, char *string);
char switchRemaind(int remaind, int registerLabel);

#endif // S_21_STRING_H
