#include <stdio.h>
#include <string.h>

#define SIZE 100



// Task is to repeat str in n times.
// for example, let str be "ali" and n be 2
// after the process, str should be "aliali"

void strRepeat(char [], int);

int main(void)
{
	char str [SIZE];
	int n;//how many times string will be repeated
	printf("enter string for strRepeat: ");
	scanf("%s", str);
	printf("how many times you want to repeat it: ");
	scanf("%d", &n);
	strRepeat(str, n);
	printf("after strRepeat, the string is %s\n", str);
	return 0;
}
void strRepeat(char str[], int n)
{ 
    char x[SIZE];

     for(int i=1; i<n; i++){

		
		strcat(x,str);
		
	 }
    strcat(str,x);


}
