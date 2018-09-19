/*H**********************************************************************
* FILENAME : WATCH_analog.C             
*
* DESCRIPTION :
*       Implements analogue clock in C DOS graphics.
*
*
* AUTHOR :    Saif Ullah Ijaz        START DATE :    15 Nov 2004
*
*H*/

#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<math.h>

#define pi 3.14159265

void main(void)
{
	struct time t;
	int gdriver=DETECT,gmode,errorcode,maxx,maxy;
	float xx,yy;
	char hrs,mins,secs,temp;

	clrscr();

	initgraph(&gdriver,&gmode,"C:\\tc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1); /* terminate with an error code */
	}
	while(!kbhit())
	{
		cleardevice();
		setbkcolor(WHITE);
		setcolor(1);		//text color
		settextstyle(10,0,1);		//settextstyle(textstyle, horizontal=0 / vertical=1,textsize)
		outtextxy(235,25,"Watch");
		setcolor(RED);
		circle(280,250,150);
		circle(280,250,5);
		setcolor(BLUE);
		settextstyle(10,0,1);
		outtextxy(335,120,"1");
		outtextxy(385,160,"2");
		outtextxy(395,225,"3");
		outtextxy(385,290,"4");
		outtextxy(335,330,"5");
		outtextxy(275,350,"6");
		outtextxy(215,330,"7");
		outtextxy(165,290,"8");
		outtextxy(150,225,"9");
		outtextxy(165,168,"10");
		outtextxy(200,120,"11");
		outtextxy(265,100,"12");

		gettime(&t);
		hrs=t.ti_hour;
		mins=t.ti_min;
		secs=t.ti_sec;
		setcolor(RED);
		xx=280+(100*cos((((-30*hrs)+90)-(mins/2))/180.0*pi)); 		///HOUR///
		yy=250-(100*sin((((-30*hrs)+90)-(mins/2))/180.0*pi));         // y = -30x+90

		line(xx,yy+4,xx,yy-4);
	      //	line(280,250,xx+1,yy+1);
	      //	line(280,250,xx-1,yy-1);
		line(280,250,xx,yy+4);
		line(280,250,xx,yy-4);

		setcolor(BLUE);
		xx=280+(150*cos(((-6*mins)+90)/180.0*pi));           	// MINUTE///
		yy=250-(150*sin(((-6*mins)+90)/180.0*pi));              // y = -6x+90
		line(280,250,xx,yy);
		line(280,250,xx,yy+1);
		line(280,250,xx,yy-1);

		setcolor(RED);
		xx=280+(150*cos(((-6*secs)+90)/180.0*pi));		//SECOND///
		yy=250-(150*sin(((-6*secs)+90)/180.0*pi));              //y = -6x+90
		line(280,250,xx,yy);
		temp=t.ti_sec;
		while(temp==t.ti_sec)
		{
			gettime(&t);

		}
		 sound(2000);
		delay(1);
		nosound();
	}


	getch();
	closegraph();

}