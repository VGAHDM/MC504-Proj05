#include <linux/syscalls.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_UID 65535

extern int errno ;
extern int user_weights[MAX_UID];

SYSCALL_DEFINE2(setuserweight, int, uid, int, weight, int, is_root){

    if((uid <-1 || uid> MAX_UID) || weight < 0){
        errno = EINVAL;
        return -1;
    }
    //////// parametro para verificar se é root
    if(is_root){
        uid = getuid();
        user_weights[uid] = weight;    
        return 0;
    }
    ////////////////////////
    
    else if (getuid() != 0){ //if not root
        errno = EACCES;
        return -1;
    }
    else {
        if (uid == -1){ 
             uid = getuid();
        }
        user_weights[uid] = weight;
        return 0;

    }
    
