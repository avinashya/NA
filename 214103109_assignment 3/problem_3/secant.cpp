#include <iostream>
#include<cmath>
using namespace std;
#define xe 0.56714329040978387299997
long double f(long double x){
    return (x*exp(x)-1);
}
int main()
{
    int i,n=1000;
    long double x[5000],conv_rate,cov_ratio,previous=1,current;
	double T =pow(10,-10);
    cout<<"enter the value of x[0] and x[1]"<<endl;
cin>>x[0]>>x[1];

for(i=1;i<=n;i++){
    x[i+1]=(x[i-1]*f(x[i])-f(x[i-1])*x[i])/(f(x[i])-f(x[i-1]));
    x[i+1]=fabs(x[i+1]);
if(fabs(x[i+1]-x[i])<T)   
break;
current=fabs(x[i+1]-xe)/fabs(x[i]-xe);
conv_rate=log(current)/log(previous);
previous=current;
cout<<x[i+1]<<" "<<conv_rate<<endl;
}

    return 0;
}
