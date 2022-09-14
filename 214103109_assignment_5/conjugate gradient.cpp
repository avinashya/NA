#include<iostream>
#include<cmath>	
#include<stdlib.h>
#include<fstream>
#define tolerance pow(10,-6)
#define itMax 1000
using namespace std;

int main()
{
    int i,j,n=5,count=0;
    double a[5][5]={0.2,0.1,1,1,0,0.1,4,-1,1,-1,1,-1,60,0,-2,1,1,0,8,4,0,-1,-2,4,700},b[5]={1,2,3,4,5},dnext[50];
    double xpre[50]={0,0,0,0,0},err=1,diff=1,dpre[50],p=0,q[50],t=0,rpre[50],rnext[50],alpha=0,xnext[50],u=0,v=0,beta=0,m[50],error;
    for(i=0;i<n;i++){
    	dpre[i]=0;
        for(j=0;j<n;j++){
            dpre[i]= a[i][j]*xpre[j];
          
        }
        dpre[i]=b[i]-dpre[i];
        rpre[i]=dpre[i];
    }
    for(i=0;i<n;i++){
        p=p+rpre[i]*rpre[i];
        for(j=0;j<n;j++){
           q[i]=a[i][j]*dpre[j] ;
           
        }
        t=t+dpre[i]*q[i];
        
    }
     alpha=p/t;
    
    while(err>tolerance && diff>tolerance)
        {
       	err=0;
		   diff=0;
       	//step2
        for(i=0;i<n;i++){
               xnext[i]=xpre[i]+alpha*dpre[i];
			   }
			   
			   //step3
               for(i=0;i<n;i++){
               	
               	m[i]=0;
                 for(j=0;j<n;j++){
                  m[i]=m[i]+alpha*a[i][j]*dpre[j];
                  
                 }
                  rnext[i]=rpre[i]-m[i];
              }
              
              //step4
        for(i=0;i<n;i++){
        	
        	         u=u + rnext[i]*rnext[i];
                 v=v + dpre[i]*rpre[i];
		}
        
        beta=u/v;
        
       // step5
        for(i=0;i<n;i++){
        	dnext[i]=0;
            dnext[i]=rnext[i]+beta*dpre[i];}
            
         for(i=0;i<n;i++){   
           err= err + (xnext[i]-xpre[i])*(xnext[i]-xpre[i]);
           diff= diff + (dnext[i]-dpre[i])*(dnext[i]-dpre[i]);

            xpre[i]=xnext[i];
           rpre[i]=rnext[i];
            dpre[i]=dnext[i];
        }
        err =sqrt(err);
        diff=sqrt(diff);
        
       count=(count+1); 
    }
    for(i=0;i<n;i++){
   cout<<xnext[i]<<endl;
    }

    return 0;
}
