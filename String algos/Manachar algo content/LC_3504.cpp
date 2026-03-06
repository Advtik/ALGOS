class Solution {
public:
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


    vector<int> longest(string s){
        int n=s.size();

        manachar.build(s);

        vector<int>ret(n+1,0);

        for(int i=0;i<n;i++){
            for(int j=n-1;j>=i;j--){
                if(manachar.check_palindrome(i,j)){
                    ret[i]=j-i+1;
                    break;
                }
            }
        }

        return ret;
    }

    int longestPalindrome(string s,string t){
        int n=s.size();
        int m=t.size();

        reverse(t.begin(),t.end());

        vector<int>sls=longest(s);
        vector<int>slt=longest(t);
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(s[i]==t[j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                }
                else{
                    dp[i+1][j+1]=0;
                }
                
                ans=max(ans,
                    2*dp[i+1][j+1]+max(
                        sls[i+(s[i]==t[j])],
                        slt[j+(s[i]==t[j])]
                    )
                );
            }
        }

        return ans;
    }
};
