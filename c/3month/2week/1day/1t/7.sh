#!/bin/bash

info=`ls -alh test.txt`

for var in $info 
do
    echo -ne "$var "
done
echo 