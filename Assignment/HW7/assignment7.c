/*
* File: assignment7.c
* Owner: Semin Bae 114730530
* Date: 2024/Nov/27
* Description: Implementation of the sleeping barber problem in C
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_CHAIRS 5
// Added: Define the total number of customers
#define NUM_CUSTOMERS 10
// Added: Define the haircut time in seconds
#define HAIR_CUT_TIME 1
// Added: Define the customer arrival interval in seconds
#define CUSTOMER_ARRIVAL_INTERVAL 1

// Semaphores for synchronization
sem_t barber_sem, customer_sem, access_seats_sem, haircut_sem;

// Variables to track state
int num_waiting = 0;
// Added: Variable to track the number of customers served or left
int customers_served = 0;

void* barber(void* arg) {
    printf("Barber shop has opened.\n");

    while (1) {
        sem_wait(&customer_sem); // Wait for a customer to arrive

        // Added: Notify that the barber is ready
        sem_post(&barber_sem);

        // Cutting hair
        printf("Barber: Start cutting hair.\n");
        sleep(HAIR_CUT_TIME);

        // Notify that the haircut is finished
        sem_post(&haircut_sem);

        // Added: Increment the number of customers served
        sem_wait(&access_seats_sem);
        customers_served++;
        // Added: Check if all customers have been served
        if (customers_served >= NUM_CUSTOMERS) {
            sem_post(&access_seats_sem);
            break;
        }
        sem_post(&access_seats_sem);
    }
    printf("Barber finished all the work!\n");
    pthread_exit(NULL);
    return NULL;
}

void* customer(void* arg) {
    long id = (long)arg + 1;

    // Protect access to seats
    sem_wait(&access_seats_sem);

    printf("Customer %ld arrives at the barber shop. Number waiting: %d\n", id, num_waiting);

    if (num_waiting < NUM_CHAIRS) {
        num_waiting++;

        sem_post(&customer_sem); // Notify the barber that a customer has arrived
        sem_post(&access_seats_sem); // Release access to seats

        sem_wait(&barber_sem); // Wait for the barber to be ready

        printf("Customer %ld: Getting a haircut.\n", id);

        sem_wait(&haircut_sem); // Wait for the haircut to be finished

        printf("Customer %ld: Finished! Got a haircut.\n", id);

        // Added: Decrease the number of waiting customers after getting a haircut
        sem_wait(&access_seats_sem);
        num_waiting--;
        sem_post(&access_seats_sem);

    } else {
        printf("Customer %ld: No seats available. Leaving.\n", id);
        // Added: Increment the number of customers served even if they leave (for termination condition)
        customers_served++;
        sem_post(&access_seats_sem); // Release access to seats
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t barber_thread, customer_threads[NUM_CUSTOMERS];

    // Initialize semaphores
    sem_init(&barber_sem, 0, 0);
    sem_init(&customer_sem, 0, 0); 
    sem_init(&access_seats_sem, 0, 1); 
    sem_init(&haircut_sem, 0, 0);

    pthread_create(&barber_thread, NULL, barber, NULL);

    for (long i = 0; i < NUM_CUSTOMERS; ++i) {
        pthread_create(&customer_threads[i], NULL, customer, (void*)i);
        // Sleep to simulate time between customer arrivals
        sleep(CUSTOMER_ARRIVAL_INTERVAL);
    }

    for (int i = 0; i < NUM_CUSTOMERS; ++i) {
        pthread_join(customer_threads[i], NULL);
    }

    pthread_join(barber_thread, NULL);

    // Destroy semaphores
    sem_destroy(&barber_sem);
    sem_destroy(&customer_sem);
    sem_destroy(&access_seats_sem);
    sem_destroy(&haircut_sem);

    return 0;
}
