#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 50
#define MAX_WORDLENGTH 30
#define MAX_WORDCOUNT 1000

int assignAllWordsInList(char* fileName, char listWord[MAX_WORDCOUNT][MAX_WORDLENGTH]){
    FILE *file = fopen(fileName, "r");

    int wordCount = 0;

    while(fscanf(file, "%s", listWord[wordCount]) == 1 && wordCount < MAX_WORDCOUNT){
        wordCount++;
    }

    fclose(file);

    return wordCount;
}

char** makeUniqueList(char listWord[MAX_WORDCOUNT][MAX_WORDLENGTH], int totalCount, int* uniqueCount){
    char** uniqueList = malloc(totalCount * sizeof(char*));
    *uniqueCount = 0;

    for (int i = 0; i < totalCount; i++) {
        int isUnique = 1;
        for (int j = 0; j < *uniqueCount; j++) {
            if (strcmp(listWord[i], uniqueList[j]) == 0) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            uniqueList[*uniqueCount] = strdup(listWord[i]);
            (*uniqueCount)++;
        }
    }

    return uniqueList;
}

int findCommonWord(char listWord[MAX_WORDCOUNT][MAX_WORDLENGTH], int totalCount, char** uniqueList, int uniqueCount){
    int maxCount = 0;
    int maxIndex = 0;

    for (int i = 0; i < uniqueCount; i++) {
        int count = 0;
        for (int j = 0; j < totalCount; j++) {
            if (strcmp(uniqueList[i], listWord[j]) == 0) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxIndex = i;
        }
    }

    return maxIndex;
}

int main(int argc, char **argv) {
    char listWord[MAX_WORDCOUNT][MAX_WORDLENGTH];
    char fileName[MAX_FILENAME];

    printf("파일 이름을 입력하세요: ");
    scanf("%s", fileName);

    int totalCount = assignAllWordsInList(fileName, listWord);

    printf("총 단어 수: %d\n", totalCount);

    int uniqueCount;
    char** uniqueList = makeUniqueList(listWord, totalCount, &uniqueCount);

    printf("고유한 단어 수: %d\n", uniqueCount);

    int commonWordIndex = findCommonWord(listWord, totalCount, uniqueList, uniqueCount);

    printf("가장 많이 나타난 단어: %s\n", uniqueList[commonWordIndex]);

    // 메모리 해제
    for (int i = 0; i < uniqueCount; i++) {
        free(uniqueList[i]);
    }
    free(uniqueList);

    return 0;
}