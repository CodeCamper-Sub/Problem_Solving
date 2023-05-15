#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> a, answer;
map<ll, ll> cnt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.resize(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
  for(ll i = 0; i < n; i++) {
    cnt[a[i]]++;
  }

  for(auto iter = cnt.begin(); iter != cnt.end(); iter++) {
    if(iter->second <= 0) continue;
    if(answer.empty() || answer.back() + 1 != iter->first) {
      while(iter->second--) answer.push_back(iter->first);
    } else {
      auto next = iter; next++;
      if(next != cnt.end()) {
        answer.push_back(next->first);
        next->second--;
        while(iter->second--) answer.push_back(iter->first);
      } else {
        vector<ll> temp;
        while(answer.size() && answer.back() + 1 == iter->first) {
          temp.push_back(answer.back());
          answer.pop_back();
        }
        while(iter->second--) answer.push_back(iter->first);
        while(temp.size()) {
          answer.push_back(temp.back());
          temp.pop_back();
        }
      }
    }
  }

  for(ll a: answer) {
    cout << a << ' ';
  }
  
  return 0;
}