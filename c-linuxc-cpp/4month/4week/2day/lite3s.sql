
-- 创建表
create table if not exists studentable(name text, age int, score float);
create table if not exists tb_student(id  int primary key not null,name text not null, age int, score float);
create table if not exists tb_book(id  int primary key not null,title text not null, author text, price float);
create table if not exists studentable(name text, age int, score float);

-- 增加数据
insert into studentable values("张三", 18, 30);

-- 修改数据
update tb_student set age=50 where id=12;
update tb_book set price=69.0 where id=1;

-- 删除数据
delete from tb_book where id=1;

-- 查询所有数据
select * from studentable;
select * from tb_student;

-- 删除表
drop table tb_student;


insert into tb_student values(12, "张三", 18, 30);insert into tb_student values(12, "张三", 18, 30);
insert into tb_student values(null, "李四", 19, 20);
insert into tb_book values(1, "三国演义", "罗贯中", 99.9); insert into tb_book values(1, "红楼梦", "曹雪芹", 88.8);


insert into studentable values("李四", 30, 16.6);insert into studentable values("王五", 25, 25.6);


create table if not exists commodity(name text, price float, number int);
insert into commodity values("水", 18, 3);

select * from commodity;

insert into commodity values("a", 18, 9);insert into commodity values("c", 17, 8);

insert into commodity values("d", 14, 7);insert into commodity values("e", 12, 6);
insert into commodity values("f", 10, 5);

select name from commodity;
select price from commodity;
select * from commodity where price>10 and number<8;

/** order by - 顺序  按照price排序 ,降序显示 */
select * from commodity order by price desc;
-- 升序
select * from commodity order by price asc; 


