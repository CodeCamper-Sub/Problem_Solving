#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

string a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> a >> b;
  cout << (a.size() >= b.size() ? "go" : "no");
  
  return 0;
}