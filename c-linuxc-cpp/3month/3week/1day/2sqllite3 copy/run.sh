#!/bin/bash

# gcc -fPIC -shared *.c -o libsqllite3.so -Wall
gcc main.c -I include  ./libsqllite3.so -o test.out -Wall -lpthread -ldl

