/*H**********************************************************************
* FILENAME : WATCH_digital.C             
*
* DESCRIPTION :
*       Implements digital clock.
*
*
* AUTHOR :    Saif Ullah Ijaz        START DATE :    16 Nov 2004
*
*H*/
#include <time.h>
#include <stdio.h>
#include<conio.h>
#include <dos.h>

void main(void)
{

	struct  time t;
	unsigned char temp;
	clrscr();
	printf("\n\n\tThe current time is: ");

   while(!kbhit())
   {
	gettime(&t);
	gotoxy(25,5);
	printf("%2d:%02d:%02d",t.ti_hour, t.ti_min, t.ti_sec);
	temp=t.ti_sec;
	while(temp==t.ti_sec)
	{
		gettime(&t);

	}
   }
   getch();

}