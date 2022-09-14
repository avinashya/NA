 #include<iostream>
using namespace std;

class complex_number{
    public:
    int a,b,c,d;
    int i;
     void setData( int a1 , int b1 , int c1 , int d1){
    a=a1;
    b=b1;
    c=c1;
    d=d1;
     }
     
         void sum(){
         int cc1,cc2,real,img;
         cc1=a+i*b;
         cc2=c+i*d;
         real=a+c;
         img= b+d;
         cout<<"sum is "<<real<<"+" <<img<<"i"<<endl;
     }
       void substraction(){
         int ccc1,ccc2,real,img;
         ccc1=a+i*b;
         ccc2=c+i*d;
      real= a-c;
      img= b-d;
      
       cout<<"substraction  "<<real<<"+("<<img<<")i"<<endl;
       }
           void multiplication(){
         int cccc1,cccc2,real , img;
         cccc1=a+i*b;
         cccc2=c+i*d;
         real=a*c-b*d;
         img = a*d+b*c;
         cout<<"mutiplication is"<<real<<"+"<<img<<"i"<<endl;
       }
       void conjugate(){
           int z,z1;
           z=a+i*b;
           z1=a-i*b;
           cout<<a<<"-"<<b<<"i";
       }
    
};
 
int main()
{
    complex_number avi;
    avi.setData(1,4,8,10);
    avi.sum();
    avi.substraction();
    avi.multiplication();
    avi.conjugate();

    return 0;
}
