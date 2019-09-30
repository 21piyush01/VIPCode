#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define MAX 1000003

struct node
{
  int data ;
  struct node *next ;  
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  struct node *head=NULL, *p, *prev, *fast, *slow ;
  int i,n,temp ;
  cin >> n ;
  for(i=0;i<n;i++)
  {
    cin >> temp ;
    p = (struct node *)malloc(sizeof(struct node)) ;
    p->data = temp ;
    p->next = NULL ;
    if(head==NULL)
    { head = p ; }
    else
    { prev->next = p ; }
    prev = p ;    
  }
  fast = head, slow = head ;
  while(fast!=NULL && fast->next!=NULL)
  {
    fast = fast->next->next ;
    slow = slow->next ;
  }
  int res = slow->data ;
  cout << res << endl ;
  return 0 ;
}   