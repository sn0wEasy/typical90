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

// 文字列 s に文字列 t が含まれていれば true
template<class T> inline bool contains(T& s, T& t)
{ if (s.find(t) != string::npos) { return true; } return false; }


int main() {

  ll N, K;  cin >> N >> K;
  vector<ll> a(N);  rep(i, N) cin >> a[i];

  ll res = 0;  // 解答

  // 区間の左端 left で場合分け
  ll right = 0;  // 毎回 right を使いまわす
  map<ll, ll> kind;  // kind も使いまわす
  rep(left, N) {
    while(right < N) {
    // kind に a[right] を加えても大丈夫なら right を動かす
      kind[a[right]]++;
      if (kind.size() > K) break;
      right++;
    }

    // break した状態で right は条件を満たす最大
    res = max(res, right-left);

    // left をインクリメントする準備
    if (right == left) right++;  // right が left に重なったら right も動かす
    else {
      kind[a[right]]--;  // right がインクリメントされているので kind から a[right] を引く
      kind[a[left]]--;  // left がインクリメントされるので kind から a[left] を引く
      if (kind[a[left]] == 0) kind.erase(a[left]);  // left が指す要素の個数が 0 なら削除する
    }
  }

  print(res);

  return 0;
}
