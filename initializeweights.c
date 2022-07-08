#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <errno.h>

#define MAX_UID 65535
#define SYS_getuserweight 451 //Syscall que pega o peso atual do usuario
#define SYS_setuserweight 452 //Syscall que atribui um novo peso para o usuario

int main(){
	int val;
	for(int i = 0; i < MAX_UID; i++){
		val = syscall(SYS_setuserweight, i, 10);
	}
	return 0;
}
