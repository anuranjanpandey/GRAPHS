// PUSH YOUR LIMITS.!!

#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
#define int long long

#define RAGE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for(i=0; i <n; i++)
#define repv(i,k,n) for(i=k; i<=n; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define endl '\n'
#define fill(x , a) x.assign(a)
#define deb(x) cout<<#x<<" = "<<x<<endl
#define gcd __gcd
#define inf LLONG_MAX
const int mod = (int)(1e9+7);
int power(int x,int n)
{   if(n==0)    return 1;
    if(n==1)    return x%mod;
    if(n%2==0)  {   int y = power(x,n/2)%mod;return (y*y)%mod;}
    if(n&1)     {   int y = power(x,n-1);return (x%mod * y%mod)%mod;}
    return 0;
}
int dx[]    =  {-1, 0, 1,  0, -1, -1, 1,  1};
int dy[]    =  { 0, 1, 0, -1, -1,  1, 1, -1};
const int maxn = 111;
//  ------------------------------------------------------------------   
vector<int> vis(maxn , 0);
vector<int> adj[maxn];
vector<int> id(maxn);
set<int> ap;
vector<int> low(maxn);
int timer=1;
void dfs(int n , int par)
{
    vis[n]=1;
    id[n] = low[n] = timer++;
    int children = 0;
    for(int x:adj[n])
    {
        if(x==par)
            continue;
        if(!vis[x])
        {   ++children;
            dfs(x,n);
            low[n] = min(low[n] , low[x]);
            if(par==-1 && children>1)
                ap.insert(n);
            if(par!=-1 && low[x]>=id[n])
                ap.insert(n);
        }
        else
        {
            low[n] = min(low[n] , id[x]);
        }
    }
}
void solve()
{   
    int n,i,j,k,m;
    cin>>n>>m;
    rep(i,m)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b) , adj[b].pb(a);
    }
    int q;
    cin>>q;
    for(i=1; i<=n; i++)
        if(!vis[i])
            dfs(i,-1);

    while(q--)
    {
        int x;
        cin>>x;
        if(ap.find(x)!=ap.end())
            cout<<"Satisfied "<<sz(adj[x])<<endl;
        else
            cout<<"Not Satisfied"<<endl;
    }
}
signed main()
{
    RAGE;
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    //  cin>>t;
    while(t--)
        solve();


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif

    return 0;
}


