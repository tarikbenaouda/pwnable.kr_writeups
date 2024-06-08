#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// bof has been cracked with reverse engineering :)
// bof.1 is the original one
void func(int key){
	char overflowme[32];
	printf("overflow me : ");
	gets(overflowme);	// smash me!
	printf("the buffer :%s\n",overflowme);
	if(key == 0xcafebabe){
		system("/bin/sh");
	}
	else{
		printf("Nah..\n");
	}
	printf("key: %X\n",key);

}
int main(int argc, char* argv[]){
	func(0xdeadbeef);
	return 0;
}

