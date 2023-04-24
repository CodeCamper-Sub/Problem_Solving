#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
string s;
set<string> used;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  ll answer = 0;
  while(n--) {
    cin >> s;
    if(s == "ENTER") {
      used.clear();
    } else if(used.find(s) == used.end()) {
      answer++;
      used.insert(s);
    }
  }

  cout << answer << '\n';
  
  return 0;
}