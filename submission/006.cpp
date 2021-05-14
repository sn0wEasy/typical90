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


// コピペ
int main() {

  int N, K;  cin >> N >> K;
  string S;  cin >> S;
  int nex[100009][26];

  // 前計算
  rep(i, 26) nex[S.size()][i] = S.size();
  for (int i=(int)S.size()-1; i>=0; --i) {
    for (int j=0; j<26; ++j) {
      if ((int)(S[i] - 'a') == j) {
        nex[i][j] = i;
      }
      else {
        nex[i][j] = nex[i+1][j];
      }
    }
  }

  // 貪欲法
  string Ans = "";
  int CurrentPos = 0;
  for (int i=1; i<=K; ++i) {
    rep(j, 26) {
      int NexPos = nex[CurrentPos][j];
      int MaxPossibleLength = (int)(S.size() - NexPos - 1) + i;  // 残りの長さと今の長さを加えたものが現時点の長さの最大になる
      if (MaxPossibleLength >= K) {  // 長さの最大値がKを超えていれば問題ない
        Ans += (char)('a' + j);
        CurrentPos = NexPos + 1;
        break;
      }
    }
  }

  print(Ans);

  return 0;
}
