/*H**********************************************************************
* FILENAME : CAR.C             
*
* DESCRIPTION :
*       Drawing a car using putpixel() function. 
*	inwhich size and color of the car will be given by the user
* PUBLIC FUNCTIONS :
*       void rectangl(float, float, float, float, int)
*	void triangle1(float, float, float, float, int)
*	void triangle2(float, float, float, float, int)
*	void triangle3(float, float, float, float, int)
*	void circl(float, float, float, float, int, int, int)
*	void body(float, int)
*	void parts(float, int)
*	void wheel(float, float, float)
*
* NOTES :
*       These functions are used to print geometrical shapes;
*       
*
* 
* AUTHOR :    Saif Ullah Ijaz        START DATE :    17 Nov 2004
*
*
*H*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

//user-defined functions to print geometrical shapes
void rectangl(float, float, float, float, int);		//rectangle(lenght start, length end, width start, width end, color)
void triangle1(float, float, float, float, int);	//triangle(base start, base end, top height, base height, color)
void triangle2(float, float, float, float, int);	//triangle(base start, base end, top height, base height, color)
void triangle3(float, float, float, float, int);        //triangle(top(base) start, top(base) end, top height, bottom height, color)
void circl(float, float, float, float, int, int, int);   //circle(x-comp. of center, y-comp. of center, radius start, radius end, color, angle start, angle end)


//user-defined functions to print structure of the car
void body(float, int);
void parts(float, int);
void wheel(float, float, float);

void main(void)
{
	int driver,mode,color_car,i,j;
	float length_car;
	clrscr();

	printf("Enter the length of the car(2-20cm):");
	scanf("%f",&length_car);
	length_car=length_car*22.30;       //to convert into centimeters

	//asking color of the car
	printf("\nEnter the color code for the car:");
	printf("\nCode number\tColor name");
	printf("\n-----------\t----");
	printf("\n    0          \tBLACK");
	textcolor(1);
	printf("\n");
	cprintf("    1           BLUE");
	textcolor(2);
	printf("\n");
	cprintf("    2           GREEN");
	textcolor(3);
	printf("\n");
	cprintf("    3           CYAN");
	textcolor(4);
	printf("\n");
	cprintf("    4           RED");
	textcolor(5);
	printf("\n");
	cprintf("    5           MAGENTA");
	textcolor(6);
	printf("\n");
	cprintf("    6           BROWN");
	textcolor(7);
	printf("\n");
	cprintf("    7           LIGHTGRAY");
	textcolor(8);
	printf("\n");
	cprintf("    8           DARKGRAY");
	textcolor(9);
	printf("\n");
	cprintf("    9           LIGHTBLUE");
	textcolor(10);
	printf("\n");
	cprintf("    10          LIGHTGEREEN");
	textcolor(11);
	printf("\n");
	cprintf("    11          LIGHTCYAN");
	textcolor(12);
	printf("\n");
	cprintf("    12          LIGHTRED");
	textcolor(13);
	printf("\n");
	cprintf("    13          LIGHTMAGENTA");
	textcolor(14);
	printf("\n");
	cprintf("    14          YELLOW");
	textcolor(15);
	printf("\n");
	cprintf("    15          WHITE");
	printf("\nCode number:");
	scanf("%d",&color_car);

	driver=DETECT;
	initgraph(&driver,&mode,"C:\\Tc\\BGI");     //initializing graph

	//setting background using putpixel() function
	for(i=0;i<=500;i++)
	{
		for(j=0;j<=635;j++)
			putpixel(j,i,WHITE);
	}

	//calling functions to print car
	body(length_car,color_car);
	parts(length_car,color_car);
	wheel(33.8235/100.0*length_car,29.4118/100.0*length_car,length_car);
	wheel(98.5294/100.0*length_car,29.4118/100.0*length_car,length_car);

	getch();
}

	////////////////
       //              //
      //                //
///////                  /////////////
//    to print main body of car     //
//                                  //
//////////////////////////////////////
void body(float length_b,int color_b)
{
	rectangl(14.7059/100.0*length_b,114.7059/100.0*length_b,11.7647/100.0*length_b,29.4118/100.0*length_b,color_b);
	triangle1(25.0/100.0*length_b,42.6471/100.0*length_b,4.4118/100.0*length_b,11.7647/100.0*length_b,color_b);
	rectangl(42.6471/100.0*length_b,72.0588/100.0*length_b,4.4118/100.0*length_b,11.7647/100.0*length_b,color_b);
	triangle2(72.0588/100.0*length_b,85.2941/100.0*length_b,4.4118/100.0*length_b,11.7647/100.0*length_b,color_b);
	triangle3(85.2941/100.0*length_b,89.7059/100.0*length_b,11.7647/100.0*length_b,14.7059/100.0*length_b,63);
	rectangl(89.7059/100.0*length_b,118.50/100.0*length_b,11.7647/100.0*length_b,14.7059/100.0*length_b,63);
	triangle3(89.7059/100.0*length_b,114.7059/100.0*length_b,14.7059/100.0*length_b,16.1765/100.0*length_b,63);
	triangle3(105.8824/100.0*length_b,114.7059/100.0*length_b,14.7059/100.0*length_b,20.5882/100.0*length_b,63);

}

//to print parts of car like windows,lights,doors,bumpers etc
void parts(float length_p,int color_p)
{
	triangle2(14.7059/100.0*length_p,17.6471/100.0*length_p,7.3529/100.0*length_p,17.6471/100.0*length_p,4);
	triangle2(14.7059/100.0*length_p,16.1765/100.0*length_p,7.3529/100.0*length_p,11.7647/100.0*length_p,63);
	triangle1(35.2941/100.0*length_p,44.1176/100.0*length_p,5.8824/100.0*length_p,14.7059/100.0*length_p,11);
	rectangl(44.1176/100.0*length_p,58.8235/100.0*length_p,5.8824/100.0*length_p,14.7059/100.0*length_p,11);
	rectangl(58.8235/100.0*length_p,61.7647/100.0*length_p,5.8824/100.0*length_p,14.7059/100.0*length_p,0);
	rectangl(61.7647/100.0*length_p,72.0588/100.0*length_p,5.8824/100.0*length_p,14.7059/100.0*length_p,11);
	triangle2(72.0588/100.0*length_p,86.7647/100.0*length_p,5.8824/100.0*length_p,14.7059/100.0*length_p,11);
	rectangl(39.7059/100.0*length_p,44.1176/100.0*length_p,17.6471/100.0*length_p,19.1176/100.0*length_p,0);
	rectangl(64.7059/100.0*length_p,69.1176/100.0*length_p,17.6471/100.0*length_p,19.1176/100.0*length_p,0);
	triangle1(11.7647/100.0*length_p,14.7059/100.0*length_p,20.5882/100.0*length_p,22.0588/100.0*length_p,color_p);
	rectangl(11.7647/100.0*length_p,14.7059/100.0*length_p,22.0588/100.0*length_p,29.41176/100.0*length_p,color_p);
	rectangl(114.7059/100.0*length_p,116.1765/100.0*length_p,23.5294/100.0*length_p,29.41176/100.0*length_p,color_p);
	triangle1(11.7647/100.0*length_p,14.7059/100.0*length_p,35.2941/100.0*length_p,36.7647/100.0*length_p,8);
	rectangl(14.7059/100.0*length_p,113.2353/100.0*length_p,35.2941/100.0*length_p,36.7647/100.0*length_p,8);
	triangle2(113.2353/100.0*length_p,116.1765/100.0*length_p,35.2941/100.0*length_p,36.7647/100.0*length_p,8);
	rectangl(44.1176/100.0*length_p,44.1176/100.0*length_p,5.8824/100.0*length_p,14.7059/100.0*length_p,0);
	rectangl(35.2941/100.0*length_p,35.2941/100.0*length_p,14.7059/100.0*length_p,29.4118/100.0*length_p,0);
	rectangl(60.2941/100.0*length_p,60.2941/100.0*length_p,14.7059/100.0*length_p,29.4118/100.0*length_p,0);
	rectangl(89.7059/100.0*length_p,89.7059/100.0*length_p,14.7059/100.0*length_p,29.4118/100.0*length_p,0);
	rectangl(14.7059/100.0*length_p,33.8235/100.0*length_p,20.5882/100.0*length_p,20.5882/100.0*length_p,0);
	rectangl(102.9412/100.0*length_p,114.7059/100.0*length_p,23.5294/100.0*length_p,23.5294/100.0*length_p,0);

}

//to print front and back wheels of the car
void wheel(float center_x,float center_y,float length_w)
{
	int i;

	circl(center_x,center_y,8.235/100.0*length_w,0.0,0,180,360);
	circl(center_x+(1.4706/100.0*length_w),center_y,7.3529/100.0*length_w,0.0,63,270,360);
	circl(center_x-(1.4706/100.0*length_w),center_y,7.3529/100.0*length_w,0.0,63,180,270);
	circl(center_x,center_y,7.3529/100.0*length_w,4.4118/100.0*length_w,0,0,360);
	for(i=15;i<360;i=i+20)
		circl(center_x,center_y,4.4118/100.0*length_w,0.0,7,i,i);

}


 ///////////////////////////
 //to print a rectangle   //
 //of desired size        //
 ///////////////////////////
void rectangl(float xi,float xf,float yi,float yf,int rc)
{
	float x,y;

	for(y=yi;y<=yf;y++)
	{
		for(x=xi;x<=xf;x++)
			putpixel(x+30,y+30,rc);
	}
}
       //
      ///
     ////
    // //    //to print a triangle of this shape
   //  //
  //   //
 ////////
void triangle1(float xi1,float xf1,float yi1,float yf1,int t1c)
{

	float x,y,z=xf1;

	for(y=yi1;y<=yf1;y++)
	{
		for(x=xf1;x>=z;x=x-(x*0.0027))
			putpixel(x+30,y+30,t1c);
		z=z-((xf1-xi1)/(yf1-yi1));
	}
}

 //
 ///
 ////
 // //    //to print a triangle of this shape
 //  //
 //   //
 ////////
void triangle2(float xi2,float xf2,float yi2,float yf2,int t2c)
{
	float x,y,z=xi2;

	for(y=yi2;y<=yf2;y++)
	{
		for(x=xi2;x<=z;x=x+(x*0.002))
			putpixel(x+30,y+30,t2c);
		z=z+((xf2-xi2)/(yf2-yi2));
	}
}

 ////////
  //   //
   //  //
    // //    //to print a triangle of this shape
     ////
      ///
       //
void triangle3(float xi3,float xf3,float yi3,float yf3,int t3c)
{
	int y;
	float x,z=xi3;

	for(y=yi3;y<=yf3;y++)
	{
		for(x=z;x<=xf3;x=x+(x*0.0001))
			putpixel(x+30,y+30,t3c);
		z=z+((xf3-xi3)/(yf3-yi3));
	}
}

 //to print a circle of desired size
void circl(float xc,float yc,float r1,float r2,int cc,int as,int ae)
{
	float pi=22.0/7.0,x,y,i,j;

	for(j=r1;j>=r2;j--)
	{
		for(i=as; i<=ae; i=i+0.27)
		{
			x=xc+j*cos(i*pi/180.0);           //converting angles into radian(angle*pi/180)
			y=yc+j*sin(i*pi/180.0);

			putpixel(x+30,y+30,cc);
		}
	}
}
