#include <iostream>
#include<stdlib.h>
#include<cmath>
#define itmax 5000
using namespace std;
int main()
{
     double a[4][4]={5,4,1,1,4,5,1,1,1,1,4,2,1,1,2,4},x0[4]={1,1,1,1},I[4][4],c=0.01,b[4][4],aug[4][8],r,m,d[4],xp,x1[4],p[4][4];
  double t[4],u,v;
 int i,j,k,n=4,count=0;
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        I[i][j]=0;
    }
    I[i][i]=1;
}
 
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        b[i][j]=a[i][j]-c*I[i][j];
    }
}
/*for(i=0;i<n;i++){
    for(j=0;j<n;j++){
    cout<<b[i][j]<<"\t";
    }
    cout<<endl;
}*/
for(i=0;i<n;i++){   // augumented matrix
    for(j=0;j<8;j++){
        if(j<n)
        aug[i][j]=b[i][j];
       else if((j-i)==4)
       aug[i][j]=1;
       else 
       aug[i][j]=0;
    }
}
 /*for(i=0;i<n;i++){
    for(j=0;j<8;j++){
    cout<<aug[i][j]<<"\t";
    }
   cout<<endl;
}*/
for(i=0;i<n;i++){  // for inverse
	if (aug[i][i]==0)
	{
		cout<<" matrix is not invertible";
			exit(0);
	} 
    for(j=0;j<n;j++){
    	if(i!=j){
		
        r=aug[j][i]/aug[i][i];
        //cout<<r<<"\t";
        for(k=0;k<8;k++){
            aug[j][k]=aug[j][k]-r*aug[i][k];
   
        
    }
}
}
}
for(i=0;i<n;i++){
    for(j=4;j<8;j++){
    	aug[i][j]=aug[i][j]/aug[i][i];
    }
}
for(i=0;i<n;i++){
    for(j=0;j<4;j++){
    p[i][j]=aug[i][j+4];	
	}
}
 
/*for(i=0;i<n;i++){
    for(j=0;j<4;j++){
    cout<<p[i][j]<<"\t";
    }
    cout<<endl;
}*/

while(count<itmax){

for(i=0;i<n;i++){
	m=0;
	for(j=0;j<4;j++){
		m=m+p[i][j]*x0[j];
	}
	d[i]=m;
}
xp=0;
for(i=0;i<n;i++){
if(xp<d[i])
xp=d[i];
}
for(i=0;i<n;i++){
x1[i]=d[i]/xp;
x0[i]=x1[i];
}
count=count+1;
}
cout<<" The eigen vector is"<<endl;
for(i=0;i<n;i++){
	cout<<x1[i]<<endl;
}
cout<<"The minimum eigen value is  "<<xp;
    return 0;
}
