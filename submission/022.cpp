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

  ll a, b, c;  cin >> a >> b >> c;
  ll d = __gcd(a, __gcd(b, c));  // 3つの数の最小公倍数
  // 分ける立方体の大きさを1*1*1にする
  rep(i, 30) {
    a = a / d;
    b = b / d;
    c = c / d;
    if (a % d != 0 || b % d != 0 || c % d != 0) {
      break;
    }
  }
  // 切る数を求める
  print(a+b+c-3);

  return 0;
}
