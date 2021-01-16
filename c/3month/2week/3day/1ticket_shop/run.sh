

gcc src/main.c -o bin/ticket_shop.out -Wall
gcc src/server.c src/load_data.c -o bin/server.out -Wall -lpthread

# ./bin/ticket_shop.out