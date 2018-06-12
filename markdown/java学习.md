# java学习#

###数据类型###

> byte(1字节), short(2字节), int(4字节), long(8字节), float(4字节), double(8字节), char(2字节), boolean(true, false)
>
> Java 没有任何无符号(unsigned) 形式的 int、long、short 或 byte 类型。 
>
> char 类型描述了 UTF-16 编码中的一个代码单元，占2字节，（有的字符编码占用两个代码单元）建议不要在程序中使用 char 类型。 
>
> 整数被 0 除将会产生一个异常， 而浮点数被 0 除将会得到无穷大或 NaN 结果。 
>
> &&和||运算符是按照“ 短路”方式来求值的: 如果第一个操作数已经能够确定表达式的值，第二个操作数就不必计算了。 
>
> \>>运算符会用符号位填充高位，\>>>运算符会用 0 填充高位。
>
> 移位运算符的右操作数要完成模32的运算(除非左操作数是long类型，在这种情况下需要对右操作数模 64 )。 例如，1<<35 的值等同于 1<<3 。
>
> 字符串“xxoo”是unicode字符x、x、o、o组成的序列。字符串、String类对象是不可变对象。
>
> 判断字符串内容相等用equals，==运算符是判断字符串的地址是否相等。
>
> String取length是取的字符串的代码单元的个数。
>
> Console类用于输入密码，为了安全起见，返回的密码存放在一维字符数组中， 而不是字符串中。
>
> 在 C++ 中， 可以在嵌套的块中重定义一个变量。 在内层定义的变量会覆盖在外层定义的变量。 但是，在java中不允许嵌套块中重定义外层的变量。
>
> 在 Java 中， 允许数组长度为 0。 在 Java 中， 允许将一个数组变量拷贝给 另一个数组变量。这时， 两个变量将引用同 一个数组。如果希望将 一个数组的所有值拷贝到一个新的数组中去， 就要使用 Arrays 类的 copyOf 方法。可以通过二维数组创建不规则数组（先创建行，再单独创建每行的数组）

~~~
System.out.println ( 1.0 / 0 );
//output Infinity

int valInt = 1<<35;
System.out.println ( valInt);
//output 8

long valLong = (long)1<<35;
System.out.println ( valLong );
//output 34359738368
~~~

### 类与对象###

> 识别类的简单规则是在分析问题的过程中寻找名词， 而方法对应着动词。 
>
> | 关系        | 含义                                      |
> | ----------- | ----------------------------------------- |
> | 继承(is a)  | is a，类A扩展自类B                        |
> | 接口实现    | 类实现接口中的方法                        |
> | 依赖(use a) | use a，一个类的方法操纵另一个类的对象     |
> | 聚合(has a) | has a，类A的对象包含类B的对象（属性关联） |
> | 关联        | 通过属性、方法关联                        |
>
> centos 安装mysql 修改root密码：
>
> > 1. vi /etc/my.cnf  添加skip-grant-tables、skip-networking
> > 2. systemctl restart mariadb
> > 3. mysql_secure_installation
> > 4. vi /etc/my.cnf 注释skip-grant-tables、skip-networking
> > 5. systemctl restart mariadb
> > 6. mysql -uroot -p123456
> > 7. GRANT ALL ON *.* TO root@'%' IDENTIFIED BY '123456' WITH GRANT OPTION; （允许远程主机连接）



