#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int fib(int n)
{
  if (n <= 1)
    return n;
  return fib(n-1) + fib(n-2);
}

void *runner(void *n){
	pthread_exit(fib((int)n));
}


int main(int argc, char* argv[])
{
  pthread_t ts;
  pthread_t ts2;
  int i=10;

  printf("Iniciando\n");
  pthread_create(&ts, NULL, runner, (void *)i-1); // cria 1 thread
  pthread_create(&ts2, NULL, runner, (void *)i-2); // cria 1 thread

  printf("Dormindo...\n");
  sleep(5); // dormir

  printf("Juntando tudo...\n");
  int resultado, resultado2;
  pthread_join(ts, &resultado);
  printf("Resultado de fibonacci de %d: %d\n", 9, resultado);
  pthread_join(ts2, &resultado2);
  printf("Resultado de fibonacci de %d: %d\n", 8, resultado2);

  printf("Resultado de fibonacci de %d: %d\n", 10, resultado+resultado2);

  printf("Saindo!\n");
  pthread_exit(NULL);
  return 0;
}

