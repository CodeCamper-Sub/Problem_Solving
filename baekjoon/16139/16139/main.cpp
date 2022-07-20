//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

string s;
char a;
ll q, l, r;
ll sum[30][200200];

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;
  for(ll i = 0; i < s.size(); i++) {
    for(ll j = 0; j < 26; j++) {
      if(s[i]-'a' == j) {
        sum[j][i] = sum[j][i-1] + 1;
      } else {
        sum[j][i] = sum[j][i-1];
      }
    }
  }
  cin >> q;
  for(ll i = 1; i <= q; i++) {
    cin >> a >> l >> r;
    if(l > 0) {
      cout << sum[a-'a'][r] - sum[a-'a'][l-1] << '\n';
    } else {
      cout << sum[a-'a'][r] << '\n';
    }
  }
  
  return 0;
}

