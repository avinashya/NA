#include<iostream>
#include<iomanip>
#include<math.h>
#include<fstream>
using namespace std;

long double sine(double x, int n = 100){
    long double fact_inv = 1;
    int sign = 1;
    long double sum = 0, xn = 1;
	
	// x = 2*pi*k + alpha where 0<=alpha<2*pi
    long long int k = x/(4*acos(0.0)); // calculating k 
    x=x-4*acos(0.0)*k; // calculating alpha
 	int a=2*n-1; 	// converting number of term into highest power of x in taylor series of sine
 	
    for(int i=1;i<=a;++i){
        fact_inv /= i; // storing 1/n! of taylor series
        xn *= x;		// storing x^n
        
        if(i%2!=0){		// when i is odd series term need to add
            sum += (sign*xn*fact_inv);		// sum of taylor series upto ith power of x;
            sign *= -1;			// to change sign of every alternate term
            
        }
        if(xn*fact_inv == 0){		// if term became 0 i.e < precision of system it stops
            break;
        }
    }
    return sum;	// return sine of x calculated with taylor series upto nth term
}

int main(){
    double x;
    ofstream avi;
    avi.open ("realtive_error.txt ");
	cout<<"enter the value of x"<<endl;
    cin>>x;

    for(int i=1;i<=50;i++){
	
    cout<<"relative error at n= "<<i<< "  is " <<fabs((sin(x)-sine(x,i))/sin(x))<<endl; // printing relative error of my calculated value and exact value
    avi<<i<<"\t"<<fabs((sin(x)-sine(x,i))/sin(x))<<endl;
    
}
	avi.close();

    return 0;
}
