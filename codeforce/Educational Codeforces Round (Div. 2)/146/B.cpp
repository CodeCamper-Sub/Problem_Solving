#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt;
ll a, b;

void init() {
  cin >> a >> b;
}
void solve() {
  ll answer = INF;
  for(ll i = 1; i * i <= a; i++) {
    if(a % i) continue;
    ll a_cost = i - 1 + a / i;
    ll partial_answer = INF;
    for(ll j = i; j <= b; j++) {
      if(b % j) continue;
      if(partial_answer > j - i + b / j) {
        partial_answer = j - i + b / j;
      } else {
        break;
      }
    }
    answer = min(answer, a_cost + partial_answer);

    partial_answer = INF;
    for(ll j = a / i; j <= b; j++) {
      if(b % j) continue;
      if(partial_answer > j - a / i + b / j) {
        partial_answer = j - a / i + b / j;
      } else {
        break;
      }
    }
    answer = min(answer, a_cost + partial_answer);
  }
  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while(tt--) {
    init();
    solve();
  }
  return 0;
}