#include <stdio.h>

// Name: Semin Bae (114730530)
// Email: semin.bae@stonybrook.edu

int main() {
    // Initialize a byte with binary value 11101100 (in hexadecimal, 0xec) <== Note, try to use a binary constant. You may need to look up how to do this if it wasn't covered in class.
    // 11101100 = 4+8+32+64+128 = 236 = 0xEC
    unsigned char data = 0b11101100; // or unsigned char data = 0xEC;

    // Display the initial value of 'data' in binary
    printf("Initial data: 0x%02X\n", data); // data = 11101100

    // All problems where an nth bit is menthioned are counting the
    // 0 bit from the right side of the word (little endian)

    // Set the 3rd bit (counting from 0 where 0 is the rightmost bit!)
    data |= (1 << 3); // data = 11101100 | 00001000 = 11101100
    printf("After setting 3rd bit: 0x%02X\n", data);

    // Clear the 5th bit
    data = data & ~(1 << 5); // ~(00100000) = 11011111 so, data = 11101100 & 11011111 = 11001100
    printf("After clearing 5th bit: 0x%02X\n", data);
    
    // Toggle the 7th bit
    data ^= (1 << 7); // data = 11001100 ^ 10000000 = 01001100
    printf("After toggling 7th bit: 0x%02X\n", data);

    // Check and print a message if the 7th bit is set
    if(data & (1 << 7)){
        printf("7th bit is set\n");
    }
    else{
        printf("7th bit is not set\n");
    }
    
    return 0;
}

