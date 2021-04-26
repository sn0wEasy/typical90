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

  int H, W;
  cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> A[i][j];
    }
  }

  vector<ll> x(W, 0);
  vector<ll> y(H, 0);
  
  rep(i, H) {
    rep(j, W) {
      y[i] += A[i][j];
    }
  }

  rep(j, W) {
    rep(i, H) {
      x[j] += A[i][j];
    }
  }

  rep(i, H) {
    rep(j, W) {
      cout << y[i] + x[j] - A[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
