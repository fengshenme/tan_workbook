mvn install -f pom.xml
java -jar target/demo-0.0.1.jar
# 数据库密码 123456tx

# mysql> create database db_example; -- Creates the new database
# mysql> create user 'springuser'@'%' identified by 'ascd123456tx,'; -- Creates the user
# mysql> grant all on db_example.* to 'springuser'@'%'; -- Gives all privileges to the new user on the newly created database

# GRANT ALL PRIVILEGES ON *.* TO 'springuser'@'%'IDENTIFIED BY 'ascd123456tx,' WITH GRANT OPTION;flush privileges;
# 