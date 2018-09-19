/*H**********************************************************************
* FILENAME : GRAPH.C             
*
* DESCRIPTION :
*       Draws a Bar graph and line graph of the specifications entered by user.
*
* NOTES :
*       All the drawing was made using putpixel() function
* 
* AUTHOR :    Saif Ullah Ijaz        START DATE :    12 Nov 2004
*
*H*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>

void main(void)
{
	int gdriver=DETECT,gmode,errorcode,maxx,maxy;
	int years,i,exp[5],xx,yy;
	float j;
	char val[5][10],temp[10];
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
	cleardevice();
	setbkcolor(WHITE);
	setcolor(1);		//text color
	settextstyle(10,0,1);		//settextstyle(textstyle, horizontal=0 / vertical=1,textsize)
	outtextxy(185,25,"Line & Bar Graphs");
	settextstyle(11,0,0);
	outtextxy(85,125,"Enter the number of years(1-5):");
	scanf("%d",&years);

	for(i=0;i<years;i++)
	{
		gotoxy(20,10+i);
		printf("Enter year%d: ",i+1);

		scanf("%s",&val[i]);
		gotoxy(40,10+i);
		printf("Enter expanses for %s: ",val[i]);
		scanf("%d",&exp[i]);
	}
	maxx=getmaxx();
	maxy=getmaxy();
	cleardevice();
	settextstyle(10,0,1);
	outtextxy(185,25,"Line & Bar Graphs");
	setcolor(RED);
	line(0,maxy/2,maxx,maxy/2);		//horizontal(year) axis for line graph
	line(0,maxy-10,maxx,maxy-10);		//horizontal(year) axis for bar graph

	settextstyle(11,1,0);
	outtextxy(50,150,"EXPANSES");
	outtextxy(50,370,"EXPANSES");
	setcolor(BLUE);
	line(50,0,50,maxy);		       //vertical(expanse) axis for both graphs
	settextstyle(11,0,0);
	outtextxy(7,240,"YEARS");
	outtextxy(7,maxy-7,"YEARS");
	xx=120;
	yy=maxy/2;
	for(i=0;i<years;i++)
	{
		strcpy(temp,val[i]);
		setcolor(RED);
		outtextxy(125+(i*60),240,temp);		//to print years on line graph
		outtextxy(125+(i*60),maxy-7,temp);	//to print years on bar graph
		setcolor(BLUE);
		line(140+(i*60),235,140+(i*60),240);	//to point years on horizontal axis(line graph)
		line(140+(i*60),maxy-9,140+(i*60),maxy-13);	//to point years on horizontal axis(bar graph)
		setcolor(RED);
		for(j=0.0;j<3.0;j+=0.01)
			circle(140+(i*60),(maxy/2)-exp[i],j);          //amplitude point on line graph
		setfillstyle(SOLID_FILL,1);
		bar(140+(i*60)-10,maxy-10,140+(i*60)+10,maxy-10-exp[i]);   //amplitude bar on bar graph
		itoa(exp[i],temp,10);
		outtextxy(130+(i*60),(maxy/2)-exp[i]-10,temp);		       //amplitude value on line graph
		outtextxy(130+(i*60),(maxy-10)-exp[i]-10,temp);                //amplitude value on bar graph
		setcolor(BLUE);
		line(xx,yy,140+(i*60),(maxy/2)-exp[i]); 			//to join amplitude values on line graph
		xx=140+(i*60);
		yy=(maxy/2)-exp[i];
	}
	getch();
	closegraph();
}