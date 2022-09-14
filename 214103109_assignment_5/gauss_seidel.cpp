 #include<iostream>
#include<cmath>	
#include<stdlib.h>
#include<fstream>
#define tolerance pow(10,-6)
#define itMax 1000
using namespace std;

int main()
{
double a[6][6]={0,0,0,0,0,0,0,0.2,0.1,1,1,0,0,0.1,4,-1,1,-1,0,1,-1,60,0,-2,0,1,1,0,8,4,0,0,-1,-2,4,700},b[6]={0,1,2,3,4,5},x[6],error,t,r[6];
int i,j,k,n=5,p,q,count=0;

for(i=1;i<=n;i++)//initial guess
{
	x[i]=0 ;
}
 
double NUM,maxi,temp;
int index;
	do{
 	for(i=1;i<=n;i++)
		{
		 
			NUM=b[i];
			for(j=1;j<=n;j++)
			{
				if(j!=i)
				{
					NUM=NUM-a[i][j]*x[j];
				}
				
			}
			x[i]=NUM/a[i][i];
		}
		
		error=0;
		for(i=1;i<=n;i++)
		{
			NUM=b[i];
			for(j=1;j<=n;j++)
			{
				NUM=NUM-a[i][j]*x[j];	
			}
			
			r[i]=NUM;
			error=error+r[i]*r[i];
		}
		
		error=sqrt(error);
		k=k+1;
		count=count+1;
	}while(k<itMax && error>tolerance);

	for(i=1;i<=n;i++){
	cout<<x[i]<<endl;}
return 0;
}
