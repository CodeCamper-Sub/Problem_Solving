#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
string s1, s2;
set<string> dancing;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  dancing.insert("ChongChong");
  while(n--) {
    cin >> s1 >> s2;
    if(dancing.find(s1) != dancing.end() || dancing.find(s2) != dancing.end()) {
      dancing.insert(s1);
      dancing.insert(s2);
    }
  }

  cout << dancing.size() << '\n';
  
  return 0;
}