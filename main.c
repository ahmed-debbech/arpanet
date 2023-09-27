#include <stdio.h>
#include "network.h"


void request(int size, struct interfaces ** a){
    int i = 0;
    for(i=0; i<=size-1; i++){
        printf("[%d] %s \t %s\n", i+1, a[i]->name, a[i]->subnet);
    }

    return;
}
int main (){
    struct interfaces ** a;
    int size = getAllInterfaces(&a);

    request(size, a);
    return 0;
}

