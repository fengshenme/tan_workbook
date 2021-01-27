if [ -e server.out ]; then
    echo fajkdsl
fi


arr=(server_udp client_udp)

for var in ${arr[*]}; do
    if [ -e $var.c ] && [ -e $var.out ]; then
        #获取文件做后修改时间戳
        echo $var
        l_c=$(stat -c %Y $var.c)
        l_out=$(stat -c %Y $var.out)
        if [ $l_c -gt $l_out ]; then
            gcc $var.c -o $var.out -Wall
        else
            echo $var.out is last \; No need to compile 
        fi
    elif [ -e $var.c ]; then
        gcc $var.c -o $var.out -Wall
    fi

done

#文件名
FILE_NAME='server_udp.c'
#获取文件做后修改时间戳
LAST_MODIFY_TIMESTAMP=$(stat -c %Y $FILE_NAME)
#格式化时间戳
formart_date=$(date '+%Y-%m-%d %H:%M:%S' -d @$LAST_MODIFY_TIMESTAMP)
echo $formart_date
echo $LAST_MODIFY_TIMESTAMP
