/*
Write a function that determines which character occurs less frequently than others (but not zero times ) in the string str placed in dynamic memory,
and how many times it is included in it. If there are several such characters, then take the first one alphabetically.
*/
#include <stdio.h>
#include <clocale>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>

const size_t SIZE = 50;

char Kol();

void* Kol(char *st){
    int *z;//Pointer to an array in which we count the number of each character
    z=(int*)calloc(SIZE,sizeof(int));
    //Counting the number of characters
    for(int i=0,n=0;i<strlen(st);i++,n=0){
        for(int j=0;j<strlen(st);j++){
            if(st[i]==st[j]){
                n++;
                z[i]=n;
            }
        }
    }
        //We use selective sorting by size
        int i;    //The number of the element from which the minimum element is searched
        int min;  //The number of the minimum element in the part of the line from i to the end of the line
        int j;    //The number of the element being compared with the minimum
        int g;    //Variable needed to exchange the number of character elements
        char f;   //Variable required for character exchange
        for(i=0;i<(strlen(st)-1);i++){
         min=i;
         for (j=i+1;j<(strlen(st)-1);j++){
             if(z[j]<z[min]){
                 min=j;
                 // We swap not only the dimensions of z[min] and z[i], but also the letters, since the letters and numbers are in different arrays
                 g=z[i];
                 f=st[i];
                 z[i]=z[min];
                 st[i]=st[min];
                 z[min]=g;
                 st[min]=f;
             }
         }
     }
        //Overwriting, we remove all characters whose number is greater than the minimum
        char* ctc;//Pointer to the array where we overwrite rare characters
        ctc=(char*)calloc(SIZE,sizeof(char));
        int* zc;//Number of rare characters
        zc=(int*)calloc(SIZE,sizeof(int));
        int m=z[0];
        for(int a=0;z[m]==z[a];a++){
            ctc[a]=st[a];
            zc[a]=z[a];
        }
        //We take the first character alphabetically
        char* alfs;//
        alfs=(char*)calloc(SIZE,sizeof(char));
        int* alfz;//Same for numbers
        alfz=(int*)calloc(SIZE,sizeof(int));
        char bol=65,mal=97;
        int t=0;
        for(;(bol<'Z')&&(mal<'z')&&(t!=1);bol++,mal++){
            for(int j=0;(j<strlen(ctc))&&(t!=1);j++){
                if(ctc[j]==bol){
                    alfs[0]=bol;
                    alfz[0]=zc[j];
                    t=1;
                }else{
                    if(ctc[j]==mal){
                        alfs[0]=mal;
                        alfz[0]=zc[j];
                        t=1;
                    }
                }
            }
        }
    printf("The character that occurs less frequently in the string --> ");
    for(int j=0;j<strlen(alfs);j++){
        printf("%c",alfs[j]);
        printf(" = ");
        printf("%d",alfz[j]);
        printf("\n");
    }
    free(z);
    free(ctc);
    free(zc);
    free(alfs);
    free(alfz);

}
int main(void){
    setlocale(LC_CTYPE, "rus");
    //Pointer to a string
    char *s;
    //Allocating memory for a string
    s=(char*)calloc(SIZE,sizeof(char));
    printf("Enter a maximum of 50 characters in the string:\n");
    fgets(s,50,stdin);
    Kol(s);
    free(s);
    return 0;
}
