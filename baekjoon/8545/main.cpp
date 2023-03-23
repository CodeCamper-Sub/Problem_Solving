#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  ll n = s.size();
  while(n--) {
    cout << s[n];
  }
  
  return 0;
}