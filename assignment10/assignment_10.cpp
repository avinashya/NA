#include <iostream>
#include<cmath>
#include<stdlib.h>
#include<fstream>
 #define n 100 //change value of n for different n
using namespace std;
double a(double h,double t){
return 1/(h*h)+cos(t)/(2*h);
}
double b(double h,double t){
return -2/(h*h)-sin(t);
}
double c(double h,double t){
return 1/(h*h)-cos(t)/(2*h);
}

double d(double t){
return -exp(t);
}
using namespace std;

double A[n+1][n+1],B[n+1],h,x[n+1];

int main()
{ 
ofstream  avi("output_n_100.txt");
int i,j,k ;
double tmin=0,tmax=1;
 
 h=(tmax-tmin)/n;
 for(i=0;i<n;i++){
 for(j=0;j<n;j++){
 if(i==j)
 A[i][j]=b(h,tmin);
 else if(i-j==1)

 A[i][j]=a(h,tmin);
 else if (j-i==1)
 A[i][j]=c(h,tmin);
 else
 A[i][j]=0;

 }
}
 for (i=1;i<n;i++){
 	if(i==n-1){
	 
 	B[i]=d(tmin)-c(h,tmin);}
 else
 B[i]=d(tmin);
tmin=tmin+h;

 }
 
 for(k=1;k<n;k++){
        for (i=k+1;i<=k+1;i++){
            for(j=k+1;j<=k+1;j++){                                                                                                                                                                                                                                      
                A[i][j]=A[i][j]-((A[k][j]/A[k][k])*A[i][k]);
                       
            }
            A[i][i-1]=0;
    B[i]=B[i]-(A[k][k+1]/A[k][k])*B[k];
        }
    }
     x[n-1]=B[n-1]/A[n-1][n-1];
     for(k=n-2;k>=0;k--){
         x[k]=(B[k]-A[k][k+1]*x[k+1])/A[k][k];
     }
       	tmin=0;
       	cout<<"t0  \t"<<"x0" <<endl;
       	 avi<<"t0  \t"<<"x0" <<endl;
   for(i=0;i<n;i++){
 
  cout<< tmin<<" \t"<<x[i]<<"\t"<<endl;
  
   avi<< tmin<<" \t"<<x[i]<<"\t"<<endl;
    tmin=tmin+h;
}
   cout<<endl;
   cout<<endl;
 
    return 0;
}
