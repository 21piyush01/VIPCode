#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,t ;
	cin >> t ;
	for(a=0;a<t;a++)
	{
	    int i,j,k,l,n,m,x,y,z ;
	    cin >> n >> k ;
	    int DP[n+1][k+1] ;
	    for(i=1;i<=n;i++)
	    { DP[i][0]=0, DP[i][1]=1 ; }
	    for(j=1;j<=k;j++)
	    { DP[1][j]=j ; }
	    for(i=2;i<=n;i++)
	    {
	        for(j=2;j<=k;j++)
	        {
	            DP[i][j]=INT_MAX ;
	            for(l=1;l<=j;l++)
	            {
	                z = 1+max(DP[i-1][l-1], DP[i][j-l]) ;
	                if(z<DP[i][j])
	                { DP[i][j]=z ; }
	            }
	        }
	    }
	    cout << DP[n][k] << endl ;
	}
	return 0 ;
}