/*
��� ��������� ����. ������� �� ������ ���������� �����, ������������� � ��� �������.
*/
#include <stdio.h>
#include <clocale>
#include <string.h>
#include <ctype.h>
const int N = 30;
int main(void){
    setlocale(LC_CTYPE, "rus");
    printf("|����� ���������� ����, ������������� � ������� �����|\n");
    FILE *f;
    printf ("�������� �����...\n");
    f=fopen("b:\\exz1.txt","r");
    char a[100];
    int ch;  //������, ��� ������������� ������
    //�������� �������� �����
    if (f == NULL)
        printf ("������ �������� exz1.txt...\n");
    else{
        printf ("���� ������ exz1.txt...\n");
        }
    printf ("���� ����� ���������� ���� � ������� ����� exz1.txt...\n");
    int i=0;
    while(((ch=fgetc(f))!=EOF)){  //���� �� ����� �����
        a[i]=ch; //���������� ������ � ������ a
        i++;
        }
    char *mass[N]={0};
    char *mass1[N]={0};
    const char separator[] = " \.,"; //�������-����������� ������
    char *Ptr = NULL; //��������� ��� ������� strtok

    Ptr = strtok(a, separator);
    int counter = 0;
    while (Ptr != NULL) //��������� ������ �� �����, ��������� � ����
    {
       mass[counter] = Ptr;
       Ptr = strtok(NULL, separator);
       counter++;
    }
    for(int i=0; i<N; i++){ //��������� �����
            for(int j=0; j<N; j++){
                if(strcmp(mass[i], mass[j])==0){
                    mass1[i] = mass[i];
                }
            }
        }
    printf("\n���������: ");
    printf("%s",mass1[i]);
    fclose(f);
    return 0;
}
