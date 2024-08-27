#include <stdio.h>

int main(void){

    int x = 50; // 4 byte
    float y = 12345678.12345678; // 4byte
    double z = 12345678.12345678; // 8 byte

    printf("\n x(int) = %d \n", x); // %d 는 int 출력
    printf("\n y(float) = %.2f \n", y); // %f 는 소수점 출력
    printf("\n z(double) = %f \n", z); // %f 는 소수점 출력
    return 0;
}