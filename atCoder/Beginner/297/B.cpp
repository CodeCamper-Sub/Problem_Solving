#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;
  bool is_valid = true;
  vector<ll> b_positions;
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] == 'B') b_positions.push_back(i);
  }

  if(b_positions[0] % 2 == b_positions[1] % 2) {
    is_valid = false;
  }

  vector<ll> r_positions;
  ll k_position;
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] == 'R') r_positions.push_back(i);
    else if(s[i] == 'K') k_position = i;
  }

  if(r_positions[0] > k_position || k_position > r_positions[1]) {
    is_valid = false;
  }

  cout << (is_valid ? "Yes" : "No") << '\n';
  
  return 0;
}