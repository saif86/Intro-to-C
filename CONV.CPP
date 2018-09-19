/*H**********************************************************************
* FILENAME : CONV.CPP             
*
* DESCRIPTION :
*       Converts the numbers to and from the following formats: 
*	>	Binary
*	>	Decimal
*	>	Octal
*	>	Hexadecimal
* PUBLIC FUNCTIONS :
*       int d2b(int, int [])
*	int d2o(int, int [])
*	int d2h(int, int [])
*	int b2d(int *, int)
*	int o2d(int *, int)
*	int h2d(int *, int)
*
* NOTES :
*       These code is implemented without using built-in functions for 
*	square root, square, x power y.
*       
*
* 
* AUTHOR :    Saif Ullah Ijaz        START DATE :    08 Nov 2004
*
*
*H*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int d2b(int num,int bin[])
{
	int div,rem,i,length;
	div=num/2;
	rem=num%2;

	i=0;
	while(div!=0)
	{
		bin[i]=rem;
		rem=div%2;
		div=div/2;

		i++;
	}
	bin[i]=rem;
	length=i+1;
	return length;
}
int d2o(int num,int oct[])
{
	int div,rem,i,length;
	div=num/8;
	rem=num%8;

	i=0;
	while(div!=0)
	{
		oct[i]=rem;
		rem=div%8;
		div=div/8;

		i++;
	}
	oct[i]=rem;
	length=i+1;
	return length;
}

int d2h(int num,int hex[])
{
	int div,rem,i,length;
	div=num/16;
	rem=num%16;

	i=0;
	while(div!=0)
	{
		hex[i]=rem;
		rem=div%16;
		div=div/16;

		i++;
	}
	hex[i]=rem;
	length=i+1;
	return length;
}
int b2d(int *bin,int len)
{
	int dec,i,temp1,temp2;
	dec=0;
	for(i=0;i<len;i++)
	{
		dec+=bin[i]*(pow(2.0,len-i-1));
	}
	return dec;
}
int o2d(int *oct,int len)
{
	int dec,i;
	dec=0;
	for(i=0;i<len;i++)
	{
		dec+=oct[i]*(pow(8.0,len-i-1));
	}
	return dec;
}
int h2d(int *hex,int len)
{
	int dec,i;
	dec=0;
	for(i=0;i<len;i++)
	{
		dec+=hex[i]*(pow(16.0,len-i-1));
	}
	return dec;
}




void main(void)
{
	int a,ch=1,num,i,fl=0;
	int len_bin,bin[32];
	int len_oct,oct[32];
	int len_hex,hex[32];
	int *bini;
	char *binc;

	clrscr();
	while(ch!=0)
	{

	printf("\n\n\tEnter no. in:\n");
	printf("1). Decimal\n");
	printf("2). Binary\n");
	printf("3). Octal\n");
	printf("4). Hexadecimal\n");
	printf("Enter your choice #: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nEnter the decimal number: ");
			scanf("%d",&num);
			len_bin=d2b(num,bin);
			printf("Binary: ");
			for(i=len_bin-1;i>=0;i--)
				printf("%d",bin[i]);

			len_oct=d2o(num,oct);
			printf("\tOctal: ");
			for(i=len_oct-1;i>=0;i--)
				printf("%d",oct[i]);

			len_hex=d2h(num,hex);
			printf("\tHexadecimal: ");
			for(i=len_hex-1;i>=0;i--)
			{
				if(hex[i]>9&&hex[i]<16)
				{
					switch(hex[i])
					{
						case 10:
							printf("A");
							break;
						case 11:
							printf("B");
							break;
						case 12:
							printf("C");
							break;
						case 13:
							printf("D");
							break;
						case 14:
							printf("E");
							break;
						case 15:
							printf("F");
							break;
						default:
							printf("X");
					}
				}
				else
					printf("%d",hex[i]);
			}
			break;
		case 2:
			printf("\nEnter the binary expression: ");
			flushall();
			gets(binc);
			printf("");
			bini=new int[strlen(binc)];
			fl=0;
			for(i=0;i<strlen(binc);i++)
			{
				switch(binc[i])
				{
					case '0':
						bini[i]=0;
						break;
					case '1':
						bini[i]=1;
						break;
					default:
						printf("Invalid binary expression.");
						fl=1;
				}
				if(fl==1)
					break;
			}
			if(fl!=1)
			{
				num=b2d(bini,strlen(binc));
				printf("\tDecimal: %d",num);
				len_oct=d2o(num,oct);
				printf("\tOctal: ");
				for(i=len_oct-1;i>=0;i--)
					printf("%d",oct[i]);

				len_hex=d2h(num,hex);
				printf("\tHexadecimal: ");
				for(i=len_hex-1;i>=0;i--)
				{
					if(hex[i]>9&&hex[i]<16)
					{
						switch(hex[i])
						{
						case 10:
							printf("A");
							break;
						case 11:
							printf("B");
							break;
						case 12:
							printf("C");
							break;
						case 13:
							printf("D");
							break;
						case 14:
							printf("E");
							break;
						case 15:
							printf("F");
							break;
						default:
							printf("X");
						}
					}
					else
						printf("%d",hex[i]);
				}
				break;
			}
			break;
		case 3:
			printf("Enter the octal number: ");
			flushall();
			gets(binc);
			printf("");
			bini=new int[strlen(binc)];
			fl=0;
			for(i=0;i<strlen(binc);i++)
			{
				switch(binc[i])
				{
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
						bini[i]=binc[i]-48;
						break;
					default:
						printf("Invalid octal expression.");
						fl=1;
				}
				if(fl==1)
					break;
			}
			if(fl!=1)
			{
				num=o2d(bini,strlen(binc));
				printf("\tDecimal: %d",num);
				len_bin=d2b(num,bin);
				printf("\tBinary: ");
				for(i=len_bin-1;i>=0;i--)
					printf("%d",bin[i]);
				len_hex=d2h(num,hex);
				printf("\tHexadecimal: ");
				for(i=len_hex-1;i>=0;i--)
				{
					if(hex[i]>9&&hex[i]<16)
					{
						switch(hex[i])
						{
						case 10:
							printf("A");
							break;
						case 11:
							printf("B");
							break;
						case 12:
							printf("C");
							break;
						case 13:
							printf("D");
							break;
						case 14:
							printf("E");
							break;
						case 15:
							printf("F");
							break;
						default:
							printf("X");
						}
					}
					else
						printf("%d",hex[i]);
				}
				break;
			}
			break;
		case 4:
			printf("Enter the Hexadecimal number: ");
			flushall();
			gets(binc);
			printf("");
			bini=new int[strlen(binc)];
			fl=0;
			for(i=0;i<strlen(binc);i++)
			{
				switch(binc[i])
				{
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						bini[i]=binc[i]-48;
						break;
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
						bini[i]=binc[i]-55;
						break;
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
						bini[i]=binc[i]-87;
						break;
					default:
						printf("Invalid octal expression.");
						fl=1;
				}
				if(fl==1)
					break;
			}
			if(fl!=1)
			{
				num=h2d(bini,strlen(binc));
				printf("\tDecimal: %d",num);
				len_bin=d2b(num,bin);
				printf("\tBinary: ");
				for(i=len_bin-1;i>=0;i--)
					printf("%d",bin[i]);
				len_oct=d2o(num,oct);
				printf("\tOctal: ");
				for(i=len_oct-1;i>=0;i--)
					printf("%d",oct[i]);



			}
			break;

		case 0:
			flushall();
			exit(0);
		default:
			printf("\nInvalid choice");

	}
	flushall();
	}
	getch();

}