#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> a, b;
stack<ll> a_inv[200200], b_inv[200200];
vector<ll> a_check, b_check;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  a.resize(n);
  b.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
    a_check.push_back(a[i]);
  }
  
  for(ll i = 0; i < n; i++) {
    cin >> b[i];
    b_check.push_back(b[i]);
  }

  sort(a_check.begin(), a_check.end());
  sort(b_check.begin(), b_check.end());

  for(ll i = 0; i < a_check.size(); i++) {
    if(a_check[i] != b_check[i]) {
      cout << "No\n";
      return 0;
    }
  }

  for(ll i = 0; i < n; i++) {
    if(a[i] != b[i]) {
      a_inv[a[i]].push(i);
      b_inv[b[i]].push(i);
    }
  }

  for(ll i = 0; i < n; i++) {
    if(a[i] == b[i]) continue;
    
  }


  
  return 0;
}