//pipe1a.cpp
//Any additional code has been added only by Thomas Cross.
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  FILE *fpi;				//for reading a pipe
  
  char cmd [10];
  strcpy(cmd, argv[0]);
  for (int i = 1; i < argc; i++){
    strcat(cmd, argv[i]);
  }

  char buffer[BUFSIZ+1];		//BUFSIZ defined in <stdio.h>
  
  int chars_read;
  memset (buffer, 0,sizeof(buffer));	//clear buffer
  fpi = popen (cmd, "r");	//pipe to command "ps -auxw"
  if (fpi != NULL) {
    //read data from pipe into buffer
    chars_read = fread(buffer, sizeof(char), BUFSIZ, fpi);  
    if (chars_read > 0) 
     cout << "Output from pipe: " << buffer << endl;
    pclose (fpi); 			//close the pipe
    return 0; 
  }

  return 1;
}