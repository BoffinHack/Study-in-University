/*
���� �������� ������ S. ������� ������, ���������� ������� ������ S, ����� ��������� ��������� �� ������ �������.
*/
#include <stdio.h>
#include <clocale>
#include <string.h>
int main(){
    setlocale(LC_CTYPE, "rus");
    char s[5];
    printf("������� ������: ");
    gets(s);
    int i=0;
    while(i<=strlen(s)){
        printf("\n%c",s[i]);
        i++;
    }
 return 0;
}
