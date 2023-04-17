#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, t, cnt[1000001], sqrtN, k;
vector<ll> a, answers;
vector<tuple<ll, ll, ll>> queries;

void add(ll s) {
  k -= cnt[s] * cnt[s] * s;
  cnt[s] += 1;
  k += cnt[s] * cnt[s] * s;
}

void erase(ll s) {
  k -= cnt[s] * cnt[s] * s;
  cnt[s] -= 1;
  k += cnt[s] * cnt[s] * s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> t;
  a.resize(n + 1);
  queries.resize(t);
  answers.resize(t);
  for(ll i = 1; i <= n; i++) cin >> a[i];
  for(ll i = 0; i < t; i++) {
    cin >> get<0>(queries[i]) >> get<1>(queries[i]);
    get<2>(queries[i]) = i;
  }

  sqrtN = sqrt(n);
  sort(queries.begin(), queries.end(), [](auto a, auto b) {
    if(get<0>(a) / sqrtN != get<0>(b) / sqrtN) {
      return get<0>(a) / sqrtN < get<0>(b) / sqrtN;
    }
    return get<1>(a) < get<1>(b);
  });

  ll s = INF, e = INF;
  for(auto [ns, ne, index]: queries) {
    if(s == INF) {
      for(ll i = ns; i <= ne; i++) {
        add(a[i]);
      }
      answers[index] = k;
    } else {
      while(s < ns) {
        erase(a[s]);
        s++;
      }
      while(ns < s) {
        s--;
        add(a[s]);
      }
      while(e < ne) {
        e++;
        add(a[e]);
      }
      while(ne < e) {
        erase(a[e]);
        e--;
      }
      answers[index] = k;
    }
    s = ns;
    e = ne;
  }

  for(ll answer: answers) {
    cout << answer << '\n';
  }
  
  return 0;
}