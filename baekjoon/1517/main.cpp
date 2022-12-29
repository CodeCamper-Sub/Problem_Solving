#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct SegmentTree {
  vector<ll> tree;
  vector<ll> arr;
  ll root, start, end;

  SegmentTree(ll n) {
    tree = vector<ll>(n * 4);
    arr = vector<ll>(n);
    root = 1;
    start = 0;
    end = n - 1;
  }

  public:
  ll update(ll target, ll value) {
    return update(root, start, end, target, value);
  }

  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  private:
  ll update(ll node, ll start, ll end, ll target, ll value) {
    if(target < start || end < target) {
      return tree[node];
    } else if(start == end) {
      arr[target] = value;
      return tree[node] = arr[target];
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = update(node * 2, start, mid, target, value) + update(node * 2 + 1, mid + 1, end, target, value);
    }
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(end < left || right < start) {
      return 0;
    } else if(left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = (start + end) / 2;
      return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
    }
  }
};

ll N, A[500500], answer;
vector<pair<ll, ll>> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(ll i = 0; i < N; i++) {
    cin >> A[i];
    v.push_back({A[i], i});
  }
  SegmentTree seg(N);

  sort(v.begin(), v.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
    return a.first < b.first;
  });

  ll left_pointer = 0;
  for(ll right_pointer = 1; right_pointer <= N; right_pointer++) {
    if(right_pointer == N || v[right_pointer].first != v[right_pointer-1].first) {
      for(ll i = left_pointer; i < right_pointer; i++) {
        answer += seg.query(v[i].second + 1, N - 1);
      }
      for(ll i = left_pointer; i < right_pointer; i++) {
        seg.update(v[i].second, 1);
      }
      left_pointer = right_pointer;
    }
  }
  
  cout << answer << '\n';

  return 0;
}