#include <bits/stdc++.h>
#include <string>
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


int main() {
  // 木の直径を求める(dfs - ver. stack 実装)
  // 他にdfs - ver. 再帰 でも実装できそう
  // bfs でもたぶん実装できる
  int N;  cin >> N;  // 頂点の数(辺の数はN-1)

  vector<vector<int>> G(N);  // グラフを格納
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;  // 1 <= a <= b <= N-1
    G[a-1].push_back(b-1);  // 1~N-1 を 0~N-2 へ調整
    G[b-1].push_back(a-1);
  }
  vector<bool> seen(N, false);  // 既に見たことがある頂点を記録する
  vector<int> distance(N);  // 始点からの距離を記録する

  stack<int> st;
  st.emplace(0);  // 0を始点とする
  seen[0] = true;  // 始点は見たこととする
  distance[0] = 0;  // 始点からの距離は0とする
  while (st.size() != 0) {  // 深さ優先探索
    int state = st.top();  // 現在の状態を取り出す
    st.pop(); // stackのtop要素を削除する
    for (auto next:G[state]) {
      if (!seen[next]) {
        seen[next] = true;  // 探索済みに更新
        st.emplace(next);  // 次の状態をstackへ格納
        distance[next] = distance[state] + 1;  // 距離を次の頂点へ引き継ぐ
      }
    }
  }

  // 始点0から最も遠い頂点を探索
  int max_dist = 0;
  int max_idx = 0;
  rep(i, N) {
    if (distance[i] > max_dist) {
      max_dist = distance[i];
      max_idx = i;
    }
  }

  vector<bool> seen2(N, false);
  vector<int> distance2(N);

  stack<int> st2;
  st2.emplace(max_idx);
  seen2[max_idx] = true;
  distance2[max_idx] = 0;
  while (st2.size() != 0) {
    int state = st2.top();
    st2.pop();
    for (auto next:G[state]) {
      if (!seen2[next]) {
        seen2[next] = true;
        st2.emplace(next);
        distance2[next] = distance2[state] + 1;
      }
    }
  }

  int diameter = 0;
  rep(i, N) {
    diameter = max(diameter, distance2[i]);
  }
  print(diameter + 1);

  return 0;
}
