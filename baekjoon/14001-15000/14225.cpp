#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> a;
set<ll> s;

void brute_force(ll now, ll sum) {
  if(now == a.size()) {
    s.insert(sum);
    return;
  }
  brute_force(now + 1, sum);
  brute_force(now + 1, sum + a[now]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.resize(n);
  for(ll& a: a) cin >> a;

  brute_force(0, 0);
  for(ll i = 1; i <= 2000000; i++) {
    if(s.find(i) == s.end()) {
      cout << i << '\n';
      return 0;
    }
  }
  
  return 0;
}