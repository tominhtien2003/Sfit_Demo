#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
#define ll long long int
const int mod=1e9+7;
//find_by_order(pos)->giá trị vị trí thứ pos
//order_of_key(x) -> số số nhỏ hơn x?
//lower_bound(x) ->phần tử đầu tiên >=x
//upper_bound(x) ->phần tử đầu tiên > x
//decltype
//ki tu sang chuoi : string(1,c);c la ki tu

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin >> n;
    vector<vector<int>>arr(n);
    for (int i=0;i<n;++i) {
        int x,y;cin >> x >> y;
        arr[i]={x,y,i};
    }
    auto comp=[](auto &a,auto &b){return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);};
    sort(begin(arr),end(arr),comp);
    pbds se,se2;
    vector<int>ans1(n,0),ans2(n,0);
    for (int i=n-1;i>=0;i--){
        ans1[arr[i][2]]=se.order_of_key(arr[i][1]+1);
        se.insert(arr[i][1]);
    }
    for (int i=0;i<n;i++){
        ans2[arr[i][2]]=se2.size()-se2.order_of_key(arr[i][1]);
        se2.insert(arr[i][1]);
    }
    for (auto it:ans1) cout << it << " ";
    cout << endl;
    for (auto it:ans2) cout << it << " ";
    return 0;
}