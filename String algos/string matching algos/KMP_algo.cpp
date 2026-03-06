#include<bits/stdc++.h>
#include<fstream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define testcases ll tsts; cin>>tsts; for(ll t=0;t<tsts;t++)
#define MOD 1000000007
#define MOD1 998244353
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define PI 3.141592653589793238462
#define ff first
#define ss second
#define len length
const long long INF=1e18;
//for rotatory array you can use mod of index by size of the array
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#ifndef ONLINE_JUDGE
#include "Adibug.h"
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
#ifndef ONLINE_JUDGE
#include "Adibug2.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
 

//kmp string matching
vector<int> kmp(string s){
    vector<int> lps(s.size(), 0);
    
    for(int i=1;i<lps.size();i++){
        int prev_idx = lps[i-1];
        
        while(prev_idx>0 && s[i] != s[prev_idx]){
            prev_idx = lps[prev_idx-1];
        }
        
        lps[i] = prev_idx + (s[i]==s[prev_idx] ? 1 : 0);
    }
    return lps;
}

//advtik solved here
void solve(){
    

}
 
int main(){
    fastio
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    #endif
    // sieve();
    // testcases{
        solve();
    // }
    return 0;
}
