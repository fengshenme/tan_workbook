
if [ sftputty.sh -nt in.txt ]; then
        echo "get 7t.out" > in.txt
        echo "exit" >> in.txt
        echo "sftputty update in.txt"
fi
../putty/psftp  gec@192.168.19.82 -pw 123456 -b "in.txt"

