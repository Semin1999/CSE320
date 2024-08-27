// 연산자 (+, -, *, /, %, ++, !, ...)

#include <stdio.h>
#define SECOND_PER_MINUTE 60
#include <math.h> // 수학 관련 연산 함수 ex) pow(), abs()

int main(void){
    int input = 1000;
    int minute = input / SECOND_PER_MINUTE;
    int second = input % SECOND_PER_MINUTE;
    printf("\n1000초를 분 초로 환산을 하게 된다면 %d 분 %d 초 입니다\n", minute, second);

    int x = 30;
    int y = 50;

    if(x==y){
        printf("\nx 와 y가 같은 수입니다");
    }
    else{
        printf("\nx 와 y가 다른 수입니다");
    }
    
    //bool 값을 %d 로 출력하면 true면 1 false 면 0

    // 조건 연산자

    x = -50;
    y = 30;
    int absoluteX = (x > 0) ? x : -x;
    printf("\nx 의 절댓값은 다음과 같습니다: %d", absoluteX);

    double x = pow(2.0, 20.0); // 2의 20제곱
}