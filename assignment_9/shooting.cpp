#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<fstream>
#define tol pow(10,-5)
using namespace std;  
double fun1(double z,double y, double x){
	return (32+2*pow(x,3)-y*z)/8;
}
double fun2(double z){
	return z;
} 
double fun3(double t,double y,double si, double z){
	return (-z*si-y*t)/8;
} 
double fun4(double t){
	return t;
} 
double analytical(double x){
	return pow(x,2)+16/x;
}
int main()
{
int i,n=20;
 ofstream avi("output_assig_9.txt");
double xmax=3,x0=1,y0,k1,k2,k3,k4,l1,l2,l3,l4,h,z0,error,k11,l11,k22,l22,k33,l33,k44,l44,si0,t0,m=100,analy;
h=(xmax-x0)/n;
cout<<" X"<<" \t   Y"<<"\t analytical"<<endl;
avi<<" X"<<" \t   Y"<<"\t analytical"<<endl;
do
{ 
y0=17,error=0,si0=1,z0=m,t0=0,x0=1;

for(i=0;i<=n;i++){
  
    k1=h*fun2(z0);
    l1=h*fun1(z0,y0,x0);
    k2=h*fun2(z0+l1/2);
    l2=h*fun1(z0+l1/2,y0+k1/2,x0+h/2);
    k3=h*fun2(z0+l2/2);
    l3=h*fun1(z0+l2/2,y0+k2/2,x0+h/2);
    l4=h*fun1(z0+l3,y0+k3,x0+h);
    k4=h*fun2(z0+l3);
    z0=z0+(l1+2*l2+2*l3+l4)/6;
    y0=y0+(k1+2*k2+2*k3+k4)/6;
    
    k11=h*fun4(t0);
    l11=h*fun3(t0,y0,si0,z0);
    k22=h*fun4(t0+l11/2);
    l22=h*fun3(t0+l11/2,y0,si0+k11/2,z0);
    k33=h*fun4(t0+l22/2);
    l33=h*fun3(t0+l22/2,y0,si0+k22/2,z0);
    l44=h*fun3(t0+l33,y0,si0+k33,z0);
    k44=h*fun4(t0+l33);
    si0=si0+(k11+2*k22+2*k33+k44)/6;
    t0=t0+(l11+2*l22+2*l33+l44)/6;
             analy= analytical(x0);
      cout<<x0<<" \t"<<y0<<"\t   "<<analy<<endl;
         avi<<x0<<" \t"<<y0<<"\t   "<<analy<<endl;
        x0=x0+h;
        
}
error=(y0-14.3333);
m=m-error/si0; 

}
while(fabs(error)>tol);
cout<<"value of m = "<<m;
avi<<"value of m = "<<m;
return 0;
}

