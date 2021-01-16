#!/bin/bash

var=`cat test.txt`

echo $var
case $var in
10) echo large ;;
5) echo middle ;;
1) echo small ;;
*) echo error ;;
esac
