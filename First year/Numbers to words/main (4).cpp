#include <stdio.h>
#include <clocale>

main() {
    setlocale(LC_CTYPE, "rus");
    int a,b;
    printf("¬ведите число, раздел€€ цифры пробелом: \b");
    scanf("%d %d", &a,&b);
    switch (a) {                                   //Switch анализирует первое число
    case 2:
        printf("\n\t ƒвадцать");
        break;
    case 3:
        printf("\n\t “ридцать");
        break;
    case 4:
        printf("\n\t —орок");
        break;
    case 5:
        printf("\n\t ѕ€тдес€т");
        break;
    case 6:
        printf("\n\t Ўесдес€т");
        break;
    default:
        printf("„исло не ");
        break;
    }
    switch (b) {                                   //Switch анализирует второе число
    case 0:
        printf(" лет");
        break;
    case 1:
        printf(" один год");
        break;
    case 2:
        printf(" два года");
        break;
    case 3:
        printf(" три года");
        break;
    case 4:
        printf(" четыре года");
        break;
    case 5:
        printf(" п€ть лет");
        break;
    case 6:
        printf(" шесть лет");
        break;
    case 7:
        printf(" семь лет");
        break;
    case 8:
        printf(" восемь лет");
        break;
    case 9:
        printf(" дев€ть лет");
        break;
    default:
        printf("входит в диапазон");
        break;
    }

  return 0;
}
