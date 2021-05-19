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
  ll A, B, C, N;  cin >> N >> A >> B >> C;
  
  ll ans = INF;
  rep(i, 10000) {
    rep(j, 10000-i) {
      ll D = A * i + B * j;
      if (D > N) break;
      if ((N - D) % C == 0) {
        ans = min(ans, i + j + (N-D)/C);
      }
    }
  }
  print(ans);
  return 0;
}
