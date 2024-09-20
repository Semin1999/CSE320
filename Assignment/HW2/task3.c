/*
Name: Semin Bae
Email: semin.bae@stonybrook.edu
*/

#include <stdio.h>
#include <stdlib.h>

struct Automobile {
  char manufacturer[30];
  char model[30];
  char year[10];
  char color[20];
  char price[20];
};

void get_array_count(int* count){

    int cnt = 0;

    printf("How many automobile’s data you want to store? (Positive Number): ");
    do{
        scanf("%d", &cnt);
    }while(cnt < 0);

    *count = cnt;
}

void write_auto_array(char* fileName, struct Automobile* pointer, int count) {

    if(count > 100) count = 100;

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

    FILE* binaryFile = fopen(fileName, "wb");

    fwrite(&count, sizeof(int), 1, binaryFile);

    fwrite(pointer, sizeof(struct Automobile), count, binaryFile);

    fclose(binaryFile);
}


void read_auto_array(char* fileName, struct Automobile* pointer, int* count) {

    if(*count > 100) *count = 100;

    FILE *binaryFile;

    binaryFile = fopen(fileName, "rb");

    fread(count, sizeof(int), 1, binaryFile);
    
    fread(pointer, sizeof(struct Automobile), *count, binaryFile);

    fclose(binaryFile);

    printf("\nThe count of Automobile array from binaryFile: %d\n", *count);

    for (int i = 0; i < *count; i++) {
        printf("\nThe Manufactures of %d sequence of array: %s\n", i, pointer[i].manufacturer);
        printf("The model of %d sequence of array: %s\n", i, pointer[i].model);
        printf("The year of %d sequence of array: %s\n", i, pointer[i].year);
        printf("The color of %d sequence of array: %s\n", i, pointer[i].color);
        printf("The price(krw) of %d sequence of array: %s\n", i, pointer[i].price);
    }
}

int validate_data(struct Automobile* original, struct Automobile* readData, int count) {
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


int main(int argc, char** argv) {

    printf("Name: Semin Bae \nEmail: semin.bae@stonybrook.edu\n");

    int count = 0;

    get_array_count(&count);
    
    struct Automobile arrayAutomobile[count];

    write_auto_array("auto.data", arrayAutomobile, count);

    struct Automobile readAutomobile[100];
    int readCount;
    read_auto_array("auto.data", readAutomobile, &readCount);

    if(validate_data(arrayAutomobile, readAutomobile, count)){
        printf("All datas are same!\n");
    }
    else{
        printf("The datas are not same!\n");
    }

    return 0;
}



