//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
typedef long long ll;
using namespace std;

string s;
unordered_set<string> substring;


int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;
  for(ll i = 1; i <= s.size(); i++) {
    for(ll j = 0; j < s.size(); j++) {
      substring.insert(s.substr(j, i));
    }
  }
  cout << substring.size() << '\n';
  
  return 0;
}

