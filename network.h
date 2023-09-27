
#ifndef NETWORK_H_
#define NETWORK_H_

#define MAX_INTERFACES 10

struct interfaces {
    char * name;
    char * subnet;
};

int getAllInterfaces(struct interfaces *** arr);

#endif