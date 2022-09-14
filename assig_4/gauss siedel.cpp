 #include<iostream>
#include<cmath>	
#include<stdlib.h>
#include<fstream>
#define tol pow(10,6)
#define itmax 1000
using namespace std;
long double a[101][101],b[101];
int main()
{
long double error,t,r[101],x[101];  
int i,j,k,n=100,p,q,index;

long double LHS,maximum,temp;

ifstream avi;
avi.open("dataA.txt");
ifstream avii;
avii.open("dataB.txt");

for(i=0;i<n;i++)//initial guess
{
	x[i]=0;
}


for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		avi>>t;
		a[i][j]=t;
	}
	avii>>t;
	b[i]=t;
}

	do{
	
		for(i=0;i<n;i++)
		{
			
			//PARTIAL PIVOTING
			maximum=fabs(a[i][i]);
			for(p=i+1;p<n;p++)
			{
				if( fabs(a[p][i]) >maximum)
				{
					maximum=fabs(a[p][i]);
					index=p;
				}
			}
			
			if(maximum!=fabs(a[i][i]))
			{
				for(q=0;q<n;q++)
				{
					temp=a[i][q];
					a[i][q]=a[index][q];
					a[index][q]=temp;	
				}
				temp=b[i];
				b[i]=b[index];
				b[index]=temp;
			}
			//END OF PIVOTING
 	
			LHS=0;
			for(j=0;j<n;j++)
			{
				if(j!=i)
				{
					LHS=LHS+a[i][j]*x[j];
				}
				
			}
			x[i]=(b[i]-LHS)/a[i][i];
		}
		
		error=0;
		for(i=0;i<n;i++)
		{
			LHS=0;
			for(j=0;j<n;j++)
			{
				LHS=LHS+a[i][j]*x[j];	
			}
			
			r[i]=b[i]-LHS;
		error=error+r[i]*r[i];
		}
		
		error=sqrt(error);
		k=k+1;
		
	}while(k<itmax && error>tol);

	for(i=0;i<n;i++)
	cout<<x[i]<<endl;
return 0;
}
