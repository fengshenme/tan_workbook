#!/bin/bash


gcc main.c -I include  ./libsqllite3.so -o test.out -Wall -lpthread -ldl

