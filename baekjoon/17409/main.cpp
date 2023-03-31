#include <bits/stdc++.h>
#define INF 999999999999
#define MAXN 100100
#define MAXK 11
#define MOD 1000000007
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree;
  ll root, start, end;
  SegTree(ll n) {
    tree.resize(n * 4);
    root = 1;
    start = 0;
    end = n - 1;
  }
  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  void update(ll target, ll value) {
    update(root, start, end, target, value);
  }

  private:
  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) {
      return 0;
    } else if(left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = start + end >> 1;
      return (query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right)) % MOD;
    }
  }

  ll update(ll node, ll start, ll end, ll target, ll value) {
    if(target < start || end < target) {
      return tree[node];
    } else if(start == end) {
      return tree[node] = value % MOD;
    } else {
      ll mid = start + end >> 1;
      return tree[node] = (update(node * 2, start, mid, target, value) + update(node * 2 + 1, mid + 1, end, target, value)) % MOD;
    }
  }
};

ll n, k;
vector<pair<ll, ll>> a;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  a.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }

  sort(a.begin(), a.end());
  vector<SegTree> segs(k + 1, SegTree(n));

  for(ll i = 0; i < n; i++) {
    segs[1].update(a[i].second, 1);
    for(ll j = 2; j <= k; j++) {
      segs[j].update(a[i].second, segs[j-1].query(0, a[i].second - 1));
    }
  }

  cout << segs[k].query(0, n - 1) << '\n';
  
  return 0;
}