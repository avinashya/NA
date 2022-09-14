#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<fstream>
using namespace std;
double deriv(double x){
	return -2*pow(x,3)+12*pow(x,2)-20*x+8.5;
}
double fun(double x){
	return (-0.5*pow(x,4)+4*pow(x,3)-10*pow(x,2)+8.5*x+1);
}
double euler( double h,double x0,double y0,int a){
double x[50],y[50],	b=4;
int n,i;
	n=(b-x0)/h;
	x[0]=x0;y[0]=y0;
	for(i=0;i<=n;i++){
 y[i+1]=y[i]+h*deriv(x[i]);
 x[i+1]=x[i]+h; 
}
return y[a];
}
double analytical(double h,double x0,double y0,int a){
	double x[50],y[50],b=4;
	int i,n;
	y[0]=y0;
	x[0]=x0;
	n=(b-x0)/h;
	for(i=0;i<=n;i++){
	y[i]= fun(x[i]);
	x[i+1]=x[i]+h;
}
return y[a];
}
double RK4(double h,double x0,double y0,int a ){
		double k1,k2,k3,k4,b=4,x[50],y[50];
		int i,n;
		x[0]=x0;
		y[0]=y0;
	n=(b-x0)/h;
	for(i=0;i< n;i++){
	k1=h*deriv(x[i]);
	k2=h*deriv(x[i]+h/2);
	k3=h*deriv(x[i]+h/2);
	k4=h*deriv(x[i]+h);
	y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6;
	x[i+1]=x[i]+h;
	}
	return y[a];
}
 int main(){
 
 	double x0=0,h, k[3]={ 0.5,0.25,0.1},x; 
 	int a,n;
 	int z;
 	ofstream avi("output.txt");
 	 
 	for(z=0;z<3;z++){
 
	 h=k[z];
	 	n=4/h;
	 cout<<"h="<<h<<endl;
	   avi<<"h="<<h<<endl;
	 cout<<"x\t"<<"euler\t"<<"RK4\t"<<"analytical"<<endl;
	  avi<<"x\t"<<"euler\t"<<"RK4\t"<<"analytical"<<endl;
	 x=x0;
 	for(a=0;a<=n;a++){
 	 cout<<x<<"\t";
 	 avi<<x<<"\t";
  cout<<euler(h,x0,1,a)<<"\t";
   avi<<euler(h,x0,1,a)<<"\t";
  	cout<<RK4(h,x0,1,a)<<"\t";
  	 avi<<RK4(h,x0,1,a)<<"\t";
 cout<<analytical(h,x0,1,a)<<endl;
   avi<<analytical(h,x0,1,a)<<endl;
 x=x+h;
 
 }
 cout<<"\n\n";
  
}
 return 0;
}
 
 
