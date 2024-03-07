#include <stdio.h>
#include <string.h>

#define SIZE 100



// swap the str1 and str2. For example, let the str1 be "ali" and the str2 be "mehmet"
// at the end of the process, the str1 should be "mehmet" and the str2 should be "ali"



void strswap(char [], char []);

int main(void)
{
	char str1 [SIZE], str2 [SIZE];
	printf("enter the first string for strswap: ");
	scanf("%s", str1);
	printf("enter the second string for strswap: ");
	scanf("%s", str2);
	strswap(str1, str2);
	printf("after strswap, the first string is %s, the second string is %s\n", str1, str2);
	return 0;
}

void strswap(char str1 [], char str2 [])
{
	
    char a[SIZE] ;
	strcpy(a, str1);
	strcpy(str1,str2);
    strcpy(str2,a);
	
}

