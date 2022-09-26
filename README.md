## Kernel module

简单的用一下内核模块，按照如下步骤使用：

### 编译

```
make
```

### 加入新模块

- 创建一个新的模块文件夹；

- 将 makefile 的 `obj-m += hello-1.o` 改成 `obj-m += module-name.o`；

- 重新编译

  ```
  make -C /lib/modules/5.15.0-46-generic/build M=/home/guanshun/gitlab/kernel-mod modules                 
  make[1]: Entering directory '/usr/src/linux-headers-5.15.0-46-generic'                                  
    CC [M]  /home/guanshun/gitlab/kernel-mod/hello-1.o                                                    
    MODPOST /home/guanshun/gitlab/kernel-mod/Module.symvers                                               
    LD [M]  /home/guanshun/gitlab/kernel-mod/hello-1.ko                                                   
    BTF [M] /home/guanshun/gitlab/kernel-mod/hello-1.ko                                                   
  Skipping BTF generation for /home/guanshun/gitlab/kernel-mod/hello-1.ko due to unavailability of vmlinux
  make[1]: Leaving directory '/usr/src/linux-headers-5.15.0-46-generic'                                   
  ```

  hello-1.ko 就是 kernel module。

### 加载内核模块
```
sudo insmod module-name.ko
```

可以用 `dmesg` 查看是否有 `hello world` 的 log。

### 移除内核模块
```
sudo rmmod kernel-name.ko"
```

### 查看所有的内核模块
```
lsmod
```

