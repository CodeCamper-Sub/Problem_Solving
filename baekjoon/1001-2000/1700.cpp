#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, k;
vector<ll> t;
set<ll> s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  t.resize(k);
  ll answer = 0;
  for(ll& t: t) cin >> t;
  for(ll i = 0; i < k; i++) {
    if(s.size() < n) {
      s.insert(t[i]);
    } else if(s.find(t[i]) == s.end()) {
      ll candidate = 0, max_distance = -INF;
      for(ll s: s) {
        ll distance = INF;
        for(ll j = i + 1; j < k; j++) {
          if(t[j] == s) {
            distance = j;
            break;
          }
        }
        if(max_distance < distance) {
          max_distance = distance;
          candidate = s;
        }
      }
      s.erase(candidate);
      s.insert(t[i]);
      answer++;
    }
  }
  
  cout << answer << '\n';
  
  return 0;
}