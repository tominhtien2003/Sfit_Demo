#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class DisjoinSet
{
    vector<int>rank,parent,size;
    public:
        DisjoinSet(int n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,1);
            for (int i=1;i<=n;i++)
                parent[i]=i;
        }
        int FindParent(int node)
        {
            if (node==parent[node]) return node;
            return parent[node]=FindParent(parent[node]);
        }
        void UnionByRank(int u,int v)
        {
            int par_u=FindParent(u);
            int par_v=FindParent(v);
            if (par_u==par_v) return;
            if (rank[par_u]<rank[par_v]) parent[par_u]=par_v;
            else if (rank[par_u]>rank[par_v]) parent[par_v]=par_u;
            else {
                parent[par_u]=par_v;
                rank[par_v]++;
            }
        }
        void UnionBySize(int u,int v)
        {
            int par_u=FindParent(u);
            int par_v=FindParent(v);
            if (par_u==par_v) return;
            if (size[par_u]<size[par_v]) 
            {
                parent[par_u]=par_v;
                size[par_v]+=size[par_u];
            }
            else
            {
                parent[par_v]=par_u;
                size[par_u]+=size[par_v];
            }
        }
};
int main()
{
    DisjoinSet ds(7);
    ds.UnionByRank(1,2);
    ds.UnionByRank(4,5);
    return 0;
}