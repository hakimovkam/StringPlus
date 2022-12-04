 #include "s21_string.h"

int main () {
    char str[1000] = "\0";
    // int d = 65656;
    // int c = 3242344;
    int d = 1.1;
//    printf("%d - orig \n", d);
    
    char* str1 = "d = %f\n";
    s21_sprintf(str, str1, d);

//    printf("%x", -1);
    
    //    printf("%s\n", str);
}
