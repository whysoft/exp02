
# iobord
 干接点输出和数字量读取综合电路
 用TSI io64通信协议，
 可使用232或485通信。
 
 
 # 提供8数字量读取功能
 # 提供8干接点输出功能
 
 
测试软件功能说明：
11 open relay 1
12 open relay 2
13 open relay 3
14 open relay 4
15 open relay 5
16 open relay 6
17 open relay 7
18 open relay 8
21 close relay 1
22 close relay 2
23 close relay 3
24 close relay 4
25 close relay 5
26 close relay 6
27 close relay 7
28 close relay 8
89: only read the input_dig_value


# 配置文件说明
配置文件名为： dry_contact_test.config.txt
内容是一行，分号隔开的若干字段。
如果在linux下则写作：
com=ttyUSB0;start=1;stop=1;speed=9600;parity=N;datalen=8;timeoutsec=0.95;
其中 ttyUSB0需要根据当时电脑中串口写成对应的设备名。
如果在windows下则写作：
com=50;start=1;stop=1;speed=9600;parity=N;datalen=8;timeoutsec=0.95;
其中50需要改为当时电脑中串口对应的号码。

