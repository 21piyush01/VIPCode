#include <bits/stdc++.h>
using namespace std ;

const int MAX = 10005 ;
typedef pair<long long, int> PII ;
bool marked[MAX] ;
vector <PII> adj[MAX] ;

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q ;
    int y ;
    long long minimumCost = 0 ;
    PII p ;
    Q.push(make_pair(0,x)) ;
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top() ;
        Q.pop() ;
        x = p.second ;
        // Checking for cycle
        if(marked[x] == true)
        { continue ; }
        minimumCost += p.first ;
        marked[x] = true ;
        for(int i=0;i<adj[x].size();i++)
        {
            y = adj[x][i].second ;
            if(marked[y] == false)
            { Q.push(adj[x][i]) ; }
        }
    }
    return minimumCost ;
}

int minKey(int key[], bool mstSet[])  
{  
    int min = INT_MAX, min_index ;  
    for(int v=0;v<V;v++)
    {  
        if(mstSet[v]==false && key[v]<min)  
        { min=key[v], min_index=v ; }  
    }
    return min_index ;  
}  
  
void printMST(int parent[], int graph[V][V])  
{  
    cout << "Edge \tWeight\n" ;  
    for(int i=1;i<V;i++)  
    { cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n" ; }  
}  

void primMST(int graph[V][V])  
{  
    int parent[V] ;  
    int key[V] ;  
    bool mstSet[V] ;  
    for(int i=0;i<V;i++)  
    { key[i]=INT_MAX, mstSet[i]=false ; }  
    key[0]=0 ;  
    parent[0]=-1 ;  
    for(int count=0;count<V-1;count++) 
    {  
        int u = minKey(key, mstSet) ;  
        mstSet[u]=true ;  
        for(int v=0;v<V;v++)
        {  
            if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v])  
            { parent[v]=u, key[v]=graph[u][v] ; }
        }      
    }  
    printMST(parent, graph);  
}  

int main()
{
    int nodes, edges, x, y ;
    long long weight, minimumCost ;
    cin >> nodes >> edges ;
    for(int i=0;i<edges;i++)
    {
        cin >> x >> y >> weight ;
        adj[x].push_back(make_pair(weight,y)) ;
        adj[y].push_back(make_pair(weight,x)) ;
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1) ;
    cout << minimumCost << endl ;
    return 0 ;
}