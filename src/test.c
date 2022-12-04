#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include "s21_string.h"

char* intToString(int d);
char* intToHexadecimalInteger(int d);
void reverseString(int j, char *string);
char switchRemaind(int remaind);
char* decimalToBinary(int d);
//MARK: - main

int main() {
    char *string;
    int d = -1000;
    
//    string = decimalToBinary(d);
//    printf("%s\n", string);
    
    sprintf(string, "%x", d);
    
//    string = intToString(d);
    
    printf("%s\n", string);
    return 0;
}

char* intToString(int d) {
    char *string;
    if ((string = (char*)calloc(1, sizeof(char))) != NULL) {
        int j = 0;
        char temp;
            
        while (d > 9) {
            if ((string = (char *)realloc(string, (j+1) * sizeof(char))) != NULL) {
                string[j] = (d % 10) + '0';
                d = d / 10;
                j += 1;
            }
        }
        
        if ((string = (char*)realloc(string,(j+1) * sizeof(char))) != NULL) {
            string[j] = d + '0';
            string[j+1] = '\0';
            j += 1;
        }
  
        reverseString(j, string);
        
        free (string);
        return (string);
    }
}

char* intToHexadecimalInteger(int d) {
    char *string;
    char temp = '\0';
    int remaind = 0, j = 0;
    
    if ((string = (char *)calloc(1, sizeof(char))) != NULL) {
        while(d) {
            remaind = d % 16;
            if (remaind > 9) {
                if ((string = (char*)realloc(string,(j+1) * sizeof(char))) != NULL) {
                    temp = switchRemaind(remaind);
                }
            } else {
                temp = remaind + '0';
            }
            string[j] = temp;
            j += 1;
            d = d / 16;
        }
    }
    reverseString(j, string);

    free (string);
    return (string);
}

void reverseString(int j, char *string) {
    char temp = '\0';
    for (int i = 0; i < j / 2; i++) {
        temp = string[i];
        string[i] = string[j - 1 - i];
        string[j - 1 - i] = temp;
    }
}

char switchRemaind(int remaind) {
    char temp = '\0';
    switch(remaind) {
        case 10:
            temp = 'a';
            break;
        case 11:
            temp = 'b';
            break;
        case 12:
            temp = 'c';
            break;
        case 13:
            temp = 'd';
            break;
        case 14:
            temp = 'e';
            break;
        case 15:
            temp = 'f';
            break;
        case 16:
            temp = 10 + '0';
            break;
        default:
            break;
    }
    return temp;
}

char* decimalToBinary(int d) {
    char *string;
    char temp;
    if ((string = (char*)calloc(1, sizeof(char))) != NULL) {
        int j = 0;
        while (d == 1 || d == 0) {
            if ((string = (char*)realloc(string,(j+1) * sizeof(char))) != NULL) {
                temp = d % 2 + '0';
                string[j] = temp;
                d = d / 2;
                printf("%d", d);
                j += 1;
            }
        }
    }
    free (string);
    return string;
}
