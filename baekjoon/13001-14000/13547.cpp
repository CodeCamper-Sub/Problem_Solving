#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

ll n, m, cnt[1000001], answer;
vector<ll> a, answers;
vector<tuple<ll, ll, ll>> queries;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  a.resize(n + 1);
  for(ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> m;
  queries.resize(m);
  answers.resize(m);
  for(ll i = 0; i < m; i++) {
    cin >> get<0>(queries[i]) >> get<1>(queries[i]);
    get<2>(queries[i]) = i;
  }

  ll sqrtN = 300;
  sort(queries.begin(), queries.end(), [=](auto a, auto b) {
    auto [s_a, e_a, i_a] = a;
    auto [s_b, e_b, i_b] = b;
    if(s_a / sqrtN != s_b / sqrtN) {
      return s_a / sqrtN < s_b / sqrtN;
    } else {
      return e_a < e_b;
    }
  });

  ll s = INF, e = INF;
  for(auto [ns, ne, i]: queries) {
    if(s == INF) {
      for(ll i = ns; i <= ne; i++) {
        if(cnt[a[i]] == 0) answer++;
        cnt[a[i]]++;
      }
      answers[i] = answer;
      s = ns;
      e = ne;
    } else {
      if(s <= ns) {
        for(ll i = s; i < ns; i++) {
          cnt[a[i]]--;
          if(cnt[a[i]] == 0) answer--;
        }
      } else {
        for(ll i = ns; i < s; i++) {
          if(cnt[a[i]] == 0) answer++;
          cnt[a[i]]++;
        }
      }

      if(e <= ne) {
        for(ll i = e + 1; i <= ne; i++) {
          if(cnt[a[i]] == 0) answer++;
          cnt[a[i]]++;
        }
      } else {
        for(ll i = ne + 1; i <= e; i++) {
          cnt[a[i]]--;
          if(cnt[a[i]] == 0) answer--;
        }
      }

      answers[i] = answer;
      s = ns;
      e = ne;
    }
  }

  for(ll answer: answers) {
    cout << answer << '\n';
  }
  
  return 0;
}