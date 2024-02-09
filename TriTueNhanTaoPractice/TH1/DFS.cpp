#include <bits/stdc++.h>
using namespace std;

bool dfs(char start, char end, unordered_map<char, vector<char>> &adj, vector<bool> &vis, string &res, ofstream &outputFile)
{
    outputFile << "TT : " << start << endl;
    outputFile << "TTK : ";
    for (char c : adj[start])
    {
        outputFile << c;
    }
    outputFile << endl;
    vis[start - 'A'] = 1;
    res.push_back(start);
    if (start == end)
    {
        outputFile << "Duong di tu Start den End : " << res << endl;
        return true;
    }
    else
        for (char c : adj[start])
        {
            if (!vis[c - 'A'])
            {
                if (dfs(c, end, adj, vis, res, outputFile))
                    return true;
            }
        }
    res.pop_back();
    return false;
}

int main()
{
    ifstream inputFile("D:\\git_practice\\Sfit_Demo\\TriTueNhanTaoPractice\\TH1\\input.txt");
    ofstream outputFile("D:\\git_practice\\Sfit_Demo\\TriTueNhanTaoPractice\\TH1\\output.txt");
    string s;
    inputFile >> s;
    char start, end;
    inputFile >> s;
    start = s[0];
    inputFile >> s;
    inputFile >> s;
    end = s[0];
    inputFile >> s;
    unordered_map<char, vector<char>> adj;
    string line;
    while (getline(inputFile, line))
    {
        adj[line[0]].push_back(line[2]);
    }
    vector<bool> vis(26, false);
    string res;
    dfs(start, end, adj, vis, res, outputFile);
    inputFile.close();
    outputFile.close();
    return 0;
}
