#include <stdio.h>
#include <string.h>

#define SIZE 100



//remove a given character from the string
//for example, let str be "pamukkale" and ch be 'a'
// after the process, str should be "pmukkle"

void removeACharachter(char [], char);

int main(void)
{
	char str [SIZE], ch;
	printf("enter string for removeACharachter: ");
	scanf("%s", str);
	getchar();
	printf("enter a characther to remove: ");
	scanf("%c", &ch);
	removeACharachter(str, ch);
	printf("after removeACharachter, he string is %s\n", str);
	return 0;
}


void removeACharachter(char str [], char ch)
{   

    char result[SIZE];  
    int x = 0; 

    
    for (int i = 0; i < SIZE; i++) {
        if (str[i] != ch) {
            result[x] = str[i];
            x++;
        }
    }
    strcpy(str, result);
  

  

 
 


}


