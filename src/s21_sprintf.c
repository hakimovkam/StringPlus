#include "s21_string.h"


char* s21_sprintf(char* str, const char* format, ...) {
    int d = 0, registerLabel = 0, n = 0, finish  = 0, gCounter = 0, percCount = 0;
    long int p = 0, x = 0, h = 0;
    int *nFunc;
    double f = 0, e = 0, g = 0;;
    char ch;
    char *str1;
    
    // char* string;
    
    va_list parametr;
    va_start(parametr, format);
    
    for (char *c = (char*)format; *c; c++) {
      finish = 0;
      percCount = 0;
        if (*c != '%') {
            *str++ = *c;
            n++;
            continue;
        }
        while (finish != 1) {
          // printf("1\n");
        switch (*c) {
            case 'd':
                d = va_arg(parametr, int);
                str1 = intToString(d);
                for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
                    *str++ = str1[i];
                    n++;
                }
                break;
            case 'f':
                f = va_arg(parametr, double);
                str1 = doubleToString(f, 0);
                for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
                    *str++ = str1[i];
                    n++;
                }
                break;
            case ('x'):
                x = va_arg(parametr,long int);
                if (x < 0) (x = unsignedInt + 1 - x);
                registerLabel = (*c == 'x') ? 0 : 1;
                str1 = intToHexadecimalInteger(x, registerLabel);
                for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
                    *str++ = str1[i];
                    n++;
                }
                break;
            case('X'):
                x = va_arg(parametr,int);
                if (x < 0) (x = unsignedInt + 1 - x);
                registerLabel = (*c == 'x') ? 0 : 1;
                str1 = intToHexadecimalInteger(x, registerLabel);
                for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
                    *str++ = str1[i];
                    n++;
                }
                break;
            case ('e'):
                e = va_arg(parametr, double);
                registerLabel = (*c == 'e') ? 0 : 1;
                str1 = doubleToE(e, registerLabel);
                for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
                    *str++ = str1[i];
                    n++;
                }
                break;
            case ('E'):
                e = va_arg(parametr, double);
                registerLabel = (*c == 'e') ? 0 : 1;
                str1 = doubleToE(e, registerLabel);
                for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
                    *str++ = str1[i];
                    n++;
                }
                break;
            case ('i'):
                d = va_arg(parametr, int);
                str1 = intToString(d);
                for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
                    *str++ = str1[i];
                    n++;
                }
                break;
            case ('c'):
                ch = va_arg(parametr, int);
                *str++ = ch;
                n++;
                break;
            case ('s'):
                str1 = va_arg(parametr, char*);
                for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
                    *str++ = str1[i];
                    n++;
                }
                break;
            case ('u'):
                h = va_arg(parametr, int);
                if (h < 0) {
                  h = unsignedInt + 1 + h;
                }
                printf("%ld\n", h);
                str1 = intToString(h);
                for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
                    *str++ = str1[i];
                    n++;
                }
                break;
            case ('%'):
                if (percCount == 1) {
                  *str++ = '%';
                  percCount = 0;
                  n++;
                } else {
                  percCount = 1;
                }
                break;
            case ('n'):
                nFunc = va_arg(parametr, int*);
                *nFunc = n;
                break;
            case ('\n'):
                *str++ = *c;
                n++;
                break;
            case ('\0'):
                *str++ = *c;
                // n++;
                finish = 1;
                break;
            case (' '):
                *str++ = *c;
                n++;
                finish = 1;
                break;
            case (','):
                *str++ = *c;
                finish = 1;
                break;
            case ('g'):
                g = va_arg(parametr, double);
                registerLabel = (*c == 'g') ? 0 : 1;
                gCounter = numCounter(g);
                if (gCounter > 6) {
                  str1 = doubleToE(g, registerLabel);
                } else {
                  str1 = doubleToString(g, 1);
                }
                for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
                    *str++ = str1[i];
                    n++;
                }
                break;
            case ('G'):
                g = va_arg(parametr, double);
                registerLabel = (*c == 'g') ? 0 : 1;
                gCounter = numCounter(g);
                if (gCounter > 6) {
                  str1 = doubleToE(g, registerLabel);
                } else {
                  str1 = doubleToString(g, 1);
                }
                for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
                    *str++ = str1[i];
                    n++;
                }
                break;
            case ('p'):
                p = va_arg(parametr, long int);
                str1 = intToHexadecimalInteger(p, 0);
                *str++ = '0';
                n++;
                *str++ = 'x';
                n++;
                for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
                    *str++ = str1[i];
                    n++;
                }
                break;
            // default:
            //     if (*c != '%') {
            //       *str++ = *c++;   Вроде не нужен, но пока оставлю
            //     }
            //     break;
        }
        c++;
        if (finish == 1) {
        *str++ = *c;
        }
        }
    }
      printf("%s\n", str1);
    va_end(parametr);
    while (*str) {
    *str++ = '\0';
  }

    // exit(1);
    return str;
}
//MARK: - int to string (%d)
///перевод целого числа в строку

