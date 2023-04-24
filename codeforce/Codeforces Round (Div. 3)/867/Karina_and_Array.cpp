#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
bool has_zero;
vector<ll> a, positive, negative;

void init() {
  cin >> n;
  a.resize(n);
  positive.clear();
  negative.clear();
  has_zero = false;
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] > 0) {
      positive.push_back(a[i]);
    } else if(a[i] < 0) {
      negative.push_back(a[i]);
    } else {
      has_zero = true;
    }
  }
}

void solve() {
  ll answer = -INF;
  sort(positive.begin(), positive.end());
  sort(negative.begin(), negative.end());
  if(positive.size() >= 2) {
    answer = max(answer, positive[positive.size() - 2] * positive[positive.size() - 1]);
  }
  if(negative.size() >= 2) {
    answer = max(answer, negative[0] * negative[1]);
  }
  if(positive.size() && negative.size()) {
    answer = max(answer, positive[0] * negative[negative.size() - 1]);
  }
  if(has_zero) {
    answer = max(answer, 0ll);
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