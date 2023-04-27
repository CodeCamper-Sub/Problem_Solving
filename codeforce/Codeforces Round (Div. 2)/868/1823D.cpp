#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, k;
vector<ll> x, c;
vector<char> answer;

void init() {
  cin >> n >> k;
  x.resize(k);
  c.resize(k);
  answer.clear();
  for(ll& x: x) cin >> x;
  for(ll& c: c) cin >> c;
}

void solve() {
  for(ll i = 0; i < k; i++) {
    if(x[i] < c[i]) {
      cout << "NO\n";
      return;
    } else if(i > 0 && x[i] - x[i - 1] < c[i] - c[i - 1]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  ll seq = 0;
  char next_c = 'd';
  answer.push_back('a');
  answer.push_back('b');
  answer.push_back('c');
  ll now = 3;
  for(ll i = 0; i < k; i++) {
    while(now != c[i]) {
      answer.push_back(next_c);
      now++;
    }
    while(answer.size() != x[i]) {
      answer.push_back('a' + seq++);
      seq %= 3;
    }
    next_c++;
  }
  for(ll i = 0; i < answer.size(); i++) {
    cout << answer[i];
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