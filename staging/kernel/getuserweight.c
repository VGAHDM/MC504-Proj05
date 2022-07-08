#include <linux/syscalls.h>
#include <linux/cred.h>
#include <linux/kernel.h>

#define MAX_UID 65535



extern int user_weights[MAX_UID];


SYSCALL_DEFINE1(getuserweight, int, uid){
    printf("uid = %d\n",uid);
    if (uid < -1 || uid > MAX_UID) {
//        errno = EINVAL;      
        return -22;


    }
    else{
        if (uid == -1){
            uid = get_current_cred()->uid.val;
        }
        return user_weights[uid];
    }
}
