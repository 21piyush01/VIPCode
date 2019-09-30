#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
#define MOD 1000000007
#define MAX 1000003

int LCSubsequence(string a, string b)
{
  int i,j, m = a.size(), n = b.size() ;
  int L[m+1][n+1] ;
  for(i=0;i<=m;i++) 
  {
  	for(j=0;j<=n;j++)
  	{
  	   if(i==0 || j==0)
  	   { L[i][j]=0 ; }
  	   else if(a[i-1]==b[j-1])
  	   { L[i][j] = L[i-1][j-1]+1 ; }
  	   else
  	   { L[i][j] = max(L[i-1][j], L[i][j-1]) ; } 
  	}	
  }
  return L[m][n] ;	
}

int LCSubstring(string a, string b)
{
  int i,j, m = a.size(), n = b.size() ;
  int L[m+1][n+1] ;
  for(i=0;i<=m;i++) 
  {
    for(j=0;j<=n;j++)
    {
       if(i==0 || j==0)
       { L[i][j]=0 ; }
       else if(a[i-1]!=b[j-1])
       { L[i][j]=0 ; }
       else
       { L[i][j]= L[i-1][j-1]+1 ; } 
    } 
  }
  //return max array element ;  
}

int main()
{
  ios_base::sync_with_stdio(false) ;
  cin.tie(NULL) ;
  string a,b ;
  cin >> a >> b ;
  //int res = LCS(a,b) ;
  cout << LCSubsequence(a,b) << " " << LCSubstring(a,b) << endl ;
  return 0 ;
}