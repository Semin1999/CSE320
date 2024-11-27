#include <pthread.h>
#include <stdio.h>

// char **ptr; // .bss

// void *thread(void *vargp) {
//     long myid = (long)vargp; // stack
//     static int cnt = 1; // .data
//     printf("[%ld]: %s (cnt=%d)\n", myid, ptr[myid], ++cnt);
//     return NULL;
// }
// int main() {
//     long i;
//     pthread_t tid;
//     char *msg[2] = {"hello", "world"};
//     ptr = msg; // copy a local msg var to a global ptr var
//     for(i = 0; i < 2; i++){
//          pthread_create(&tid, NULL, thread, (void*)i);
//     }
//     pthread_exit(NULL);
// }

// #include <pthread.h>
// #include <stdio.h>
// void *thread(void *vargp) {
//     int a;
//     printf("%ld: &a = %p\n", pthread_self(), &a);
//     pthread_exit(NULL);
//     return NULL;
// }
// int main() {
//     pthread_t tid;
//     int i = 0;
//     for(i = 0; i < 10; i++){
//         pthread_create(&tid, NULL, thread, NULL);
//     }
//     pthread_exit(NULL);
//     return 0;
// }

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

// sem_t mutex;
// volatile long cnt = 0;

// void* thread(void *vargp) {
//     long i, niters = *((long*)vargp);

//     sem_wait(&mutex);
//     for(i = 0; i < niters; i++){
//         cnt++;
//         sem_post(&mutex);
//     }

//     return NULL;
// }

// int main() {
//     pthread_t tid1, tid2;

//     sem_init(&mutex, 0, 1);

//     long n = 100000;

//     pthread_create(&tid1, NULL, thread, &n);
//     pthread_create(&tid2, NULL, thread, &n);
    
//     pthread_join(tid1, NULL);
//     pthread_join(tid2, NULL);

//     sem_destroy(&mutex);
    
//     printf("cnt = %ld\n", cnt);
//     return 0;
// }

#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

// typedef struct {
//     int *buf;
//     int capacity, head, tail;
//     sem_t mutex;
//     sem_t slots;
//     sem_t items;
// } sbuf_t;

// void sbuf_init(sbuf_t* sp, int n) {
//     sp->buf = (int*) calloc(n, sizeof(int));
//     sp->capacity = n;
//     sp->head = sp->tail = 0;
//     sem_init(&sp->mutex, 0, 1);
//     sem_init(&sp->slots, 0, n);
//     sem_init(&sp->items, 0, 0);
// }

// void sbuf_deinit(sbuf_t *sp) {
//     free(sp->buf);
//     sem_destroy(&sp->mutex);
//     sem_destroy(&sp->slots); sem_destroy(&sp->items);
// }

// int sbuf_size(sbuf_t *sp) {
//     sem_wait(&sp->mutex); // access buffer after acquiring the lock
//     int n = (sp->head + sp->capacity - sp->tail) % sp->capacity;
//     sem_post(&sp->mutex);
//     return n;
// }

// void sbuf_insert(sbuf_t *sp, int item) {
//     sem_wait(&sp->slots); // wait while the buffer is full
//     sem_wait(&sp->mutex); // access buffer after acquiring the lock
//     sp->head = (sp->head + 1) % sp->capacity;
//     sp->buf[sp->head] = item;
//     sem_post(&sp->mutex);
//     sem_post(&sp->items); // wake up consumer if it is suspended
// }

// int sbuf_remove(sbuf_t *sp) {
//     sem_wait(&sp->items); // wait while the buffer is empty
//     sem_wait(&sp->mutex); // access buffer after acquiring the lock
//     sp->tail= (sp->tail + 1) % sp->capacity;
//     int item = sp->buf[sp->tail];
//     sem_post(&sp->mutex);
//     sem_post(&sp->slots); // wake up producer if it is suspended
//     return item;
// }

