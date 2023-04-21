#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  while(n--) {
    cin >> s;
    sort(s.begin(), s.end());
    do {
      cout << s << '\n';
    } while(next_permutation(s.begin(), s.end()));
  }
  
  return 0;
}