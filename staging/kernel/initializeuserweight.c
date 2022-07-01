#include <linux/kernel.h>
#include <linux/syscalls.h>

#define USER_ARRAY_SIZE 65535
#define USER_DEFAULT_WEIGHT 10

int user_weights[USER_ARRAY_SIZE];
EXPORT_SYMBOL(user_weights);

SYSCALL_DEFINE0(initializeuserweight)
{
	for (int i = 0; i < USER_ARRAY_SIZE; i++) {
		user_weights[i] = USER_DEFAULT_WEIGHT;
	}
	return 453;
}