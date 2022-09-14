#include<iostream>
#include<cmath>

using namespace std;
double f(double x){
    return pow(x,2)-x-2;
}
int main(){
    double a,b,x,T=pow(10,-6);
    cout<<"enter the value of a and b"<<endl;
    cin>>a>>b;
    do{
   if((f(a)*f(b))<0)
	{ 
        x=(a*f(b)-b*f(a) )/(f(b)-f(a));
         if (f(x)*f(b)<0) {	
            a=0.5*x;
          }
        else if(f(x)*f(a)<0){
        b=0.5*x;
         }
        
		  }
     
     else
     {
     	cout<<"no solution";
     	return 0;
	 }
}
while (fabs(b-a)<=T );
 cout<<x<<endl;
    return 0;
}
