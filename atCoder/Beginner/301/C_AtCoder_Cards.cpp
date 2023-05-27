#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

string a, b;
vector<ll> cnt_a, cnt_b;
ll w_a, w_b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> a >> b;
  cnt_a.resize(26);
  cnt_b.resize(26);
  for(ll i = 0; i < a.size(); i++) {
    if(a[i] != '@') {
      cnt_a[a[i] - 'a']++;
    } else {
      w_a++;
    }
  }
  for(ll i = 0; i < b.size(); i++) {
    if(b[i] != '@') {
      cnt_b[b[i] - 'a']++;
    } else {
      w_b++;
    }
  }

  for(ll i = 0 ; i < 26; i++) {
    if(cnt_a[i] == cnt_b[i]) continue;
    if(i + 'a' != 'a' && i + 'a' != 't' && i + 'a' != 'c' && i + 'a' != 'o' && i + 'a' != 'd' && i + 'a' != 'e' && i + 'a' != 'r') {
      cout << "No\n";
      return 0;
    }
    if(cnt_a[i] < cnt_b[i]) {
      w_a -= cnt_b[i] - cnt_a[i];
    } else {
      w_b -= cnt_a[i] - cnt_b[i];
    }
  }

  if(w_a >= 0 && w_b >= 0) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  
  return 0;
}