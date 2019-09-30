#include <bits/stdc++.h>
using namespace std ;

#define fr freopen("input.txt","r",stdin)
#define fw freopen("output.txt","w",stdout)
#define MOD 1000000007

typedef long long int ll ;
vector< pair<int,int> > V ;
    
int main()
{
  ios_base::sync_with_stdio(false) ;
  cin.tie(NULL) ;   
  string s ; char c ;
  ll n,m,i,j,k,x=0,y=0,z=0 ;
  cin >> n >> m ;
  vector<int> v[2000+10] ;
  int dis[1000+10] ;
  for(i=0;i<m+2;i++)
  {
    v[i].clear() ;
    dis[i]=2e9 ;
  }
  for(i=0;i<m;i++)
  {
    cin >> from >> next >> weight ;
    v[i].push_back(from) ;
    v[i].push_back(next) ;
    v[i].push_back(weight) ;
  }
  dis[0]=0 ;
  for(i=0;i<n-1;i++)
  {
    int j=0 ;
    while(v[j].size()!=0)
    {
      if(dis[v[j][0]]+v[j][2]<dis[v[j][1]])
      { dis[v[j][1]] = dis[v[j][0]]+v[j][2] ; }
      j++ ;
    }
  }

  return 0 ;	
}