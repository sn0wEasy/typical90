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

  ll N;  cin >> N;
  string S;  cin >> S;

  // t より前の全ての a がもつ通り数の和を求める を繰り返す

  // dp[AtC文字の何文字目か][文字列Sの何文字目か]
  vector<vector<ll>> dp(7, vector<ll>(N, 0));

  // AtC文字を定義
  string AtC = "atcoder";

  rep(i, AtC.size()-1) {
    ll sum = 0;
    rep(j, N) {
      if (AtC[i] != S[j] && AtC[i+1] != S[j]) continue;
      else if (AtC[i] == S[j]) {
        if (i == 0) {
          sum = (sum + 1) % MOD;
        } else {
          sum = (sum + dp[i][j]) % MOD;
        }
      }
      else if (AtC[i+1] == S[j]) dp[i+1][j] = sum;
      else {
        print("bug");
      }
    }
  }

  ll ans = 0;
  rep(j, N) {
    ans = (ans + dp[6][j]) % MOD;
  }

  print(ans);
 
  return 0;
}
