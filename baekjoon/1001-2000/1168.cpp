#include <bits/stdc++.h>
#define INF 999999999999
#define N_MAX 100100
typedef long long ll;
using namespace std;

ll N, K;

struct SegTree {
  vector<ll> tree;
  vector<ll> arr;
  ll root, start, end, now;
  SegTree(ll n) {
    tree = vector<ll>(n * 4);
    arr = vector<ll>(n + 1);
    fill(arr.begin(), arr.end(), 1);
    root = 1;
    start = 1;
    end = n;
    now = 1;
    build_tree(root, start, end);
  }

  public:
  ll pop(ll k) {
    if(k % tree[root] == 0) {
      k = tree[root];
    } else {
      k %= tree[root];
    }
    if(now == 1) {
      now = query(root, start, end, k);
      update(root, start, end, now, 0);
      return now;
    } else {
      ll previous = section_query(root, start, end, 1, now - 1);
      if(previous + k <= tree[root]) {
        now = query(root, start, end, previous + k);
        update(root, start, end, now, 0);
        return now;
      } else {
        k = previous + k;
        if(k % tree[root] == 0) {
          k = tree[root];
        } else {
          k %= tree[root];
        }
        now = query(root, start, end, k);
        update(root, start, end, now, 0);
        return now;
      }
    }
  }

  private:
  ll build_tree(ll node, ll start, ll end) {
    if(start == end) {
      return tree[node] = arr[start];
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = build_tree(node * 2, start, mid) + build_tree(node * 2 + 1, mid + 1, end);
    }
  }

  ll section_query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) {
      return 0;
    } else if(left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = (start + end) / 2;
      return section_query(node * 2, start, mid, left, right) + section_query(node * 2 + 1, mid + 1, end, left, right);
    }
  }

  ll query(ll node, ll start, ll end, ll target) {
    if(start == end) return start;
    ll mid = (start + end) / 2;
    if(target <= tree[node * 2]) {
      return query(node * 2, start, mid, target);
    } else {
      return query(node * 2 + 1, mid + 1, end, target - tree[node * 2]);
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K;
  SegTree seg(N);

  cout << "<";
  for(ll i = 0; i < N - 1; i++) {
    cout << seg.pop(K) << ", ";
  }
  cout << seg.pop(K) << ">\n";

  return 0;
}