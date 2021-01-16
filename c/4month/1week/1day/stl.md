一、string 容器
1、构造函数
string();                  //创建一个空的字符串 例如string str;
string(const char* s);       //使用字符串s初始化
string(const string& str);     //使用一个string对象初始化另外一个string对象。
string(int n,char c);          //使用n个字符c初始化。

2、赋值操作
string& operator=(const char*s); //char*类型字符串赋值给当前的字符串
string& operator=(const string& s); //把字符串s赋值给当前的字符串
string& operator=(char c);  //字符赋值给当前的字符串
string& assign(const char *s); //把字符串s赋给当前的字符串
string& assign(const char *s,int n); //把字符串s的前n个字符赋给当前的字符串。
string& assign(const string &s);  //把字符串赋给当前的字符串
string& assign(int n,char c);   //用n个字符c赋值给当前字符串。

3、字符串拼接
string& operator+=(const char*str);   //重载+=操作符
string& operator+=(const char c);     //重载+=操作符
string& operator+=(const string& str);//重载+=操作符
string& append(const char *s);        //把字符串s连接到当前字符串结尾
string& append(const char *s，int n); //把字符串s前n个字符连接到当前字符串结尾
string& append(const string &s);      //同operator+=(const string& str);
string& append(const string &s,int pos,int n);   //字符串s中从pos开始的n个字符连接到字符串结尾

4、查找和替换
int find(const string &str,int pos = 0) const;//查找str第一次出现位置，从pos开始查找
int find(const char *s,int pos = 0) const;//查找s第一次出现位置，从pos开始查找
int find(const char *s,int pos,int n) const;//从pos位置查找s的前n个字符第一次位置
int find(const char c,int pos = 0) const;//查找字符c第一次出现位置
int rfind(const string&str,int pos = npos) const;//查找str最后一次位置，从pos开始查找
int rfind(const char *s,int pos = npos) const;//查看s最后一次出现位置，从pos开始查找。
int rfind(const char *s,int pos,int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c,int pos = 0) const;//查找字符c最后一次出现位置
string& replace(int pos,int n,const string& str);//替换从pos开始n个字符为字符串str
string& replace(int pos,int n,const char *s);//替换从pos开始的n个字符为字符串s

5、字符串比较。
int compare(const string& s) const;  //与字符串s比较
int compare(const char *s) const;    //与字符串s比较




6、字符存取
char& operator[](int n);  //通过[]方式取字符
char& at(int n);          //通过at方法获取字符

7、插入和删除
string& insert(int pos,const char *s);     //插入字符串
string& insert(int pos,const string& str); //插入字符串
string& insert(int pos,int n,char c);  //在指定位置插入n个字符c
string& erase(int pos,int n = npos); //删除从pos开始的n个字符

8、string子串。
string substr(int pos = 0,int n = npos) const; //返回由pos开始的n个字符组成的字符串。


二、vector容器。
1、构造函数
vector<T> v;        //采用模板实现类实现，默认构造函数。
vector(v.begin(),v.end()); //将v[begin(),end()]区间中的元素拷贝给本身。
vector(n,elem);            //构造函数将n个elem拷贝给本身。
vector(const vector &vec); //拷贝构造函数

2、赋值操作
vector& operator=(const vector &vec); //重载等号操作符
assign(beg,end); //将(beg,end)区间中的数据拷贝赋值给本身。
assign(n,elem);  //将n个elem拷贝赋值给本身。

