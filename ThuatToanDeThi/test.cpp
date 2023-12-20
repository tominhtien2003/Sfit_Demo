#include<bits/stdc++.h>
using namespace std;

struct Word{
    string english;
    string vietnamese;
};
class HashTable{
    private:
        vector<Word>table;
        int sz;
    public:
        HashTable(){
            sz=0;
            table.resize(1);
        }
        void ResizeTable(){
            int newSizeTable = table.size()*2;
            vector<Word>NewTable(newSizeTable);
            for (int i=0;i<table.size();i++){
                int id=Hash(table[i].english);
                while(!NewTable[id].english.empty()){
                    id=(id+1)%NewTable.size();
                }
                NewTable[id]=table[i];
            }
            table=NewTable;
        }
        int Hash(string word){
            int sum=0;
            for (char c:word){
                sum+=c;
                sum%=table.size();
            }
            return sum;
        }
        void Insert(string eng,string vietnam){
            if (++sz==table.size()){
                ResizeTable();
            }
            int id=Hash(eng);
            while(!table[id].english.empty()){
                id=(id+1)%sz;
            }
            table[id].vietnamese=vietnam;
            table[id].english=eng;
        }
        string FindMeaning(string eng){
            int id=Hash(eng);
            int cur=id;
            if (table[cur].english==eng) return table[id].vietnamese;
            cur=(cur+1)%table.size();
            while (table[cur].english!=eng){
                cur=(cur+1)%table.size();
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