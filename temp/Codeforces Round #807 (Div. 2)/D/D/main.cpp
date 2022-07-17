//
//  main.cpp
//
//  Created by 한경수 on 2022/07/15.
//

#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

ll tt, n;
string s, t;
ll answer;

void testcase() {
  answer = 0;
  cin >> n;
  cin >> s;
  cin >> t;
  vector<pair<char, ll>> v_s, v_t;
  
  for(ll i = 0; i < s.size(); i++) {
    if(v_s.empty()) {
      v_s.push_back({s[i], 1});
    } else {
      if(v_s.back().first == s[i]) {
        v_s.back().second++;
      } else {
        v_s.push_back({s[i], 1});
      }
    }
  }
  for(ll i = 0; i < t.size(); i++) {
    if(v_t.empty()) {
      v_t.push_back({t[i], 1});
    } else {
      if(v_t.back().first == t[i]) {
        v_t.back().second++;
      } else {
        v_t.push_back({t[i], 1});
      }
    }
  }
  if(v_s.size() != v_t.size() || v_s[0].first != v_t[0].first) {
    cout << -1 << '\n';
    return;
  }
  for(ll i = 0; i < v_s.size() - 1; i++){
    answer += abs(v_s[i].second - v_t[i].second);
    v_s[i+1].second = v_s[i+1].second + (v_s[i].second - v_t[i].second);
  }
  cout << answer << '\n';
  
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> tt;
  while(tt--) {
    testcase();
  }
  
  return 0;
}


