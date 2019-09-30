#include<bits/stdc++.h>
using namespace std;

#define fr freopen("input.txt","r",stdin)
#define fw freopen("output.txt","w",stdout)
#define MOD 1000000007

typedef long long int ll ;
vector< pair<int,int> > V ;

// min no of coins required    
int minCoins(int coins[], int m, int V) 
{ 
  int table[V+1] ; 
  table[0]=0 ; 
  for(int i=1; i<=V; i++) 
  { table[i] = INT_MAX ; } 
  for(int i=1; i<=V; i++) 
  { 
    for(int j=0; j<m; j++) 
    {  
      if(i>=coins[j]) 
      { 
        int sub_res = table[i-coins[j]] ; 
        if(sub_res!=INT_MAX && sub_res+1<table[i]) 
        { table[i] = sub_res+1 ; } 
      }
    }  
  } 
  return table[V] ; 
} 


// min no of ways
int count(int S[], int m, int n)  
{  
  int i,j,x,y ; 
  int table[n+1][m] ; 
  for(i=0;i<m;i++) 
  { table[0][i]=1 ; } 
  for(i=1;i<n+1;i++) 
  { 
    for(j=0;j<m;j++) 
    { 
      x = (i>=S[j]) ? table[i-S[j]][j] : 0 ; 
      y = (j>=1) ? table[i][j-1] : 0 ; 
      table[i][j] = x+y ; 
    } 
  } 
  return table[n][m-1] ; 
} 

int main()
{
	int a,t ;
	cin >> t ;
	for(a=0;a<t;a++)
	{
	  int i,j,n,m,z ;
	  cin >> m >> n ;
	  int A[n] ;
    for(i=0;i<n;i++)
	  { cin >> A[i] ; }
	  sort(A, A+n) ;
	  z = count(A,n,m) ;
	  cout << z << endl ;
	}
	//code
	return 0;
}