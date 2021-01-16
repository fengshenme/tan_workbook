#include <stdio.h>

#include "sqlite3.h"


int main(int argc, char const *argv[])
{
    
    return 0;
}


void InitDataBase()
{

	sqlite3 *pdb; //数据库句柄

	int ret = sqlite3_open("ticketing.db", &pdb);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_open:%s\n", sqlite3_errmsg(pdb));
		exit(1);
	}

	char sql[128] = {0};
    char sss[] = "CREATE TABLE `user` ( `id` INT NOT NULL,`name` CHAR(50) NOT NULL DEFAULT '' COMMENT '用户名',\
	`password` CHAR(50) NOT NULL DEFAULT '' COMMENT '密码',`phone` CHAR(50) NOT NULL DEFAULT '' COMMENT '手机号',\
	`status` INT NOT NULL DEFAULT 0 COMMENT '0是未登录下线状态, 1是登录状态',\
	`account` INT NOT NULL DEFAULT 0 COMMENT '账户余额',\
	`vipclass` INT NOT NULL DEFAULT 0 COMMENT 'vip等级')\
     COLLATE='utf8mb4_0900_ai_ci';";

	sprintf(sql, "create table if not exists user (id int not null name text, tel text);");
	ret = sqlite3_exec(pdb, sql, NULL, NULL, NULL);
	if (ret != SQLITE_OK)
	{
		printf("sqlite3_exec1:%s\n", sqlite3_errmsg(pdb));
		exit(1);
	}
	sqlite3_close(pdb);
}
