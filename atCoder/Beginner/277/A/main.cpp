#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll N, X;
  ll p[110];
  cin >> N >> X;
  for(ll i = 1; i <= N; i++) {
    cin >> p[i];
  }
  for(ll i = 1; i <= N; i++) {
    if(p[i] == X) {
      cout << i << '\n';
      return 0;
    }
  }

  return 0;
}