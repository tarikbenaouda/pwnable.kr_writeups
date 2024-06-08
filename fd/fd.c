#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// solution 
// exec 3< <(echo "LETMEWIN")
// ./fd 4663

char buf[32];
int main(int argc, char* argv[], char* envp[]){
        if(argc<2){
                printf("pass argv[1] a number\n");
                return 0;
        }
        int fd = atoi( argv[1] ) - 0x1234;
        //int fd = atoi( argv[1] );
        printf("atoi: %d\n",atoi(argv[1]));
        int len = 0;
        len = read(fd, buf, 32);
        printf("len: %d, fd: %d\n",len,fd);
        printf("Content of buffer: %s\n",buf);
        if(!strcmp("LETMEWIN\n", buf)){
                printf("good job :)\n");
                system("/bin/cat flag");
                exit(0);
        }
        printf("learn about Linux file IO\n");
        return 0;

}