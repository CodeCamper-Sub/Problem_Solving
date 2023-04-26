#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> a, answer;

void init() {
  cin >> n;
  a.resize(n);
  for(ll& a: a) { 
    cin >> a;
  }
  answer.clear();
}

void solve() {
  sort(a.begin(), a.end());
  if(a[0] == 0 && a.back() == 0) {
    cout << "No\n";
    return;
  }
  ll l = 0, r = n - 1;
  for(ll i = 0; i < n; i++) {
    if(a[i] < 0) {
      l = max(l, i);
    }
    if(a[i] > 0) {
      r = min(r, i);
    }
  }
  ll sum = 0;
  for(ll i = l + 1; i < r; i++) {
    answer.push_back(0);
  }
  while(l >= 0 || r < n) {
    if(sum >= 0) {
      sum += a[l];
      answer.push_back(a[l]);
      l--;
    } else {
      sum += a[r];
      answer.push_back(a[r]);
      r++;
    }
  }
  cout << "Yes\n";
  for(ll i = 0; i < answer.size(); i++) {
    cout << answer[i] << ' ';
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