#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

set<ll> s;
ll n, x;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  bool is_valid = false;
  cin >> n >> x;
  for(ll i = 0; i < n; i++) {
    ll a;
    cin >> a;
    if(s.find(a-x) != s.end() || s.find(a+x) != s.end())
      is_valid = true;
    s.insert(a);
  }

  if(is_valid || x == 0) {
    cout << "Yes";
  } else{
    cout << "No";
  }

  return 0;
}