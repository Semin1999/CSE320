#include <stdio.h>

int main(){
    float seedMoney;
    float interestRate;
    int interestYear; // that whill be length of 


    printf("Type the seed money in $: ");
    scanf("%f", &seedMoney);

    printf("\nType the interestRate: ");
    scanf("%f", &interestRate);

    printf("\nType the Interest Year: ");
    scanf("%d", &interestYear);

    float year[interestYear];
    year[0] = seedMoney;

    int pointer = 0;

    printf("Year \t Money \n");

    for(int i = 0; i <= interestYear; i++)
    {
        printf("%dY \t", i);
        if(i == 0){
            printf("$ %f\n", year[i]);
        }
        else{
            year[i] = year[i-1] +  year[i-1] * 0.01 * interestRate;
            printf("$ %f\n", year[i]);
        }
    }
}