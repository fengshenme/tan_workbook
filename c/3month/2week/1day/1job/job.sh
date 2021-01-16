#!/bin/bash

# D D C E 对

declare -i num
while true; do
    echo "========================="
    echo "          1.one          "
    echo "          2.two          "
    echo "          3.three         "
    echo "          4.four         "
    echo "========================="
    echo "please input a num:"

    read num

    case $num in
    1) echo "one!" ;;
    2) echo -ne "two!\n" ;;
    3) echo "three" ;;
    4) echo "four" ;;
    *) echo "unknown!" ;;
    esac

done
