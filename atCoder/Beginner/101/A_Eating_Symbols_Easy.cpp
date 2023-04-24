#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll answer;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;
  for(ll i = 0; i < s.size(); i++) {
    if(s[i] == '+') {
      answer++;
    } else {
      answer--;
    }
  }

  cout << answer << '\n';
  
  return 0;
}