#include<bits/stdc++.h>
using namespace std;

const int SZ=10;
class HashTable{
    private:
        vector<int>arr;
        int sz;
    public:
        HashTable(){
            arr.resize(SZ,-1);
        }
        void Insert(int key){
            int id = key%SZ;
            while (arr[id]!=-1){
                id=(id+1)%SZ;
            }
            arr[id]=key;
        }
};
int main(){
    vector<int> arr ={4371, 1323, 6173, 4199, 4344, 9679, 1989};
    return 0;
}