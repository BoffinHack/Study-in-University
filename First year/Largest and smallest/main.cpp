#include <stdio.h>
#include <clocale>
int main() {
    int a,b,n,y;
    printf("Enter the numbers A and B: ");
    scanf("%d %d", &a,&b);
    if(a != b){                        //An algorithm that calculates the largest and smallest or zeroes values
            n=a+b;
            y=b-a;
    } else {
        n=0;
        y=0;
    }
    printf("Value lowest value = ");
    printf("%d", n);
    printf("Value largest value = ");
    printf("%d", y);
  return 0;
}
