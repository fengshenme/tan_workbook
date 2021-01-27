#include "../include/head.h"

int main(int argc, char const *argv[])
{
    //     const char *ip = "192.168.24.82";
    // const char *port = "6868";
    if (argc != 3)
    {
        fprintf(stderr, "%d] %s <ip addr> <port> \n", __LINE__, argv[0]);
        exit(EXIT_FAILURE);
    }

    
     index_t(argv[1], argv[2]);

    return 0;
}