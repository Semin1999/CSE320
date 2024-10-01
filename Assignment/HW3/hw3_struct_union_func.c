#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// Define a union named "Data" to hold different data types
union Data {
    int intData;
    double doubleData;
    char *stringData;
};

// Define a structure named "SNN" to represent a spiking neuron network
struct SNN {
    char *neuronName;
    int neuronNumber;
    union Data commonData;
};

// Use typedef to create aliases for the structure and union
typedef struct SNN SNN;
typedef union Data Data;

// Function to modify a neuron name of SNN by reference
void modifyName(SNN *snn, char *newName) {
    snn->neuronName = newName;
}

void modifyNumber(SNN *snn, int newNumber) {
    snn->neuronNumber = newNumber;
}

// Function to modify the common data of a SNN by reference
void modifyData(SNN *snn, Data *data) {
    snn->commonData.intData = data->intData;
    snn->commonData.doubleData = data->doubleData;
    snn->commonData.stringData = data->stringData;
}

int main() {
    // Create an instance of the SNN structure
    SNN snnA;
    snnA.neuronName = malloc(50 * sizeof(char));
    strcpy(snnA.neuronName, "LIF Neuron");
    snnA.neuronNumber = 100;

    // print it
    printf("snnA.neuronName : %s\n", snnA.neuronName);
    printf("snnA.neuronNumber : %d\n", snnA.neuronNumber);
    
    // Create an instance of the Data union
    Data dataA;
    dataA.intData = 150;
    printf("dataA.intData : %d\n", dataA.intData);
    dataA.doubleData = 12.7;
    printf("dataA.doubleData : %.2f\n", dataA.doubleData);
    dataA.stringData = malloc(100 * sizeof(char));
    strcpy(dataA.stringData, "Number of synapses and average weight"); 
    printf("dataA.stringData : %s\n", dataA.stringData);

    printf("\n-- After modify name and number --\n");
    // Call the modifyName function by reference to change the name of snnA
    modifyName(&snnA, "Hodgkin-Huxley");
    printf("snnA.neuronName : %s\n", snnA.neuronName);

    // Call the modifyAge function by reference to change the number of snnA
    modifyNumber(&snnA, 20);
    printf("snnA.neuronNumber : %d\n", snnA.neuronNumber);

    // Call the modifyData function by reference to change the common data of snnA
    modifyData(&snnA, &dataA);

    // Display the modified snnA information
    printf("snnA.commonData.intData : %d <- 'garbage value' since union save only one(the last) value of data type\n", snnA.commonData.intData);
    printf("snnA.commonData.doubleData : %.2f <- 'garbage value' since union save only one(the last) value of data type\n", snnA.commonData.doubleData);
    printf("snnA.commonData.stringData : %s <- stringData was last assigned data\n", snnA.commonData.stringData);

    return 0;
}
