#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> pre, in;

void init() {
  cin >> n;
  pre.resize(n);
  in.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> pre[i];
  }
  for(ll i = 0; i < n; i++) {
    cin >> in[i];
  }
}

void recursion(ll prel, ll prer, ll inl, ll inr) {
  if(prel == prer) {
    cout << pre[prel] << ' ';
    return;
  }
  for(ll k = inl; k <= inr; k++) {
    if(in[k] == pre[prel]) {
      recursion(prel + 1, prel + k - inl, inl, k - 1);
      recursion(prel + k - inl + 1, prer, k + 1, inr);
      cout << in[k] << ' ';
      return;
    }
  }
}

void solve() {
  recursion(0, n - 1, 0, n - 1);
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