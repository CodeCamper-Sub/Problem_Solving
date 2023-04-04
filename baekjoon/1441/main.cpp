#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, L, R;
vector<ll> a;
ll coefficient;

ll get_number_of_multiples(ll divider) {
  if(R / divider == 0) return 0;
  return (R / divider) - max(((L + divider - 1) / divider), 1ll) + 1;
}

void get_combinations(vector<vector<ll>>& list, vector<ll>& sublist, ll length, ll now) {
  if(sublist.size() == length) {
    list.push_back(vector<ll>(sublist));
    return;
  }
  if(now >= a.size()) {
    return; 
  }
  for(ll i = now; i < a.size(); i++) {
    sublist.push_back(a[i]);
    get_combinations(list, sublist, length, i + 1);
    sublist.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> L >> R;
  a.resize(N);
  for(ll& a: a) cin >> a;
  sort(a.begin(), a.end());

  if(a[0] == 1) {
    cout << R - L + 1 << '\n';
    return 0;
  }

  ll answer = 0;
  coefficient = 1;
  for(ll i = 1; i <= N; i++) {
    vector<vector<ll>> list;
    vector<ll> sublist;
    get_combinations(list, sublist, i, 0);
    for(ll j = 0; j < list.size(); j++) {
      ll product = list[j][0];
      for(ll k = 1; k < list[j].size(); k++) {
        product = (list[j][k] * product) / (gcd(product, list[j][k]));
        if(product > R) break;
      }
      if(product > R) continue;
      answer += coefficient * get_number_of_multiples(product);
    }
    coefficient = -coefficient;
  }

  cout << answer << '\n';
  
  return 0;
}