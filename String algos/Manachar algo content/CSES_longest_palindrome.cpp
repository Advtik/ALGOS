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


//manachar algo
struct manachar{
    vector<int>p;

    //this is where actual manachar is running
    void run_manachar(string s){
        int n=s.length();
        p.assign(n,1);
        int l=0,r=0;
        for(int i=0;i<n;i++){
            if(i<r){
                p[i]=min(r-i, p[l+r-i]);
            }
            while(i+p[i]<n && i-p[i]>=0 && s[i+p[i]]==s[i-p[i]]){
                p[i]++;
            }
            if(i+p[i]>r){
                l=i-p[i];
                r=i+p[i];
            }
        }
    }

    //building the #string
    void build(string s){
        string t;
        for (auto &it:s){
            t+=string("#")+it;
        }
        run_manachar(t+"#");
    }

    //longest palindrome at the center which is either odd length or even length 
    int get_longest(int cen, int odd){
        int pos=2*cen+1+(!odd);
        return p[pos]-1;
    }

    //checking that there is a palindrome between l and r
    bool check_palindrome(int l,int r){
        int len=r-l+1;
        int cen=(l+r)/2;

        return get_longest(cen,len%2)>=len;
    }


}manachar;




//advtik solved here
void solve(){
    string s;
    cin>>s;
    manachar.build(s);
    int n=s.length();
    int ans=0;
    for(int i=0;i<n;i++){
        int temp=max(manachar.get_longest(i,1),manachar.get_longest(i,0));
        ans=max(temp,ans);
    }
    string sans="";
    for(int i=0;i<=n-ans;i++){
        if(manachar.check_palindrome(i,i+ans-1)){
            for(int j=i;j<i+ans;j++){
                sans+=s[j];
            }
            cout<<sans<<endl;
            return;
        }
    }

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
