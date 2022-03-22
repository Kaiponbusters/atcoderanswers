#include <bits/stdc++.h>
using namespace std;

// clang-format off
/* accelration */
// 高速バイナリ生成
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// cin cout の結びつけ解除, stdioと同期しない(入出力非同期化)
// cとstdの入出力を混在させるとバグるので注意
struct Fast {Fast() {std::cin.tie(0); ios::sync_with_stdio(false);}} fast;

/* alias */
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using pii = pair<int, int>;

/* define short */
#define pb push_back
#define mp make_pair
#define all(obj) (obj).begin(), (obj).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define repd(i,n) for(ll i=n-1;i>=0;i--)
#define rrepd(i,n) for(ll i=n;i>=1;i--)

/* debug */
// 標準エラー出力を含む提出はrejectされる場合もあるので注意
#define debug(x) cerr << "\033[33m(line:" << __LINE__ << ") " << #x << ": " << x << "\033[m" << endl;

/* func */
inline int in_int() {int x; cin >> x; return x;}
inline ll in_ll() {ll x; cin >> x; return x;}
inline string in_str() {string x; cin >> x; return x;}
// search_length: 走査するベクトル長の上限(先頭から何要素目までを検索対象とするか、1始まりで)
template <typename T> inline bool vector_finder(std::vector<T> vec, T element, unsigned int search_length) {
    auto itr = std::find(vec.begin(), vec.end(), element);
    size_t index = std::distance( vec.begin(), itr );
    if (index == vec.size() || index >= search_length) {return false;} else {return true;}
}
template <typename T> inline void print(const vector<T>& v, string s = " ")
    {rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");}
template <typename T, typename S> inline void print(const pair<T, S>& p)
    {cout << p.first << " " << p.second << endl;}
template <typename T> inline void print(const T& x) {cout << x << "\n";}
template <typename T, typename S> inline void print(const vector<pair<T, S>>& v)
    {for (auto&& p : v) print(p);}
// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}
// gcd lcm
// C++17からは標準実装
// template <typename T> T gcd(T a, T b) {if (b == 0)return a; else return gcd(b, a % b);}
// template <typename T> inline T lcm(T a, T b) {return (a * b) / gcd(a, b);}
// clang-format on

ll nCk(ll n, ll k) {
    ll nkaijo = 1;
    ll kkaijo = 1;
    ll nkkaijo = 1;

    rep(i,n) nkaijo *= n - i;
    rep(i,k) kkaijo *= k - i;
    rep(i,n - k) nkkaijo *= n - k - i;

    return (nkaijo / (kkaijo * nkkaijo));
}


//Answer
int main() {
    vs s(3),t(3);
    rep(i,3) cin >> s[i];
    rep(i,3) cin >> t[i];
    int rcnt1 = 0,gcnt1 = 0, bcnt1 = 0;
    int rcnt2 = 0,gcnt2 = 0, bcnt2 = 0;
    rep(i,s.size()) {
        if(s.at(i) == "R") rcnt1++;
        else if(s.at(i) == "G") gcnt1++;
        else if(s.at(i) == "B") bcnt1++;
    }
    rep(i,t.size()) {
        if(t.at(i) == "R") rcnt2++;
        else if(t.at(i) == "G") gcnt2++;
        else if(t.at(i) == "B") bcnt2++;
    }
    int cnt = 0;
    bool flag = false;
    if(rcnt1 == rcnt2 && gcnt1 == gcnt2 && bcnt1 == bcnt2) flag = true;

    if(rcnt1 == 3 && rcnt2 == 3) cout << "Yes" << endl;
    else if(gcnt1 == 3 && gcnt2 == 3) cout << "Yes" << endl;
    else if(bcnt1 == 3 && bcnt2 == 3) cout << "Yes" << endl;
    else if(flag){
        rep(i,s.size()) {
            if(s[i] == t[i]) cnt++;
        }
        if(cnt == 1) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}