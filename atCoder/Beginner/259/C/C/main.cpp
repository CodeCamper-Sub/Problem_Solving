//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <queue>
#include <string>
typedef long long ll;
using namespace std;

string s, t;
queue<pair<char, int>> q_s, q_t;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;
  cin >> t;
  
  for(int i = 0; i < s.size(); i++){
    if(q_s.empty()) {
      q_s.push({s[i], 1});
    } else if(q_s.back().first == s[i]) {
      q_s.back().second++;
    } else {
      q_s.push({s[i], 1});
    }
  }
  for(int i = 0; i < t.size(); i++) {
    if(q_t.empty()) {
      q_t.push({t[i], 1});
    } else if(q_t.back().first == t[i]) {
      q_t.back().second++;
    } else {
      q_t.push({t[i], 1});
    }
  }
  if(q_s.size() != q_t.size()) {
    cout << "No\n";
    return 0;
  }
  while(!q_s.empty() && !q_t.empty()) {
    if(q_s.front().first != q_t.front().first || q_s.front().second > q_t.front().second) {
      cout << "No\n";
      return 0;
    }
    if(q_s.front().second == 1 && q_t.front().second > 1) {
      cout << "No\n";
      return 0;
    }
    
    q_s.pop();
    q_t.pop();
  }
  cout << "Yes\n";
  
  return 0;
}

