**install oracle on centos 7**

*refer to https://docs.oracle.com/cd/E26370_01/doc.121/e26358/dbinstall.htm*

1. download oracle 12c standard edition
2. unzip oracle 12c package
3. install dependency package according to official documents  
4. yum -y install unixODBC
5. yum -y install unixODBC-devel
6. yum install -y xterm
7. add user and dir

>  groupadd oinstall
>
> groupadd dba
>
> useradd -g oinstall -G dba oracle
>
> passwd oracle
>
> mkdir -p /u01/app/oracle/product/12.1.0/db_1
>
> mkdir -p /u01/app/oraInventory
>
> chown -R oracle:oinstall /u01/app
>
> chmod -R 775 /u01/app

8. configure kernel parameter

>**vi /etc/sysctl.conf**
>
>fs.aio-max-nr = 1048576  
>
>fs.file-max = 6815744  
>
>kernel.shmall = 2097152  
>
>kernel.shmmax = 4294967295  
>
>kernel.shmmni = 4096  
>
>kernel.sem = 250 32000 100 128  
>
>net.ipv4.ip_local_port_range = 9000 65500  
>
>net.core.rmem_default = 262144  
>
>net.core.rmem_max = 4194304  
>
>net.core.wmem_default = 262144  
>
>net.core.wmem_max = 1048576
>
>**sysctl -p**
>
>**vi /etc/security/limits.conf**
>
>oracle              soft    nproc   2047  
>
>oracle              hard    nproc   16384  
>
>oracle              soft    nofile  1024  
>
>oracle              hard    nofile  65536 
>
>**vi /etc/pam.d/login**
>
>session    required     /lib/security/pam_limits.so  
>
>session    required     pam_limits.so  
>
>**vi /etc/profile**
>
>if [ $USER = "oracle" ]; then  
>
>​        if [ $SHELL = "/bin/ksh" ]; then  
>
>​              ulimit -p 16384  
>
>​              ulimit -n 65536  
>
>​        else  
>
>​              ulimit -u 16384 -n 65536  
>
>​        fi  
>
>fi
>
>**su - oracle**
>
>**vi .bash_profile**
>
>\# .bash_profile  
>
>\# Get the aliases and functions  
>
>if [ -f ~/.bashrc ]; then  
>
>​        . ~/.bashrc  
>
>fi  
>
>\# User specific environment and startup programs  
>
>\#PATH=$PATH:$HOME/.local/bin:$HOME/bin  
>
>\#export PATH  
>
>ORACLE_BASE=/u01/app/oracle  
>
>ORACLE_HOME=$ORACLE_BASE/product/12.1.0/db_1  
>
>ORACLE_SID=shenlan  
>
>PATH=$PATH:$HOME/bin:$ORACLE_HOME/bin  
>
>LD_LIBRARY_PATH=$ORACLE_HOME/lib:/usr/lib  
>
>export ORACLE_BASE ORACLE_HOME ORACLE_SID PATH LD_LIBRARY_PATH  
>
>**source .bash_profile**

9. install oracle 

> xhost +
>
> su - oracle
>
> export DISPLAY=:0
>
> cd database
>
> ./runInstaller

10. execute dbca to install database，if fail to run dbca in gui model. then do the silent install

