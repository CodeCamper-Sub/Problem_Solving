//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <string>
#include <set>
typedef long long ll;
using namespace std;

ll n, m, answer;
string k;
set<string> s;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  for(ll i = 1; i <= n; i++) {
    cin >> k;
    s.insert(k);
  }
  for(ll i = 1; i <= m; i++){
    cin >> k;
    if(s.find(k) != s.end()) {
      answer++;
    }
  }
  cout << answer << '\n';
  
  return 0;
}
