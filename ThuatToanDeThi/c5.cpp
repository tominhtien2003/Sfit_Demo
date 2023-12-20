#include<bits/stdc++.h>
using namespace std;

const int SZ = 10;
struct Word{
    string english;
    string vietnamese;
};
class HashTable{
    private:
        vector<Word>table;
    public:
        HashTable(){
            table.resize(SZ);
        }
        int Hash(string word){
            int sum=0;
            for (char c:word){
                sum+=c;
                sum%=SZ;
            }
            return sum;
        }
        void Insert(string eng,string vietnam){
            int id=Hash(eng);
            while(!table[id].english.empty()){
                id=(id+1)%SZ;
            }
            table[id].vietnamese=vietnam;
            table[id].english=eng;
        }
        string FindMeaning(string eng){
            int id=Hash(eng);
            int cur=id;
            if (table[cur].english==eng) return table[id].vietnamese;
            cur=(cur+1)%SZ;
            while (table[cur].english!=eng){
                cur=(cur+1)%SZ;
                if (cur==id) return "Khong ton tai";
            }
            return table[cur].vietnamese;
        }
};
int main(){
    HashTable hashTable;
    hashTable.Insert("Hello", "Xin Chao");
    hashTable.Insert("Goodbye", "Tam Biet");

    cout << "Nghia cua tu 'Hello': " << hashTable.FindMeaning("Hello") << endl;
    cout << "Nghia cua tu 'Goodbye': " << hashTable.FindMeaning("Goodbye") << endl;
    cout << "Nghia cua tu 'Dog': " << hashTable.FindMeaning("Dog") << endl;


    return 0;
}