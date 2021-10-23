#include <signal.h>
#include <stdio.h>
#include <unistd.h>


void handleSignal(int signal){
    printf("Jajaja no me matas %d\n",signal);
}


int main(){
    signal(2,handleSignal);
    signal(12,handleSignal);
    while(1){
        printf("Trabajando \n");
        sleep(1);
    }
    return 0;
}



