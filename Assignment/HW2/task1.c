/*
Name: Semin Bae
Email: semin.bae@stonybrook.edu
*/

#include <stdio.h>

/* Declare enum to use typedef */
typedef enum DayOfWeek{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
} DayOfWeek;

/* Function to print Sun ~ Sat according to DayofWeek */
void printDay(DayOfWeek day) {
    switch (day) {
        case Sunday:
            printf("Sun\n");
            break;
        case Monday:
            printf("Mon\n");
            break;
        case Tuesday:
            printf("Tue\n");
            break;
        case Wednesday:
            printf("Wed\n");
            break;
        case Thursday:
            printf("Thur\n");
            break;
        case Friday:
            printf("Fri\n");
            break;
        case Saturday:
            printf("Sat\n");
            break;
        default:
            printf("Invalid\n");
            break;
    }
}

/* Validate how it works! */
int main(int argc, char **argv) {
    printf("Name: Semin Bae \nEmail: semin.bae@stonybrook.edu\n");
    printDay(Sunday);
    printDay(Monday);
    printDay(Tuesday);
    printDay(Wednesday);
    printDay(Thursday);
    printDay(Saturday);

    return 0;
}