char* intToString(long int d) {
    char *string;
    int minCount = 0;
    if (d < 0) {
      d = d * (-1);
      minCount = 1;
    }
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
    }
    if (minCount == 1) {
      if ((string = (char*)realloc(string, 1 * sizeof(char))) != NULL) {
        s21_size_t i = s21_strlen(string);
        do {
          string[i + 1] = string[i];
        } while (i--);
        string[0] = '-';
      }
    }
    return (string);
    free (string);
}

//MARK: - double to string
/// перевод нецелочисленного числа в строку
/// q = целое, d = дробное

char* doubleToString(double d, int gFlag) {
    char *string1, *string2, *string;
    int qInt = 0, dInt = 0, minCount = 0;
    double q = 0;
    if (d < 0) {
      d = d * (-1);
      minCount = 1;
    }
    d = modf(d, &q);
    qInt = q;
    string2 = intToString(qInt);
    for (int i = 0; i < 6; i++) {
        d = d * 10;
    }
    // d = round(d);

    dInt = d;
    string1 = intToString(dInt);
    
    int sum = (int)s21_strlen(string1) + (int)s21_strlen(string2);
    string = glueTwoString(string1, string2, sum, gFlag);

    if (minCount == 1) {
      if ((string = (char*)realloc(string, 1 * sizeof(char))) != NULL) {
        s21_size_t i = s21_strlen(string);
        do {
          string[i + 1] = string[i];
        } while (i--);
        string[0] = '-';
      }
    }
    return (string);
    free(string);
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
    
    return (string);
    free (string);
}
//MARK: - double to e

char* doubleToE(double e, int registerLabel) {
  char *string, *string1, *string2;
  int j = 0;
  // if (e < 0) {
  //   minCount = 1;
  // }
  int counter = 0;
  int plusCounter = 0;
  if (e > 0) {
    if (e < 1) {
      while (e < 1) {
        e = e * 10;
        counter++;
        plusCounter = 1;
      }
    } else if (e > 1) {
      while (e > 9) {
        e = e / 10;
        counter++;
      }
    }
  } else if (e < 0) {
    if (e > -1) {
      while (e > -1) {
        plusCounter = 1;
        e = e * 10;
        counter++;
      }
    } else if (e < -1) {
      while (e < -9) {
        e = e / 10;
        counter++;
      }
    }
  }
  string1 = doubleToString(e, 0);
  s21_size_t lenght1 = s21_strlen(string1);
  if (registerLabel == 0) {
    if ((string1 = (char*)realloc(string1, 1 * sizeof(char))) != NULL) {
      string1[lenght1++] = 'e';
    }
  } else {
    if ((string1 = (char*)realloc(string1, 1 * sizeof(char))) != NULL) {
      string1[lenght1++] = 'E';
    }
  }
  if (plusCounter == 1) {
    if ((string1 = (char*)realloc(string1, 1 * sizeof(char))) != NULL) {
      string1[lenght1++] = '-';
    }
  } else {
    if ((string1 = (char*)realloc(string1, 1 * sizeof(char))) != NULL) {
      string1[lenght1++] = '+';
    }
  }
  string2 = intToString(counter);
  if (counter < 10) {
    s21_size_t i = s21_strlen(string2);
    if ((string2 = (char*)realloc(string2, 1 * sizeof(char))) != NULL) {
      do {
        string2[i + 1] = string2[i];
      } while (i--);
    }
    string2[0] = '0';
  }
    
  int lenght = (int)s21_strlen(string1) + (int)s21_strlen(string2);
  if ((string = (char*)calloc((lenght + 1), sizeof(char))) != NULL) {
    for (int i = 0;  i < (int)(s21_strlen(string1)); i++) {
            string[j] = string1[i];
            j += 1;
        }
        for (int i = 0; i < (int)s21_strlen(string2); i++) {
            string[j] =  string2[i];
            j += 1;
        }
  }
  // if (minCount == 1) {
  //   if ((string = (char*)realloc(string, 1 * sizeof(char))) != NULL) {
  //       s21_size_t i = s21_strlen(string);
  //       do {
  //         string[i + 1] = string[i];
  //       } while (i--);
  //       string[0] = '-';
  //     }
  // }
  return string;
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

int numCounter(double g) {
  double q = 0;
  int counter = 0;
  g = modf(g, &q);
  while (q > 9) {
    q = q / 10;
    counter++;
  }
  counter++;
  return counter;
}

char* glueTwoString(char *string1, char *string2, int sum, int gFlag) {
    char *string;
    int j = 0, gCounter = 0;
    if ((string = (char *)calloc((sum + 1), sizeof(char))) != NULL) {
        for (int i = 0;  i < (int)(s21_strlen(string2)); i++) {
            if (gFlag == 1) {
              if (gCounter < 6) {
              string[j] = string2[i];
              j += 1;
              gCounter++;
              }
            } else {
              string[j] = string2[i];
              j += 1;
            }
        }
        if (gCounter < 6) {
        string[j] = '.';
        j += 1;
        }
        for (int i = 0; i < (int)s21_strlen(string1); i++) {
            if (gFlag == 1) {
                if (gCounter < 6) {
                  string[j] = string1[i];
                  j += 1;
                  gCounter++;
              }
            } else {
                string[j] = string1[i];
                j += 1;
            }
        }
    }
    return (string);
    free (string);
}
