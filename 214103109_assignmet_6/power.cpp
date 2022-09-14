
#include <iostream>
#include<cmath>
#include<cstdlib>
#define itmax 5000
#define tolerance pow(10,-6)
using namespace std;


int main()
{
    double a[4][4]={5,4,1,1,4,5,1,1,1,1,4,2,1,1,2,4},x0[4]={1,3,-1,-2};
    int i,j,k=0,n=4;
    double sum,x1[4],xp,b[10],err=1;
    
     while(k<itmax)
     { 
    for(i=0;i<n;i++){
           sum=0;
        for(j=0;j<n;j++){
                 
            sum=sum+(a[i][j])*(x0[j]);
        }
        b[i]=sum;
                   //cout<<b[i]<<endl;
    }
    xp=0;
     for(i=0;i<n;i++){
         
         if(xp<b[i])
         xp=b[i];
     }
     for(i=0;i<n;i++){
    x1[i]=b[i]/xp;
 
    x0[i]=x1[i];
    
     }
    
       k=k+1;
    }
    cout<<" The eigen vector is"<<endl;
      for(i=0;i<n;i++){
           cout <<x1[i]<< endl;
           
      }
cout<<"The maximum eigen value is  "<<xp<<endl;

    return 0;
}
