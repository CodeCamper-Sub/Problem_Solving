#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<string> s;
vector<ll> a;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  s.resize(n);
  a.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> s[i] >> a[i];
  }
  ll mini = *min_element(a.begin(), a.end());
  ll i;
  for(i = 0; i < n; i++) {
    if(a[i] == mini) break;
  }
  for(ll j = i; j < n; j++) {
    cout << s[j] << '\n';
  }
  for(ll j = 0; j < i; j++) {
    cout << s[j] << '\n';
  }
  
  return 0;
}