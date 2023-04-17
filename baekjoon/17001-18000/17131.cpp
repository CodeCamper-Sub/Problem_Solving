#include <bits/stdc++.h>
#define INF 999999999999
#define MOD 1000000007
#define POINT_MAX 400400
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree;
  vector<ll> arr;
  ll root, start, end;
  SegTree() {
    tree = vector<ll>(POINT_MAX * 4);
    arr = vector<ll>(POINT_MAX);
    root = 1;
    start = 0;
    end = POINT_MAX - 1;
  }

  public:
  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  ll update(ll target, ll delta) {
    return update(root, start, end, target, arr[target] + delta);
  }

  private:
  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) {
      return 0;
    } else if(left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = (start + end) / 2;
      return (query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right)) % MOD;
    }
  }

  ll update(ll node, ll start, ll end, ll target, ll value) {
    if(target < start || end < target) {
      return tree[node];
    } else if(start == end && start == target) {
      arr[target] = value;
      return tree[node] = arr[target] % MOD;
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = (update(node * 2, start, mid, target, value) + update(node * 2 + 1, mid + 1, end, target, value)) % MOD;
    }
  }
};

ll N;
vector<tuple<ll, ll, ll>> points; // x, y, id
ll memo[200200];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  for(ll i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    points.push_back({x + 200001, y + 200001, i});
  }

  sort(points.begin(), points.end());

  SegTree seg;
  for(auto [x, y, id]: points) {
    memo[id] = seg.query(y + 1, POINT_MAX - 1);
    seg.update(y, 1);
  }

  sort(points.begin(), points.end(), [](auto a, auto b) {
    auto [a_x, a_y, a_id] = a;
    auto [b_x, b_y, b_id] = b;
    if(a_x != b_x) {
      return a_x < b_x;
    } else {
      return a_y > b_y;
    }
  });

  seg = SegTree();
  ll answer = 0;
  for(auto [x, y, id]: points) {
    answer += seg.query(0, y - 1);
    answer %= MOD;
    seg.update(y, memo[id]);
  }

  cout << answer << '\n';

  return 0;
}