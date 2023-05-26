#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, k, c;
vector<ll> fact;

void solve(ll k, set<ll>& remain, vector<ll>& result) {
  if(remain.size() == 0) return;
  for(auto iter = remain.begin(); iter != remain.end(); iter++) {
    if(k >= fact[n - result.size() - 1]) {
      k -= fact[n - result.size() - 1];
    } else {
      result.push_back(*iter);
      remain.erase(iter);
      solve(k, remain, result);
      break;
    }
  }
}

void solve2(ll now, vector<ll>& p, set<ll>& remain, ll& answer) {
  if(remain.size() == 0) return;
  ll cnt = 0;
  for(auto iter = remain.begin(); iter != remain.end(); iter++) {
    if(*iter == p[now]) {
      remain.erase(iter);
      answer += cnt * fact[n - now - 1];
      solve2(now + 1, p, remain, answer);
      break;
    }
    cnt++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  fact.push_back(1);
  while(fact.size() < 20) fact.push_back(fact.back() * (fact.size()));
  
  cin >> n >> c;
  set<ll> remain;
  for(ll i = 1; i <= n; i++) {
    remain.insert(i);
  }
  if(c == 1) {
    vector<ll> result;
    cin >> k;
    solve(k - 1, remain, result);
    for(ll a: result) {
      cout << a << ' ';
    }
  } else {
    vector<ll> p(n);
    for(ll i = 0; i < n; i++) cin >> p[i];
    ll answer = 1;
    solve2(0, p, remain, answer);
    cout << answer << '\n';
  }
  
  return 0;
}