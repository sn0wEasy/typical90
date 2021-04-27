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

  ll N, B, K;  cin >> N >> B >> K;
  vector<int> c(11);  for (int i=1; i<=K; ++i) cin >> c[i];

  // "s 桁目での余りが t_(s) であるのは u_(s) 通りである" 状態を保持
  // -> "s+1 桁目での余りが t_(s+1) であるのは u_(s+1) 通りである" 状態が計算可能
  // --> "N 桁目での余りが 0 であるのは ans 通りである" を得られる
  vector<vector<ll>> dp(N+1, vector<ll>(B));
  dp[0][0] = 1;
  
  rep(i, N) {  // i 桁目
    rep(j, B) {  // 余り j
      for (int k=1; k<=K; ++k) {
        int b = (10 * j + c[k]) % B;  // i+1 桁目の余り
        dp[i+1][b] += dp[i][j];  // 遷移
        dp[i+1][b] %= MOD;
      }
    }
  }

  print(dp[N][0]);

  return 0;
}
