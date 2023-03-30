#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

string n;
ll b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> b;
  ll k = 1;
  ll answer = 0;
  for(ll i = n.size() - 1; i >= 0; i--) {
    if(n[i] <= '9') answer += k * (n[i] - '0');
    else answer += k * (n[i] - 'A' + 10);
    k *= b;
  }
  cout << answer << '\n';
  
  return 0;
}