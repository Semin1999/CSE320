// 자료형 (int, char, float, double ...)
#include <stdio.h>
#define MONTHS 12 // 상수형 변수 지정

int main(void){
    
    double monthSalary = 1000.5;
    printf("The Annual Salary is : %.2f", monthSalary * MONTHS);
    
    char a = 'A'; // 캐릭터는 내부적으로 숫자이다
    char b = 65; // A = 65 for Ascii code
    int c = 65; // int 나 char 는 서로 선언하는거에 자유롭게 보여질수 있다.
    printf("\nThe character is : %c", a);
    printf("\nThe character is : %c", b);
    printf("\nThe character is : %c", c);

    int numeric = 100;
    printf("\n10 진수 출력: %d", numeric);
    printf("\n8 진수 출력: %o", numeric);

    return 0;
}

