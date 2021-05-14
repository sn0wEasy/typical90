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
  // 桁DP + 繰り返し二乗法  
  ll N, B, K;  cin >> N >> B >> K;
  vector<int> c(10);  for (int i=1; i<=K; ++i) cin >> c[i];

  // ** DPの遷移行列を算出 ** 
  vector<vector<ll>> matrix(B, vector<ll>(B));
  rep(j, B) {
    vector<ll> b(B, 0);  // 余りの数の個数
    for(int k=1; k<=K; ++k) {
      ll d = (10*j + c[k]) % B;  // 余りの数
      b[d]++;  // 余りの数の個数をカウント
    }
    rep(l, B) {
      matrix[j][l] = b[l];
    }
  }

  // 行列の確認
  /*rep(i, B) {
    rep(j, B) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }*/

  // ** 繰り返し二乗法により事前の計算結果を格納 **
  // 2^10 ~ 10^3 なので，10^18 ~ 2^60 と見て事前に計算しておく
  vector<vector<vector<ll>>> li_matrix(60, vector<vector<ll>>(B, vector<ll>(B)));
  // li_matrix[指数][行ベクトル次元][列ベクトル次元]
  rep(i, 60) {
    vector<vector<ll>> pow(B, vector<ll>(B));
    rep(j, B) {
      rep(k, B) {
        pow[j][k] += matrix[j][k] * matrix[k][j];
      }
    }
  }

  // ** DP **
  vector<vector<ll>> dp(N+1, vector<ll>(B));


  return 0;
}
