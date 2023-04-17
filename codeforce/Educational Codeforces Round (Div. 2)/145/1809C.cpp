#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, n, k;
vector<ll> answers;

void init() {
  cin >> n >> k;
  answers.clear();
}

void solve() {
  while(ll(answers.size() + 1) * ll(answers.size() + 2) / 2 <= k) {
    answers.push_back(2);
  }
  ll t = ll(answers.size()) * ll(answers.size() + 1) / 2;
  if(k != t) {
    ll sum = 2ll * answers.size() + 1;
    sum *= -1;

    for(ll i = 0; i < k - t; i++) {
      sum += 2;
    }

    answers.push_back(sum);
  }

  while(answers.size() < n) {
    answers.push_back(-1000);
  }

  for(ll a: answers) {
    cout << a << ' ';
  }
  cout << '\n';
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