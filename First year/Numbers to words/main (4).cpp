#include <stdio.h>
#include <clocale>

main() {
    setlocale(LC_CTYPE, "rus");
    int a,b;
    printf("������� �����, �������� ����� ��������: \b");
    scanf("%d %d", &a,&b);
    switch (a) {                                   //Switch ����������� ������ �����
    case 2:
        printf("\n\t ��������");
        break;
    case 3:
        printf("\n\t ��������");
        break;
    case 4:
        printf("\n\t �����");
        break;
    case 5:
        printf("\n\t ��������");
        break;
    case 6:
        printf("\n\t ��������");
        break;
    default:
        printf("����� �� ");
        break;
    }
    switch (b) {                                   //Switch ����������� ������ �����
    case 0:
        printf(" ���");
        break;
    case 1:
        printf(" ���� ���");
        break;
    case 2:
        printf(" ��� ����");
        break;
    case 3:
        printf(" ��� ����");
        break;
    case 4:
        printf(" ������ ����");
        break;
    case 5:
        printf(" ���� ���");
        break;
    case 6:
        printf(" ����� ���");
        break;
    case 7:
        printf(" ���� ���");
        break;
    case 8:
        printf(" ������ ���");
        break;
    case 9:
        printf(" ������ ���");
        break;
    default:
        printf("������ � ��������");
        break;
    }

  return 0;
}
