#include<bits/stdc++.h>
using namespace std;

map<char, vector<char>> adj;

void dfs(char start, char end, string &res, vector<int>& vis, ofstream& outputFile) {
    res.push_back(start);
    vis[start - 'A'] = 1;

    if (start == end) {
        outputFile << res << endl;
    } else {
        for (char c : adj[start]) {
            if (!vis[c - 'A']) {
                dfs(c, end, res, vis, outputFile);
            }
        }
    }

    vis[start - 'A'] = false;
    res.pop_back();
}

int main() {
    fstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cout << "Ko mo duoc" << endl;
        return 1;
    }

    string line;
    char start, end, prev;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        char a, b;
        if (iss >> a >> b) {
            adj[a].push_back(b);
            prev = a;
        }
    }

    inputFile.close();

    start = prev;
    end = adj[prev].back();
    adj[prev].pop_back();

    vector<int> vis(26, false);

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cout << "Ko mo duoc" << endl;
        return 1;
    }
    string res;
    dfs(start, end,res, vis, outputFile);

    outputFile.close();

    return 0;
}
