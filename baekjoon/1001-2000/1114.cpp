#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll l, k, c;
vector<ll> a;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> l >> k >> c;
  a.resize(k);
  for(ll& a: a) cin >> a;
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());


  ll left = 0;
  ll right = l;

  while(left <= right) {
    ll mid = (left + right) / 2;

    ll cnt = c;
    ll now = a[0];
    bool is_valid = true;
    for(ll i = 0; i < k; i++) {
      if(cnt < 0 || now > mid) {
        is_valid = false;
        break;
      }
      if(i == k - 1) {
        if(now + l - a[i] > mid) {
          cnt--;
          now = l - a[i];
        } else {
          now += l - a[i];
        }
      } else {
        if(now + a[i + 1] - a[i] > mid) {
          cnt--;
          now = a[i + 1] - a[i];
        } else {
          now += a[i + 1] - a[i];
        }
      }
    }

    if(cnt < 0 || now > mid) is_valid = false;
    if(is_valid) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  reverse(a.begin(), a.end());
  for(ll i = 0; i < k; i++) {
    a[i] = l - a[i];
  }

  ll cnt = c;
  ll now = a[0];
  for(ll i = 0; i < k; i++) {
    if(i == k - 1) {
      if(now + l - a[i] > left) {
        cnt--;
        now = l - a[i];
      } else {
        now += l - a[i];
      }
    } else {
      if(now + a[i + 1] - a[i] > left) {
        cnt--;
        now = a[i + 1] - a[i];
      } else {
        now += a[i + 1] - a[i];
      }
    }
  }

  cout << left << ' ';
  if(cnt > 0) {
    cout << l - a.back() << '\n';
  } else {
    cout << now << '\n';
  }

  return 0;
}