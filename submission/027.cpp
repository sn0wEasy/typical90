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

  int N;  cin >> N;
  vector<string> S(N);
  rep(i, N) cin >> S[i];

  set<string> s;
  rep(i, N) {
    // S[i]がsに含まれるか確認
    decltype(s)::iterator it = s.find(S[i]);
    // 含まれていなければ出力してsに追加
    if (it == s.end()) {
      print(i+1);
      s.insert(S[i]);
    }
  }

  return 0;
}
