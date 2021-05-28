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

  int N, M;  cin >> N >> M;
  vector<pair<int, int>> P;
  rep(i, M) {
    int a, b;  cin >> a >> b;
    P.push_back(make_pair(a, b));
  }

  ll cnt = 0;
  rep(i, M) {
    // 線分iについて見る
    rep(j, M) {
      // 線分jの，線分iとの関係を見る
      if (i == j) continue;  // 同じ線分の場合は無視
      // 交差パターン1
      bool cond1 = (P[i].first < P[j].first && P[i].second > P[j].first);
      bool cond2 = (P[i].first > P[j].second || P[i].second < P[j].second);
      // 交差パターン2
      bool cond3 = (P[i].first < P[j].second && P[i].second > P[j].second);
      bool cond4 = (P[i].first > P[j].first || P[i].second < P[j].first);
      // パターン1またはパターン2に当てはまるものをカウント
      bool cond = (cond1 && cond2) || (cond3 && cond4);
      if (cond) {
        cnt++;
      }
    }
  }

  // かぶりを取り除く
  print(cnt / 2);

  return 0;
}
