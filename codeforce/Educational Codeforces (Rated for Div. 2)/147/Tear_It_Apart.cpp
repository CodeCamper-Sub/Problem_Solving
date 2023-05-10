#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

string s;
vector<vector<ll>> cnt;

void init() {
  cin >> s;
  cnt.assign(26, vector<ll>());
}

ll get_needed_operation(ll n) {
  ll cnt = 0;
  while(n) {
    cnt++;
    n /= 2;
  }
  return cnt;
}

void solve() {
  ll answer = INF;
  for(ll i = 0; i < s.size(); i++) {
    cnt[s[i] - 'a'].push_back(i);
  }
  for(ll i = 0; i < 26; i++) {
    if(cnt[i].size() == 0) continue;
    ll partial_answer = get_needed_operation(cnt[i][0]);
    for(ll j = 1; j < cnt[i].size(); j++) {
      partial_answer = max(partial_answer, get_needed_operation(cnt[i][j] - cnt[i][j - 1] - 1));
    }
    partial_answer = max(partial_answer, get_needed_operation(s.size() - 1 - cnt[i].back()));
    answer = min(answer, partial_answer);
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