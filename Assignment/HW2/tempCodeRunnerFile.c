void read_auto_array(char* fileName, struct Automobile* pointer, int* count) {
    FILE *binaryFile;

    //binaryFile = fopen(fileName, "rb");

    //fread(count, sizeof(int), 1, binaryFile);
    
    //fread(pointer, sizeof(struct Automobile), *count, binaryFile);

    //fclose(binaryFile);

    for (int i = 0; i < *count; i++) {
        printf("Manufacturer: %s, Model: %s, Year: %s, Color: %s, Price: %s\n", 
               pointer[i].manufacturer, pointer[i].model, pointer[i].year, 
               pointer[i].color, pointer[i].price);
    }
}