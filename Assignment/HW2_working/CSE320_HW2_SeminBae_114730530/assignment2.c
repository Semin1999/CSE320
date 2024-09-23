/*
Name: Semin Bae
Email: semin.bae@stonybrook.edu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculator();

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


void sumAndAverage(int* pnt, int cnt, double** dst){

    /* Initalizes sum and average variables */
    double sum = 0.0;
    double average = 0.0;

    /* Add up the every pnt int values in to sum variables */ 
    for(int i = 0; i < cnt; i++){
        int pntValue = *(pnt + i);
        sum += pntValue;
    }

    /* Get average from sum and count */
    if(cnt > 0)average = sum/cnt;
    else average = 0;
    
    /* Use malloc to get dynamic memory allocate for two double return value */
    *dst = malloc(2 * sizeof(double));

    /* Store to the first element */
    **dst = sum;
    *(*dst+1) = average;

    /* Print sum and average from the memory address */
    printf("\nPrint in sumAndAverage function from memory address not the variables\n");
    printf("The Sum in List Elements: %.2f \n", **dst);
    printf("the Average in List Elements: %.2f \n", *(*dst+1));
}



/* Make struct named Automobile */
struct Automobile {
  char manufacturer[30];
  char model[30];
  char year[10];
  char color[20];
  char price[20];
};

/* input the array count */
void get_array_count(int* count){

    /* initalize number count */
    int cnt = 0;

    /* Get array count through scan until it's positive number */
    printf("How many automobile’s data you want to store? (Positive Number): ");
    do{
        scanf("%d", &cnt);
    }while(cnt < 0);

    /* assign the number in to the count memory address */
    *count = cnt;
}

/* write function with proper name */
void write_auto_array(char* fileName, struct Automobile* pointer, int count) {

    /* if count is better than 100, then make limit with 100 length */
    if(count > 100) count = 100;

    /* get user input through scan with for loops */
    for(int i = 0; i < count; i++){
        printf("\nWhat's the Manufacturer for %d sequence of array?: ", i);
        scanf("%30s", pointer[i].manufacturer);

        printf("What's the model for %d sequence of array?: ", i);
        scanf("%30s", pointer[i].model);
        
        printf("What's the year for %d sequence of array?: ", i);
        scanf("%10s", pointer[i].year);
        
        printf("What's the color for %d sequence of array?: ", i);
        scanf("%20s", pointer[i].color);
        
        printf("What's the price for %d sequence of array? (krw): ", i);
        scanf("%20s", pointer[i].price);
    }

    /* open the file with binary write */
    FILE* binaryFile = fopen(fileName, "wb");

    /* the first write for the integer number with length of struct array */
    /* write the count with size of int(4bytes) with 1 space in to the binary file */
    fwrite(&count, sizeof(int), 1, binaryFile);

    /* then write the struct array what we made with user inputs */
    /* write the struct array with pointer where the array start in size of sturct Automobile with array length size to the binary file */
    fwrite(pointer, sizeof(struct Automobile), count, binaryFile);

    /* close the write function */
    fclose(binaryFile);
}

/* read function with proper name */
void read_auto_array(char* fileName, struct Automobile* pointer, int* count) {

    /* if the array length is over 100, the make it 100 size (give limit for 100)*/
    if(*count > 100) *count = 100;

    /* initalize file binary with pointer */
    FILE *binaryFile;

    /* open for binary read */
    binaryFile = fopen(fileName, "rb");

    /* read the first size of integer in binary file and assign in to the count variable */
    fread(count, sizeof(int), 1, binaryFile);
    
    /* read the next number of count size for automobile struct from the pointer*/
    fread(pointer, sizeof(struct Automobile), *count, binaryFile);

    /* close reading */
    fclose(binaryFile);

    /* print the variables for the validation */
    printf("\nThe count of Automobile array from binaryFile: %d\n", *count);

    /* print the variables for the validation */
    for (int i = 0; i < *count; i++) {
        printf("\nThe Manufactures of %d sequence of array: %s\n", i, pointer[i].manufacturer);
        printf("The model of %d sequence of array: %s\n", i, pointer[i].model);
        printf("The year of %d sequence of array: %s\n", i, pointer[i].year);
        printf("The color of %d sequence of array: %s\n", i, pointer[i].color);
        printf("The price(krw) of %d sequence of array: %s\n", i, pointer[i].price);
    }
}

