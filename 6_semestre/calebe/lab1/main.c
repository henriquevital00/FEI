/**
 * @author      : Henrique Vital Carvalho (henriquevital1000@hotmail.com)
 * @file        : main
 * @created     : sexta ago 27, 2021 21:57:45 -03
 */

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

/* Integrantes
 *  Nome: Henrique Vital Carvalho     Nº: 22.119.078-8
 *  Nome: Gabriel Bueno Vila Real De Oliveira     Nº: 22.119.077-0
 *  Nome: Thiago Andrade Do Nascimento     Nº: 22.119.080-4
*/

void SRZstatus(){
  pid_t child_pid = fork();

    if (child_pid > 0)
      // S/Z status process
        sleep(50);

    else{
      int var = 0;
      // Running status process
      while(var < 1000000){
        var++;
      }
      // Zombie status process
        exit(0);
  }
}

int main() {
  SRZstatus();
  return 0;
}

