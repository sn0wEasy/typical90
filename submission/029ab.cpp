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



int main() {

  ll W, N;  cin >> W >> N;
  vector<ll> L(N), R(N);
  rep(i, N) cin >> L[i] >> R[i];

  vector<ll> vals;
  rep(i, N) {
    vals.push_back(L[i]);
    vals.push_back(R[i]);
  }

  /* 座標圧縮 */
  sort(vals.begin(), vals.end());  // O(NlogN)
  auto itr = unique(vals.begin(), vals.end());  // 重複した要素を消す
  // これだけだと消されたところが穴になる
  // unique()の戻り値は消されたところの次のイテレータ
  vals.erase(itr, vals.end());  // 穴を消す
  // O(logN)
  for (ll i=0; i<N; ++i) {
    L[i] = lower_bound(vals.begin(), vals.end(), L[i]) - vals.begin();  // 要素を二分探索して座標圧縮されたidxを取得
    R[i] = lower_bound(vals.begin(), vals.end(), R[i]) - vals.begin();
  }

  vector<ll> base(N*2, 0);
  rep(i, N) {
    // L[i] ~ R[i] の範囲の base の max をとる
    ll max_height = -1;
    for (ll j=L[i]; j<=R[i]; ++j) {
      max_height = max(max_height, base[j]);
    }
    // max + 1 が答え
    print(max_height + 1);
    // レンガの範囲を max + 1 で更新する
    for (ll j=L[i]; j<=R[i]; ++j) {
      base[j] = max_height + 1;
    }
  }

  return 0;
}
