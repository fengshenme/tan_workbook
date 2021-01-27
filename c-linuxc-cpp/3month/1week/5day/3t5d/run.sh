#!/bin/bash

if [ -e server.out ]
then
rm *.out
fi

gcc server.c -o server.out -Wall
gcc client.c -o client.out -Wall
