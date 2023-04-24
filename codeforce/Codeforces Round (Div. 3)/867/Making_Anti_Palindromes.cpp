#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, answer;
string s;
vector<ll> same_cnt;
vector<pair<ll, ll>> differs;

void init() {
  cin >> n >> s;
  same_cnt.assign(26, 0);
  differs.clear();
}

void solve() {
  if(n % 2) {
    cout << "-1\n";
    return;
  }
  for(ll i = 0; i < n / 2; i++) {
    if(s[i] == s[n - i - 1]) {
      same_cnt[s[i] - 'a']++;
    } else {
      differs.push_back({s[i], s[n - i - 1]});
    }
  }
  ll sum = 0, maxi = 0;
  char mc;
  for(ll i = 0; i < 26; i++) {
    sum += same_cnt[i];
    if(maxi < same_cnt[i]) {
      mc = 'a' + i;
      maxi = max(maxi, same_cnt[i]);
    }
  }

  if(maxi <= sum - maxi) {
    cout << sum / 2 + (sum % 2 ? 1 : 0) << '\n';
    return;
  }

  answer = sum - maxi;
  maxi -= sum - maxi;
  for(auto [a, b]: differs) {
    if(a == mc || b == mc) continue;
    maxi--;
    answer++;
    if(maxi == 0) break;
  }
  if(maxi) {
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