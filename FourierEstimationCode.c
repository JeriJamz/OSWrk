//this is an example from the book
// its supposed to go over the flow of C but It look Cool. I wanna code it 
#include <stdio.h>
#include <math.h>

void main(void);
double geta(double);
double getb(double);
double getsee(void);
double g(double);


//Globals
double width = 0.0001;
double RightorLeft = 0;//Initalized to zero so that Sum of the Rectangle from the left side first
//put this in case later you wanna prove the accuracy of A and B
int numTerms = 10;		//Set the Number of the coefffiecent be calculated and pritned
double T=1;	//Time		#this sets the Period and Frequency
double f=1;	//Freq

void main(void){

  double a[numTerms + 1], b[numTerms + 1],c, ctoo, n;
  int i,j;
    printf("\n");
  c = getsee();

    for(n=1 ; n<= numTerms ; n++){
	//ignore the Zero array value so a[1] can repersent a1
      i = n;
      a[i] = geta(n);
     }
    for(n=1 ; n <= numTerms ; n++){
      i = n;
      b[i] = getsee();
    }

RightorLeft = width;
//this is the area for calculation of areas using the right side

  ctoo = getsee();

    for(i = 1 ; i  <= numTerms ; i++){//prints tables of results
	printf("%s%d%s" , "a", i, " is: ");
	printf("%lf", a[i]);
	printf("%s%d%s", "		b", i , " is: ");//I like 
	printf("%lf\n", b[i]);
    }

    printf("\n%s%lf\n", "c is ", c );
    printf("%s%lf\n\n", "ctoo is ", ctoo);
}

double geta(double n){

  double i, total=0;
  double end;

  if(RightorLeft == 0)end = T - width; //this is to make sure an extra triangle doesnt get counted
  else end = T;

  for(i = RightorLeft ; i <= end ; i+=width)
  total += width * (g(i) * cos(6.28 * n * f * i));
  total *= 2/T;
  return total;
}

double getsee(void){
  double i, total = 0;
  double end;

  if(RightorLeft == 0) end = T - width; //this need to make sure an extra rectangle isnt counted
  else end = T;

  for(i=RightorLeft ; i <= end ; i+=width)
  total += width * g(i); 
  total *= 2/T;
  return total; 
}

double g(double t){

  return sqrt(1 /(1 + t));

}


