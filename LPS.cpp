#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define MOD 1000000007
#define MAX 1000003

int LPSubsequence(string s)
{
    int i,j,k, n = s.size() ;
    int L[n][n] ;
    for(i=0;i<n;i++)
    { L[i][i]=1 ; }    
    for(k=2;k<=n;k++)
    {
       for(i=0;i<n-k+1;i++)
       {
          j = i+k-1 ;
          if(s[i]==s[j] && k==2)
          { L[i][j]=2 ; }
          else if(s[i]==s[j])
          { L[i][j] = L[i+1][j-1]+2 ; }
          else
          { L[i][j] = max(L[i][j-1], L[i+1][j]) ; }  
       } 
    }    
    return L[0][n-1] ;
}

// LPSubstring => O(n*n)
// Manacher's Algo for LPSubstring => O(n)
void findLongestPalindromicString(string s) 
{ 
    int N = s.size() ; 
    if(N==0) 
    { return ; } 
    N = 2*N + 1 ;  
    int L[N] ;  
    L[0]=0, L[1]=1 ; 
    int C=1, R=2, i=0 ;
    int iMirror ;  
    int maxLPSLength=0 ; 
    int maxLPSCenterPosition=0 ; 
    int start=-1, end=-1, diff=-1 ; 
    for(i=2;i<N;i++)  
    { 
        iMirror = 2*C-i ; 
        L[i] = 0 ; 
        diff = R-i ; 
        if(diff>0) 
        { L[i] = min(L[iMirror], diff) ; } 
        while( ((i+L[i])<N && (i-L[i])>0) && (((i+L[i]+1)%2==0) || (s[(i+L[i]+1)/2]==s[(i-L[i]-1)/2])) ) 
        { L[i]++ ; } 
        if(L[i]>maxLPSLength) 
        { 
            maxLPSLength = L[i] ; 
            maxLPSCenterPosition = i ; 
        } 
        if(i+L[i]>R)  
        { C=i, R=i+L[i] ;  } 
    } 
    start = (maxLPSCenterPosition-maxLPSLength)/2 ; 
    end = start+maxLPSLength-1 ; 
    cout << "LPS of string is: " ; 
    for(i=start;i<=end;i++) 
    { cout << s[i] ; } 
    cout << "\n" ; 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    string s ;
    cin >> s ;
    //int res = LPSubsequence(s) ;
    cout << LPSubsequence(s) << " " << findLongestPalindromicString(s) << endl ;
    return 0 ;    
} 