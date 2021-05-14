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
  vector<ll> A(N);  rep(i, N) cin >> A[i];
  ll Q;  cin >> Q;
  vector<ll> B(Q);  rep(i, Q) cin >> B[i];

  sort(A.begin(), A.end());
  rep(i, Q) {
    // B[i] 以上の値が現れる最初の位置を O(logN)で取得
    ll idx = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
    if (idx == 0) {
      print(abs(A[idx] - B[i]));
      continue;
    }
    ll front = abs(A[idx] - B[i]);
    ll back = abs(B[i] - A[idx-1]);
    print(min(front, back));
  }

  return 0;
}
