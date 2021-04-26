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
  ll L;  cin >> L;
  int K;  cin >> K;

  vector<ll> A(N);
  rep(i, N) { cin >> A[i]; }

  vector<ll> B(N+1);  // 切れ目の長さを格納
  B[0] = A[0];
  rep1(i, N) { B[i] = A[i] - A[i-1]; }
  B[N] = L - A[N-1];

  //rep(i, N+1) {print(B[i]);}

  ll left=0, right=L;
  ll mid;
  while(left < right) {
    // left が right を超えない限りループ
    
    // greedy ここから
    mid = (left + right) / 2;
    bool flag;
    ll m = 0, cnt = 0;
    rep(j, N+1) {
      m += B[j];
      if (m >= mid) {
        m = 0;
        cnt++;
      }
    }
    if (cnt >= K+1) {
      flag = true;
    } else {
      flag = false;
    }
    // greedy ここまで
    
    if (flag) {
      if (right - left == 1) {
        break;
      }
      left = mid;
    } else {
      right = mid;
    }
  }

  print(left);



  return 0;
}
