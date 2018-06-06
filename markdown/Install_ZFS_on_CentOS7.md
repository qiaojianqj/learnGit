**Install ZFS on CentOS7**

1. check CentOS7 version

> cat /etc/redhat-release

2. add the corresponding repository

> yum install http://download.zfsonlinux.org/epel/zfs-release.el7_5.noarch.rpm

3. modify the zfs.repo to disable the DKMS based ZFS repository and enable kABI based ZFS repository 

> vi /etc/yum.repos.d/zfs.repo
>
> modify 
>
> [zfs]
> name=ZFS on Linux for EL7 - dkms
> baseurl=http://download.zfsonlinux.org/epel/7.5/$basearch/
> *<u>enabled=1</u>*
> metadata_expire=7d
> gpgcheck=1
> gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-zfsonlinux
>
> [zfs-kmod]
> name=ZFS on Linux for EL7 - kmod
> baseurl=http://download.zfsonlinux.org/epel/7.5/kmod/$basearch/
> <u>enabled=0</u>
> metadata_expire=7d
> gpgcheck=1
> gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-zfsonlinux
>
> to
>
> [zfs]
> name=ZFS on Linux for EL7 - dkms
> baseurl=http://download.zfsonlinux.org/epel/7.5/$basearch/
> <u>enabled=0</u>
> metadata_expire=7d
> gpgcheck=1
> gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-zfsonlinux
>
> [zfs-kmod]
> name=ZFS on Linux for EL7 - kmod
> baseurl=http://download.zfsonlinux.org/epel/7.5/kmod/$basearch/
> <u>enabled=1</u>
> metadata_expire=7d
> gpgcheck=1
> gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-zfsonlinux

4. install ZFS

> yum install zfs

5. reboot

> reboot

6. load zfs module to kernel

> modprobe zfs

7. lsmod, you should see ZFS kernel module loaded

> lsmod | grep zfs

8. add 2 new disk (sdb, sdc)each of 10G, then check if add successfully

> lsblk

9. create ZFS pool using the 2 new disk

> zpool create zfstest /dev/sdb /dev/sdc

10. list all the available ZFS pool 

> zpool list

11. check the filesystem mount points, you can see the <u>zfstest</u> zpool mount on the /zfstest dir

> df -h

12. By default the ZFS pool is belong to root user and group, you can change it using chown command. Now you can create, remove,edit files under /zfstest



