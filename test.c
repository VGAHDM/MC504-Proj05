#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <errno.h>

#define SYS_getuserweight 451 //Syscall que pega o peso atual do usuario
#define SYS_setuserweight 452 //Syscall que atribui um novo peso para o usuario
#define SYS_initializeuserweight 453  //Syscall que reseta todos os pesos para o valor default (10)

int main(int argc, char **argv)
{
  int id, weight, val;
  errno = 0;

  val = syscall(SYS_initializeuserweight);
  ///printf(val);
  printf("User_Weight foi inicializado com os valores default. Syscall ID: %d\n", val);

  printf("Digite o user id:\n");
  scanf("%d", &id);
  val = syscall(SYS_getuserweight, id);
  printf("Peso atual: %d", val);

  if (val == -1)   {
    printf("\nErro na chamada de sistema(ERROR NUMBER %d)\n", errno);
    return 0;
  }
  else printf("\nPeso do usuario %d: %d\nDigite novo peso: ", id, val);
  printf("Digite o peso a ser setado ao user %d\n", id);
  scanf("%d", &weight);

  val = syscall(SYS_setuserweight, id, weight, 1);// chamar como root

  if (val == -1) printf("\nErro na chamada de sistema(ERROR NUMBER %d)\n", errno);    
  else printf("\nPeso alterado com sucesso.\n");
    
  return 0;
}