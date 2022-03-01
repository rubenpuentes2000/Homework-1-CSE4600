//Written by:

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <queue>

void *processes(){
  int chain = 10;
  pid_t child;
  std::queue <pid_t> ancestors;
  for ( int i = 0; i < chain; i++ ) {

    if ( (child = fork()) )
        break;                    
    ancestors.push ( getppid() ); 
}
  
wait (0);
  
std::cout << "process " << getpid() << " with child " << child << " and ancestors: ";
while ( ancestors.empty() == 0 ) { 
    std::cout << ancestors.front() << " ";
    ancestors.pop();              
}
std::cout << std::endl;
return 0;
}

int main(){
  processes();
}
