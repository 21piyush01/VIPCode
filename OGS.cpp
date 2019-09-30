#include<bits/stdc++.h>
using namespace std;

const int MAX=100 ; 
int DP[MAX][MAX] ; 
  
int oSRec(int A[], int i, int j, int m) 
{ 
    if(j==i+1) 
    { return max(A[i], A[j]) ; } 
    if(DP[i][j]!=-1) 
    { return DP[i][j] ; } 
    DP[i][j] = max((m-oSRec(A,i+1,j,m-A[i])),(m-oSRec(A,i,j-1,m-A[j]))) ; 
    return DP[i][j] ; 
} 
  
int optimalStrategyOfGame(int A[], int n) 
{ 
    int i,j,m=0 ; 
    for(i=0;i<n;i++)
    { m+=A[i] ; }
    for(i=0;i<100;i++) 
    {
        for(j=0;j<100;j++) 
        { DP[i][j]=-1 ; } 
    }
    return oSRec(A,0,n-1,m) ; 
} 

int main()
{
	int a,t ;
	cin >> t ;
	for(a=0;a<t;a++)
	{
	    int i,j,k,l,n,m=0,x,y,z ;
	    cin >> n ;
	    int A[n] ;
	    for(i=0;i<n;i++)
	    { cin >> A[i] ; }
	    cout << optimalStrategyOfGame(A,n) << endl ;
	}
	return 0;
}