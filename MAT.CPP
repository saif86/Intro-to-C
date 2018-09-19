/*H**********************************************************************
* FILENAME : MAT.CPP             
*
* DESCRIPTION :
*       Performs follwoing matrix operation: 
*		i.	Addition
*		ii.	Subtraction
*		iii.	Multiplication
*		iv.	Determinant
*		v.	Inverse
*
* PUBLIC FUNCTIONS :
*       float** inputmat(int, int)
*	float** addmatr(float **, float **, int, int)
*	float** submatr(float **, float **, int, int)
*	float** multmatr(float **, float **, int, int, int)
*	long float detrmin(float **, int)
*	float** invmat(float **, int)
*	void prntmat(float **, int, int)
*
* AUTHOR :    Saif Ullah Ijaz        START DATE :    13 Nov 2004
*
*H*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>


float** inputmat(int r,int c)
{
	int i,j,spc,spr;
	float **matout;
	matout=new float*;
	for(i=0;i<r;i++)
		matout[i]=new float[c];
	printf("\n--");
	for(i=0;i<c;i++)
		printf("  \t");
	printf("     --");
	spc=wherey()+1;
	for(i=0;i<r;i++)
	{
		printf("\nI");
		spr=wherex()+5;
		for(j=0;j<c;j++)
		{
			gotoxy(spr+j,spc+i);
			scanf("%f",&matout[i][j]);
			spr=spr+7;
		}
		gotoxy(j+spr,spc+i);
		printf("I");

	}
	printf("\n--");
	for(i=0;i<c;i++)

		printf("  \t");
	printf("     --\n");


	return matout;
}

float** addmatr(float **,float **,int,int);
float** submatr(float **a,float **b,int row,int col)
{
	int i,j;
	float **result;
	result=new float*;
	for(i=0;i<row;i++)
		result[i]=new float[col];

	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			result[i][j]=a[i][j]-b[i][j];

	return result;
}

float** multmatr(float **a,float **b,int ar,int ac,int bc)
{
	int i,j,k,temp;
	float **result;
	result=new float*;
	for(i=0;i<ar;i++)
		result[i]=new float[bc];
	for(i=0;i<ar;i++)
		for(j=0;j<bc;j++)
		{
			temp=0;
			for(k=0;k<ac;k++)
				temp=temp+((a[i][k])*(b[k][j]));
			result[i][j]=temp;
		}

	return result;

}


long float detrmin(float **matin,int dim)
{
	if(dim==2)
		return((matin[0][0]*matin[1][1])-(matin[0][1]*matin[1][0]));
	else if(dim==1)
		return(matin[0][0]);
	else
	{
		float ***temp;
		int i,j,k,ik,jk;
		long float det;
		temp=new float**;
		for(i=0;i<dim;i++)
		{
			temp[i]=new float*;
			for(j=0;j<dim-1;j++)
				temp[i][j]=new float[dim-1];
		}
		for(k=0;k<dim;k++)
		{
			ik=0;
			for(i=0;i<dim;i++)
			{
				if(i==0)
				{
				}
				else
				{
					jk=0;
					for(j=0;j<dim;j++)
					{
						if(j==k)
						{

						}
						else
						{
							temp[k][ik][jk]=matin[i][j];
							jk++;
						}
					}
					ik++;
				}
			}
		}
	 ///////////////temp matrices complete////
		det=0;
		float **temp2;
		temp2=new float*;
		for(i=0;i<dim-1;i++)
			temp2[i]=new float[dim-1];
		for(k=0;k<dim;k++)
		{

			for(i=0;i<dim-1;i++)
				for(j=0;j<dim-1;j++)
					temp2[i][j]=temp[k][i][j];

			det=det+((pow(-1.0,k))*(matin[0][k])*(detrmin(temp2,dim-1)));
		}

		return det;
	 }
}
float** invmat(float **matin,int dim)
{
	float **result;
	int i,j,k;
	float det;
	result=new float*;
	for(i=0;i<dim;i++)
		result[i]=new float[dim];
	det=detrmin(matin,dim);

	if(dim==2)
	{
		result[0][0]=matin[1][1]/det;
		result[0][1]=-1*matin[0][1]/det;
		result[1][0]=-1*matin[1][0]/det;
		result[1][1]=matin[0][0]/det;
		return result;
	}
	else if(dim==1)
	{
		result[0][0]=matin[0][0]/det;
		return(result);
	}
	else
	{
		float ****temp;
		int l,ik,jk;
		temp=new float***;
		for(k=0;k<dim;k++)
		{
			temp[k]=new float**;
			for(i=0;i<dim;i++)
			{
				temp[k][i]=new float*;
				for(j=0;j<dim-1;j++)
					temp[k][i][j]=new float[dim-1];
			}
		}
		for(l=0;l<dim;l++)
		{
			for(k=0;k<dim;k++)
			{
				ik=0;
				for(i=0;i<dim;i++)
				{
					if(i==0)
					{
					}
					else
					{
						jk=0;
						for(j=0;j<dim;j++)
						{
							if(j==k)
							{

							}
							else
							{
								temp[l][k][ik][jk]=matin[i][j];
								jk++;
							}
						}
						ik++;
					}
				}
			}
		}
		det=detrmin(matin,dim);
		float **temp2;
		temp2=new float*;
		for(i=0;i<dim-1;i++)
			temp2[i]=new float[dim-1];
		for(l=0;l<dim;l++)
		{
			for(k=0;k<dim;k++)
			{

				for(i=0;i<dim-1;i++)
					for(j=0;j<dim-1;j++)
						temp2[i][j]=temp[l][k][i][j];

				result[l][k]=((pow(-1.0,l+k))*(detrmin(temp2,dim-1))/det);
			}
		}

		return result;
	}
}
void prntmat(float **matin,int m1,int n1)
{
	int i,j,c;

	printf("\n --");
	for(i=0;i<n1;i++)
		printf("  \t");
	printf("     --");

	c=wherey();
	for(i=0;i<m1;i++)
	{
		c++;
		printf("\nI");
		for(j=0;j<n1;j++)
		{
			gotoxy((j*8)+7,c);
			printf("%.2f",matin[i][j]);
		}
		gotoxy((j*8)+7,c);
		printf("I");
	}
	printf("\n --");
	for(i=0;i<n1;i++)
		printf("  \t");
	printf("     --\n");
}
void main(void)
{
	int ar,ac,br,bc,ch,i;
	long float det;
	float **ma,**mb,**mc;

	clrscr();
	printf("\n\n\n\t\t\t***** Enter Matrix A *****\n\n");


	printf("Enter no. of rows of MatrixA(max.100): ");
	scanf("%d",&ar);
	printf("Enter no. of columns of MatrixA(max.100): ");
	scanf("%d",&ac);

	ma=inputmat(ar,ac);

	printf("\n\n\n\t\t\t***** Enter Matrix B *****\n\n");

	printf("Enter no. of rows of MatrixB(max.100): ");
	scanf("%d",&br);
	printf("Enter no. of columns of MatrixB(max.100): ");
	scanf("%d",&bc);

	mb=inputmat(br,bc);

	printf("\n\t\t1. Addition");
	printf("\n\t\t2. Subtraction");
	printf("\n\t\t3. Multiplication");
	printf("\n\t\t4. Determinant");
	printf("\n\t\t5. Inverse");
	printf("\n\n\tSelect your choice#:");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
			if((ar!=br)||(ac!=bc))
				printf("\n\t\t A & B are not conformable for addition.");
			else
			{
				mc=addmatr(ma,mb,ar,ac);
				prntmat(mc,ar,ac);
			}
			break;
		case 2:
			if((ar!=br)||(ac!=bc))
				printf("\n\t\t A & B are not conformable for subtraction.");
			else
			{
				mc=submatr(ma,mb,ar,ac);
				prntmat(mc,ar,ac);
			}
			break;
		case 3:
			if(ac!=br)
				printf("\n\t\t A & B are not conformable for multiplication.");
			else
			{
				mc=multmatr(ma,mb,ar,ac,bc);
				prntmat(mc,ar,bc);
			}
			break;
		case 4:
			if(ac!=ar)
				printf("\nMatrix A is not a square matrix. So determinant is not possible.");
			else
			{
				det=detrmin(ma,ar);
				printf("\nDeterminant of A is: %ld",det);
			}
			if(bc!=br)
				printf("\nMatrix B is not a square matrix. So determinant is not possible.");
			else
			{
				det=detrmin(mb,br);
				printf("\nDeterminant of B is: %ld",det);
			}
			break;

		case 5:
			if(ac!=ar)
				printf("\nMatrix A is not a square matrix. So inverse is not possible.");
			else
			{
				det=detrmin(ma,ar);
				if(det==0)
				{
					printf("\nDeterminant is zero. So A inverse is not possible.");
					break;
				}
				mc=invmat(ma,ar);
				printf("\nInverse of matrix A is: ");
				prntmat(mc,ar,ar);
			}
			if(bc!=br)
				printf("\nMatrix B is not a square matrix. So inverse is not possible.");
			else
			{
				det=detrmin(mb,br);
				if(det==0)
				{
					printf("\nDeterminant is zero. So B inverse is not possible.");
					break;
				}
				mc=invmat(mb,br);
				printf("\nInverse of matrix B is: ");
				prntmat(mc,br,br);
			}
			break;

		case 0:
			exit(0);
		default:
			printf("\nInvalid choice.");
	}


	getch();
}

float** addmatr(float **a,float **b,int row,int col)
{
	int i,j;
	float **result;
	result=new float*;
	for(i=0;i<row;i++)
		result[i]=new float[col];

	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			result[i][j]=a[i][j]+b[i][j];

	return result;
}
