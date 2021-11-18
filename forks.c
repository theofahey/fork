//
//  forks.c
//  Systems
//
//  Created by Theodore Fahey on 11/16/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(){
    srand(time(NULL));
    printf("Before the Fork...\n");
    int n = fork();
    if (!n){
        int a = fork();
        printf("Child pid: %d\n", getpid());
        float b = rand()%4+2;
        sleep(b);
        printf("Done with child pid\n");
        return b;
        }
    
    if (n){
        int f = wait(&n);
        if (WIFEXITED(n)){
            printf("pid of child: %d, which slept for %d seconds\n",f,WEXITSTATUS(n) );
            printf("Parent is done\n");
        }
    }
}
