#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

enum Operation {
  SUM,
  SUBTRACT,
  MULTIPLE,
  DIVIDE
};

bool operation_hiercy(ll o) {
  return (o == MULTIPLE || o == DIVIDE) ? 1 : 0;
}

struct Expression {
  ll lhs, operation, rhs;

  bool operator<(const Expression& other) {
    if(operation_hiercy(operation) != operation_hiercy(other.operation)) {
      return operation_hiercy(operation) < operation_hiercy(other.operation);
    }
    if(compute() != other.compute()) {
      return compute() < other.compute();
    }
    return false;
  }

  ll compute() const {
    if(operation == SUM) return lhs + rhs;
    else if(operation == SUBTRACT) return lhs - rhs;
    else if(operation == MULTIPLE) return lhs * rhs;
    else return lhs / rhs;
  }
};

string s;
deque<ll> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> s;
  ll num = 0;
  for(ll i = 0; i < s.size(); i++) {
    if(i == 0 && s[i] == '-') continue;
    if(s[i] >= '0' && s[i] <= '9') {
      num *= 10;
      num += s[i] - '0';
    } else {
      q.push_back(num);
      num = 0;
      if(s[i] == '+') {
        q.push_back(SUM);
      } else if(s[i] == '-') {
        q.push_back(SUBTRACT);
      } else if(s[i] == '*') {
        q.push_back(MULTIPLE);
      } else {
        q.push_back(DIVIDE);
      }
    }
  }
  q.push_back(num);
  if(s[0] == '-') {
    ll f = q.front();
    q.pop_front();
    q.push_front(-f);
  }

  while(q.size() >= 3) {
    Expression left, right;
    left.lhs = q.front(); q.pop_front();
    left.operation = q.front(); q.pop_front();
    left.rhs = q.front();
    q.push_front(left.operation);
    q.push_front(left.lhs);

    right.rhs = q.back(); q.pop_back();
    right.operation = q.back(); q.pop_back();
    right.lhs = q.back();
    q.push_back(right.operation);
    q.push_back(right.rhs);

    if(left < right) {
      for(ll i = 0; i < 3; i++) q.pop_back();
      q.push_back(right.compute());
    } else {
      for(ll i = 0; i < 3; i++) q.pop_front();
      q.push_front(left.compute());
    }
  }

  cout << q.front() << '\n';
  
  return 0;
}