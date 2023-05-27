#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> a, b, c;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.resize(n);
  b.resize(n);
  c.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(ll i = 0; i < n; i++) {
    cin >> b[i];
  }
  for(ll i = 0; i < n; i++) {
    cin >> c[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  ll i = 0, j = 0, k = 0;
  ll answer = 0;
  while(i < n && j < n && k < n) {
    while(j < n && a[i] >= b[j]) j++;
    while(k < n && b[j] >= c[k]) k++;
    if(i < n && j < n && k < n) {
      answer++;
      i++; j++; k++;
    }
  }

  cout << answer << '\n';
  
  return 0;
}