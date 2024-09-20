#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define the max filename, word length for each word, word count in the list */
#define MAX_FILENAME 50
#define MAX_WORDLENGTH 30
#define MAX_WORDCOUNT 1000

/* It just assign the values in text file to the list and count how many words inside */
int assignAllWordsInList(char* fileName, char listWord[MAX_WORDCOUNT][MAX_WORDLENGTH]){

    /* open the file with filename for read */
    FILE *file = fopen(fileName, "r");

    /* initialize word count */
    int wordCount = 0;

    /* read and scan the string in file with sequence wordCount, so I gradually increment the wordCount until MAX_WORDCOUNT */
    while(fscanf(file, "%s", listWord[wordCount]) == 1 && wordCount < MAX_WORDCOUNT){
        /* increment wordcount for count the word and go to the next list of word */
        wordCount++;
    }

    /* close the file */
    fclose(file);

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

int main(int argc, char **argv) {
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