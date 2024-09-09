#include "sort_words.h"
#include <string.h>


int main(){
    // char hello[] = "Hello";
    // char* pointerHello = hello;
    // char** secondPointerHello = &pointerHello;
}

//swap word[i] and word[j]
static void swap(char **words, int i, int j) {
    char *tmp = words[i];
    words[i] = words[j];
    words[j] = tmp;
}

//TODO: sort words using the selection sort
void sort_words(char **words, int wc) {
    for (int i = 0; i < wc; i++) {
        printf("%s\n", words[i]); // Print each word
    }
}
