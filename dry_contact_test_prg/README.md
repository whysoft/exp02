
# dry contact iobord
 干接点输出和数字量读取综合电路
 using "TSI io64" commu protocol
 use 232 or 485 
 
 
 # provides 8 channel(max) digital value sensor
 # provides 8 channel(max) dry contact output
 
 
function:
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


# config file
config file name must be： dry_contact_test.config.txt
the content is one line。the format is here below:


linux ：
com=ttyUSB0;start=1;stop=1;speed=9600;parity=N;datalen=8;timeoutsec=0.95;
 ttyUSB0 should be the corresponding device name according to the serial port in the computer 。


windows ：
com=50;start=1;stop=1;speed=9600;parity=N;datalen=8;timeoutsec=0.95;
 50 should be the corresponding device number according to the serial port in the computer 。



