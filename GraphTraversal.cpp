#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MAX 1000003

vector<int> adj[MAX] ;
bool visited[MAX] ;
long long int nodes=0 ;

void BFS(int s)
{
    queue<int> q;
    visited[s] = true;
    q.push(s); 
    vector<int>::iterator i;
    while(!q.empty())
    {
        s = q.front();
        cout << s << " " ;
        q.pop();
        for(i=adj[s].begin(); i!=adj[s].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true ;
                q.push(*i) ;
            }
        }
    }
}

void DFS(int s)
{
    //nodes++;
    visited[s] = true ;
    cout << s << " " ;
    vector<int>::iterator i ;
    for(i=adj[s].begin(); i!=adj[s].end(); i++)
    {
        if(!visited[*i])
        { DFS(*i) ; }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    int i,N,M,a,b;
    cin >> N >> M ;
    for(i=0;i<M;i++)
    {
        cin >> a >> b ;
        adj[a].push_back(b);
    }
    for(i=0;i<N;i++)
    {  visited[i] = false ;  }
    // DFS(0) ; BFS(0) ;
    return 0;
}

// To detect cycle in UD-G : maintain a parent & check if visited_node!=parent
// To detect cycle in D-G : just check using White, Gray, Black scheme