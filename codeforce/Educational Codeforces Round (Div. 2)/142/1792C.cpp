#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> p, inv;

void init() {
  cin >> n;
  p.resize(n + 1);
  inv.resize(n + 1);
  for(ll i = 0; i < n; i++) {
    cin >> p[i];
    inv[p[i]] = i;
  }
}

void solve() {
  ll answer = n / 2;
  ll now = n / 2;
  while(now >= 1) {
    if(n % 2 == 0 && now == n / 2) {
      if(inv[now] < inv[n - now + 1]) {
        answer--;
      } else {
        break;
      }
    } else {
      if(inv[now] < inv[now + 1] && inv[n - now] < inv[n - now + 1]) {
        answer--;
      } else {
        break;
      }
    }
    now--;
  }

  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}