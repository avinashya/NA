
#include <iostream>
#include<cmath>
#define xe 0.56714329040978387299997
using namespace std;
double f(double x){
    return (x*exp(x)-1);
}
double df(double x){
    return (exp(x)+x*exp(x));
}
int main()
{
    double x0,x1,t=pow(10,-4),current,previous=1,conv_rate;
    int i ;
    cout<<"enter the initial guess value of x"<<endl;
    cin>>x0;
    do{
    	x1=x0-(f(x0)/df(x0));
    	if(fabs(x1-x0)<t)
    	break;
    	
    current=fabs(x1-xe)/fabs(x0-xe);
conv_rate=log(current)/log(previous);
previous=current;
x0=x1;
cout<<x1<<" "<<conv_rate<<endl;
}
    
	
	while(true);
   
      cout<<x1<<endl;
    return 0;
}
