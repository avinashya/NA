#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<fstream>
using namespace std;  
double fun1(double z,double y, double t){
	return (-4*z+2*y+2*pow(t,3)-10);
} 
double fun2(double z){
	return z;
} 
int main()
{
int i,n;
ofstream avi("output_h=0.005.txt");
double tmax=1,t0=0,y0=0,k1,k2,k3,k4,l1,l2,l3,l4,h=0.005,z0=1;
n=(tmax-t0)/h;
for(i=0;i<=n;i++){
	    avi<<t0<<"  \t"<<y0<<endl;
	     cout<<t0<<"  \t"<<y0<<endl;
    k1=h*fun2(z0);
    l1=h*fun1(z0,y0,t0);
    k2=h*fun2(z0+l1/2);
    l2=h*fun1(z0+l1/2,y0+k1/2,t0+h/2);
    k3=h*fun2(z0+l2/2);
    l3=h*fun1(z0+l2/2,y0+k2/2,t0+h/2);
    k3=h*fun2(z0+l3/2);
    l4=h*fun1(z0+l3,y0+k3,t0+h);
    k4=h*fun2(z0+l3);
    z0=z0+(l1+2*l2+2*l3+l4)/6;
    y0=y0+(k1+2*k2+2*k3+k4)/6;
    t0=t0+h;

}
return 0;
}
