#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

ll n;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  bool is_valid = true;
  cin >> n >> s;
  for(ll i = 0; i < s.size() - 1; i++) {
    if(s[i] == s[i+1]) is_valid = false;
  }

  if(is_valid) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  
  return 0;
}