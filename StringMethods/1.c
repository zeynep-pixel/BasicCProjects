#include <stdio.h>
#include <string.h>

#define DESTSIZE 100
#define SOURCESIZE 20




//Task is to place each character in the source string between characters in the destination string. 
//For example, let the destination string be "ozone" and the source string be "para". 
//At the end of the process, the destination string should be "opzaorna".
void strinsert(char [], char[]);

int main(void)
{
	char destination [DESTSIZE], source [SOURCESIZE];
	printf("enter destinantion string for strinsert: ");
	scanf("%s", destination);
	printf("enter source string for strinsert: ");
	scanf("%s", source);
	strinsert(destination, source);
	printf("after strinsert, destination string is %s\n", destination);
	
	return 0;
}

void strinsert(char destination[], char source [])
{
  int SIZE = 100;
  char x[SIZE];
  int i , j=0, y=0,z;
  for(i=0; i<SIZE; i++){
     x[i]= destination[j];
    i++;
    j++;
  }
  for(z=1; z<SIZE; z++){
     x[z]= source[y];
	 z++;
   y++;
  }
 printf("%s \n",x);
 strcpy(destination,x);
 //printf("%s",destination);
  


	
}

