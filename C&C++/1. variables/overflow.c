#include <stdio.h>
#include <limits.h>

int main(void){
    int x = INT_MAX;
    printf("int x 의 최댓값은 %d 입니다\n", x);
    printf("int 의 한게값보다 1이 더해지면 overflow 가 됩니다. \n값은 다음과 같습니다: %d", x+1);
    return 0;
}