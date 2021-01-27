#!/bin/bash

if [ $# -ne 1 ]; then
    echo "param error : a param "
    exit 1
elif [ -r $1 ]; then
    cat $1

elif [ -e $1 ]; then
    chmod 755 $1
    cat $1
else
    echo "file not exists"
    exit 1
fi
