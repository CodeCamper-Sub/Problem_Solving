#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll N, Q;
  cin >> N >> Q;
  unordered_map<ll, set<ll>> m;
  for(ll i = 0; i < Q; i++) {
    ll T, A, B;
    cin >> T >> A >> B;
    if(T == 1) {
      m[A].insert(B);
    } else if (T == 2){
      m[A].erase(B);
    } else {
      if(m[A].find(B) != m[A].end() && m[B].find(A) != m[B].end()) {
        cout << "Yes" << '\n';
      } else {
        cout << "No" << '\n';
      }

    }

  }

  return 0;
}