#include <linux/syscalls.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_UID 65535

extern int errno ;

int user_weights[MAX_UID];
EXPORT_SYMBOL(user_weights);

SYSCALL_DEFINE1(getuserweight, int, uid){
    if (uid < -1 || uid > MAX_UID) {
        errno = EINVAL;
        return -1;
        //Talvez seja possivel mandar um return -EINVAL (sem mudar o errno). Talvez nem seja assim que usa o errno, pode ser pra retornar o inteiro equivalente ao erro, nesse caso, 22. 
        
    }
    else{
        if (uid == -1){
            uid = getuid(); //N sei se isso aqui ta certo...
        }
        return user_weights[uid];
    }
}