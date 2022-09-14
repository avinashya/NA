#include <iostream>
#include<cmath>
#include<cstdlib>
#include<time.h>

using namespace std;

int main()
{ 
int n=10;
  int i,j,a[100][100], trace=0;
 
 srand(time(0));
  for(i=0;i<n;i++){
      for(j=0;j<n;j++){
          a[i][j]=rand()%10;
      }
  }
      cout<<"the random matrix of 10 x 10 is"<<endl;
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
      
          cout<<a[i][j]<<"\t";
      }
      cout<<endl;
    }
    cout<<"the trace of the matrix is";
    for(i=0; i<10;i++){
        
            trace= trace+a[i][i];
    }
       cout<<" "<< trace<<endl;
    return 0;
}
