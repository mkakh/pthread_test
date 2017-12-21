#include <stdio.h>
#include <pthread.h>
#define TH_NUM 8
#define N  1000000
#define INTERVAL  (N/TH_NUM)

static pthread_mutex_t mutex;
typedef struct {
    int id;
    long a[N];
} array_t;

void *th(void *aa) {
    array_t *arr = aa;
    pthread_mutex_lock(&mutex);
    const int id = arr->id;
    (arr->id)++;
    pthread_mutex_unlock(&mutex);
    const int s = INTERVAL * id;
    const int e = INTERVAL * (id + 1);

    for (int i = s; i < e; i++) {
        arr->a[i] = arr->a[i] * arr->a[i] * arr->a[i];
    }
    pthread_exit(NULL);
}

int main(void) {
    array_t arr;
    arr.id = 0;

    pthread_t thread[TH_NUM];
    for (int i = 0; i < N; i++) {
       arr.a[i] = i;
    }

    for (int i = 0; i < TH_NUM; i++) {
        pthread_create(&thread[i], NULL, th, (void *)&arr);
    }

    for (int i = 0; i < TH_NUM; i++) {
        pthread_join(thread[i], NULL);
    }

    //for (int i = 0; i < N; i++) {
    //    printf("%ld ", arr.a[i]);
    //}
    puts("");
}

