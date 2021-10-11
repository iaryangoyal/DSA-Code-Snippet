// Floyd-Warshall Algorithm Implementation in CPP.


//pooja singh
#include <bits/stdc++.h>
using namespace std;
 typedef long long int  ll;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define t_ime auto end = chrono::steady_clock::now(); auto diff = end - start;
#define t_time cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
#define  clk auto start = chrono::steady_clock::now();
#define MOD     1000000007
#define mp      make_pair
#define pb        push_back
#define f           first
#define s          second
#define ln "\n"
#define min_heap    priority_queue<ll,vector<ll>,greater<ll>> //min top
#define max_heap     priority_queue<ll> //max top
#define vpair  vector<pair<ll,ll>> 
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, 1,  0, -1};
#define nodes 4
#define INF 99999



void floyd_algorithm(ll graph[][nodes])
{
  ll temp[nodes][nodes];
  for (ll i = 0; i <nodes;i++)
  {
      for(ll j=0;j<nodes;j++)
      {
          temp[i][j]=graph[i][j];
      }
  }
  // adding every vertices
  for (ll k = 0; k < nodes; k++)
  {
    for (ll i = 0; i < nodes; i++)
    {
      for (ll j = 0; j < nodes; j++)
      {
        if (temp[i][k] + temp[k][j] < temp[i][j])
        {
            temp[i][j] = temp[i][k] + temp[k][j];
        }
          
      }
    }
  }
  
  
  // PRINT FINAL matrix
  cout<<"FINAL SHORTEST PATH"<<ln<<ln;
   for (ll i = 0; i < nodes; i++)
   {
    for (ll j = 0; j < nodes; j++)
    {
      if (temp[i][j] == INF)
       cout<<"INF"<<" ";
      else
       cout<<temp[i][j]<<" ";
    }
   cout<<ln;
  }
}


int main() 
{
    FAST;
    
	ll t;
	t=1;
	clk;
//	cin>>t;
	while(t--)
	{
       ll graph[nodes][nodes] = {{0, 3, INF, 5},
             {2, 0, INF, 4},
             {INF, 1, 0, INF},
             {INF, INF, 2, 0}};
            floyd_algorithm(graph);
	}

	  
	//t_ime;t_time;
	
	return 0;
}
// Floyd-Warshall Algorithm in C++

