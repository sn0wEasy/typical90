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
  vector<vector<int>> A(N, vector<int>(N));
  rep(i, N) {
    rep(j, N) {
      cin >> A[i][j];
    }
  }
  int M;  cin >> M;
  vector<vector<bool>> P(N, vector<bool>(N, false));  // 仲違いを記録
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    P[a][b] = true;
    P[b][a] = true;
  }

  vector<int> v(N);
  rep(i, N) v[i] = i;
  int ans = INF;
  // N! の順列を列挙
  do {
    int tmp = A[v[0]][0];
    rep1(i, N) {
      // 順列に仲違いがないか確認
      if (P[v[i-1]][v[i]]) {
        tmp = INF;
        break;
      }
      // コストを追加
      tmp += A[v[i]][i];
    }
    ans = min(ans, tmp);
  } while (next_permutation(v.begin(), v.end()));

  if (ans != INF) print(ans);
  else print(-1);

  return 0;
}
