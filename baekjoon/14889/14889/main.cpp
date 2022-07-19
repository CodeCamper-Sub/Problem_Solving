//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
typedef long long ll;
using namespace std;

ll n, s[30][30];
ll answer = LONG_LONG_MAX;

bool contains(vector<ll> v, ll num) {
  for(ll i = 0; i < v.size(); i++) {
    if(v[i] == num) return true;
  }
  return false;
}

void backtracking(vector<ll> team_a, ll now) {
  if(team_a.size() == n / 2) {
    ll team_a_power = 0;
    ll team_b_power = 0;
    for(ll i = 1; i <= n; i++) {
      for(ll j = i+1; j <= n; j++) {
        if(i == j) continue;
        ll team_a_contains_i = binary_search(team_a.begin(), team_a.end(), i);
        ll team_a_contains_j = binary_search(team_a.begin(), team_a.end(), j);
        if(team_a_contains_i && team_a_contains_j) {
          team_a_power += s[i][j];
          team_a_power += s[j][i];
        } else if(!team_a_contains_i && !team_a_contains_j) {
          team_b_power += s[i][j];
          team_b_power += s[j][i];
        }
      }
    }
    answer = min(answer, abs(team_a_power - team_b_power));
  } else {
    ll left_team_a_member = n / 2 - team_a.size();
    for(ll i = now + 1; i <= n + 1 - left_team_a_member; i++) {
      team_a.push_back(i);
      backtracking(team_a, i);
      team_a.pop_back();
    }
  }
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= n; j++) {
      cin >> s[i][j];
    }
  }
  
  backtracking(vector<ll>(), 0);
  
  cout << answer << '\n';
  
  return 0;
}

