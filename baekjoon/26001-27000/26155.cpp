#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, M, a, b, Q, network_cnt;
double p;
vector<tuple<ll, ll, ll>> e;
vector<tuple<ll, ll>> queries;
ll answer[100100], parent[100100];

ll Find(ll now){
  if(parent[now] == -1) {
    return now;
  } else {
    return parent[now] = Find(parent[now]);
  }
}

bool Union(ll a, ll b) {
  a = Find(a);
  b = Find(b);
  if(a != b) {
    parent[a] = b;
    return true;
  } else {
    return false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  network_cnt = N;
  for(ll i = 0; i <= N; i++) {
    parent[i] = -1;
  }
  for(ll i = 0; i < M; i++) {
    cin >> a >> b >> p;
    e.push_back({a, b, p * 10000 + 0.5});
  }
  cin >> Q;
  for(ll i = 0; i < Q; i++) {
    cin >> p;
    queries.push_back({p * 10000 + 0.5, i});
  }
  sort(e.begin(), e.end(), [](tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
    return get<2>(a) > get<2>(b);
  });

  sort(queries.begin(), queries.end(), [](tuple<ll, ll> a, tuple<ll, ll> b) {
    return get<0>(a) > get<0>(b);
  });

  auto iter = e.begin();
  for(ll i = 0; i < queries.size(); i++) {
    tuple<ll, ll> query = queries[i];
    while(iter != e.end() && get<2>(*iter) >= get<0>(query)) {
      if(Union(get<0>(*iter), get<1>(*iter))) {
        network_cnt--;
      }
      iter++;
    }
    answer[get<1>(query)] = network_cnt;
  }

  for(ll i = 0; i < Q; i++) {
    cout << answer[i] << '\n';
  }

  return 0;
}