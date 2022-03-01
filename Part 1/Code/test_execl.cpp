//test_execl.cpp
// All code is original and written by Thomas Cross
#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
  cout << "Running ps with execl!\n";
  execl("/bin/ps", "/bin/ps", "-ax", 0); //Execl requires a directory rather than a command

  cout << "The program is exiting!\n";
  
  return 0;
}