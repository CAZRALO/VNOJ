# include <bits/stdc++.h>
    using namespace std;
    int a[100001];
    vector <int> st[400001];
    void build_tree(int id,int l,int r)
        {
            if (l == r) return st[id].push_back(a[l]) , void();
            int mid = l + r >> 1;
            build_tree(id*2,l,mid);
            build_tree(id*2+1,mid+1,r);
            int s1 = st[id*2].size();
            int s2 = st[id*2+1].size();
            vector <int> vt(s1+s2);
            st[id] = vt;
            merge(st[id*2].begin(),st[id*2].end(),st[id*2+1].begin(),st[id*2+1].end(),st[id].begin());
        }
    int get(int id,int l,int r,int u,int v,int z)
        {
            if ( u > r || v < l) return 0;
            if (l >= u && r <= v)
                return st[id].size() - (upper_bound(st[id].begin(),st[id].end(),z)- st[id].begin());
            int mid = l + r >> 1;
            return get(id*2,l,mid,u,v,z)+get(id*2+1,mid+1,r,u,v,z);
        }
        int main()
            {
                ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
                int n; cin >> n;
                for (int i = 1 ; i <= n ; i++) cin >> a[i];
                build_tree(1,1,n);
                int TEST; cin >> TEST;
                while (TEST--)
                {
                    int x,y,z; cin >> x >> y >> z;
                    cout << get(1,1,n,x,y,z) << "\n";
                }
            }
