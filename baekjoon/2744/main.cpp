#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  ll differ = ll('a') - ll('A');
  for(ll i = 0; i < s.size(); i++) {
    cout << char(s[i] >= 'a' ? s[i] - differ : s[i] + differ);
  }
  
  return 0;
}