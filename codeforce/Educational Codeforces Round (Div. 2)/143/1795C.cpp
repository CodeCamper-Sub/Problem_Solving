#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> a, b, bsum, drunk, rem;

void init() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  bsum.resize(n);
  drunk.assign(n + 1, 0);
  rem.assign(n + 1, 0);
  for(ll i = 0; i < n; i++) cin >> a[i];
  for(ll i = 0; i < n; i++) cin >> b[i];
}

ll get_sum(ll i, ll j) {
  if(i > j) return 0;
  else if(i == 0) return bsum[j];
  else return bsum[j] - bsum[i - 1];
}

void solve() {
  bsum[0] = b[0];
  for(ll i = 1; i < b.size(); i++) {
    bsum[i] = bsum[i - 1] + b[i];
  }
  for(ll i = 0; i < a.size(); i++) {
    // 0번째 ~ i - 1번째 합 + a[i]를 bsum에서 찾기
    auto iter = lower_bound(bsum.begin(), bsum.end(), get_sum(0, i - 1) + a[i]);
    if(iter != bsum.end() && *iter == get_sum(0, i - 1) + a[i]) {
      // i부터 iter번째까지 1 증가
      drunk[i] += 1;
      drunk[iter - bsum.begin() + 1] -= 1;
    } else if(iter == bsum.end()) {
      drunk[i] += 1;
      drunk[n] -= 1;
    } else {
      drunk[i] += 1;
      drunk[iter - bsum.begin()] -= 1;
      rem[iter - bsum.begin()] += a[i ] - get_sum(i, iter - bsum.begin() - 1);
    }
  }
  for(ll i = 1; i < drunk.size(); i++) {
    drunk[i] = drunk[i - 1] + drunk[i];
  }
  for(ll i = 0; i < drunk.size() - 1; i++) {
    drunk[i] *= b[i];
    drunk[i] += rem[i];
  }
  
  for(ll i = 0; i < n; i++) {
    cout << drunk[i] << ' ';
  }
  cout << '\n';
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