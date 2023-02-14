#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree;
  vector<ll> arr;
  ll root, start, end;
  SegTree(ll n) {
    tree = vector<ll>(n * 4);
    arr = vector<ll>(n);
    root = 1;
    start = 0;
    end = n - 1;
  }

  public:
  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  ll update(ll target) {
    return update(root, start, end, target, arr[target] + 1);
  }

  private:
  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) {
      return 0;
    } else if(left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = (start + end) / 2;
      return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
    }
  }

  ll update(ll node, ll start, ll end, ll target, ll value) {
    if(target < start || end < target) {
      return tree[node];
    } else if(start == end && start == target) {
      arr[start] = value;
      return tree[node] = arr[start];
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = update(node * 2, start, mid, target, value) + update(node * 2 + 1, mid + 1, end, target, value);
    }
  }
};

ll tt, n, x, y;
unordered_map<ll, ll> m;
vector<pair<ll, ll>> p;
set<ll> used_y;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> tt;
  while(tt--) {
    m.clear();
    p.clear();
    used_y.clear();
    cin >> n;
    for(ll i = 0; i < n; i++) {
      cin >> x >> y;
      p.push_back({x, y});
      used_y.insert(y);
    }
    ll used_y_cnt = 0;
    for(auto iter = used_y.rbegin(); iter != used_y.rend(); iter++) {
      m[*iter] = used_y_cnt++;
    }
    sort(p.begin(), p.end(), [](auto a, auto b) {
      if(a.first != b.first) {
        return a.first < b.first;
      } else {
        return a.second > b.second;
      }
    });

    SegTree seg(used_y_cnt);
    ll answer = 0;
    for(auto[x, y]: p) {
      answer += seg.query(0, m[y]);
      seg.update(m[y]);
    }
    cout << answer << '\n';
  }

  return 0;
}