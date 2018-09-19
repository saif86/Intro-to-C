/*H**********************************************************************
* FILENAME : FILING.CPP             
*
* DESCRIPTION :
*       Reads a passage from a file and perform the following functions: 
*	i.	Convert all characters to lower/upper case
*	ii.	Convert the Ist character of the word to lower/upper case.
*	iii.	Adds a space after a full stop or comma
*
* PUBLIC FUNCTIONS :
*       void to_up(void)
*	void to_low(void)
*	void first_up(void)
*	void first_low(void)
*	void punct(void)
*
* AUTHOR :    Saif Ullah Ijaz        START DATE :    10 Nov 2004
*
*H*/

#include<stdio.h>
#include<conio.h>
#include<IO.H>
#include<fcntl.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


void to_up(void)
{
	FILE *fptr,*fptr2;
	char str[30],*check,string[30];
	int i;
	clrscr();
	fptr=fopen("C:\\file5.saf","r");
	fptr2=fopen("C:\\upper.saf","w");
	if(fptr==NULL)
	{
		printf("Error opening file");
		getch();
		exit(0);
	}
	while(1)
	{
		check=fgets(str,29,fptr);

		if(check!=NULL)
		{
			for (i=0; i<strlen(str); i++)
			{
				str[i] = toupper(str[i]);
			}
			fputs(str,fptr2);
		}
		else
			break;
	}
	fclose(fptr);
	fclose(fptr2);

}

void to_low(void)
{
	FILE *fptr,*fptr2;
	char str[30],*check,string[30];
	int i;
	clrscr();
	fptr=fopen("C:\\file5.saf","r");
	fptr2=fopen("C:\\lower.saf","w");
	if(fptr==NULL)
	{
		printf("Error opening file");
		getch();
		exit(0);
	}
	while(1)
	{
		check=fgets(str,29,fptr);

		if(check!=NULL)
		{
			for (i=0; i<strlen(str); i++)
			{
				str[i] = tolower(str[i]);
			}
			fputs(str,fptr2);
		}
		else
			break;
	}
	fclose(fptr);
	fclose(fptr2);

}
void first_up(void)
{
	FILE *fptr,*fptr2;
	char str,*check;
	int fl;
	clrscr();
	fptr=fopen("C:\\file5.saf","r");
	fptr2=fopen("C:\\fupper.saf","w");
	if(fptr==NULL)
	{
		printf("Error opening file");
		getch();
		exit(0);
	}
	fl=0;
	do
	{
		str=getc(fptr);
		if(str==EOF)
			break;
		if(fl==0)
			str=toupper(str);
		fl=1;
		if(str==' '||str=='\n')
			fl=0;
		putc(str,fptr2);

	}while(str!=EOF);
	fclose(fptr);
	fclose(fptr2);

}
void first_low(void)
{
	FILE *fptr,*fptr2;
	char str,*check;
	int fl;
	clrscr();
	fptr=fopen("C:\\file5.saf","r");
	fptr2=fopen("C:\\flower.saf","w");
	if(fptr==NULL)
	{
		printf("Error opening file");
		getch();
		exit(0);
	}
	fl=0;
	do
	{
		str=getc(fptr);
		if(str==EOF)
			break;
		if(fl==0)
			str=tolower(str);
		fl=1;
		if(str==' '||str=='\n')
			fl=0;
		putc(str,fptr2);

	}while(str!=EOF);
	fclose(fptr);
	fclose(fptr2);

}

void punct(void)
{
	FILE *fptr,*fptr2;
	char str,*check;
	int fl;
	clrscr();
	fptr=fopen("C:\\file5.saf","r");
	fptr2=fopen("C:\\punc.saf","w");
	if(fptr==NULL)
	{
		printf("Error opening file");
		getch();
		exit(0);
	}
	fl=0;
	do
	{
		str=getc(fptr);
		if(str==EOF)
			break;
		if(fl==1)
		{
			if(str!=' ')
				putc(' ',fptr2);
		}
		fl=0;
		if(str=='.'||str==',')
			fl=1;
		putc(str,fptr2);

	}while(str!=EOF);
	fclose(fptr);
	fclose(fptr2);

}
void main(void)
{
	int ch;
	clrscr();
	printf("Select your choice:");
	printf("\n1). Convert all characters to upper case.");
	printf("\n2). Convert all characters to lower case.");
	printf("\n3). Convert first character to upper case.");
	printf("\n4). Convert first character to lower case.");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			to_up();
			break;
		case 2:
			to_low();
			break;
		case 3:
			first_up();
			break;
		case 4:
			first_low();
			break;
		case 5:
			punct();
			break;
		default:
			printf("Invalid choice selected");
	}
	getch();

}