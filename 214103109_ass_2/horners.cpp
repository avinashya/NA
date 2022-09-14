#include<iostream>
#include<iomanip>
#include<math.h>
#include<fstream>
using namespace std;

long double sine(double x, int n = 50){ // can change the value of n 
    long double fact_inv = 1;
    int sign = 1;
    double a[n+1],b[n+1];
    
    int p = x/(4*acos(0.0));
    x = x - 4*acos(0.0)*p;
    
	a[0] = 0;
    for(int i=1;i<=n;++i){
        fact_inv /= i;
        if(i%2!=0){
        	a[i] = sign*fact_inv;
        	sign = -1*sign;
		}
		else{
			a[i] = 0;
		}
		
    }
    int k =n;
    b[k] = a[k];
	while(k>=0){
		b[k-1] = a[k-1] + x* b[k];
		k = k - 1;
	}
	
    return b[0];	
}

int main(){
    double x;
    cout<<"enter the value of x"<<endl;
    cin>>x;
    cout<<"sin value using horner's algo: "<<sine(x)<<endl<<"Actual value of sin(x): "<<sin(x);

    return 0;
}
