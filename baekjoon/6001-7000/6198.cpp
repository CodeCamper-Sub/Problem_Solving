#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> h;
stack<pair<ll, ll>> s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  h.resize(n);
  for(ll i = 0; i < n; i++) cin >> h[i];
  ll answer = 0;
  for(ll i = h.size() - 1; i >= 0; i--) {
    while(s.size() && s.top().first < h[i]) {
      s.pop();
    }
    if(s.size()) {
      answer += s.top().second - i - 1;
    } else {
      answer += n - 1 - i;
    }
    s.push({h[i], i});
  }
  cout << answer << '\n';
  
  return 0;
}