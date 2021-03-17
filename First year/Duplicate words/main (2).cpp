/*
Дан текстовый файл. Вывести на печать одинаковые слова, встречающиеся в его строках.
*/
#include <stdio.h>
#include <clocale>
#include <string.h>
#include <ctype.h>
const int N = 30;
int main(void){
    setlocale(LC_CTYPE, "rus");
    printf("|Поиск одинаковых слов, встречающихся в строках файла|\n");
    FILE *f;
    printf ("Открытие файла...\n");
    f=fopen("b:\\exz1.txt","r");
    char a[100];
    int ch;  //Символ, для посимвольного чтения
    //Проверка открытия файла
    if (f == NULL)
        printf ("Ошибка открытия exz1.txt...\n");
    else{
        printf ("Файл открыт exz1.txt...\n");
        }
    printf ("Идет поиск одинаковых слов в строках файла exz1.txt...\n");
    int i=0;
    while(((ch=fgetc(f))!=EOF)){  //Пока не конец файла
        a[i]=ch; //Записываем данные в строку a
        i++;
        }
    char *mass[N]={0};
    char *mass1[N]={0};
    const char separator[] = " \.,"; //Символы-разделители строки
    char *Ptr = NULL; //Указатель для функции strtok

    Ptr = strtok(a, separator);
    int counter = 0;
    while (Ptr != NULL) //Разделяем строку на слова, записывая в ЬФЫЫ
    {
       mass[counter] = Ptr;
       Ptr = strtok(NULL, separator);
       counter++;
    }
    for(int i=0; i<N; i++){ //Сравнение строк
            for(int j=0; j<N; j++){
                if(strcmp(mass[i], mass[j])==0){
                    mass1[i] = mass[i];
                }
            }
        }
    printf("\nРезультат: ");
    printf("%s",mass1[i]);
    fclose(f);
    return 0;
}
