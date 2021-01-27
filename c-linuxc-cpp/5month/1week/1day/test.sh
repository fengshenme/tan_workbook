#!/bin/bash

# arm-linux-gnueabi-gcc 1d.c -I include lib/libjpeg.so.9.4.0 -o 1d.out -Wall
arm-linux-gnueabi-gcc 2d.c -I include -L lib -ljpeg -o 1d.out -Wall

# arecord -d5  -c1 -r16000 -twav -fS16_LE example.wav
# arecord -D hw:0,0 -c2 -r16000 -fS16_LE test.wav