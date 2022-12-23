#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string S, T;
  cin >> S >> T;
  ll i = 0;
  ll j = 0;
  while(i < S.size() && j < T.size()) {
    if(S[i] == T[j]) {
      i++; j++;
    } else {
      i++;
      j = 0;
    }
  }

  if(j == T.size()) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }

  return 0;
}