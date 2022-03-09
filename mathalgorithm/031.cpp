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


//Answer
// int main() {
//     ll n,a[500009];
//     ll dp1[500009],dp2[500009];

//     cin >> n;
//     for(int i = 1;i <= n; i++) cin >> a[i];

//     dp1[0] = 0;
//     dp2[0] = 0;

//     for(int i = 1;i <= n; i++) {
//         dp1[i] = dp2[i - 1] + a[i];
//         dp2[i] = max(dp1[i - 1],dp2[i - 1]);
//     }

//     cout << max(dp1[n],dp2[n]) << endl;
//     return 0;
// }

/*
    dp1[i]: i日目に勉強する場合の、これまでの実力アップ最大値
    dp2[i]: i日目に勉強しない場合の、これまでの実力アップ最大値

    i日目に勉強する場合は方法は一つ
        ・i日目に勉強する場合、実力がa[i]上がるため、dp1[i] = dp2[i-1] + a[i](i-1日目に勉強しない)・・・2日連続で勉強ができないから
    
    i日目に勉強しない場合は2つの方法がある。
        ・i-1日目に勉強する場合(dp1[i-1])
        ・i-1日目に勉強しない(dp2[i-1])


    ex) N = 5, A[i] = {2,5,3,3,1}の場合
*/

ll n,a[500009];
ll dp1[500009],dp2[500009];

int main() {
    cin >> n;
    reps(i,1,n+1) cin >> a[i];
    
    dp1[0] = 0; dp2[0] = 0;

    reps(i,1,n+1) {
        dp1[i] = dp2[i - 1] + a[i];
        dp2[i] = max(dp1[i - 1], dp2[i - 1]);
    }

    cout << max(dp1[n], dp2[n]) << endl;
    return 0;
}

// long long N, A[500009];
// long long dp1[500009], dp2[500009];

// int main() {
// 	// 入力
// 	cin >> N;
// 	for (int i = 1; i <= N; i++) cin >> A[i];
	
// 	// 配列の初期化
// 	dp1[0] = 0;
// 	dp2[0] = 0;
	
// 	// 動的計画法
// 	for (int i = 1; i <= N; i++) {
// 		dp1[i] = dp2[i - 1] + A[i];
// 		dp2[i] = max(dp1[i - 1], dp2[i - 1]);
// 	}
	
// 	// 答えを出力
// 	cout << max(dp1[N], dp2[N]) << endl;
// 	return 0;
// }