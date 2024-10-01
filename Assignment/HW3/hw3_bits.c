#include <stdio.h>

int main() {
    // Initialize a byte with binary value 11101100 (in hexadecimal, 0xec) <== Note, try to use a binary constant. You may need to look up how to do this if it wasn't covered in class.
    // 11101100 = 4+8+32+64+128 = 236 = 0xEC
    int data = 0b11101100;
    data = 0xEC;

    // Display the initial value of 'data' in binary
    printf("Initial data: 0x%02X\n", data);

    // All problems where an nth bit is menthioned are counting the
    // 0 bit from the right side of the word (little endian)

    // Set the 3rd bit (counting from 0 where 0 is the rightmost bit!)
    int scaler = 1;
    data = data | scaler << 3; // data = 11101100 | 00001000
    printf("After setting 3rd bit: 0x%02X\n", data);
    printBinary(data);

    // Clear the 5th bit
    data = data & ~(scaler << 5); // ~(00100000) = 11011111 so 11101100 & 11011111
    printf("After clearing 5th bit: 0x%02X\n", data);
    printBinary(data);
    
    // Toggle the 7th bit
    if(data & scaler << 7){
        data = data & ~(scaler << 7);
    }
    else{
        data = data | scaler << 7;
    }
    printBinary(data);

    printf("After toggling 7th bit: 0x%02X\n", data);

    // Check and print a message if the 7th bit is set
    if(data & scaler << 7){
        print("7th bit is set");
    }
    
    return 0;
}

