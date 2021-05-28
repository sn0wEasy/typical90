#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define INF (1e9)
#define PI (acos(-1))
#define print(x) cout << x << endl
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl

template<class T> inline bool chmin(T& a, T b) 
{ if (a > b) { a = b; return true; } return false; }

template<class T> inline bool chmax(T& a, T b) 
{ if (a < b) { a = b; return true; } return false; }

template<class T> inline auto __lcm(T& a, T& b) 
{ return a * b / __gcd(a, b); }

template<typename T> void remove(std::vector<T>& vector, unsigned int index)
{ vector.erase(vector.begin() + index); }


int N;  
vector<vector<int>> G;
vector<int> cost;

void bfs() {
  queue<int> que;
  que.push(0);
  cost[0] = 0;

  while(!que.empty()) {
    int p = que.front();
    que.pop();
    rep(i, G[p].size()) {
      if (cost[G[p][i]] != -1) continue;
      cost[G[p][i]] = cost[p] + 1;
      que.push(G[p][i]);
    }
  }
}

int main() {
  cin >> N;
  G = vector<vector<int>>(N);
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
  }

  cost = vector<int>(N, -1);
  bfs();
  vector<int> even_node;
  vector<int> odd_node;
  rep(i, cost.size()) {
    if (cost[i] % 2) {
      odd_node.push_back(i);
    } else {
      even_node.push_back(i);
    }
  }

  if (odd_node.size() > even_node.size()) {
    rep(i, odd_node.size()) {
      if (i > (N/2 - 1)) break;
      cout << odd_node[i] + 1 << " ";
    }
  } else {
    rep(i, even_node.size()) {
      if (i > (N/2 - 1)) break;
      cout << even_node[i] + 1 << " ";
    }
  }
  cout << endl;

  return 0;
}
