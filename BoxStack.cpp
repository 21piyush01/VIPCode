#include<bits/stdc++.h>
using namespace std;

int maxHeight(int height[], int width[], int length[], int n) ;

int main()
{
	int t ;
	cin >> t ;
	while(t--)
    {
	   int n ;
	   cin >> n ;
       int A[1000], B[1000], C[10001] ;
	   for(int i=0;i<n;i++)
       {
	   	  int a, b, c ;
		  cin >> a >> b >> c ;
		  A[i]=a, B[i]=b, C[i]=c;
	   }
	   cout << maxHeight(A,B,C,n) << endl ;
    }
} 

bool compare1(pair< pair<int, int>, int > a, pair< pair<int, int>, int > b)
{ return (a.first.second*a.second > b.first.second*b.second) ; }

int maxHeight(int h[],int w[],int l[],int n)
{
    int i,j,k,x,y,z=-1 ;
    vector< pair <pair <int, int>, int> > V ;
    for(i=0;i<n;i++)
    { 
        int a,b,c ;
        a = h[i] ;
        b = min(w[i],l[i]) ;
        c = max(w[i],l[i]) ;
        V.push_back(make_pair(make_pair(a,b),c)) ;
        a = w[i] ;
        b = min(h[i],l[i]) ;
        c = max(h[i],l[i]) ;
        V.push_back(make_pair(make_pair(a,b),c)) ;
        a = l[i] ;
        b = min(w[i],h[i]) ;
        c = max(w[i],h[i]) ;
        V.push_back(make_pair(make_pair(a,b),c)) ;
    }
    sort(V.begin(), V.end(), compare1) ;
    int DP[3*n] ;
    for(i=0;i<3*n;i++)
    { DP[i] = V[i].first.first ; }
    for(i=1;i<3*n;i++)
    {
        for(j=0;j<i;j++)
        {
            if( (V[j].first.second>V[i].first.second) && (V[j].second>V[i].second) )
            { DP[i] = max(DP[i], DP[j]+V[i].first.first) ; }
        }
        z = max(z,DP[i]) ;
    }
    return z ;
}