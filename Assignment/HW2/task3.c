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
        printf("What's the Manufacturer for %d sequence of array?: ", i);
        scanf("%30s", pointer[i].manufacturer);

        printf("What's the model for %d sequence of array?: ", i);
        scanf("%30s", pointer[i].model);
        
        printf("What's the year for %d sequence of array?: ", i);
        scanf("%10s", pointer[i].year);
        
        printf("What's the color for %d sequence of array?: ", i);
        scanf("%20s", pointer[i].color);
        
        printf("What's the price for %d sequence of array?: ", i);
        scanf("%20s", pointer[i].price);
    }

    FILE* binaryFile = fopen(fileName, "wb");

    fwrite(&count, sizeof(int), 1, binaryFile);

    fwrite(pointer, sizeof(struct Automobile), count, binaryFile);

    fclose(binaryFile);
}

void read_auto_array(char* fileName, struct Automobile* pointer, int* count) {

    if(count > 100) count = 100;

    FILE *binaryFile;

    binaryFile = fopen(fileName, "rb");

    fread(count, sizeof(int), 1, binaryFile);
    
    fread(pointer, sizeof(struct Automobile), *count, binaryFile);

    fclose(binaryFile);

    for (int i = 0; i < *count; i++) {
        printf("Manufacturer: %s, Model: %s, Year: %s, Color: %s, Price: %s\n", 
               pointer[i].manufacturer, pointer[i].model, pointer[i].year, 
               pointer[i].color, pointer[i].price);
    }
}

int main(int argc, char** argv) {

    printf("Name: Semin Bae \nEmail: semin.bae@stonybrook.edu\n");

    int count = 0;

    get_array_count(&count);
    
    struct Automobile arrayAutomobile[count];

    char* fileName = "auto.txt";

    //write_auto_array(fileName, arrayAutomobile, count);

    read_auto_array(fileName, arrayAutomobile, &count);

    return 0;
}



