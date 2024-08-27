#include <stdio.h>

int main(void){
    char c;
    int i, j;

    while(1){
        printf("\n 수식을 입력하세요: ");
        scanf("%d %c %d", &i, &c, &j);

        if(c == '+'){
            printf("%d + %d = %d", i, j, i+j);
        }
        else if(c == '-'){
            printf("%d + %d = %d", i, j, i-j);
        }
        else if(c == '*'){
            printf("%d + %d = %d", i, j, i*j);
        }
        else if(c == '/'){
            printf("%d + %d = %d", i, j, i/j);
        }
        else{
            printf("\n수식 입력이 잘못 되었습니다");
        }
        printf("\n프로그램을 종료 하실건가요?");
        
        getchar(); //버퍼를 처리 해줌
        
        scanf("%c", &c);

        if(c == 'y' || c == 'Y'){
            printf("\n게임이 종료되었습니다");
            break;
        }
        else if(c == 'n' || c == 'N'){
            printf("\n게임이 한번 더 시작됩니다");
            continue;
        }
        else{
            printf("\n입력이 잘못 되었습니다");
        }
    }

    return 0;
}