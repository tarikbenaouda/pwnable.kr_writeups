#include <stdio.h>

int main(){
        unsigned int random;
        random = rand();        // random value!

        unsigned int key=0;
        scanf("%d", &key);
        printf("value key ^ random: %X, %d\nvalue random:%d\nvalue key:%d\n",key ^ random,key ^ random,random,key);
        printf("the key: %d\n",random ^ 0xdeadbeef);
        if( (key ^ random) == 0xdeadbeef ){
                printf("Good!\n");
                system("/bin/cat flag");
                return 0;
        }

        printf("Wrong, maybe you should try 2^32 cases.\n");
        return 0;
}