#!/bin/bash

a=1

while(($a<=100))
do
    echo $a
    let "a++"
done