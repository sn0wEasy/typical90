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


const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;  // i までの累積積
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;  // i の逆元
        finv[i] = finv[i - 1] * inv[i] % MOD;  // i の逆元までの逆元の累積積
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    // 二項係数は n! * (k!の逆元) * ((n-k)!の逆元) で求められる
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main() {

  int N;  cin >> N;
  COMinit();

  for (int k = 1; k <= N; ++k) {
    ll ans = 0;
    if (k == 1) {
      for (int a = 1; a <= N; ++a) {
        ans = (ans + COM(N, a)) % MOD;
      }
    }
    else {
      for (int a = 1; a <= N/(k-1)+1; ++a) {
        ans = (ans + COM(N - (k-1) * (a-1), a)) % MOD;
      }
    }
    print(ans);
  }
  return 0;
}
