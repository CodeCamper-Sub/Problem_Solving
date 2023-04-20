#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, k;
vector<pair<ll, ll>> segments;

void init() {
  cin >> n >> k;
  segments.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> segments[i].first;
  }
  for(ll j = 0; j < n; j++) {
    cin >> segments[j].second;
  }
}

void solve() {
  ll answer = INF;
  ll sum = 0;
  ll cost = 0;

  priority_queue<ll, vector<ll>, greater<ll>> q;
  for(ll i = 0; i < segments.size(); i++) {
    if(sum + segments[i].second - segments[i].first + 1 < k) {
      sum += segments[i].second - segments[i].first + 1;
      q.push(segments[i].second - segments[i].first + 1);
    } else {
      while(q.size() && sum - q.top() + segments[i].second - segments[i].first + 1 >= k && q.top() <= segments[i].second - segments[i].first + 1) {
        sum -= q.top();
        q.pop();
      }
      if(sum < k) {
        answer = min(answer, ll(q.size() + 1) * 2 + segments[i].first + k - sum - 1);
      }
      sum += segments[i].second - segments[i].first + 1;
      q.push(segments[i].second - segments[i].first + 1);
    }
  }

  if(answer == INF) {
    cout << -1 << '\n';
  } else {
    cout << answer << '\n';
  }
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