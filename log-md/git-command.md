# 配置

## git ssh配置
- pkg install git 
- ssh-keygen 
- 私钥id-rsa 公钥id-rsa.pub 
## 链接远程仓库
- git remote remove origin
- git remote add origin git@github.com:fengshenme/java.git

<!-- 克隆仓库 -->
- git clone git@github.com:fengshenme/java.git
- git clone git@gitcode.net:tan1015956962/java.git

<!-- add change -->
- git add .

<!-- 提交到本地仓库 -->
- git commit -m "提交信息"
<!-- 推送远程仓库 -->
- git push 

<!-- - git push --set-upstream origin master -->

添加第二个远程仓库
```
git remote set-url --add origin git@gitcode。net:tan1015956962/java.git
```
同时推送,推送命令:
```
git push -u origin master
```

test