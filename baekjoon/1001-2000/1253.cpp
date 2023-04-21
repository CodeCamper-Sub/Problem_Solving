#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

map<ll, ll> m;
set<ll> s;
ll n, answer;
vector<ll> a;

void back_tracking(ll now, vector<ll>& selected) {
  if(selected.size() >= 2) {
    ll sum = selected[0] + selected[1];
    if(selected[0] == 0 && selected[1] == 0) {
      if(m[0] >= 3) {
        s.insert(sum);
      }
    } else if(selected[0] == 0) {
      if(m[selected[1]] > 1) {
        s.insert(sum);
      }
    } else if(selected[1] == 0) {
      if(m[selected[0]] > 1) {
        s.insert(sum);
      }
    } else {
      s.insert(sum);
    }
    return;
  }
  if(now == a.size()) return;
  
  back_tracking(now + 1, selected);
  selected.push_back(a[now]);
  back_tracking(now + 1, selected);
  selected.pop_back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.assign(n, 0);
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }

  vector<ll> selected;
  back_tracking(0, selected);

  for(ll s: s) {
    if(m.find(s) == m.end()) continue;
    answer += m[s];
  }

  cout << answer << '\n';
  
  return 0;
}