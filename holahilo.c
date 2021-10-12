#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 20 //numero de hilos
int saldo;
pthread_mutex_t saldoLock = PTHREAD_MUTEX_INITIALIZER;

void * suma100(void *arg){
    //char *c=(char *)arg;
    //printf("Hola desde un hilo %s \n", c);
    int lsaldo;
    pthread_mutex_lock(&saldoLock); //pongo un candado
    lsaldo = saldo; //crear una variable local
    lsaldo += 100; // sumo 100 a la variable local
    saldo = lsaldo; // actualizo variable global
    pthread_mutex_unlock(&saldoLock); //quito el candado
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    saldo = 0;
    char *s="Soy un argumento";
    for(int i=0; i<NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, suma100, NULL);
    }
    for(int i=0; i<NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    printf("Saldo final es %d\n", saldo);
    pthread_exit(NULL); //Hace que el proceso termine, no se ejecuta cualquier cosa después

    return 0;

}
