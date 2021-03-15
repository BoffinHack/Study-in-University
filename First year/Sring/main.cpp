/*
Дана непустая строка S. Вывести строку, содержащую символы строки S, между котороыми вставлено по одному пробелу.
*/
#include <stdio.h>
#include <clocale>
#include <string.h>
int main(){
    setlocale(LC_CTYPE, "rus");
    char s[5];
    printf("Введите строку: ");
    gets(s);
    int i=0;
    while(i<=strlen(s)){
        printf("\n%c",s[i]);
        i++;
    }
 return 0;
}
