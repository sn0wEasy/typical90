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

  // 入力
  int N;  cin >> N;
  vector<int> lx(N), ly(N), rx(N), ry(N);
  rep(i, N) {
    cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
  }

  // 最左下点と最右上点を取得
  int rxmax = -1;
  int rymax = -1;
  int lxmin = INF;
  int lymin = INF;
  rep(i, N) {
    chmax(rxmax, rx[i]);
    chmin(lxmin, lx[i]);
    chmax(rymax, ry[i]);
    chmin(lymin, ly[i]);
  }

  // 最左下点を(0, 0)として初期化
  int H = rymax - lymin + 1;
  int W = rxmax - lxmin + 1;
  vector<vector<int>> imos(H, vector<int>(W, 0));

  // いもす法による重みの加算
  // 原点とその対角にある点を+1，それとは異なる点を-1
  rep(i, N) {
      imos[ly[i]-lymin][lx[i]-lxmin]++;
      imos[ly[i]-lymin][rx[i]-lxmin]--;
      imos[ry[i]-lymin][lx[i]-lxmin]--;
      imos[ry[i]-lymin][rx[i]-lxmin]++;
  }

  // 横方向へ累積和
  rep(i, H) {
    rep1(j, W) {
      imos[i][j] += imos[i][j-1];
    }
  }

  // 縦方向へ累積和
  rep1(i, H) {
    rep(j, W) {
      imos[i][j] += imos[i-1][j];
    }
  }

  // 重なっている枚数をカウント
  vector<int> ans(N+1, 0);
  rep(i, H) {
    rep(j, W) {
      ans[imos[i][j]]++;
    }
  }

  // 出力
  rep1(i, N+1) {
    print(ans[i]);
  }

  return 0;
}
