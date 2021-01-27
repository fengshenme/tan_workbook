

# if [ -e *.out ] && [ -x *.out ]
# then
rm *.out
# fi

gcc server.c -o server.out -Wall -lpthread
gcc client.c -o client.out -Wall -lpthread
