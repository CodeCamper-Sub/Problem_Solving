//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

ll n, w;
string s;
ll sum, maximum;
vector<pair<ll, char>> v;



int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  cin >> s;
  for(int i = 0; i < n; i++) {
    cin >> w;
    v.push_back({w, s[i]});
    if(s[i] == '1') {
      sum++;
    }
  }
  maximum = sum;
  sort(v.begin(), v.end());
  for(ll i = 0; i < v.size(); i++) {
    if(v[i].second == '0') {
      sum++;
    } else {
      sum--;
    }
    if(i < v.size()-1) {
      if(v[i].first != v[i+1].first) {
        maximum = max(maximum, sum);
      }
    } else {
      maximum = max(maximum, sum);
    }
  }
  cout << maximum << '\n';
  return 0;
}

