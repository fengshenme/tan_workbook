# rm acd -r

# mkdir acd

HEAD_PATH="-I include"

# 制作静态库

rm lib/*.so bin/*.out

gcc -fPIC -shared src/*.c -o lib/libcopy.so $HEAD_PATH -lpthread

# 制作动态库
gcc main/*.c -o bin/2t1d.out lib/libcopy.so $HEAD_PATH -lpthread

./bin/2t1d.out $1 $2
