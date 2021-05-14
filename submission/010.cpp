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
  vector<int> C(N);
  vector<int> P(N);
  rep(i, N) { cin >> C[i] >> P[i]; }
  int Q;  cin >> Q;
  vector<int> L(Q);
  vector<int> R(Q);
  rep(i, Q) { cin >> L[i] >> R[i]; }

  vector<int> First(N+1, 0);
  vector<int> Second(N+1, 0);
  rep(i, N) {
    if (C[i] == 1) {
      First[i+1] = First[i] + P[i];
      Second[i+1] = Second[i];
    } else {
      First[i+1] = First[i];
      Second[i+1] = Second[i] + P[i];
    }
  }

  rep(i, Q) {
    cout << First[R[i]] - First[L[i]-1] << " " << Second[R[i]] - Second[L[i]-1] << endl;
  }

  return 0;
}