> **dbca in gui:**
>
> export DISPLAY=:0.0
>
> xhost+
>
> su - oracle
>
> export DISPLAY=:0.0
>
> /u01/app/oracle/product/12.1.0/db_1/bin/dbca
>
> **dbca in silent:**
>
> su - oracle
>
> mkdir /home/oracle/etc
>
> cp  /home/oracle/database/response/* /home/oracle/etc
>
> su - root; chmod 755 /home/oracle/etc/*.rsp
>
> /u01/app/oracle/product/12.1.0/db_1/bin/netca -silent -responseFile /home/oracle/etc/netca.rsp
>
> lsnrctl start
>
> lsnrctl status
>
> lsnrctl reload
>
> vi /home/oracle/etc/dbca.rsp
>
> >  modify the dbca.rsp: 
> >
> > GDBNAME="qiaojian"
> >
> > SID="qiaojian"
> >
> > CHARACTERSET="AL32UTF8"
>
> /u01/app/oracle/product/12.1.0/db_1/bin/dbca -silent -responseFile /home/oracle/etc/dbca.rsp

**oracle sql command**

0. 设置显示列的格式

>set linesize 200;
>
>column fieldxx format a20;

1. 查询oracle中的用户信息

> select username, account_status from dba_users;

2. unlock某个用户，并设置口令

> alter user scott account unlock;
>
> alter user scott identified by xx;

3. 查看数据文件的结构信息

> desc dba_data_files;

4. 查询某个表空间所对应的数据文件信息

> select file_name,bytes,blocks,status from dba_data_files where table space_name = 'xx';

5. 查看数据文件的动态信息

> select file#,name, checkpoint_change# from v$datafile;

6. 查看控制文件信息

> select name from v$controlfile;

7. 查看重做日志文件组信息

> select group#,members, status from v$log;

8. 手工切换当前使用的日志文件

> alter system switch logfile;

9. 查看允许启动的DBWn进程的个数

> show parameter db_writer_processes;

10. 查看允许启动的ARCn进程的个数

> show parameter log_archive_max_processes;

11. 查看日志缓冲区的大小

> show parameter log_buffer;

12. 查看当前数据库实例的信息

> select instance_number,instance_name,host_name,status from v$instance;

13. sqlplus

> sqlplus [username/password@host]
>
> disconnect 
>
> connect as sysdba
>
> startup
>
> shutdown immediate;
>
> exit

14. 查看表空间的信息

> select tablespace_name,extent_management,allocation_type from dba_tablespaces;

15. 创建表空间

> create tablespace jiantmp01 datafile '/home/oracle/oracledbf/jiantmp01.dbf' size 10m autoextend on next 10m maxsize 100m extent management local uniform size 800k;

16. 修改表空间

> alter tablespace jiantmp01 add datafile '/home/oracle/oracledbf/jiantmp02.dbf' size 5m;
>
> alter database datafile '/home/oracle/oracledbf/jiantmp02.dbf' autoextend on maxsize 10m;

17. 删除表空间

> drop tablespace jiantmp01 including contents and datafiles;

18. 查看数据文件的路径

> select name from v$datafile;

19. 查看日志文件的路径

> select group#,member from v$logfile;

20. 查看控制文件的路径

>select name from v$controlfile;

21. 创建日志文件组（组编号最好连续）

>alter database add logfile group 4
>
>(
>
>'/home/oracle/oraclelog/redo01.log',
>
>'/home/oracle/oraclelog/redo02.log'
>
>)
>
>size 10m;

22. 创建日志文件（向日志文件组中添加日志成员）

>alter database add logfile member '/home/oracle/oraclelog/redo03.log' to group 4;

23. 重新定义日志文件组中的日志成员

>alter database rename file '/home/oracle/oraclelog/redo03.log' to '/home/oracle/oraclelog/redo03_new.log';

24. 删除日志文件

> alter database drop logfile member '/home/oracle/oraclelog/redo03_new.log';

25. 删除日志文件组

> alter database drop logfile group 4;

26. 手工切换日志文件

> alter system switch logfile;

27. 查看日志文件信息

> v$log： 包含控制文件中的日志信息
>
> v$logfile：包含日志文件组及其成员信息
>
> v$log_history：包含日志历史信息

28. 设置启动的归档进程的个数

> alter system set log_archive_max_processes = 10 scope = both;

29. 查看数据库的当前日志归档模式

> archive log list;

30. 设置数据库的当前日志归档模式为归档模式

> shutdown immediate;
>
> startup mount;
>
> alter database archivelog;
>
> alter database open;

31. 查看归档日志文件的保存位置

> show parameter db_recovery_file_dest;

32. 设置log_archive_dest_n参数为数据库设置1～10个归档日志文件的保存位置

> alter system set log_archive_dest_1='location=/home/oracle/oraclelog/myarchive01';

33. 设置归档日志名称格式

> alter system set log_archive_format='myarchive%S_%R.%T' scope=spfile;

34. 设置归档进程的跟踪级别（ 跟踪文件中记录有关日志归档的信息的级别）

> alter system set log_archive_trace=17;

35. 查看归档日志信息

>v$database: (select log_mode from v\$database;) 查询数据库是否处于归档模式
>
>v$archived_log: 包含控制文件中所有已经归档的日志信息
>
>v$archive_dest: 查看归档目标（归档文件的保存位置）的信息
>
>v$archive_processes: 包含已经启动的ARCn进程的状态信息
>
>v$backup_redolog: 包含所有已经备份的归档日志的信息
>
>v$log: 包含所有日志文件组信息

36. 查看系统的默认表空间

> select default_tablespace from user_users;

37. 查看表和表空间的对应关系

> select table_name,tablespace_name from user_tables;

38. 创建表时显示指定logging字句，此字句默认添加，作用是把对该表的操作都记录到重做日志文件中

> create table mybook (
>
> bookid number(10) not null primary key,
>
> bookname varchar2(40)
>
> ) tablespace jiantmp01
>
> logging;

39. sql 内连接，外连接，自连接
40. 事务隔离级别（幻象读，不可重复读，脏读），oracle默认（允许幻象读，不可重复读，不允许脏读）
41. Command: show parameter name;
42. Command: show parameter arch;
43. Command: tail -f /u01/app/oracle/diag/rdbms/qiaojian/qiaojian/trace/alert_qiaojian.log
44. Command: alter system set log_archive_dest_1='location=/u01/app/oracle/oradata/qiaojian';
45. Command: alter system switch logfile;
46. 可以通过dbca创建多个database，通过sid区分。修改oracle用户下的.bash_profile文件里的ORACLE_SID环境变量来切换instance每次连接到的database
47. SQL审计：

> 查看审计参数，根据不同的审计参数，将审计结果放在不同的地方（默认放在SYS.AUD$表中）
>
> show parameter audit_trail;
>
> 开始审计：
>
> audit  table by scott;
>
> 停止审计：
>
> noaudit table by scott;

48. SQL索引（index）、簇（cluster）、视图（view）、序列（sequence）、同义词（synonym）

> 索引类型：
>
> B树索引（默认）、位图索引（适用于在表中基数较小的列上创建）、反向键索引（适用于在表中严格排序的列上创建）、函数索引（适用于使用函数和表达式时的查询）
>
> 索引组织表、堆表（普通表）、临时表（当前事务或会话期间有效）、外部表（读取操作系统文件来创建表，是只读表）、分区表（将大表分区到不同的表空间，分为范围分区，散列分区，列表分区、组合分区）
>
> 簇（cluster，将有共享字段的多个表组成簇）和簇表（基于共享字段的表，创建时指定所使用的簇和簇字段[共享字段]）
>
> 视图：虚拟表
>
> 序列：虚拟表，自动产生一系列唯一数字值，用于其他表的自动编号字段
>
> 同义词：	 为表、视图、索引等创建别名

49. 对象：和java中的类对象一样，可以定义属性、方法，然后应用对象到表中
50. 大对象：LOB，用于存储大型数据的数据类型；细分为四种类型：CLOB（存储字符数据）、NCLOB（存储语言字符集多字节字符数据）、BLOB（存储二进制数据）、BFILE（存储文件指针，指向数据库外的文件）
51. SQL语句优化技巧：尽量明确清晰，不要模糊

>用具体的列名代替*
>
>用truncate代替delete来删除表中的所有行
>
>尽量及时的使用commit命令
>
>减少对表的查询次数
>
>用exists代替in
>
>用where代替having
>
>用<=代替<
>
>选择记录最少的表作为from字句中的最后一个表
>
>当where字句的条件不止一个时，应该将能过滤掉最大数量记录的条件放在末尾
>
>使用表别名
>
>> 索引的使用：
>>
>> 1. 对索引定期重构
>> 2. 创建索引的基本原则
>>
>> >2.1 经常以查询关键字为基础的表且表中的数据行均匀分布
>> >
>> >2.2 以查询关键字为基础的表中的数据行随机排序
>> >
>> >2.3 表中的列相对比较少
>> >
>> >2.4 表中的查询大多包含相对简单的where字句
>>
>> 3. 选择索引列的基本原则
>>
>> >3.1 经常在where字句中使用的列
>> >
>> >3.2 经常在表连接查询中用于表之间连接的列
>> >
>> >3.3 不宜将经常修改的列作为索引列
>> >
>> >3.4 不宜将经常在where字句中使用函数或操作符的列作为索引列
>> >
>> >3.5 对于取值较少的列，考虑建立位图索引，而不是B树索引
>>
>> 4. 避免对索引列使用函数或not关键字
>> 5. 避免对唯一索引列使用is (not) null判断
>> 6. 选择复合索引列，并将使用频率较高的列作为主列
>> 7. 监视索引是否被使用，并定期删除不使用的索引
>>
>> >监视索引：alter index xx monitoring usage;
>> >
>> >了解索引的使用状态：select table_name,index_name,monitoring from v$object_usage;

52. 数据库的备份和恢复

>备份
>
>>物理备份：对数据库文件（数据文件，控制文件，重做日志文件等）进行备份
>>
>>逻辑备份：Data Pump Export & Data Pump Import
>
>恢复
>
>>实例恢复：系统自动实现，恢复在内存缓冲区中因实例故障而未保存到数据文件中的数据
>>
>>介质恢复：存储介质故障时进行的恢复
>
>备份恢复管理
>
>>用户管理的手动备份恢复（操作系统命令+SQL/SQL*Plus命令）
>>
>>RMAN
>>
>>> 1. lsnrctl start
>>> 2. sqlplus / as sysdba
>>> 3. CREATE USER rman IDENTIFIED BY rman;
>>> 4. GRANT RECOVERY_CATALOG_OWNER TO rman;
>>> 5. rman target system/nocatalog

53. 闪回（flashback）: 实现数据的迅速恢复而不依赖于数据备份

>create table flash_table01( id number primary key, content varchar2(20) not null);
>
>insert into flash_table01 (id, content) values (1, 'first line data');
>
>insert into flash_table01 (id, content) values (2, 'second line data');
>
>insert into flash_table01 (id, content) values (3, 'third line data');
>
>select to_char(sysdate, 'yyyy-mm-dd hh24:mi:ss') from dual;
>
>select * from flash_table01;
>
>delete from flash_table01 where id=3;
>
>commit;
>
>select * from flash_table01;
>
>alter table flash_table01 enable row movement;
>
>flashback table flash_table01 to timestamp to_timestamp('2018-06-08 11:16:06', 'yyyy-mm-dd hh24:mi:ss');
>
>select * from flash_table01;

***

RMAN Component

> RMAN Executable: rman
>
> Target Database: 目标数据库
>
> RMAN Repository: RMAN资料档案库，存放RMAN使用到的管理信息和数据。RMAN资料档案库可以保存在目标数据库的控制文件中（默认，此时Oracle建议将控制文件配置为自动备份[RMAN> configure controlfile autobackup on;]），也可以保存在RMAN恢复目录中。
>
> RMAN Recover Catalog: RMAN恢复目录， 可选组件，它被存放在另外一个独立的Oracle数据库中。
>
> Media Management Subsystem: 介质管理子系统，RMAN利用此组件将目标数据库备份到其他存储设备中去
>
> Standy Database: 备用数据库，是对目标数据库的一个精确复制

RMAN Configure

>查看当前默认配置：show all;
>
>分配通道：
>
>>1. 手动分配：run { allocate channel ch1 device type disk; format=‘/xx’; backup xx;}
>>2. 自动分配：在run命令块外面执行backup，restore，delete；在run命令块内部执行backup等命令前未使用allocate channel手动分配通道
>
>通道参数配置
>
>>filesperset：限制多少个文件备份成一个备份集
>>
>>connect：设置连接到的数据库实例
>>
>>format：设置备份文件的存储格式以及备份文件的存储目录
>>
>>rate：设置通道的I/O速率
>>
>>maxsetsize：设置备份集的最大尺寸
>>
>>maxpiecesize：设置备份片的最大尺寸
>>
>>optimization：开启或关闭优化

在当前数据库创建恢复目录：

> \# sqlplus / as sysdba
>
> SQL> create tablespace rman_tbs datafile '/u01/app/oracle/oradata/qiaojian/rman_tbs.dbf' size 125m autoextend on next 50m maxsize 500m;
>
> SQL> create user rman identified by rman default tablespace rman_tbs temporay tablespace temp;
>
> SQL> grant connect, resource to rman;
>
> SQL> grant recovery_catalog_owner to rman;
>
> SQL> exit
>
> \# rman
>
> RMAN> connect catalog rman/rman
>
> RMAN> create catalog;

连接到当前目标数据库

> 1. 
>
> \# rman target / catalog rman/rman@qiaojian;
>
> RMAN> register database;
>
> 2. 
>
> \# rman target  sys/123456@qiaojian;
>
> RMAN> connect catalog rman/rman@qiaojian;
>
> RMAN> register database;
>
> RMAN> resync catalog;
>
> RMAN> list incarnation;
>
> RMAN> reset database;
>
> RMAN> resync catalog;

完全备份

> 1. 配置参数
>
> RMAN> configure retention policy to recovery  windows of 7 days;
>
> RMAN> configure default device type to disk;
>
> RMAN> configure controlfile autobackup on;
>
> RMAN> configure channel device type disk format '/u01/oracle/oradata/qiaojian/backup/%d_DB_%u_%s_%p';
>
> 2. 执行全备命令
>
> RMAN> run {
>
> allocate channel ch1 type disk format '/home/oracle/qiaojian/backup/db_t%t_s%s_p%p';
>
> backup full database tag full_db_backup plus archivelog;  
>
> release channel ch1;
>
> }

查看建立的备份集与备份片信息

> RMAN> list backup of database;

数据库归档模式恢复

>1. 确认数据库处于归档模式，启动RMAN连接到目标数据库，备份整个数据库
>
>   > \# rman target / nocatalog
>   >
>   > RMAN> configure channel device type disk format 
>   >
>   > RMAN> '/u01/oradata/qiaojian/backup/%d\_db\_%t\_%s\_%p';
>   >
>   > RMAN> backup database tag qiao_full_bak plus archivelog;
>
>2. 模拟故障，删除数据文件user01.dbf
>
>3. 运行以下命令恢复
>
>> \# rman target / nocatalog
>>
>> RMAN> startup mount;
>>
>> RMAN> restore database;



~~~
kill -9 ora_pmon_xxsid
rman target /
~~~

~~~
RMAN> run {
startup mount;
set until scn 1120000;
restore database;
recover database;
alter database open resetlogs;
}
~~~

~~~
1. RMAN> CONFIGURE CONTROLFILE AUTOBACKUP ON;
2. RMAN> backup database plus archivelog tag qiaojiantest;(记录dbid：2275815882从备份controlfile文件的output)
3. 删除数据库的datafile、controlfile、redologfile
4. kill -9 ora_pmon_test
5. rman target /
6. RMAN> startup nomount;
7. RMAN> set dbid 2275815882;
8. RMAN> restore controlfile from autobackup; （从output：AUTOBACKUP found: c-2275815882-20180607-00可知autobackup的controlfile是通过bdid来匹配的）
9. RMAN> startup mount;
10.RMAN> restore database;
11.SQL> alter database open resetlogs;
~~~

~~~
image copy 1:
# rman
RMAN> connect target /
RMAN> backup as copy database;
RMAN> list copy of database;
RMAN> backup as copy current controlfile;
RMAN> backup as copy archivelog all;

image copy 2:
RMAN> copy
2> datafile 1 to '/u01/oradata/test/backup/dbf_1.cpy',
3> datafile 2 to '/u01/oradata/test/backup/dbf_2.cpy',
4> datafile 3 to '/u01/oradata/test/backup/dbf_3.cpy',
5> datafile 4 to '/u01/oradata/test/backup/dbf_4.cpy',
6> current controlfile to '/u01/oradata/test/backup/cf_cpy';

image copy 3:
RMAN> copy level=0
2> datafile 1 to '/u01/oradata/test/backup/dbf_1.cpy',
3> datafile 2 to '/u01/oradata/test/backup/dbf_2.cpy',
4> datafile 3 to '/u01/oradata/test/backup/dbf_3.cpy',
5> datafile 4 to '/u01/oradata/test/backup/dbf_4.cpy';

incremental_update:
RMAN> run {
2> backup incremental level 1 for recover of copy with tag 'incr_update' database;
3> recover copy of database with tag 'incr_update';
4> }
~~~

































