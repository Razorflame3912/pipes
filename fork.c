#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>


int main(){
  int fds1[2];
  int fds2[2];
  pipe(fds1);
  pipe(fds2);
  int READ = 0;
  int WRITE = 1;
  int f = fork();
  if (f){
    int num = 12;
    printf("parent sent to child: %d\n", num);
    close(fds1[READ]);
    close(fds2[WRITE]);
    write(fds1[WRITE], &num, sizeof(num));
    read(fds2[READ], &num, sizeof(num));
    printf("parent received: %d\n", num);
  }
  else{
    int num;
    close(fds1[WRITE]);
    close(fds2[READ]);
    read(fds1[READ], &num, sizeof(num));
    printf("child multiplying by two...\n");
    num *= 2;
    write(fds2[WRITE], &num, sizeof(num));
  }
    
  return 0;
}
