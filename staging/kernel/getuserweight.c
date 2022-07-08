#include <linux/syscalls.h>
#include <linux/cred.h>
#include <linux/kernel.h>
//#include <linux/errno.h>
#define MAX_UID 65535

//extern int errno ;

extern int user_weights[MAX_UID];


SYSCALL_DEFINE1(getuserweight, int, uid){
    printf("uid = %d\n",uid);
    if (uid < -1 || uid > MAX_UID) {
//        errno = EINVAL;
        
        return -22;

        //Talvez seja possivel mandar um return -EINVAL (sem mudar o errno). Talvez nem seja assim que usa o errno, pode ser pra retornar o inteiro equivalente ao erro, nesse caso, 22. 
        
    }
    else{
        if (uid == -1){
            uid = get_current_cred()->uid.val;
        }
        return user_weights[uid];
    }
}
