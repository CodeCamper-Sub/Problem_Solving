#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt;
ll n, a, b;

void init() {
  cin >> a >> b;
}

void solve() {
  string c = to_string(a);
  string d = to_string(b);
  ll mini = INF;
  ll maxi = -INF;
  if(c.size() != d.size()) {
    for(ll i = 0; i < c.size(); i++) {
      cout << 9;
    }
    cout << '\n';
    return;
  }
  ll thres = 0;
  while(c[thres] == d[thres]) {
    mini = min(mini, 1ll * (c[thres] - '0'));
    maxi = max(maxi, 1ll * (c[thres] - '0'));
    thres++;
  }
  if(thres == c.size()) {
    cout << c << '\n';
    return;
  }
  
  // 상한선 채택
  ll next_mini = min(mini, 1ll * (d[thres] - '0'));
  ll temp = thres;
  string answer_top = "";
  while(temp <= d.size() - 2 && d[temp] >= d[temp + 1]) {
    next_mini = min(next_mini, 1ll * (d[temp + 1] - '0'));
    temp++;
  }
  for(ll i = 0; i <= temp; i++) {
    answer_top += d[i];
  }
  for(ll i = temp + 1; i < d.size(); i++) {
    answer_top += d[temp];
  }
  

  // 하한선 채택
  ll next_maxi = max(maxi, 1ll * (c[thres] - '0'));
  temp = thres;
  string answer_bottom = "";
  while(temp <= c.size() - 2 && c[temp] <= c[temp + 1]) {
    next_maxi = max(next_maxi, 1ll * (c[temp + 1] - '0'));
    temp++;
  }
  for(ll i = 0; i <= temp; i++) {
    answer_bottom += c[i];
  }
  for(ll i = temp + 1; i < d.size(); i++) {
    answer_bottom += c[temp];
  }

  string answer = "";
  if(maxi - next_mini > next_maxi - mini) {
    answer = answer_bottom;
  } else {
    answer = answer_top;
  }

  if(maxi == next_maxi || mini == next_mini) {
    cout << answer << '\n';
    return;  
  }

  // 중간선 채택
  if(abs(c[thres] - d[thres]) > 1) {
    string answer_middle = "";
    for(ll i = 0; i < thres; i++) {
      answer_middle += c[i];
    }
    bool is_possible = false;
    for(ll i = c[thres] + 1; i < d[thres] - 1; i++) {
      if(mini <= i && maxi <= i) {
        for(ll j = thres; j < c.size(); j++) {
          answer_middle += i;
        }
        is_possible = true;
        break;
      }
    }
    if(!is_possible) {
      for(ll i = thres; i < c.size(); i++) {
        answer_middle += c[thres] + 1;
      }
    }
    answer = answer_middle;
  }


  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while(tt--) {
    init();
    solve();
  }
  return 0;
}