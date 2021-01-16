
if [ -e *.out ]; then
    rm *.out
fi

gcc clientudp.c -o clientudp.out -Wall
gcc udpserver.c -o udpserver.out -Wall

