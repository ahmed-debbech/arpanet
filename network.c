#include <arpa/inet.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include "network.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getAllInterfaces(struct interfaces *** arr){
    struct ifaddrs *ifap, *ifa;
    struct sockaddr_in *sa;
    getifaddrs (&ifap);

    int i =0;
    ifa = ifap;
    while (ifa != NULL) {
        if (ifa->ifa_addr->sa_family==AF_INET) {
            sa = (struct sockaddr_in *) ifa->ifa_netmask;
            char * addr =  inet_ntoa(sa->sin_addr);
            struct interfaces * inter = malloc(sizeof(struct interfaces));
            inter->name = ifa->ifa_name;
            char * addr2 = (char*) malloc(sizeof(char) * (strlen(addr)-1));
            int y=0;
            for(y=0; y<=strlen(addr)-1; y++){
                addr2[y] = addr[y];
            }
            addr2[y]='\0';
            inter->subnet = addr2;
            *arr = realloc(*arr, (i+1)*  sizeof(struct interfaces *));
            (*arr)[i] = inter;
            i++;
        }
        ifa = ifa->ifa_next;
    }
    freeifaddrs(ifap);
    return i-1;
}