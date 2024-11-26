/*
* File: assignment7.c
* Owner: Yoonseok Yang
* Date: 05.02.2024
* Description: Implement of sleeping barber problem in C
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_CHAIRS 5

sem_t barber_sem, customer_sem, access_seats_sem, haircut_sem, barber_done_sem;
int num_waiting = 0;

void* barber(void* arg) {
    while (1) {
        sem_wait(&customer_sem);
        sem_wait(&access_seats_sem);

        if (num_waiting > 0) {
            num_waiting--;
            printf("Barber: Cutting hair. Customers waiting: %d\n", num_waiting);

            sem_post(&access_seats_sem);
            sem_post(&haircut_sem);

            // Simulate haircut
            sleep(1);

            sem_post(&barber_done_sem);
        } else {
            // If no customers are waiting, release the access_seats_sem
            sem_post(&access_seats_sem);
        }
    }
}

void* customer(void* arg) {
    sem_wait(&access_seats_sem);

    if (num_waiting < NUM_CHAIRS) {
        num_waiting++;
        printf("Customer: Arrived. Customers waiting: %d\n", num_waiting);

        sem_post(&access_seats_sem);
        sem_post(&customer_sem);

        sem_wait(&haircut_sem);
        printf("Customer: Got a haircut.\n");

        // Acknowledge that the haircut is done
        sem_wait(&barber_done_sem);
    } else {
        printf("Customer: No seats available. Leaving.\n");
        sem_post(&access_seats_sem);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t barber_thread, customer_threads[10];

    sem_init(&barber_sem, 0, 0);
    sem_init(&customer_sem, 0, 0);
    sem_init(&access_seats_sem, 0, 1);
    sem_init(&haircut_sem, 0, 0);
    sem_init(&barber_done_sem, 0, 0);

    pthread_create(&barber_thread, NULL, barber, NULL);

    for (int i = 0; i < 10; ++i) {
        pthread_create(&customer_threads[i], NULL, customer, NULL);
        // Sleep to simulate time between customer arrivals
        sleep(1);
    }

    pthread_join(barber_thread, NULL);

    for (int i = 0; i < 10; ++i) {
        pthread_join(customer_threads[i], NULL);
    }

    sem_destroy(&barber_sem);
    sem_destroy(&customer_sem);
    sem_destroy(&access_seats_sem);
    sem_destroy(&haircut_sem);
    sem_destroy(&barber_done_sem);

    return 0;
}