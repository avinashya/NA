
#include <iostream>
using namespace std;

int main()
{
     int a[100] ,i;
     cout<<"enter the first and second no. of series"<<endl;
     cin>>a[0]>>a[1] ;//enter the initial value 0 and 1
     
     for (i=0;i<=20;i++){
         a[i+2]=a[i]+a[i+1];
    
cout<<a[i]<<endl;
 }
    return 0;
}
