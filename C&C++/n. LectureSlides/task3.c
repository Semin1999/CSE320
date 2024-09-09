#include <stdio.h>

/*
POINTER: & or *

int x = 10;
어떠한 메모리 값에 10이 저장되어 있고 이를 x라고 정의한것

int p;
p는 위 x와 동일한 변수이지만

int *p;
라면 그때부터 이건 포인터이다

int *p = 10; 을 넣는게 아니라

int *p = &x; 이런식으로 주소를 관리하는것이다
&는 주소를 말 하는것이다

그래서 int *p = &x 를 한다면 x의 주소에 현재 10이 저장되어있기 떄문에 10이 출력이 된다


만들어보자

학생 3명의 점수가 영어, 수학 90 85 , 80 55, 100 100 이고
struct 는 이름, 영어, 수학, 평균이고
전체 3명의 학생의 총 평균을 구하여라
*/

#include <stdio.h>

int main() {
    int a = 10;        // 일반 정수 변수
    int *p = &a;       // 포인터 p가 변수 a의 주소를 가리킴
    int **pp = &p;     // 이중 포인터 pp가 포인터 p의 주소를 가리킴
    int ***ppp = &pp;  // 삼중 포인터 ppp가 이중 포인터 pp의 주소를 가리킴

    // 값 출력
    printf("Value of a: %d\n", a);         // 변수 a의 값
    printf("Value of a using *p: %d\n", *p); // 포인터 p를 통해 변수 a의 값
    printf("Value of a using **pp: %d\n", **pp); // 이중 포인터 pp를 통해 변수 a의 값
    printf("Value of a using ***ppp: %d\n", ***ppp); // 삼중 포인터 ppp를 통해 변수 a의 값

    // 주소 출력
    printf("Address of a: %p\n", (void*)&a);   // 변수 a의 주소
    printf("Address of p: %p\n", (void*)p);    // 포인터 p가 저장하고 있는 주소 (a의 주소)
    printf("Address of pp: %p\n", (void*)pp);  // 이중 포인터 pp가 저장하고 있는 주소 (p의 주소)
    printf("Address of ppp: %p\n", (void*)ppp); // 삼중 포인터 ppp가 저장하고 있는 주소 (pp의 주소)

    return 0;
}
