/*H**********************************************************************
* FILENAME : DIC.C             
*
* DESCRIPTION :
*       Implements a small dictionary usig files. Take a word as input 
*	from user and prints it meaning if the word is in the dictionary 
*
* PUBLIC FUNCTIONS :
*       int search1(char *)
*	void entr(void)
*
* NOTES :
*       These code is implemented structures in C.
*       
*
* 
* AUTHOR :    Saif Ullah Ijaz        START DATE :    09 Nov 2004
*
*
*H*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Dict
{
	char word[30], mean[30], parts[30], pro[30];
};
int search1(char *srch)
{
	struct Dict d;
	FILE *fptr;
	int check,a;
	char ch;



	fptr=fopen("c:\\dictionary.dic","rb");
	if(fptr==NULL)
	{
		printf("Error opening file.");
		return 2;
	}

	a=0;
	while(1)
	{
		check=fread(&d,sizeof(struct Dict),1,fptr);
		if(check>0)
		{
			if(strcmp(d.word,srch)==0)
			{
				printf("\nPronounciation: ");
				puts(d.pro);
				printf("Parts-of-speech: ");
				puts(d.parts);
				printf("Meanings: ");
				puts(d.mean);
				a=1;
			}
		}
		else
			break;
	}
	fclose(fptr);



	return a;
}
void entr(void)
{
	FILE *fptr;
	char ch,*temp;
	struct Dict d2;
	fptr=fopen("c:\\dictionary.dic","ab");
	if(fptr==NULL)
	{
		printf("Error opening file.");
		getch();
	}

		printf("\nEnter the word: ");
		gets(temp);
		if((search1(temp))==0||(search1(temp))==2)
		{
			strcpy(d2.word,temp);
			printf("Enter the pronounciation of %s: ",d2.word);
			gets(d2.pro);
			printf("Enter parts-of-speech of %s: ",d2.word);
			gets(d2.parts);
			printf("Enter the meaning of %s: ",d2.word);
			gets(d2.mean);
			fwrite(&d2,sizeof(struct Dict),1,fptr);
		}
		else
			printf("\n%s is already included in the dictionary.",temp);

	fclose(fptr);

}


void main(void)
{
	char ch,srch[30];
	int a;
	clrscr();
	while(1)
	{
		printf("\n\n\t\tPress 'd' to enter a word into the dictionary.");
		printf("\n\t\tPress 's' to search a word from the dictionary.");
		printf("\n\n\t\tPress 'e' to exit.");
		ch=getche();
		switch(ch)
		{
			case 'd':
			case 'D':

				entr();
				break;
			case 's':
			case 'S':
				printf("\nEnter a word to search: ");
				gets(srch);
				a=search1(srch);
				if(!a)
					printf("\n%s is not included in the dictionary.",srch);
				break;
			case 'e':
			case 'E':
				exit(0);


		}
	}
}