/* function for validate data*/
int validate_data(struct Automobile* original, struct Automobile* readData, int count) {
   
   /* if even one of data is different between original datas and read datas then return 0 else return 1 */
    for (int i = 0; i < count; i++) {
        if (original[i].manufacturer == readData[i].manufacturer)
            return 0;
        else if (original[i].model == readData[i].model)
            return 0;
        else if (original[i].year == readData[i].year)
            return 0;
        else if (original[i].color == readData[i].color)
            return 0;
        else if (original[i].price == readData[i].price)
            return 0;
        }
    return 1;
}

/* define the max filename, word length for each word, word count in the list */
#define MAX_FILENAME 50
#define MAX_WORDLENGTH 30
#define MAX_WORDCOUNT 1000

/* It just assign the values in text file to the list and count how many words inside */
int assignAllWordsInList(char* fileName, char listWord[MAX_WORDCOUNT][MAX_WORDLENGTH]) {
    /* open the file with filename for read */
    FILE *file = fopen(fileName, "r");
    
    /* check if file opened successfully */
    if (file == NULL) {
        fprintf(stderr, "OPEN ERROR '%s'\n", fileName);
        return -1;  /* return -1 to indicate error */
    }

    /* initialize word count */
    int wordCount = 0;

    /* read and scan the string in file with sequence wordCount, so I gradually increment the wordCount until MAX_WORDCOUNT */
    while (wordCount < MAX_WORDCOUNT) {
        if (fscanf(file, "%s", listWord[wordCount]) != 1) {
            if (feof(file)) {
                break;  /* End of file reached */
            } else {
                fprintf(stderr, "Reading ERROR '%s' failed\n", fileName);
                fclose(file);
                return -1;  /* return -1 to indicate error */
            }
        }
        /* increment wordcount for count the word and go to the next list of word */
        wordCount++;
    }

    /* check if we reached MAX_WORDCOUNT */
    if (wordCount == MAX_WORDCOUNT && !feof(file)) {
        fprintf(stderr, "MAX WORD COUNT!.\n");
    }

    /* close the file */
    if (fclose(file) != 0) {
        fprintf(stderr, "CLOSE ERROR '%s'\n", fileName);
        return -1;  /* return -1 to indicate error */
    }

    /* return the word count in the text file */
    return wordCount;
}

