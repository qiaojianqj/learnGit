# linux命令行编辑快捷键

其他：

ctrl + ? 撤消前一次输入

ctrl + c 另起一行

ctrl + r 输入单词搜索历史命令

删除：

ctrl + u 删除光标前面所有字符

ctrl + y 恢复ctrl+u上次执行时删除的字符

ctrl + k 删除光标后面所有字符

ctrl + d 删除光标所在位置上的字符

ctrl + w 删除光标前一个单词

移动：

ctrl + a 将光标移动到命令行开头处

ctrl + e 将光标移动到命令行结尾处

ctrl + f 光标向后移动一个字符

ctrl + b 光标向前移动一个字符

ctrl + 方向键左键 光标移动到前一个单词开头

ctrl + 方向键右键 光标移动到后一个单词结尾

### 硬件信息

------

生产厂商：dmidecode -t 1 | grep Manufacturer | cut -f2 -d:

产品系列:  dmidecode -t 1 | grep 'Product Name' | cut -f2 -d:

BIOS版本:  dmidecode -t 0 | grep Version | cut -f2 -d:

序列号: dmidecode -t 1 | grep 'Serial Number' | cut -f2 -d:

UUID: dmidecode -t 1 | grep UUID | cut -f2 -d:

CPU型号：cat /proc/cpuinfo | grep name | cut -f2 -d: | uniq

CPU类型：cat /proc/cpuinfo | grep vendor_id | cut -f2 -d: | uniq

物理CPU个数：cat /proc/cpuinfo| grep 'physical id'| uniq| wc -l

逻辑CPU个数(线程数)： cat /proc/cpuinfo| grep "processor"| wc -l

每个物理CPU的核数：cat /proc/cpuinfo| grep "cpu cores" | uniq | cut -f2 -d:

物理内存：总数，已使用，空闲: free -m

总数： cat /proc/meminfo  | grep MemTotal | cut -f2 -d:

空闲：cat /proc/meminfo  | grep MemFree | cut -f2 -d:

已使用： 总数 - 空闲

引导时间: date -d ''\`cut -f1 -d. /proc/uptime\` seconds ago"      who -b

bootTime=\`cut -f1 -d. /proc/uptime\`; data -d "${bootTime} seconds ago"

逻辑CPU内核

CPU插槽

每个内核的CPU线程数： 

**软件信息：**

操作系统：Linux

操作系统版本：lsb_release -a | grep 'Distributor ID' | cut -f2 -d:

操作系统描述：lsb_release -a | grep Description |  cut -f2 -d:

内核版本：uname -a | cut -f3 -d' '

IP地址：ip addr | grep 'inet ' | grep -v 127.0 | sed 's/^.\*inet//g' | sed 's#/.*$##g'

ssh端口：netstat -anltp | grep ssh | awk '{print \$4}' | awk -F: '{print \$2}' | grep -v '^$' | uniq

Tookit路径：

时区：date +"%Z %z"

操作系统用户：cat /etc/passwd | grep -v '/sbin'| cut -f1 -d:

**socket连接诊断**

netstat

ss