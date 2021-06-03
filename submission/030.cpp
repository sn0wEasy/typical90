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


// 参考：https://ei1333.github.io/luzhiled/snippets/math/prime-table.html
vector<int> prime_cnt(int n) {
  vector<int> prime(n+1, 0);
  if(n >= 0) prime[0] = 0;
  if(n >= 1) prime[1] = 0;
  for(int i = 2; i <= n; i++) {
    if(prime[i] != 0) continue;
    for(int j = i; j <= n; j += i) {
      prime[j]++;
    }
  }
  return prime;
}

int main() {

  int N, K;  cin >> N >> K;

  auto t = prime_cnt(N);
  int ans = 0;
  rep(i, N+1) {
    if (t[i] >= K) ans++;
  }

  print(ans);

  return 0;
}