/* return the unique list, so it has only unique word in this list */
char** makeUniqueList(char listWord[MAX_WORDCOUNT][MAX_WORDLENGTH], int totalCount, int* uniqueCount){
    /* assign the dynamic memory space with size total list size for string */
    char** uniqueList = malloc(totalCount * sizeof(char*));

    /* start with count zero for the first word */
    *uniqueCount = 0;

    /* check wheather is this unique or not to use for loops */
    for (int i = 0; i < totalCount; i++) {
        /* start with isUnique = true */
        int isUnique = 1;

        /* and traversal the uniqueCount that we're collecting */
        for (int j = 0; j < *uniqueCount; j++) {
            /* if the listWord and uniquewords are same */
            if (strcmp(listWord[i], uniqueList[j]) == 0) {
                /* then it is not unique and break the for loops */
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            /* if it is unique, then copy the list word in to the unique list sequence, if it assigned then unique, then count will increse */
            uniqueList[*uniqueCount] = strdup(listWord[i]);
            (*uniqueCount)++;
        }
    }

    return uniqueList;
}

/* compare the uniquelist and wordlist to find common word in the wordlist */
char* findCommonWord(char listWord[MAX_WORDCOUNT][MAX_WORDLENGTH], int totalCount, char** uniqueList, int uniqueCount, int* commonWordCount){
    /* assign the maxCount and maxIndex with start 0 */
    int maxCount = 0;
    char* commonWord = "";

    /* find common word to use for loops */
    for (int i = 0; i < uniqueCount; i++) {
        int count = 0;
        for (int j = 0; j < totalCount; j++) {
            /* if the uniquelist and this listword are same then increase the count */
            if (strcmp(uniqueList[i], listWord[j]) == 0) {
                count++;
            }
        }
        /* if this word is greater than maxCount, then that count will be the maxCount, and change the commonWord */
        if (count > maxCount) {
            maxCount = count;
            commonWord = uniqueList[i];

            /* assign the most common word count in the address */
            *commonWordCount = maxCount;
        }
    }

    /* return the common word string */
    return commonWord;
}

int task1(){
    
    printDay(Sunday);
    printDay(Monday);
    printDay(Tuesday);
    printDay(Wednesday);
    printDay(Thursday);
    printDay(Saturday);
    
    return 0;
}

void task2(){
    
    /* Initialize count variable */
    int count = 0;

    /* scan the count variables until it positive number */
    do{
        printf("Please enter the number of values for which you want to calculate the sum and average : ");
        scanf("%d", &count);
    }while(count <= 0);

    /* make dynamic allocated memory for the pointer */
    int* pointer = malloc(count * sizeof(int));

    /* scan the array elements to use for loops */
    printf("Enter %d number of Integers: ", count);
    for(int i = 0; i < count; i++){
        scanf("%d", &pointer[i]);
    }

    /* Initialize the destination address */
    double* destination;

    /* Function call */
    sumAndAverage(pointer, count, &destination);

    /* Print sum and Average from testFunction */
    printf("Print sum and Average from testFunction\n");
    printf("The Sum in List Elements: %.2f \n", *destination);
    printf("the Average in List Elements: %.2f \n", *(destination+1));
}

int task3(){
    int count = 0;

    /* get array count */
    get_array_count(&count);
    
    /* this is for write array */
    struct Automobile arrayAutomobile[count];

    /* write function */
    write_auto_array("auto.data", arrayAutomobile, count);

    /* this is for read array */
    struct Automobile readAutomobile[100];
    int readCount;
    read_auto_array("auto.data", readAutomobile, &readCount);

    /* check the write array and read array are same */
    if(validate_data(arrayAutomobile, readAutomobile, count)){
        printf("All datas are same!\n");
    }
    else{
        printf("The datas are not same!\n");
    }

    return 0;
}

int task6(){
    /* Initialize the listWord and fileName with given Max Length */
    char listWord[MAX_WORDCOUNT][MAX_WORDLENGTH];
    char fileName[MAX_FILENAME];

    /* scan the file name */
    printf("Enter the file name: ");
    scanf("%s", fileName);

    /* assign the words in text file to the listWord */
    int totalCount = assignAllWordsInList(fileName, listWord);

    /* print the total word count in the text file */
    printf("Word Count in the file: %d\n", totalCount);

    /* Initialize the length of unique list */
    int uniqueCount = 0;

    /* Make the uniqueList that assign the listWord elements with no duplicate */
    char** uniqueList = makeUniqueList(listWord, totalCount, &uniqueCount);

    /* Initialize the most common word count */
    int commonWordCount = 0;

    /* find the common word*/
    char* commonWord = findCommonWord(listWord, totalCount, uniqueList, uniqueCount, &commonWordCount);

    /* print to check how it works! */
    printf("The Most Common Word is '%s' with '%d' number of apperance\n", commonWord, commonWordCount);

    return 0;
}

/* Check how it works! */
int main(int argc, char **argv) {

    printf("Name: Semin Bae \nEmail: semin.bae@stonybrook.edu\n");

    printf("============\n== Task 1 ==\n============\n");
    task1();

    printf("============\n== Task 2 ==\n============\n");
    task2();


    printf("============\n== Task 3 ==\n============\n");
    task3();

    calculator();

    printf("============\n== Task 6 ==\n============\n");
    task6();

    return 0;

}
