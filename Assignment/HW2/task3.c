/*
Name: Semin Bae
Email: semin.bae@stonybrook.edu
*/

#include <stdio.h>

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

/* run my function! */
int main(int argc, char** argv) {

    printf("Name: Semin Bae \nEmail: semin.bae@stonybrook.edu\n");

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