// void* producer(void* vargp) {
//     sbuf_t *sp = (sbuf_t*)vargp;
//     int i, j;
//     for(i = 0; i < 100; i++) {
//         long s = 0;
//         for(j = 0; j < 10000; j++){
//             s += j, sbuf_insert(sp, j);
//         }
//         printf("producer: sum: %ld, size: %d\n", s, sbuf_size(sp));
//     }
//     pthread_exit(NULL);
// }

// void* consumer(void* vargp) {
//     sbuf_t *sp = (sbuf_t*)vargp;
//     int i, j;
//     for(i = 0; i < 100; i++) {
//         long s = 0;
//         for(j = 0; j < 10000; j++){
//             s += sbuf_remove(sp);
//         }
//         printf("consumer: sum: %ld, size: %d\n", s, sbuf_size(sp));
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t tid_p, tid_c;
//     sbuf_t sb;
//     sbuf_init(&sb, 15000);
//     pthread_create(&tid_p, NULL, producer, &sb);
//     pthread_create(&tid_c, NULL, consumer, &sb);
//     pthread_join(tid_p, NULL);
//     pthread_join(tid_c, NULL);
//     sbuf_deinit(&sb);
//     return 0;
// }

// // First Readers-Writers problem
// //
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

// typedef struct {
//     sem_t mutex;
//     sem_t wlock;
//     int readcount;
// } rwlock;

// typedef struct {
//     int data;
//     int copy;
//     rwlock lock;
// } object;

// void rwlock_init(rwlock *lock) {
//     sem_init(&lock->mutex, 0, 1);
//     sem_init(&lock->wlock, 0, 1);
//     lock->readcount = 0;
// }

// void rwlock_deinit(rwlock *lock) {
//     sem_destroy(&lock->mutex);
//     sem_destroy(&lock->wlock);
// }

// void acquire_reader_lock(rwlock *lock) {
//     sem_wait(&lock->mutex);
//     lock->readcount++;
//     if(lock->readcount == 1) //if this is the first reader
//     sem_wait(&lock->wlock);//wait for a writer to finish or block writers
//     sem_post(&lock->mutex);
// }

// void release_reader_lock(rwlock *lock) {
//     sem_wait(&lock->mutex);
//     lock->readcount--;
//     if(lock->readcount == 0) //if this is the last reader
//     sem_post(&lock->wlock);//unblock any waiting writers
//     sem_post(&lock->mutex);
// }

// void acquire_writer_lock(rwlock *lock) {
//     sem_wait(&lock->wlock);
// }

// void release_writer_lock(rwlock *lock) {
//     sem_post(&lock->wlock);
// }

// void* reader(void *vargp) {
//     object* pobj = (object*)vargp;
//     int i;
//     for(i = 0; i < 100; i++) {
//         acquire_reader_lock(&pobj->lock);
//         int data = pobj->data;
//         int copy = pobj->copy;
//         release_reader_lock(&pobj->lock);
//         printf("R_%d: data: %d, copy: %d\n", i, data, copy);
//     }
// }

// void* writer(void *vargp) {
//     object* pobj = (object*)vargp;
//     int i;
//     for(i = 0; i < 100; i++) {
//         acquire_writer_lock(&pobj->lock);
//         int data = pobj->data = i % 10;
//         int copy = pobj->copy = pobj->data;
//         release_writer_lock(&pobj->lock);
//         printf("W_%d: data: %d, copy: %d\n", i, data, copy);
//     }
// }

// int main() {
//     pthread_t tid[3];
//     object obj;
//     obj.data = obj.copy = 0;
//     rwlock_init(&obj.lock);
//     pthread_create(tid+0, 0, reader, &obj);
//     pthread_create(tid+1, 0, reader, &obj);
//     pthread_create(tid+2, 0, writer, &obj);
//     pthread_join(tid[0], NULL);
//     pthread_join(tid[1], NULL);
//     pthread_join(tid[2], NULL);
//     rwlock_deinit(&obj.lock);
// }
