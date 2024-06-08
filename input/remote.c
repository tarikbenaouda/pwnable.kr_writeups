#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

char* exe = "/home/tarik/Desktop/pwnable.kr/input/input";

int main(int argc,char** argv){
    char* new_argv[101];
    char* new_envp[2];
    // argv 
    for (int i = 0; i < 100;i++){
        new_argv[i] = "";
    }
    new_argv[100] = NULL;
    new_argv['A'] = "\x00";
    new_argv['B'] = "\x20\x0a\x0d";

    // for networking
    new_argv['C'] = "8080";

    // stdio / fd
    int new_stdin = open("./first",O_RDWR | O_CREAT , 00777);
    write(new_stdin,"\x00\x0a\x00\xff",4);
    int new_stderr = open("./second",O_RDWR | O_CREAT, 00777);
    write(new_stderr,"\x00\x0a\x02\xff",4);
    lseek(new_stdin,0,SEEK_SET);
    lseek(new_stderr,0,SEEK_SET);

    dup2(new_stdin,0);
    dup2(new_stderr,2);
    // env  

    new_envp[0] = "\xde\xad\xbe\xef=\xca\xfe\xba\xbe";
    new_envp[1] = NULL;

    // file
    unlink("./\x0a");
    int new_line = open("./\x0a",O_RDWR | O_CREAT,00777);
    write(new_line,"\x00\x00\x00\x00",4);
    close(new_line);
    // execution
    execve(exe,new_argv,new_envp);
    return 0;
}