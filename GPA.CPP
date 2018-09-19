/*H**********************************************************************
* FILENAME : GPA.CPP             
*
* DESCRIPTION :
*       Takes the following inputs from user: 
*		i.	name
*		ii.	registration#
*		iii.	number of subjects
*		iv.	marks obtained in each subject
*		v.	name os all subjects
*		vi.	credit hours of all subjects
*	Takes thes inputs for 5 students and calculate their GPA and displays
*	all the information on the screen
*
* PUBLIC FUNCTIONS :
*       float marks2GPA(float)
*	void nam2i(char *, char *)
*
* NOTES :
*       Number of subjects, name of all subjects & credit hours of all subjects 
*	will be same for all the students. So program input these values only once.
*	It uses structures, arrays & strings to implement the code.
* 
* AUTHOR :    Saif Ullah Ijaz        START DATE :    11 Nov 2004
*
*H*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
struct Student
{
	char Sname[30],Rnum[15];
	float marks1[30],GPA[30],CGPA;

};
float marks2GPA(float in)
{
	float out;
	if(in>=90.00)
		out=4.00;
	else if(in>=85.00)
		out=3.70;
	else if(in>=80.00)
		out=3.30;
	else if(in>=75.00)
		out=3.00;
	else if(in>=70.00)
		out=2.70;
	else if(in>=65.00)
		out=2.30;
	else if(in>=60.00)
		out=2.00;
	else if(in>=55.00)
		out=1.70;
	else if(in>=50.00)
		out=1.30;
	else
		out=0.00;
	return out;
}
void nam2i(char *in,char *out)
{
	if(strcmp("System on Chip",in)==0)
		strcpy(out,"SOC");
	else if(strcmp("Advance Digital Logic Design",in)==0)
		strcpy(out,"ADLD");
	else if(strcmp("Wireless Communication",in)==0)
		strcpy(out,"wless");
	else if(strcmp("Control Engineering",in)==0)
		strcpy(out,"CE");
	else if(strcmp("Digital Image Processing",in)==0)
		strcpy(out,"DIP");
	else if(strcmp("Data Communication & Computer Networks",in)==0)
		strcpy(out,"Dcom");
	else
		strcpy(out,in);
}


void main(void)
{
	int num,cred[30],i,j;
	float numer,denom,mm;
	char nam[30][40],inam[30][10];
	struct Student s[5];
	clrscr();
	printf("Enter number of subjects: ");
	scanf("%d",&num);

	for(i=0;i<num;i++)
	{
		flushall();
		printf("\nEnter name of subject%d: ",i+1);
		gets(nam[i]);
		nam2i(nam[i],inam[i]);
		printf("\nEnter credit hours of %s: ",inam[i]);
		scanf("%d",&cred[i]);
	}
	printf("\n\n");
	for(i=0;i<5;i++)
	{
		flushall();
		printf("\n\tEnter name of student%d: ",i+1);
		gets(s[i].Sname);
		printf("\n\tEnter registration# of %s: ",s[i].Sname);
		gets(s[i].Rnum);
		numer=0.0;
		denom=0.0;

		for(j=0;j<num;j++)
		{

			printf("\n\t\tEnter marks in %s: ",nam[j]);
			scanf("%f",&mm);
			s[i].marks1[j]=mm;
			s[i].GPA[j]=marks2GPA(s[i].marks1[j]);
			numer+=(s[i].GPA[j]*cred[j]);
			denom+=cred[j];
		}
		s[i].CGPA=numer/denom;
	}
	clrscr();
	printf("Name:");
	for(i=0;i<5;i++)
	{
		gotoxy((i*15)+7,wherey());
		printf("%s",s[i].Sname);

	}
	printf("\n\nRegs\n#:");
	for(i=0;i<5;i++)
	{
		gotoxy((i*15)+7,wherey());
		printf("%s",s[i].Rnum);

	}
	printf("\n");
	for(i=0;i<80;i++)
		printf("-");
	for(i=0;i<num;i++)
	{
		printf("\n\n%s\nMarks:",inam[i]);
		for(j=0;j<5;j++)
		{
			gotoxy((j*15)+7,wherey());
			printf("%.2f",s[j].marks1[i]);

		}
		printf("\nGPA:");
		for(j=0;j<5;j++)
		{
			gotoxy((j*15)+7,wherey());
			printf("%.2f",s[j].GPA[i]);

		}

	}
	printf("\n");
	for(i=0;i<80;i++)
		printf("-");
	printf("\n\nCGPA:");
	for(i=0;i<5;i++)
	{
		gotoxy((i*15)+7,wherey());
		printf("%.2f",s[i].CGPA);

	}
	getch();
}