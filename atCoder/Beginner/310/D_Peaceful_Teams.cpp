#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n, t, m, cnt;
vector<set<ll>> st;

bool can_go(ll me, vector<ll>& team) {
  for(ll member: team) {
    if(st[me].find(member) != st[me].end()) return false;
  }
  return true;
}

ll brute_force(ll now, vector<vector<ll>>& team) {
  if(now > n) 
    return team.size() == t ? 1 : 0;
  if(t - team.size() > n - now + 1) return 0;
  ll result = 0;
  for(ll i = 0; i < team.size(); i++) { 
    if(can_go(now, team[i])) {
      team[i].push_back(now);
      result += brute_force(now + 1, team);
      team[i].pop_back();
    }
  }

  if(team.size() < t) {
    team.push_back({now});
    result += brute_force(now + 1, team);
    team.pop_back();
  }
  
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> t >> m;
  if(t == 1) {
    cout << (m > 0 ? 0 : 1) << '\n';
    return 0;
  }

  st.resize(n + 1);
  for(ll i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    st[a].insert(b);
    st[b].insert(a);
  }

  vector<vector<ll>> team;
  cout << brute_force(1, team) << '\n';

  return 0;
}