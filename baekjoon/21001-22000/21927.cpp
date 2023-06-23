#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m;
vector<ll> a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  a.resize(n);
  b.resize(m);
  for(ll& a: a) cin >> a;
  for(ll& b: b) cin >> b;

  queue<ll> q_a, q_b;
  for(ll i = 0; i < n; i++) {
    if(a[i] != 0) {
      q_a.push(a[i]);
    }
  }

  for(ll i = 0; i < m; i++) {
    if(b[i] != 0) {
      q_b.push(b[i]);
    }
  }

  ll now = 1;
  ll i = 0, j = 0;
  while(q_a.size() || q_b.size()) {
    if(q_b.empty() || (q_a.size() && q_a.front() < q_b.front())) {
      while(a[i] != q_a.front()) {
        a[i++] = now++;
      }
      while(now < q_a.front()) {
        b[j++] = now++;
      }
      q_a.pop();
      i++; now++;
    } else {
      while(b[j] != q_b.front()) {
        b[j++] = now++;
      }
      while(now < q_b.front()) {
        a[i++] = now++;
      }
      q_b.pop();
      j++; now++;
    }
  }
  
  for(ll a: a) {
    if(a == 0) {
      cout << now++ << ' ';
    } else {
      cout << a << ' ';
    }
  }
  cout << '\n';
  for(ll b: b) {
    if(b == 0) {
      cout << now++ << ' ';
    } else {
      cout << b << ' ';
    }
  }
  
  return 0;
}