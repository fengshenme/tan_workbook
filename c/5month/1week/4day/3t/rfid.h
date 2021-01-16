#ifndef RFID_H
#define RFID_H

#include <QObject>
#include <QTimer>

#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/types.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#define DEV_PATH "/dev/ttySAC2"

class RFID {
public:
    RFID();
    ~RFID();
    void init_tty(int fd);
    unsigned char CalBCC(unsigned char* buf, int n);
    int PiccRequest(int fd);
    int PiccAnticoll(int fd);
    int open_serial();
    int close_serial(int fd);
    struct timeval timeout;
    unsigned int cardid;

private:
    // unsigned int buf[6] ;
};

#endif // RFID_H
