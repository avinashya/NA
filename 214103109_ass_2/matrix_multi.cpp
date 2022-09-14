
#include <iostream>
#include<cmath>
#include<iomanip>
#include<stdlib.h>

using namespace std;
int main()
{
    int i,j,k,m,n,o,p;
    
    cout<<"enter the dimension m x n of first matrix"<<endl;
    cin>>m>>n;
    cout<<"enter the dimension o x p of second matrix"<<endl;
    cin>>o>>p;
    if(o!=n){
    	cout<<"Matrix multiplication not possible";
    	return 0;
	}
    double matrix1[m][n],matrix2[o][p],resultant_matrix[m][p];
    cout<<"enter the element of first matrix"<<endl;
    
 	for(i=0;i<m;i++){   
     	for(j=0;j<n;j++){
        	cin>>matrix1[i][j];
     	}
 	}
 	
 	cout<<"enter the element of second matrix"<<endl;
 	for(i=0;i<n;i++){
     	for(j=0;j<p;j++){
         	cin>>matrix2[i][j];
     	}
 	}
 	cout<<"resultant_matrix  is"<<endl;
  
 	for (i=0;i<m;i++){
     	for(j=0;j<p;j++){
         	resultant_matrix[i][j]=0;
         		for(k=0;k<n;k++){
            		resultant_matrix[i][j]=resultant_matrix[i][j] + ( matrix1[i][k] * matrix2[k][j]);
         		}
     			cout<<resultant_matrix[i][j]<<" ";

 		}
     	cout<<endl; 
 	}
	return 0;
}
 
