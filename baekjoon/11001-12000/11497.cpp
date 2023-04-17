#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt;
ll n, answer;
vector<ll> l;

ll max(ll a, ll b, ll c) { 
  return max(a, max(b, c));
}

void init() {
  cin >> n;
  l.resize(n);
  for(ll& l: l) cin >> l;
  answer = -INF;
}
void solve() {
  sort(l.begin(), l.end());
  answer = l.back() - l[l.size() - 2];
  for(ll i = l.size() - 3; i >= 0; i--) {
    answer = max(answer, l[i + 2] - l[i], l[i + 1] - l[i]);
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