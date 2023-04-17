#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
ll arr[1001000], cnt[1001000], ngf[1001000];
stack<ll> s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(ll i = 0; i < n; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
  }
  for(ll i = n - 1; i >= 0; i--) {
    if(s.empty()) {
      ngf[i] = -1;
    } else {
      while(!s.empty()) {
        if(cnt[arr[i]] < cnt[s.top()]) {
          ngf[i] = s.top();
          break;
        } else {
          s.pop();
        }
      }
      if(s.empty()) {
        ngf[i] = -1;
      }
    }
    s.push(arr[i]);
  }

  for(ll i = 0; i < n; i++) {
    cout << ngf[i] << ' ';
  }

  return 0;
}