#include <bits/stdc++.h>
using namespace std ;

#define fr freopen("input.txt","r",stdin)
#define fw freopen("output.txt","w",stdout)
#define SIZE 100000 + 1

vector < pair < int , int > > v[SIZE] ;   // each vertex has all the connected vertices with the edges weights
int dist[SIZE] ;
bool vis[SIZE] ;

void Dijkstra()
{                                                   // set the vertices distances as infinity
    memset(vis,false,sizeof(vis)) ;                 // set all vertex as unvisited
    dist[1]=0 ;
    multiset < pair < int , int > > s ;             // multiset do the job as a min-priority queue
    s.insert({0, 1}) ;                              // insert the source node with distance = 0
    while(!s.empty())
    {
        pair <int, int> p = *s.begin() ;            // pop the vertex with the minimum distance
        s.erase(s.begin()) ;
        int x=p.s, wei=p.f ;
        if( vis[x] ) continue;                      // check if the popped vertex is visited before
         vis[x]=true ;
        for(int i=0; i<v[x].size(); i++)
        {
            int e = v[x][i].f, int w=v[x][i].s ;
            if(dist[x]+w < dist[e])
            {                                       // check if the next vertex distance could be minimized
                dist[e] = dist[x]+w ;
                s.insert({dist[e], e}) ;            // insert the next vertex with the updated distance
            }
        }
    }
}

int minDistance(int dist[], bool sptSet[]) 
{ 
    int min = INT_MAX, min_index ; 
    for(int v=0;v<V;v++)
    { 
        if(sptSet[v]==false && dist[v]<=min) 
        { min=dist[v], min_index=v ; }
    }     
    return min_index ; 
} 
  
void dijkstra(int graph[V][V], int src) 
{ 
    int dist[V] ;  
    bool sptSet[V] ;  
    for(int i=0;i<V;i++) 
    { dist[i]=INT_MAX, sptSet[i]=false ; } 
    dist[src]=0 ; 
    for(int count=0;count<V-1;count++) 
    { 
        int u = minDistance(dist, sptSet) ; 
        sptSet[u]=true ; 
        for (int v=0;v<V;v++)
        { 
            if(!sptSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u] + graph[u][v]<dist[v]) 
            { dist[v] = dist[u]+graph[u][v] ; }
        }     
    } 
    printSolution(dist) ;  
} 

void FloydWarshall()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            { dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]) ; }
        }
    }
}

int main()
{
    int i,j,k,n,m,x,y,z ; 
    for(i=0;i<m;i++)
    { adj[a].push_back(b) ; }
    for(i=0;i<n;i++)
    { v[i] = false ; }
    
}