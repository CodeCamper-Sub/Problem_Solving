#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD ll(1e9 + 7)
typedef long long ll;
using namespace std;

ll n, k, answer;
vector<vector<ll>> e;

ll power(ll a, ll b) {
  if(b == 0) return 1;
  ll temp = power(a, b / 2);
  if(b % 2) return temp * temp % MOD * a % MOD;
  else return temp * temp % MOD;
}

ll mod_inv(ll a) {
  return power(a, MOD - 2) % MOD;
}

ll dfs(ll now, ll parent) {
  vector<ll> childs;
  ll sum = 0;
  ll childs_sum = 0;
  for(ll next: e[now]) {
    if(next == parent) continue;
    childs.push_back(dfs(next, now));
    sum += childs.back();
  }
  answer += (sum + 1) % MOD * (n - sum) - 1;
  answer %= MOD;
  
  answer += sum * (sum - 1) % MOD * mod_inv(2) % MOD;
  answer %= MOD;
  for(ll i = 0; i < childs.size(); i++) {
    answer -= childs[i] * (childs[i] - 1) % MOD * mod_inv(2) % MOD;
    answer = (answer + MOD) % MOD;
  }
  return sum + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  e.resize(n + 1);
  for(ll i = 0; i < n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  if(k % 2) {
    cout << 1 << '\n';
    return 0;
  }

  dfs(1, -1);

  cout << answer * mod_inv(n * (n - 1) % MOD * mod_inv(2) % MOD) % MOD << '\n';
  
  return 0;
}