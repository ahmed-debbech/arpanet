#include <arpa/inet.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include "network.h"
#include <stdio.h>
#include <stdlib.h>

int getAllInterfaces(struct interfaces *** arr){
    struct ifaddrs *ifap, *ifa;
    struct sockaddr_in *sa;
    char *addr;
    getifaddrs (&ifap);

    int i =0;
    for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr->sa_family==AF_INET) {
            sa = (struct sockaddr_in *) ifa->ifa_netmask;
            addr = inet_ntoa(sa->sin_addr);
            printf("%s == %s\n", addr, ifa->ifa_name);
            struct interfaces * inter = malloc(sizeof(struct interfaces));
            inter->name = ifa->ifa_name;
            inter->subnet = addr;
            *arr = realloc(*arr, (i+1)*  sizeof(struct interfaces *));
            (*arr)[i] = inter;
            i++;
        }
    }
    freeifaddrs(ifap);
    return i-1;
}