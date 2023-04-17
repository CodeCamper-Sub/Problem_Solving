#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

enum Move {
  None,
  Do,
  Gae,
  Gul,
  Yut,
  Mo
};

istream& operator>>(istream& cin, Move& rhs) {
  string s;
  cin >> s;
  if(s == "Do") {
    rhs = Do;
  } else if(s == "Gae") {
    rhs = Gae;
  } else if(s == "Gul") {
    rhs = Gul;
  } else if(s == "Yut") {
    rhs = Yut;
  } else {
    rhs = Mo;
  }
  return cin;
}

ll tt, u, n, A, B;
vector<Move> moves;
vector<ll> a, b;

ll go(ll now, ll previous, ll left_move, bool start_from_here) {
  if(left_move == 0) return now;
  if(now == 5) {
    if(start_from_here) {
      return go(20, now, left_move - 1, false);
    } else {
      return go(6, now, left_move - 1, false);
    }
  } else if(now == 10) {
    if(start_from_here) {
      return go(25, now, left_move - 1, false);
    } else {
      return go(11, now, left_move - 1, false);
    }
  } else if(now == 22) {
    if(start_from_here || previous == 26) {
      return go(27, now, left_move - 1, false);
    } else {
      return go(23, now, left_move - 1, false);
    }
  } else if(now == 24) {
    return go(15, now, left_move - 1, false);
  } else if(now == 28 || now == 19) {
    return go(0, now, left_move - 1, false);
  } else if(now == 0) {
    return go(-2, now, 0, false);
  } else if(now == 26) {
    return go(22, now, left_move - 1, false);
  } else if(now == -1) {
    return go(1, now, left_move - 1, false);
  } else {
    return go(now + 1, now, left_move - 1, false);
  }
}

void init() {
  cin >> u >> n >> A >> B;
  moves.resize(n);
  a.resize(A);
  b.resize(B);
  for(ll i = 0; i < n; i++) {
    cin >> moves[i];
  }
  for(ll i = 0; i < A; i++) {
    cin >> a[i];
  }
  for(ll i = 0; i < B; i++) {
    cin >> b[i];
  }
}

void play_game(ll& a_now, ll& b_now, ll turn, ll t) {
  if(t == moves.size()) return;
  if(a_now == -2) {
    b_now = go(b_now, -1, moves[t], true);
    play_game(a_now, b_now, turn, t + 1);
  } else if(b_now == -2) {
    a_now = go(a_now, -1, moves[t], true);
    play_game(a_now, b_now, turn, t + 1);
  }
  ll next_turn = 1 - turn;
  if(turn == 0) {
    ll a_next = go(a_now, -1, moves[t], true);
    if(b_now == a_next) {
      next_turn = turn;
      b_now = -1;
    } else if(moves[t] == Yut || moves[t] == Mo) {
      next_turn = turn;
    }
    a_now = a_next;
    play_game(a_now, b_now, next_turn, t + 1);
  } else {
    ll b_next = go(b_now, -1, moves[t], true);
    if(a_now == b_next) {
      next_turn = turn;
      a_now = -1;
    } else if(moves[t] == Yut || moves[t] == Mo) {
      next_turn = turn;
    }
    b_now = b_next;
    play_game(a_now, b_now, next_turn, t + 1);
  }
}

bool a_correct(ll a_now) {
  if((a.size() == 0 && (a_now == -1 || a_now == -2)) || a[0] == a_now) return true;
  return false;
}

bool b_correct(ll b_now) {
  if((b.size() == 0 && (b_now == -1 || b_now == -2)) || b[0] == b_now) return true;
  return false;
}

string solve() {
  ll a_now = -1;
  ll b_now = -1;
  ll turn = 0;
  play_game(a_now, b_now, turn, 0);
  if(a_correct(a_now) && b_correct(b_now)) {
    return "YES";
  }
  a_now = -1;
  b_now = -1;
  turn = 1;
  play_game(a_now, b_now, turn, 0);
  if(a_correct(a_now) && b_correct(b_now)) {
    return "YES";
  }
  return "NO";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    cout << "Case #" << T << ": " << solve() << '\n';
  }
  return 0;
}