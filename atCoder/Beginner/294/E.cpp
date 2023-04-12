#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll L, N[2];
queue<pair<ll, ll>> info[2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> L >> N[0] >> N[1];
  // info[0].resize(N[0]);
  // info[1].resize(N[1]);
  for (ll i = 0; i < N[0]; i++) {
    pair<ll, ll> p;
    cin >> p.first >> p.second;
    info[0].push(p);
  }
  for (ll i = 0; i < N[1]; i++) {
    pair<ll, ll> p;
    cin >> p.first >> p.second;
    info[1].push(p);
  }

  ll answer = 0;
  ll now_a = 0, now_b = 0;
  while (info[0].size() && info[1].size()) {
    if (info[0].front().first == info[1].front().first) {
      answer += min(now_a + info[0].front().second, now_b + info[1].front().second) - max(now_a, now_b);
    }
    if (now_a + info[0].front().second < now_b + info[1].front().second) {
      now_a += info[0].front().second;
      info[0].pop();
    } else if (info[0].front().second == info[1].front().second) {
      now_a += info[0].front().second;
      now_b += info[1].front().second;
      info[0].pop();
      info[1].pop();
    } else {
      now_b += info[1].front().second;
      info[1].pop();
    }
  }

  cout << answer << '\n';

  return 0;
}