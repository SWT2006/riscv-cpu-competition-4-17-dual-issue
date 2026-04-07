# 4.如何使用

本项目可以运行在Windows和Linux平台(macOS平台理论上也是可以的)，编译仿真工具使用的是iverilog和vpp，波形查看工具使用的是gtkwave。

## 4.1Windows平台环境搭建

在使用之前需要安装以下工具：

1. 安装iverilog工具

可以在这里[http://bleyer.org/icarus/](http://bleyer.org/icarus/)下载，安装过程中记得同意把iverilog添加到环境变量中，当然也可以在安装完成后手动进行添加。安装完成后iverilog、vvp和gtkwave等工具也就安装好了。

2. 安装GNU工具链

可以通过百度网盘下载(链接: https://pan.baidu.com/s/1bYgslKxHMjtiZtIPsB2caQ 提取码: 9n3c)，或者通过微云下载[https://share.weiyun.com/5bMOsu9](https://share.weiyun.com/5bMOsu9)，下载完成后将压缩包解压到本项目的tools目录下。注意目录的层次结构，解压后的工具路径应该如下所示：

`tinyriscv\tools\gnu-mcu-eclipse-riscv-none-gcc-8.2.0-2.2-20190521-0004-win64\bin\riscv-none-embed-gcc`

3. 安装make工具

可以通过百度网盘下载(链接: https://pan.baidu.com/s/1nFaUIwv171PDXuF7TziDFg 提取码: 9ntc)，或者通过微云下载[https://share.weiyun.com/59xtmWR](https://share.weiyun.com/59xtmWR)，下载完成后直接解压，然后将make所在的路径添加到环境变量里。

4. 安装python3

到[python官网](https://www.python.org/)下载win版本的python，注意要下载python3版本的。网速慢的同学可以通过百度网盘下载(链接: https://pan.baidu.com/s/1gNC8L5dZTsN6E5TJD2rmnQ 提取码: 3b4t)，或者通过微云下载[https://share.weiyun.com/XwzSQHND](https://share.weiyun.com/XwzSQHND)。安装完后将python添加到环境变量里。

5. 下载tinyriscv代码

**使用git clone命令下载，不要使用zip方式下载**，否则有些文件会有格式问题。

`git clone https://gitee.com/liangkangnan/tinyriscv.git`

## 4.2Linux平台环境搭建

这里以Ubuntu系统为例进行说明。

1. 下载iverilog源码

`git clone https://github.com/steveicarus/iverilog.git`

2. 切换到v11分支(必须用V11或以上的版本)

`git checkout v11-branch`

3. 安装依赖

`sudo apt-get install autoconf gperf flex bison build-essential`

4. 编译、安装iverilog和vvp

```
sh autoconf.sh
./configure
make
make install
```

5. 创建python软链接

`sudo ln -s /usr/bin/python3.8 /usr/bin/python`

其中/usr/bin/python3.8对应你实际安装的python版本。

6. 安装gtkwave

`sudo apt-get install gtkwave`

7. 安装GNU工具链

可以从百度网盘下载(链接：https://pan.baidu.com/s/10uLZYf_cgtH94kZI_N6JhQ 
提取码：uk0w)或者自行下载其他版本的，下载后解压到tools目录下。

最后，需要确认tests/example/common.mk文件里的这几行内容要与你安装的工具链对应得上。

![toolchain](F:\Work\tinyriscv_master\pic\toolchain.png)

## 4.3运行指令测试程序

这里以Windows平台为例进行说明，Linux平台是类似的。

### 4.3.1 运行旧的指令测试程序

旧的指令测试程序属于比较早的指令兼容性测试方法，虽然目前RISC-V官方已经不更新了，但仍然是一个比较好的测试参考。

下面以add指令为例，说明如何运行旧的指令测试程序。

打开CMD窗口，进入到sim目录，执行以下命令：

```python .\sim_new_nowave.py ..\tests\isa\generated\rv32ui-p-add.bin inst.data```

如果运行成功的话就可以看到&quot;PASS&quot;的打印。其他指令使用方法类似。

![](F:\Work\tinyriscv_master\pic\test_output.png)

也可以一次性对所有指令进行测试，方法如下。

打开CMD窗口进入到sim目录下，执行以下命令：

`python .\test_all_isa.py`

### 4.3.2运行新的指令测试程序

新的指令兼容性([riscv-compliance](https://github.com/riscv/riscv-compliance))测试项相对于旧的指令兼容性测试项来说对指令的测试更加严谨，可以精确到每一条指令的运行结果，而且RISC-V官方一直在更新。

下面以add指令为例，说明如何运行新的指令测试程序。

打开CMD窗口，进入到sim/compliance_test目录，执行以下命令：

`python .\compliance_test.py ..\..\tests\riscv-compliance\build_generated\rv32i\I-ADD-01.elf.bin inst.data`

如果运行成功的话就可以看到&quot;PASS&quot;的打印。其他指令使用方法类似。

![new_test_output](F:\Work\tinyriscv_master\pic\new_test_output.png)

## 4.4运行C语言程序

C语言程序例程位于tests\example目录里。

下面以simple程序为例进行说明。

打开CMD窗口，进入到tests\example\simple目录，执行以下命令编译：

`make`

编译成功之后，进入到sim目录，执行以下命令开始测试：

` python .\sim_new_nowave.py ..\tests\example\simple\simple.bin inst.data`
