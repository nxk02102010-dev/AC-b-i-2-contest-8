#include <bits/stdc++.h>
using namespace std;
//Coder:RichKidlor in 10IT CTL_DL
//Contest : Codeforces,Vnoi,Clueoj,TLOI
#define FOR(i,a,b) for(int i = (a);i < (b);i++)
#define REP(i,a,b) for(int i = (a);i <= (b);i++)
#define REPD(i,a,b) for(int i = (a); i >= (b);i--)
#define FORD(i,a,b) for(int i = (a);i > (b);i--)
#define fi first
#define se second
#define pb push_back
#define BIT(mask,i) (mask) & (1 << (i))
#define CHECK(mask,i) (((mask) >> (i)) & 1)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define allr(x) (x).rbegin(),(x).rend()
#define pli pair<ll,int>
#define nocout cout << "NO" << '\n'
#define yescout cout << "YES" << '\n'
#define INF (ll) 1e18
#define iINF 1e9
#define i128 __int128_t
#define minusone cout << -1 << '\n'
#define ar array
//_________MODPOW___________
//ll modpow(ll a,ll b){
//    ll res = 1;
//    while(b){
//        if(b & 1) res = res * a % MOD;
//        a = a * a % MOD;
//        b >>= 1;
//    }
//    return res;
//}
//_________HASH__________
//vector<ll> h,p;
//void hashing(const string &s){
//    int n = sz(s);
//    h.assign(n + 1,0);
//    p.assign(n + 1,1);
//    FOR(i,0,n){
//        h[i + 1] = (h[i] * BASE + (s[i] - 'a' + 1)) % MOD;
//        p[i + 1] = (p[i] * BASE) % MOD;
//    }
//}
//ll gethash(int l,int r){
//    return (h[r] - h[l] * p[r - l] % MOD + MOD) % MOD;
//}
// ___________Segment_Tree____________
//struct Segment{
//    void build(int v,int l,int r){
//        if(l == r) t[v] = a[l];
//        else{
//            int m = (l + r ) / 2;
//            build(2 * v,l,m);
//            build(2 * v + 1,m + 1,r);
//            t[v] = t[2 * v] + t[2 * v + 1];
//        }
//    }
//    void update(int v,int l,int r,int pos,int val){
//        if(l == r) t[v] = val;
//        else{
//            int m = (l + r) / 2;
//            if(pos >= m){ update(2 * v + 1,m + 1,r,pos,val);}
//            else update(2 * v,l,m,pos,val);
//            t[v] = t[2 * v] + t[2 * v + 1];
//        }
//    }
//    int query(int v,int l,int r,int tl,int tr){
//        if(l > tr || r < tl) return 0;
//        if(l >= tl && r <= tr) return t[v];
//        int m = (l + r) / 2;
//        return query(2 * v,l,m,tl,tr) + query(2 * v + 1,m + 1,r,tl,tr);
//    }
//};
//____FENWICK___
//struct Fenwick{
//    void update(int pos,int val){
//        while(pos <= n){
//            bit[pos] += val;
//            pos += pos & -pos;
//        }
//    }
//    int query(int pos){
//        int ans = 0;
//        while(pos){
//            ans += bit[pos];
//            pos -= pos & -pos;
//        }
//    }
//};
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
#define STR(x) #x
#define FileName(x) STR(x)
//#define File dcs
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
//#define int long long
//#define ll __int128
#define ll long long
char noi(char a,char b,char c){
    int A = (a == 'A') + (b == 'A') + (c == 'A');
    return (A >= 2 ? 'A' : 'B');
}
void solve(void){
    int n,q;cin >> n >> q;
    vector<string> f(n + 1);
    cin >> f[0];
    FOR(i,1,n + 1){
        //int b = i * 3;
        int len = sz(f[i - 1]);
        f[i].resize(len + 1);
        FOR(k,0,len){
            int b = k * 3;
            f[i][k] = noi(f[i - 1][b],f[i - 1][b + 1],f[i - 1][b + 2]);
        }
    }
    while(q--){
        int posi;
        cin >> posi;posi--;
        f[0][posi] = (f[0][posi] == 'A' ? 'B' : 'A');
        int pos = posi;
        FOR(k,1,n + 1){
            int i = pos / 3;
            f[k][i] = noi(f[k - 1][i * 3],f[k - 1][i * 3 + 1],f[k - 1][i * 3 + 2]);
            pos = i;
        }
        cout << f[n][0] << '\n';
    }
}
signed main(){
    //freopen("DoiCuuTroIT.Inp","r",stdin);
    //freopen("DoiCuuTroIT.Out","w",stdout);
#ifdef File
    freopen(FileName(File)".inp","r",stdin);
    freopen(FileName(File)".out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;//cin >> t;
    while(t--)
    solve();
    return 0;
}

