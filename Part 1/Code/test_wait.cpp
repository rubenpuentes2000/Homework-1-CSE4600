//test_wait.cpp
// Additional modifications made exclusively by Thomas Cross.
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
  pid_t pid;		//process id
  char *message;
  int n;
  int exit_code;

  cout << "fork program starting\n";
  pid = fork();
  switch (pid) {
  case -1:
    cout << "Fork failure!\n";
    return 1;
  case 0:
    message = "This is the child\n";
    n = 5;
    exit_code = 9;
    break;
  default:
    message = "This is the parent\n";
    n = 3;
    exit_code = 0;
    break;
  }
  for (int i = 0; i < n; ++i) {
    cout << "Process ID: " << pid << "\n";
    cout << message;
    sleep (1);
  }

  //waiting for child to finish
  if (pid != 0) {		//parent 
    int stat_val;
    pid_t child_pid;

    child_pid = wait (&stat_val);	//wait for child
    cout << "Child finished: PID = " << child_pid << endl;
    if (WIFEXITED (stat_val))
 	cout << "child exited with code " << WEXITSTATUS (stat_val) << endl;
    else
	cout << "child terminated abnormally!" << endl;
  }
  

// Code iteration based off of a combination of the implementation above

if (pid == 0) {		//child process 
    int stat_val;
    pid_t GC_pid, pid1;
    pid1 = fork();
    GC_pid = wait (&stat_val);	//wait for grandchild
    switch(pid1){
        case -1:
            cout << "Fork Failiure" << endl;
            break;
        case 0:
            // cout << "Process ID: " << pid1 << "\n";
            cout <<  "This is the Grandchild" << endl;
            exit_code = 9;
            cout << "Grandchild finished with PID: " << getpid() << endl;
            cout << "Grandchild's parent PID: " << getppid() << endl;
            break;
        default:
            cout << "Grandchild finished: PID = " << GC_pid << endl;
    }
 
}
exit (exit_code); 
}
