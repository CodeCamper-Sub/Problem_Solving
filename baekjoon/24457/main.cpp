#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, e, c;
vector<pair<ll, ll>> v; // {e, c}
ll dp[5050];         // {e, c}
ll maxi[5050];

bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
  return a.second < b.second;
}

ll solution() {
  sort(v.begin(), v.end(), cmp);
  for(ll i = 0; i < n; i++) {
    for(ll j = n - i; j > 0; j--) {
      dp[j] = max(0ll, maxi[j+1] + v[i].first - v[i].second * (j - 1));
    }
    for(ll j = n - i; j > 0; j--) {
      maxi[j] = max(maxi[j], dp[j]);
    }
  }

  return maxi[1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for(ll i = 0; i < n; i++) {
    cin >> e;
    v.push_back({e, 0});
  }
  
  for(ll i = 0; i < n; i++) {
    cin >> c;
    v[i].second = c;
  }

  cout << solution() << '\n';
  
  return 0;
}