#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <errno.h>

#define SYS_getuserweight 451 //Syscall que pega o peso atual do usuario
#define SYS_setuserweight 452 //Syscall que atribui um novo peso para o usuario

int main(int argc, char **argv)
{
  int id, weight, val;
  errno = 0;

  
  printf("Insira um usuario para consulta:\n");
  scanf("%d", &id);
  val = syscall(SYS_getuserweight, id);
  printf("Peso do usuario: %d", val);

  if (val == -1)   {
    printf("\nErro na syscall: %d\n", errno);
    return 0;
  }
  else printf("\nPeso do usuario %d: %d\nInsira novo peso: ", id, val);
  printf("Insira um peso para o user %d\n", id);
  scanf("%d", &weight);

  val = syscall(SYS_setuserweight, id, weight);

  if (val == -1) printf("\nErro na syscall: %d\n", errno);    
  else printf("\nPeso modificado\n");
    
  return 0;
}

