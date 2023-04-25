#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
string s;

void init() {
  cin >> n >> s;
}
void solve() {
  char mini = *(min_element(s.begin(), s.end()));
  for(ll i = s.size() - 1; i >= 0; i--) {
    if(s[i] == mini) {
      string answer = s.substr(0, i) + s.substr(i + 1);
      answer = mini + answer;
      cout << answer << '\n';
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}