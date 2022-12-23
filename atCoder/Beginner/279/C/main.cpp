#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll H, W;
  string S[400400], T[400400];
  cin >> H >> W;
  for(ll i = 0; i < H; i++) {
    cin >> S[i];
  }
  for(ll i = 0; i < H; i++) {
    cin >> T[i];
  }
  string vertical_s[400400], vertical_t[400400];
  for(ll i = 0; i < W; i++) {
    vertical_s[i] = "";
    for(ll j = 0; j < H; j++) {
      vertical_s[i] += S[j][i];
      vertical_t[i] += T[j][i];
    }
  }
  sort(vertical_s, vertical_s+W);
  sort(vertical_t, vertical_t+W);

  bool answer = true;
  for(ll i = 0; i < W; i++) {
    answer &= vertical_s[i].compare(vertical_t[i]) == 0;
  }
  if(answer) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}