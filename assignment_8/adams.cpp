#include<iostream>  
#include<cmath> 
#include<stdlib.h> 
#include<fstream>
using namespace std;
double adams(double t) {
return (2-2*t+4*pow(t,2)-4*pow(t,3)-4*pow(t,4));
}
int main(){

int i,n;
double y0=1,t0=0,tmax=1,h=0.002;
n=(tmax-t0)/h;
ofstream avi("adams.txt");
for(i=0;i<=n;i++){
		cout<<t0<<" \t"<<y0<<endl;
		avi<<t0<<" \t"<<y0<<endl;
	y0=y0+h*(55*adams(t0)-59*adams(t0-h)+37*adams(t0-2*h)-9*adams(t0-3*h))/24;
	t0=t0+h;
}
return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
