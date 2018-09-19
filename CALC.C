/*H**********************************************************************
* FILENAME : CALC.C             
*
* DESCRIPTION :
*       A simple calculator which is capable to perfrom follwoing functions: 
*	i.	Addition, subtraction, division, multiplication
*	ii.	sin, cos, tan
*	iii.	Square root, square, x power y(where x is the number and y is its power) 
* PUBLIC FUNCTIONS :
*       float sqroot(int)
*
* NOTES :
*       These code is implemented without using built-in functions for 
*	square root, square, x power y.
*       
*
* 
* AUTHOR :    Saif Ullah Ijaz        START DATE :    07 Nov 2004
*
*
*H*/

#include<stdio.h>
#include<conio.h>
#include<math.h>


#define  pi 3.14159265
float sqroot(int a)
{
	float ans;

	ans=a;
	while((ans*ans)-a>=0.01)
		ans-=0.001;

	return ans;
}
void main(void)
{
	char ch;
	int x,y,i,ans;
	float sq;
	clrscr();
	do
	{
		printf("\n\n\t\t\tSelect your choice:");
		printf("\n\t1). Addition, Subtraction, Multiplication, Division, Power");
		printf("\n\t2). sin(x), cos(x), tan(x), square(x), cube(x), squareroot(x)");
		ch=getche();
		switch(ch)
		{
			case '1':
				printf("\nEnter the value of x: ");
				scanf("%d",&x);
				printf("\nEnter the value of y: ");
				scanf("%d",&y);
				printf("\nAddition of %d and %d is : %d",x,y,x+y);
				printf("\nSubtraction of %d and %d is : %d",x,y,x-y);
				printf("\nMultiplication of %d and %d is : %d",x,y,x*y);
				if(y==0)
					printf("\nDivision of %d and %d is undefined.",x,y);
				else
				printf("\nDivision of %d and %d is : %d",x,y,x/y);
				ans=1;
				for(i=0;i<y;i++)
					ans*=x;
				printf("\n%d power %d is: %d",x,y,ans);
				break;
			case '2':
				printf("\nEnter the value of x: ");
				scanf("%d",&x);
				printf("\nSine(%d): %f",x,sin(x/180.0*pi));
				printf("\nCosine(%d): %f",x,cos(x/180.0*pi));
				printf("\nTangent(%d): %f",x,tan(x/180.0*pi));
				printf("\n%d square: %d",x,x*x);
				printf("\n%d cube: %d",x,x*x*x);
				sq=sqroot(x);
				printf("\nSquare root %d: %.3f (approx)",x,sq);
				break;
			default:
				printf("\nInvalid choice selected.");
		}

	}while(ch!=48);

}