3、容量和大小。
empty();             //判断容器是否为空
capacity();          //容器的容量
size();              //返回容器中元素的个数
resize(int num);     //重新指定容器的长度为num，若容器变长，则以默认值填充新位置，如果容器变短，则末尾超出容器的长度的元素被删除。
resize(int num,elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置，如果容器变短，则末尾超出容器的长度的元素被删除。

4、插入和删除。
push_back(ele);                           //尾插插入元素
pop_back();                               //删除最后一个元素
insert(const_iterator pos,ele);           //迭代器指向位置pos插入元素ele。
insert(const_iterator pos,int count,ele); //迭代器指向位置pos插入count个元素ele
erase(const_iterator pos);                //删除迭代器指向的元素
erase(const_iterator start,const_iterator end); //删除迭代器从start到end之间的元素
clear();                                  //删除容器中所有的元素

5、数据存取
at(int idx);    //返回索引idx所指的数据
operator[];     //返回索引idx所指的数据
front();        //返回容器中第一个数据元素
back();         //返回容器中最后一个数据元素

6、互换容器
swap(vec); //将vec与本身的元素互换。

7、预留空间。
reserve(int len); //容器预留len个元素长度，预留位置不初始化，元素不可访问。

三、deque容器(双向队列)
1、构造函数。
deque<T> deqT;    //默认构造形式
deque(beg,end);   //构造函数将[beg,end)区间中的元素拷贝给本身。
deque(n,elem);    //构造函数将n个elem拷贝给本身。
deque(const deque &deq);  //拷贝构造函数

2、赋值操作
deque& operator=(const deque &deq); //重载等号操作符
assign(beg,end); //将[beg,end)区间中的数据拷贝赋值给本身
assign(n,elem);  //将n个elem拷贝赋值给本身

3、大小操作。
deque.empty();   //判断容器是否为空
deque.size();    //返回容器中元素的个数
deque.resize(num);  //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
		    //如果容器变短，则末尾超过容器长度的元素被删除。
deque.resize(num,elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
		    //如果容器变短，则末尾超过容器长度的元素被删除。

4、插入与删除
两端插入操作：
push_back(elem);  //在容器尾部添加一个数据。
push_front(elem); //在容器头部插入一个数据。
pop_back();       //删除容器最后一个数据。
pop_front();      //删除容器第一个数据。

指定位置操作：
insert(pos,elem); //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem); //在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end); //在pos位置插入[beg,end)区间的数据，无返回值。
clear();   //清空容器的所有数据
erase(beg,end); //删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos); //删除pos位置的数据，返回下一个数据的位置。

5、数据存取。
at(int dex);  //返回索引idx所指的数据
operator[];   //返回索引idx所指的数据
front();      //返回容器中第一个数据元素
back();       //返回容器中最后一个数据元素

6、排序。
sort(iterator beg,iterator end)  //对beg和end区间内元素进行排序

四、stack容器(栈)
1、构造函数：
stack<T> stk;  //stack采用模板类实现，stack对象的默认构造形式
stack(const stack &stk);  //拷贝构造函数

2、赋值操作：
stack& operator=(const stack &stk);  //重载等号操作符

3、数据存取：
push(elem); //向栈顶添加元素
pop();      //从栈顶移除第一个元素
top();      //返回栈顶元素

4、大小操作：
empty();    //判断堆栈是否为空
size();     //返回栈的大小

五、queue容器。(队列)
1、构造函数：
queue<T> que;   //queue采用模板类实现，queue对象的默认构造形式
queue(const queue &que); //拷贝构造函数

2、赋值操作：
queue& operator=(const queue &que); //重载等号操作符

3、数据存取：
push(elem);   //往队尾添加元素
pop();        //从队头移除第一个元素
back();       //返回最后一个元素
front();      //返回第一个元素

4、大小操作：
empty();   //判断堆栈是否为空
size();    //返回栈的大小

六、list容器。(链表)
1、构造函数
list<T> lst;   //list采用模板类实现对象的默认构造形式。
list(beg,end); //构造函数将{beg,end)区间中的元素拷贝给本身。
list(n,elem);  //构造函数将n个elem拷贝给本身。
list(const list &list);  //拷贝构造函数。

2、赋值与交换。
assign(beg,end);   //将[beg,end)区间中的数据拷贝赋值给本身。
assign(n,elem);    //将n个elem拷贝赋值给本身
list& operator=(const list &lst); //重载等号操作符
swap(lst);  //将lst与本身的元素互换。

3、大小操作。
size();   //返回容器中元素的个数
empty();  //判断容器是否为空
resize(num); //重新指定容器的长度为num,若容器变长，则以默认值填充新位置，如果容器变短，则末尾超出的容器长度的元素被删除。
resize(num,elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置，如果容器变短，则末尾超出的容器长度的元素被删除。

4、插入和删除。
push_back(elem);  //在容器尾部加入一个元素
pop_back();       //删除容器中最后一个元素
push_front(elem); //在容器开头插入一个元素
pop_front();      //从容器开头移除第一个元素
insert(pos,elem); //在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);/在pos位置插入[beg,end)区间的数据，无返回值
clear(); //移除容器的所有数据
erase(pos); //删除pos位置的数据，返回下一个数据的位置
remove(elem); /删除容器中所有与elem匹配的元素。

5、数据存取。
front();   //返回第一个元素
back();    //返回最后一个元素

6、反转与排序。
reverse();  //反转链表
sort();     //链表排序

七、set/multiset容器。(红黑树)
1、set构造和赋值。
构造：
set<T> st;  //默认构造函数
set(const set &set);  //拷贝构造函数

赋值：
set& operator=(const set &set);  //重载等号操作符

2、大小与交换。
size();   //返回容器中元素的数目。
empty();  //判断容器是否为空。
swap();   //交换两个集合容器。

3、插入与删除。
insert(elem);  //在容器中插入元素
clear();       //清楚所有元素
erase(pos);    //删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg,end);//删除区间[beg,end)的所有元素，返回下一个元素的迭代器。
erase(elem);   //删除容器中值为elem的元素。

4、查找与统计。
find(key);  
//查找key是否存在，若存在，返回该键的元素的迭代器，若果不存在，返回set.end();
count(key);  //统计key元素的个数。

5、pair对组创建
pair<type,type> p(value1,value2);
pair<type,type> p = make_pair(value1,value2);

八、map/multimap容器。
1、构造：
map<T1,T2> mp;      //map默认构造函数
map(const map &mp); //拷贝构造函数

赋值：
map& operator=(const map&mp);  //重载等号操作符

2、大小和交换
size();   //返回容器中元素的数目
empty();  //判断容器是否为空
swap();   //交换两个集合容器

3、插入与删除
insert(elem);  //在容器中插入元素
clear();       //清除所有元素
erase(pos);    //删除pos迭代器所指的元素，返回下一个元素的迭代器
erase(beg,end);//删除区间[beg,end)的所有元素，返回下一个元素的迭代器
erase(key);    //删除容器中值为key的元素。

4、查找与统计。
find(key);   //查找key是否存在，若存在，返回该键的元素的迭代器，如不存在，返回set.end();
count(key);  //统计key的元素个数

九、函数对象。
1、算术仿函数。
template<class T> T plus<T>       //加法仿函数
template<class T> T minus<T>      //减法仿函数
template<class T> T multiplies<T> //乘法仿函数
template<class T> T divides<T>    //除法仿函数
template<class T> T modulus<T>    //取模仿函数
template<class T> T negate<T>     //取反仿函数

2、关系仿函数。
template<class T> bool equal_to<T>       //等于
template<class T> bool not_equal_to<T>   //不等于
template<class T> bool greater<T>        //大于
template<class T> bool greater_equal<T>  //大于等于
template<class T> bool less<T>           //小于
template<class T> bool less_equal<T>     //小于等于

3、逻辑仿函数。
template<class T> bool logical_and<T>    //逻辑与
template<class T> bool logical_or<T>     //逻辑或
template<class T> bool logical_not<T>    //逻辑非

十、常见遍历算法。
算法简介：
for_each   //遍历容器
transform  //搬运容器到另一个容器中

1、
for_each(iterator beg,iterator end,_func);
//遍历算法 遍历容器元素
//beg  开始迭代器
//end  结束迭代器
//_func 函数或者函数对象

2、
transform(iterator beg1,iterator end1,iterator beg2,_func);
//beg1 源容器开始迭代器
//end1 源容器结束迭代器
//beg2 目标容器开始迭代器
//_func 函数或者函数对象

十一、常见查找算法。
算法简介：
find             //查找元素
find_if          //按条件查找元素
adjacent_find    //查找相邻重复元素
binary_search    //二分查找法
count            //统计元素个数
count_if         //按条件统计元素个数

1、
find(iterator beg,iterator end,value);
//按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//beg  开始迭代器
//end  结束迭代器
//value 查找的元素

2、
find_if(iterator beg,iterator end,_Pred);
//按条件查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//beg  开始迭代器
//end  结束迭代器
//_Pred 函数或者谓词(返回bool类型的仿函数)

3、
adjacent_find(iterator beg,iterator end);
//查找相邻重复元素,返回相邻元素的第一个位置的迭代器
//beg  开始迭代器
//end  结束迭代器

4、
bool binary_search(iterator beg,iterator end,value);

//查找指定的元素，查到返回true 否则false
//注意：在无序序列中不可用
//beg  开始迭代器
//end  结束迭代器
//value 查找的元素

5、
count(iterator beg,iterator end,value);
//统计元素出现次数

//beg 开始迭代器
//end 结束迭代器
//value 统计的元素

6、
count_if(iterator beg,iterator end,_Pred);
//按条件统计元素出现次数
//beg  开始迭代器
//end  结束迭代器
//_Pred 函数或者谓词(返回bool类型的仿函数)

十二、常见排序算法。
算法简介：
sort            //对容器内元素进行排序
random_shuffle  //洗牌 指定范围内的元素随机调整次序
merge           //容量元素合并，并存储到另一个容器中
reverse         //反转指定范围的元素

1、
sort(iterator beg,iterator end,_Pred)
//按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//beg 开始迭代器
//end 结束迭代器
//_Pred 谓词

2、
random_shuffle(iterator beg,iterator end);
//指定范围内的元素随机调整次序
//beg 开始迭代器
//end 结束迭代器

3、
merge(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
//容器元素合并，并存储到另一个容器中
//注意： 两个容器必须是有序的
//beg1 容器1开始迭代器
//beg1 容器1结束迭代器
//beg2 容器2开始迭代器
//beg2 容器2结束迭代器
//dest 目标容器开始迭代器

4、
reverse(iterator beg,iterator end)
//反转指定范围的元素
//beg 开始迭代器
//end 结束迭代器

十三、常见拷贝和替换算法。
算法简介:
copy        //容器内指定范围的元素拷贝到另一容器中
replace     //将容器内指定范围的旧元素修改为新元素
replace_if  //容器内指定范围满足条件的元素替换为新元素
swap        //互换两个容器的元素

1、
copy(iterator beg,iterator end,iterator dest)
//beg 开始迭代器
//end 结束迭代器
//dest 目标起始迭代器

2、
replace(iterator beg,iterator end,oldvalue,newvalue)
//将区间内旧元素替换成新元素
//beg 开始迭代器
//end 结束迭代器
//oldvalue 旧元素
//newvalue 新元素

3、
replace_if(iterator beg,iterator end,_Pred,newvalue)
//按条件替换元素，满足条件的替换成指定的元素
//beg 开始迭代器
//end 结束迭代器
//_Pred 谓词
//newvalue 替换的新元素

4、
swap(container c1,container c2)
//互换两个容器的元素
//c1容器1
//c2容器2

十四、常见算术生成算法。
accumulate  //计算容器元素累计总和。
fill         //向容器中添加元素

1、
accumulate(iterator beg,iterator end,value);
//计算容器元素累计总和
//beg 开始迭代器
//end 结束迭代器
//value 起始值

2、
fill(iterator beg,iterator end,value)
//向容器中填充元素
//beg 开始迭代器
//end 结束迭代器
//value 填充的值

十五、常见集合算法。
set_intersection   //求两个容器的交集。
set_union          //求两个容器的并集。
set_difference     //求两个容器的差集。

1、
set_intersection(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
//求两个集合的交集
//注意：两个集合必须是有序序列
//beg1 容器1开始迭代器
//end1 容器1结束迭代器
//beg2 容器2开始迭代器
//end2 容器2结束迭代器
//dest 目标容器开始迭代器

2、
set_union(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
//求两个集合的并集
//注意：两个集合必须是有序序列
//beg1 容器1开始迭代器
//end1 容器1结束迭代器
//beg2 容器2开始迭代器
//beg2 容器2结束迭代器
//dest 目标容器开始迭代器

3、
set_difference(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
//求两个集合的差集
//注意：两个集合必须是有序序列
//beg1 容器1开始迭代器
//end1 容器1结束迭代器
//beg2 容器2开始迭代器
//beg2 容器2结束迭代器
//dest 目标容器开始迭代器






