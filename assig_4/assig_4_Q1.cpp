#include <iostream>
#include<time.h>
#include<cmath>
#include<fstream>
using namespace std;
int main()
{
    int i,j,k,l,n=50;
    double m[500][500],b[100],x[100];
   ofstream avi;
   avi.open("output.txt");
    for(l=0;l<n;l++){
        
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j){
            m[i][i]=5;}
            else if (j==i+1){
            m[i][j]=-1;}
            else if (j==i-1){
             m[i][j]=-1;}
             else 
             m[i][j]=0;
             //cout<<" "<<m[i][j];
        }
          b[i]=(i+l-1)%n+1;
         //cout<<b[i][1];
     //cout<<endl;
    }
     avi<<"x"<<l+1<<" = [";
    for(k=1;k<=n-1;k++){
        for (i=k+1;i<=k+1;i++){
            for(j=k+1;j<=k+1;j++){                                                                                                                                                                                                                                      
                m[i][j]=m[i][j]-((m[k][j]/m[k][k])*m[i][k]);
                       
            }
            m[i][i-1]=0;
    b[i]=b[i]-(m[k][k+1]/m[k][k])*b[k];
        }
    }
     x[n]=b[n]/m[n][n];
     for(k=n-1;k>=1;k--){
         x[k]=(b[k]-m[k][k+1]*x[k+1])/m[k][k];
     }
   for(i=1;i<=n;i++){
       for(j=1;j<=n;j++){
    
             // cout<<" "<<m[i][j];
       }
  cout<<x[i]<<endl<<" ";
          
   }
   avi<<" ]";
   avi<<endl;
   avi<<endl;
    }
    cout<<" check the output file";
    return 0;
}
