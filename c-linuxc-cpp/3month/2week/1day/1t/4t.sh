#!/bin/bash

if  [ $# -ne 1 ]; then
    echo "param error : a param "
    exit 1
elif [ -e $1 ]; then
    if [ -r $1 ]; then
        cat $1
    else
        chmod 755 $1
        cat $1
    fi
else 
    echo "file not exists"
    exit 1
fi
