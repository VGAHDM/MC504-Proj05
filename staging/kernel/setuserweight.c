#include <linux/syscalls.h>
#include <linux/cred.h>
#include <linux/kernel.h>
//#include <linux/errno.h>


#define MAX_UID 65535
//extern int errno ;
extern int user_weights[MAX_UID];

SYSCALL_DEFINE2(setuserweight, int, uid, int, weight){


    if((uid <-1 || uid> MAX_UID) || weight < 0){
//        errno = EINVAL;
        return -22;
    }


    else if (get_current_cred()->uid.val != 0){ //if not root
 //       errno = EACCES;
        return -13;

    }
    else {
        if (uid == -1){ 
             uid = get_current_cred()->uid.val;
        }
        user_weights[uid] = weight;
        return 0;

    }
}
