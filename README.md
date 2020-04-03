# 笔记
----
文件服务器,图片显示,视频播放,
ssm框架,代码经过p3c检测无报告,sonarLint的报告看心情在优化

增加cnn,文本模型训练

打包
```
mvn install
```
Spring boot 启动运行命令
第一种：
```
java -jar xxxx.jar > error.log 2>&1 &
```
第二种：
```
nohup java -jar xxxx.jar > error.log 2>&1 &
```
第三种：
```
java -jar xxxx.jar &
```
第四种
```
setsid java -jar xxxx.jar
```
第五种：
1、首先先用vim创建文件start.sh
vim start.sh
3、在文件中写入java -jar xxxx.jar
4、在保存一下：wq！
5、先给文件 chmod 777 start.sh 权限
6、其次：nohup  ./start.sh &
