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


struct UnionFind {
  vector<vector<pair<int, int>>> par;  // par[h][w]: (h, w)の親の番号　（例）par[3][4] = (2, 3): (3, 4)の親が(2, 3)

  UnionFind() : par(2010, vector<pair<int, int>>(2010)) {  // データが格納される予定の配列を初期化
  
    pair<int, int> p = make_pair(2009, 0);
    rep(i, 2010) {
      rep(j, 2010) {
        par[i][j] = p;
      }
    }
  }

  bool isFilled(int r, int c) {  // データが入っているかを確認する
    return par[r][c] != make_pair(2009, 0);
  }

  void append(int r, int c) {  // データを根として追加
    pair<int, int> p = make_pair(r, c);
    par[r][c] = p;
  }

  pair<int, int> root(pair<int, int> p) {  // データxが属する木の根を再帰で得る：root(r, c) = {xの木の根}
    int r = p.first;
    int c = p.second;
    if (par[r][c] == p) return p;
    return par[r][c] = root(par[r][c]);
  }

  void unite(pair<int, int> pa, pair<int, int> pb) {  // aとbの木を併合
    pair<int, int> ra = root(pa);  // aの根をra
    pair<int, int> rb = root(pb);  // bの根をrb
    if (ra == rb) return;  // aとbの根が同じ（=同じ木にある）時はそのまま
    par[ra.first][ra.second] = rb;  // aとbの根が同じでない（=同じ木にない）時はaの根raをyの根rbにつける
  }

  bool same(pair<int, int> pa, pair<int, int> pb) {// 2つのデータa, bが属する木が同じならtrueを返す
    pair<int, int> ra = root(pa);
    pair<int, int> rb = root(pb);
    return ra == rb;
  }
};


int main() {
  int H, W;  cin >> H >> W;
  int Q;  cin >> Q;

  UnionFind tree;
  
  rep(i, Q) {
    int q;  cin >> q;
    if (q == 1) {  // q == 1 の時
      int r, c;  cin >> r >> c;
      tree.append(r, c);
      // 上下左右を見る
      vector<int> rlook = {1, 0, -1, 0};
      vector<int> clook = {0, 1, 0, -1};
      rep(i, 4) {
        // 隣接していれば，uniteする
        if (tree.isFilled(r + rlook[i], c + clook[i])) {
          // uniteする
          pair<int, int> p = make_pair(r, c);
          pair<int, int> _p = make_pair(r+rlook[i], c+clook[i]);
          tree.unite(p, _p);
        }
      }
    } else {  // q == 2 の時
      int ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;
      // sameかどうかチェックする
      pair<int, int> pa = make_pair(ra, ca);
      pair<int, int> pb = make_pair(rb, cb);
      if (tree.isFilled(pa.first, pa.second) && tree.isFilled(pb.first, pb.second)) {
        if (tree.same(pa, pb)) yes;
        else no;
      } else no;
    }
    
  }

  return 0;
}
