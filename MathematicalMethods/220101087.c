#include <stdio.h>
#include <math.h>

#define NPEOPLE 10


void readAges(int []);
void printAges(const int []);
float calcMean(const int []);
float calcVariance(const int [], int);
float calcStd(float);
void printStats(float, float, float);
void drawHistogram(const int []);

int main(void)
{
	
	int ages[NPEOPLE];
	float mean, variance, std;
	readAges(ages);
	printAges(ages);
	mean =calcMean(ages);
	variance = calcVariance(ages, mean);
	
	std = calcStd(variance);
	printStats(mean, variance, std);
	drawHistogram(ages);
	return 0;
}

void readAges(int ages[NPEOPLE])
{
 int i, x=1 , control=0;
 
 for(i=0; i<NPEOPLE ; i++){

	printf("Age for %d. person: ", x);
	scanf("%d", &control);
    if(control<0 || control > 100){
        printf("The age you enter suppose to be greater than 0 and less than 100 \n");
        printf("Age for %d. person: ", x);
		scanf("%d", &ages[i]);

	}
	else{
		ages[i]= control;
	}
	
	
	



    x++;

	
 }
 printf("\n");
 
 
 

}

void printAges(const int ages[])

{
 int i, x=1 ;
printf("Here is the ages you entered \n");
 for(i=0; i<NPEOPLE ; i++){
   
   printf("%d. person age: %d \n", x , ages[i]);
   x++;
 }
 printf("\n");
}



float calcMean(const int ages[])
{
 int i,total = 0;
 float mean;
 for(i=0 ; i<NPEOPLE; i++){
	total = total+ ages[i];
 }
 
 mean = total / NPEOPLE;
 return mean;



}

float calcVariance(const int ages[], int mean)
{
 int i,total = 0;
 float variance, x;
 for(i=0 ; i<NPEOPLE; i++){
	total = total+ ages[i];
 }

 x = total-mean;
 variance = pow(x,2) / NPEOPLE;
 return variance;



}





float calcStd(float variance)
{
  float std;
  std = sqrt(variance);
  return std;
}

void printStats(float mean, float variance, float std)
{
	printf("Mean: %.3f \n", mean);
	printf("Variance: %.3f \n", variance);
	printf("Standard deviation: %.3f \n", std);

}

void drawHistogram(const int ages[])
{
  int first = 0, last = 9 ,i;
  printf("\n  ");
  while(last<100){
  printf("%d - %d |" ,first, last);
  for(i =0; i< NPEOPLE; i++){
    if(ages[i]< last && ages[i] > first){
		printf("*");

	}
  }
   printf("\n");

   first = first +10;
   last = last + 10;
  }
  
  
  


}