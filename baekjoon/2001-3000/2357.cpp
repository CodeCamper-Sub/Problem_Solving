#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

enum TreeType {
  MIN,
  MAX
};

struct SegmentTree {
  vector<ll> tree;
  vector<ll> arr;
  ll start, end, root;
  TreeType type;

  SegmentTree(vector<ll> arr, TreeType type) {
    tree = vector<ll>(arr.size() * 4);
    this->arr = arr;
    this->type = type;
    root = 1;
    start = 1;
    end = arr.size() -1;
    build_tree(root, start, end);
  }

  public:
  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  private:
  ll build_tree(ll node, ll start, ll end) {
    if(start == end) {
      tree[node] = arr[start];
    } else {
      ll mid = (start + end) / 2;
      if(type == MIN) {
        tree[node] = min(build_tree(node * 2, start, mid), build_tree(node * 2 + 1, mid + 1, end));
      } else {
        tree[node] = max(build_tree(node * 2, start, mid), build_tree(node * 2 + 1, mid + 1, end));
      }
    }
    return tree[node];
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(end < left || right < start) {
      if(type == MIN) {
        return INF;
      } else {
        return -INF;
      }
    } else if(left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = (start + end) / 2;
      if(type == MIN) {
        return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
      } else {
        return max(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
      }
    }
  }
};

ll N, M, a, b;
vector<ll> arr;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  arr = vector<ll>(N + 1);
  for(ll i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  SegmentTree min_seg = SegmentTree(arr, MIN);
  SegmentTree max_seg = SegmentTree(arr, MAX);
  for(ll i = 0; i < M; i++) {
    cin >> a >> b;
    cout << min_seg.query(a, b) << ' ' << max_seg.query(a, b) << '\n';
  }

  return 0;
}