/*H**********************************************************************
* FILENAME : TRNSL.C             
*
* DESCRIPTION :
*       Takes a number from user whose range is from 0 - 999. 
*	Displays this number in words.
*
* PUBLIC FUNCTIONS :
*       void trns(int)
*	void conv(int)
*
* AUTHOR :    Saif Ullah Ijaz        START DATE :    15 Nov 2004
*
*H*/

#include<stdio.h>
#include<conio.h>

void trns(int a)
{
	char wordz[27][10]={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
	printf("%s",wordz[a-1]);

}
void conv(int a)
{
	if(a>=100)
	{
		trns(a/100);
		printf(" Hundred");
		if((a%100)!=0)
		{
			printf(" and ");
			if((a%100)!=0)
			{
				if((a%100)<=20)
				{
					trns((a%100));

				}
				else
					trns(((a%100)/10)+18);
			}
			if(((a%10)!=0)&&((a%100)>20))
			{
				trns((a%10));
			}
		}

	}
	else if(a!=0)
	{
		if(a<=20)
			trns(a);
		else
			trns((a/10)+18);
		if(((a%10)!=0)&&(a>20))
			trns((a%10));
	}
	else
		printf("Zero");
}


void main(void)
{
	int a;
	clrscr();
	printf("Enter a number between(0-999): ");
	scanf("%d",&a);
	printf("\n\n\t\t%d in words is: ",a);
	conv(a);

	getch();
}