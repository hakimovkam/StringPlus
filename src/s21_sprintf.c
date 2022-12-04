#include "s21_string.h"


char* s21_sprintf(char* str, const char* format, ...) {
    // printf("%s\n\n", str);
    int d = 0, registerLabel = 0;
    double f = 0;
    long int x = 0;
    char *str1;
    va_list parametr;
    va_start(parametr, format);
    
    for (char *c = (char*)format; *c; c++) {
        if (*c != '%') {
            *str++ = *c;
            continue;
        }
        switch (*++c) {
            case 'd':
                d = va_arg(parametr, int);
                str1 = intToString(d);
                for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
                    *str++ = str1[i];
                }
                break;
            case 'f':
                f = va_arg(parametr, double);
                str1 = doubleToString(f, str1);
                break;
            case ('x'):
                x = va_arg(parametr,long int);
                if (x < 0) (x = unsignedInt + 1 - x);
                registerLabel = (*c == 'x') ? 0 : 1;
                str1 = intToHexadecimalInteger(x, registerLabel);
                break;
            case('X'):
                x = va_arg(parametr,int);
                if (x < 0) (x = unsignedInt + 1 - x);
                registerLabel = (*c == 'x') ? 0 : 1;
                str1 = intToHexadecimalInteger(x, registerLabel);
                break;
            default:
                *str++ = *c++;
        }
    }
     printf("%s\n", str1);
    va_end(parametr);
    // exit(1);
    return str;
}
//MARK: - int to string (%d)
///перевод целого числа в строку
///
char* intToString(int d) {
    char *string;
    if ((string = (char*)calloc(1, sizeof(char))) != NULL) {
        int j = 0;
            
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
        printf("---%s\n", string);
    }
    free (string);
    return (string);
}

//MARK: - double to string
/// перевод нецелочисленного числа в строку
/// q = целое, d = дробное

char* doubleToString(double d, char* str) {
    char *string, *string2;
    int qInt = 0, dInt = 0;
    double q = 0;
    
    d = modf(d, &q);
    qInt = q;
    
    string2 = intToString(qInt);
    
    str[s21_strlen(string2)+1] = '.';
    
    for (int i = 0; i < 6; i++) {
        d = d * 10;
    }
    d = round(d);
    dInt = d;
  
    string = intToString(dInt);
    s21_strcat(string2, string);
    return (string2);
    }

// MARK: - int to hexadecimal (%x)
///перевод целого числа в шестнадцатеричное число
char* intToHexadecimalInteger(long int d, int registerLabel) {
    char *string;
    char temp = '\0';
    int remaind = 0, j = 0;
    
    if ((string = (char *)calloc(1, sizeof(char))) != NULL) {
        while(d) {
            remaind = d % 16;
            if (remaind > 9) {
                if ((string = (char*)realloc(string,(j+1) * sizeof(char))) != NULL) {
                    temp = switchRemaind(remaind, registerLabel);
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

//MARK: - вспомогательные функции

void reverseString(int j, char *string) {
    char temp = '\0';
    for (int i = 0; i < j / 2; i++) {
        temp = string[i];
        string[i] = string[j - 1 - i];
        string[j - 1 - i] = temp;
    }
}

char switchRemaind(int remaind, int registerLabel) {
    char temp = '\0';
    switch(remaind) {
        case 10:
            temp = registerLabel ? 'A' : 'a' ;
            break;
        case 11:
            temp = registerLabel ? 'B' : 'b' ;
            break;
        case 12:
            temp = registerLabel ? 'C' : 'c' ;
            break;
        case 13:
            temp = registerLabel ? 'D' : 'd' ;
            break;
        case 14:
            temp = registerLabel ? 'E' : 'e' ;
            break;
        case 15:
            temp = registerLabel ? 'F' : 'f' ;
            break;
        case 16:
            temp = 10 + '0';
            break;
        default:
            break;
    }
    return temp;
}

