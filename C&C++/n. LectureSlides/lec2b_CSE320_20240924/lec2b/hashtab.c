#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 7

typedef struct {
  char name[40];
  int age;
} Person;

static Person *people[TABLE_SIZE];

int hash (char *key) {
  int hashidx = 0;
  char *workingKey = key;
  if (strlen(key) > 40) {
    return 0;
  } else {
    for (int i = 0; i < strlen(key); i++) {
      hashidx = ((hashidx << 1) + *workingKey++) % TABLE_SIZE;
    }
  }
  return hashidx;
}

int addToTable(char *key, Person *data) {
  int hashIdx = hash(key);

  Person *tempPerson = (Person *) malloc(sizeof(Person));

  strncpy(tempPerson->name, data->name, 40);

  // (*tempPerson).age = (*data).age;   // Need () to bind * first
  // C gives a shorthand for this [Syntactic sugar] :
  // tempPerson->name is equiavelent to: (*tempPerson).name

  tempPerson->age = data->age;
  
  int startHashIdx = hashIdx;
  
  while (people[hashIdx] != 0) {
    printf("Entry taken, trying next slot\n");
    hashIdx = (hashIdx + 1) % TABLE_SIZE;
    if (hashIdx == startHashIdx) {
      hashIdx = -1;
      break;
    }
  }
  if (hashIdx >= 0) {
    people[hashIdx] = tempPerson;
  } else {
    free (tempPerson);
  }
  return hashIdx;
}



int main(int argc, char **argv) {
  char *first = "Antonino";
  char *second = "Antonio";

  printf("Hash(Antonino) = %d\n", hash(first));
  printf("Hash(Antonio) = %d\n", hash(second));

  int location = 0;

  while (1) {
    Person *tempPerson = (Person *) malloc(sizeof(Person));
    printf("Enter name: ");
    scanf("%40s", tempPerson->name);
    if (strncmp(tempPerson->name, "-", 1) == 0) {
      break;
    }
    printf("Enter age: ");
    scanf("%d", &tempPerson->age);
    location = addToTable(tempPerson->name, tempPerson);
    if (location < 0) {
      printf("Failed to save data!\n");
      break;
    }
  }

  printf("Hash table contents: \n");
  for (int idx = 0; idx < TABLE_SIZE; idx++) {
    printf("Entry %d: \n", idx);
    if (people[idx] != 0) {
      printf("   Name: %s\n", people[idx]->name);
      printf("   Age: %d\n", people[idx]->age);
    } else {
      printf("   NULL\n");
    }
  }
}



