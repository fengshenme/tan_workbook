#!/bin/bash

file="server.out"


if [ -e *.out ]; then
    rm *.out
fi

gcc server.c -o server.out -Wall
gcc client.c -o client.out -Wall

