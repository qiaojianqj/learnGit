**nfs**

centos7 nfs:

```
rpm -qa | grep nfs
```

设置nfs相关服务在操作系统启动时启动：

```
systemctl enable rpcbind
systemctl enable nfs-server
systemctl enable nfs-lock
systemctl enable nfs-idmap  
```

启动nfs服务：

```
systemctl start rpcbind
systemctl start nfs-server
systemctl start nfs-lock
systemctl start nfs-idmap
```

编辑 `/etc/exports` 添加：

```
/home/qiaojian 192.168.0.0/16(rw,sync,no_root_squash,no_subtree_check)
```

导出：

```
exportfs -a
```

客户端挂载：

```
mount -t nfs  192.168.99.138:/home/qiaojian ~/nfstest
```

