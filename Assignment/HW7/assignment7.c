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
#define NUM_CUSTOMERS 10
#define HAIR_CUT_TIME 3 
#define CUSTOMER_ARRIVAL_INTERVAL 1

sem_t barber_sem, customer_sem, access_seats_sem, haircut_sem, barber_done_sem;

int num_waiting = 0;
// Added variable to track the number of customers served
int customers_served = 0;

void* barber(void* arg) {
    printf("Barber shop has opened.\n");

    while (1) {
        sem_wait(&customer_sem); // 손님 기다림, 0 이니까 아마 안할거

        // 이발사 준비 완료를 알림
        sem_post(&barber_sem);

        // 이발 중
        printf("Barber: Start Cutting hair.\n");
        sleep(HAIR_CUT_TIME);

        // 이발 완료를 알림
        sem_post(&haircut_sem);

        // 고객 처리 완료 수 증가
        sem_wait(&access_seats_sem);
        customers_served++;
        // 모든 고객을 처리했는지 확인
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

    // 좌석 접근 보호
    sem_wait(&access_seats_sem);

    printf("Customer %ld come barber shop with num waiting: %d\n", id, num_waiting);

    if (num_waiting < NUM_CHAIRS) {
        num_waiting++;

        sem_post(&customer_sem); // 이발사에게 고객 도착 알림
        sem_post(&access_seats_sem); // 좌석 접근 해제

        sem_wait(&barber_sem); // 이발사 준비 대기

        printf("Customer %ld: Getting a haircut.\n", id);

        sem_wait(&haircut_sem); // 이발 완료 대기

        printf("Customer %ld: Finish! got a haircut.\n", id);

        // 이발 의자에 앉으므로 num_waiting 감소
        sem_wait(&access_seats_sem);
        num_waiting--;
        sem_post(&access_seats_sem);

    } else {
        printf("Customer %ld: No seats available. Leaving.\n", id);
        customers_served++;
        sem_post(&access_seats_sem); // 좌석 접근 해제
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t barber_thread, customer_threads[NUM_CUSTOMERS];

    sem_init(&barber_sem, 0, 0); // 바버는 처음에 일 안함
    sem_init(&customer_sem, 0, 0); // 커스터머도 처음에 안함
    sem_init(&access_seats_sem, 0, 1); // 자리는 처음에 가능
    sem_init(&haircut_sem, 0, 0); // 헤어컷도 처음에 안함

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

    sem_destroy(&barber_sem);
    sem_destroy(&customer_sem);
    sem_destroy(&access_seats_sem);
    sem_destroy(&haircut_sem);

    return 0;
}