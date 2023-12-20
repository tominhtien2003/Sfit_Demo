#include <bits/stdc++.h>
using namespace std;

#define int long long int
struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};
class HuffmanTree {
public:
    HuffmanNode* buildHuffmanTree(vector<char>& ch, vector<int>& freq) {
        auto comp=[](HuffmanNode* &left, HuffmanNode* &right){
            return left->freq > right->freq;
        };
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, decltype(comp)> pq(comp);
        for (int i = 0; i < ch.size(); i++) {
            pq.push(new HuffmanNode(ch[i], freq[i]));
        }

        while (pq.size() != 1) {
            HuffmanNode* left = pq.top();
            pq.pop();
            HuffmanNode* right = pq.top();
            pq.pop();

            HuffmanNode* newNode = new HuffmanNode('$', left->freq + right->freq);
            newNode->left = left;
            newNode->right = right;

            pq.push(newNode);
        }

        return pq.top();
    }

    void printHuffmanCodes(HuffmanNode* root, string code) {
        if (root == nullptr) {
            return;
        }

        if (root->data != '$') {
            cout << root->data << " " << code << endl;
        }

        printHuffmanCodes(root->left, code + "0");
        printHuffmanCodes(root->right, code + "1");
    }
};

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<char>ch={'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int>freq={5, 9, 12, 13, 16, 45};
    HuffmanTree tree;
    HuffmanNode *root = tree.buildHuffmanTree(ch, freq);
    tree.printHuffmanCodes(root, "");
    return 0;
}
