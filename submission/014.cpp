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

  int N;  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  rep(i, N) {
    cin >> A[i];
  }
  rep(i, N) {
    cin >> B[i];
  }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  ll ans = 0;
  rep(i, N) {
    ans += abs(A[i]-B[i]);
  }
  print(ans);

  return 0;
}
