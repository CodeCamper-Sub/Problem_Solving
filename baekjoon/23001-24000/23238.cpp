#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, q, k, s, e, maxi;
vector<ll> a;
vector<tuple<ll, ll, ll>> queries;
unordered_map<ll, ll> cnt, ccnt;
vector<priority_queue<ll>> st;
vector<ll> answers;

void add(ll k) {
  ccnt[cnt[k]]--;
  cnt[k]++;
  ccnt[cnt[k]]++;
  st[cnt[k]].push(k);
  maxi = max(maxi, cnt[k]);
}

void remove(ll k) {
  ccnt[cnt[k]]--;
  cnt[k]--;
  ccnt[cnt[k]]++;
  st[cnt[k]].push(k);
  if(ccnt[maxi] == 0) maxi--;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> q;
  
  a.resize(n);
  st.resize(n + 1);
  for(ll& a: a) cin >> a;

  queries.resize(q);
  answers.resize(q);
  ll id = 0;
  for(auto& [s, e, i]: queries) {
    cin >> s >> e;
    s--; e--;
    i = id++;
  }

  k = sqrt(n);
  sort(queries.begin(), queries.end(), [](auto& a, auto& b) {
    if(get<0>(a) / k != get<0>(b) / k) return get<0>(a) / k < get<0>(b) / k;
    else return get<1>(a) < get<1>(b);
  });


  s = -1;
  e = -1;
  maxi = 0;
  for(auto [ns, ne, i]: queries) {
    if(s == -1 && e == -1) {
      s = ns;
      e = ns - 1;
      while(e < ne) {
        add(a[++e]);
      }
    } else {
      if(ns < s) {
        while(ns < s) {
          add(a[--s]);
        }
      }

      if(e < ne) {
        while(e < ne) {
          add(a[++e]);
        }
      } 
      
      if(s < ns) { // s < ns
        while(s < ns) {
          remove(a[s++]);
        }
      }
      if(ne < e) { // ne < e
        while(ne < e) {
          remove(a[e--]);
        }
      }
    }

    while(maxi > 0) {
      while(st[maxi].size() && cnt[st[maxi].top()] != maxi) st[maxi].pop();
      if(st[maxi].size()) break;
      else maxi--;
    }

    answers[i] = st[maxi].top();
  }

  for(ll answer: answers) cout << answer << '\n';

  return 0;
}