#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll T;
  cin >> T;
  while(T--) {
    string s;
    cin >> s;
    cout << s[0] << s[s.size()-1] << '\n';
  }

  return 0;
}