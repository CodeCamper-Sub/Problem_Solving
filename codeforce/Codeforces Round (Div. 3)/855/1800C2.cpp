#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> deck, maxi;

void init() {
  cin >> n;
  deck.assign(n, 0);
  maxi.assign(n, -INF);
  for(ll i = 0; i < n; i++) cin >> deck[i];
}

void solve() {
  priority_queue<ll> q;
  ll answer = 0;
  for(ll i = 0; i < n; i++) {
    if(deck[i] == 0 && q.size()) {
      answer += q.top();
      q.pop();
    } else if(deck[i] != 0) {
      q.push(deck[i]);
    }
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