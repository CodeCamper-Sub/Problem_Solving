#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree;
  vector<ll> arr;
  ll root, start, end;
  function<ll(ll, ll)> compare;

  SegTree(ll n, function<ll(ll, ll)> compare) {
    tree = vector<ll>(n * 4);
    arr = vector<ll>(n);
    for(ll i = 0; i < n; i++) {
      arr[i] = i;
    }
    this->compare = compare;
    root = 1;
    start = 0;
    end = n - 1;
    build_tree(root, start, end);
  }

  void update(ll a, ll b) {
    ll temp = arr[a];
    arr[a] = arr[b];
    update(root, start, end, a);
    arr[b] = temp;
    update(root, start, end, b);
  }

  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  private:
  ll build_tree(ll node, ll start, ll end) {
    if(start == end) {
      return tree[node] = arr[start];
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = compare(build_tree(node * 2, start, mid), build_tree(node * 2 + 1, mid + 1, end));
    }
  }

  ll update(ll node, ll start, ll end, ll target) {
    if(target < start || end < target) {
      return tree[node];
    } else if(start == end) {
      return tree[node] = arr[target];
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = compare(update(node * 2, start, mid, target), update(node * 2 + 1, mid + 1, end, target));
    }
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) {
      return -compare(INF, -INF);
    } else if (left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = (start + end) / 2;
      return compare(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
    }
  }
};

ll T;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  while(T--) {
    ll N, K;
    cin >> N >> K;
    SegTree min_tree(N, [](ll a, ll b) {
      return a < b ? a : b;
    });
    SegTree max_tree(N, [](ll a, ll b) {
      return a < b ? b : a;
    });
    for(ll i = 0; i < K; i++) {
      ll Q, A, B;
      cin >> Q >> A >> B;
      if(Q == 0) {
        min_tree.update(A, B);
        max_tree.update(A, B);
      } else {
        if(min_tree.query(A, B) == A && max_tree.query(A, B) == B) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      }
    }
  }

  return 0;
} 