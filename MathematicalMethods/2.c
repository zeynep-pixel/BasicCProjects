#include <stdio.h>
#include <stdlib.h>

#define ARRSIZE 5

void question_1();
int power(int, int);
void question_2();
int logarithm(int, int);
void question_3();
int findMax(int *, int, int);

int main(void)
{
    question_1();
    question_2();
    question_3();
   
}



void question_1()
{
    int base, exp;
    printf("Enter base and exponent: ");
    scanf("%d%d", &base, &exp);
    printf("%d^%d: %d\n", base, exp, power(base, exp));
}


void question_2()
{
    int number, b;
    printf("Enter number and base for logarithm: ");
    scanf("%d%d", &number, &b);
    printf("log_%d(%d): %d\n", b, number, logarithm(number, b));

}


void question_3()
{
    int *numbers = (int *)malloc(ARRSIZE * sizeof(int)), i, maximum;
    for(i = 0; i < ARRSIZE; i++)
    {
        printf("Enter %d. number: ", i+1);
        scanf("%d", &numbers[i]);
    }
    //for now, set the maximum to the last element of the array
    maximum = numbers[ARRSIZE - 1];
    maximum = findMax(numbers, numbers[ARRSIZE-1], ARRSIZE);
    printf("maximum number in the array: %d\n", maximum);
    

}




int power(int base, int exp)
{
    
   if(exp==0){
    return 1;
   }
   return base * power(base, exp-1);




}




int logarithm(int number, int b)
{

   int result = 0;
   number /= b;
   if(number == 1)
    return 1;
   return result + 1 + logarithm(number , b);




    
}




int findMax(int *arr, int maximum, int n)
{

    
     if (n == 0) {
        return maximum;
    }
    if (maximum < arr[n-1]) {
        maximum = arr[n-1];
    }
    return findMax(arr, maximum, n-1);






}
