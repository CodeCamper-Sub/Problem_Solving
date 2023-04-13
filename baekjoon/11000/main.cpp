#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, s, t;
vector<pair<ll, ll>> a;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(ll i = 0; i < n; i++) {
    cin >> s >> t;
    a.push_back({s, 1});
    a.push_back({t, -1});
  }

  sort(a.begin(), a.end());

  ll answer = -INF;
  ll cnt = 0;
  for(auto [t, delta]: a) {
    cnt += delta;
    answer = max(answer, cnt);
  }

  cout << answer << '\n';
  
  return 0;
}