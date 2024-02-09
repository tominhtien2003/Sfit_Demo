#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> h, g, f;
map<char, vector<pair<char, int>>> adj;

void BranchAndBound(pair<char, int> &st, pair<char, int> &ed, ofstream &outputFile)
{
    int minCost = INT_MAX;
    queue<char> Q;
    Q.push({st.first});
    auto comp = [](auto &a, auto &b)
    {
        return a.second < b.second;
    };
    unordered_map<char, char> par;
    par[st.first] = '*';
    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> PQ(comp);
    vector<char> L;
    while (!Q.empty())
    {
        char cur = Q.front();
        if (!L.empty())
            L.pop_back();
        Q.pop();
        outputFile << "TT : " << cur << endl;
        outputFile << "TTK : ";
        for (auto it : adj[cur])
        {
            outputFile << it.first << " ";
        }
        outputFile << endl;
        outputFile << "K : ";
        for (auto it : adj[cur])
        {
            outputFile << it.second << " ";
        }
        outputFile << endl;
        outputFile << "H : ";
        for (auto it : adj[cur])
        {
            outputFile << h[it.first] << " ";
        }
        outputFile << endl;
        for (auto it : adj[cur])
        {
            if (it.first != ed.first)
            {
                if (f[it.first] >= minCost)
                    continue;
                if (g[cur] + it.second < g[it.first])
                {
                    g[it.first] = g[cur] + it.second;
                    f[it.first] = g[it.first] + h[it.first];
                    PQ.push({it.first, f[it.first]});
                    par[it.first] = cur;
                }
            }
            else if (minCost > g[cur] + it.second)
            {
                minCost = g[cur] + it.second;
                g[it.first] = g[cur] + it.second;
                f[it.first] = g[it.first] + h[it.first];
                par[it.first] = cur;
            }
        }
        outputFile << "G : ";
        for (auto it : adj[cur])
        {
            outputFile << g[it.first] << " ";
        }
        outputFile << endl;
        outputFile << "F : ";
        for (auto it : adj[cur])
        {
            outputFile << f[it.first] << " ";
        }
        outputFile << endl;
        outputFile << "L1 (Hight to Low) : ";
        while (!PQ.empty())
        {
            Q.push(PQ.top().first);
            L.push_back(PQ.top().first);
            outputFile << PQ.top().first << " ";
            PQ.pop();
        }
        outputFile << endl;
        outputFile << "L (Hight to Low) : ";
        for (char c : L)
        {
            outputFile << c << " ";
        }
        outputFile << endl;
        outputFile << endl;
    }
    char cur = ed.first;
    vector<char> res;
    while (par[cur] != '*')
    {
        res.push_back(cur);
        cur = par[cur];
    }
    res.push_back(st.first);
    reverse(res.begin(), res.end());
    for (char c : res)
        outputFile << c << " ";
    outputFile << endl
               << "Gia tri toi uu la : " << minCost;
}

int main()
{
    ifstream inputFile("D:\\git_practice\\Sfit_Demo\\TriTueNhanTaoPractice\\TH3\\inputA.txt");
    ofstream outputFile("D:\\git_practice\\Sfit_Demo\\TriTueNhanTaoPractice\\TH3\\outputA.txt");
    string s;
    inputFile >> s;
    string start, end;
    inputFile >> start;
    inputFile >> s;
    inputFile >> end;
    inputFile.ignore();
    getline(inputFile, s);
    string line;
    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string temp;
        vector<string> store;
        while (ss >> temp)
        {
            store.push_back(temp);
        }
        pair<char, int> x = {store[0][0], stoi(store[1])};
        pair<char, int> y = {store[2][0], stoi(store[3])};
        adj[x.first].push_back({y.first, stoi(store[4])});
        g[x.first] = INT_MAX;
        g[y.first] = INT_MAX;
        h[x.first] = x.second;
        h[y.first] = y.second;
    }
    pair<char, int> st = {start[0], h[start[0]]};
    pair<char, int> ed = {end[0], h[end[0]]};
    g[st.first] = 0;
    BranchAndBound(st, ed, outputFile);
    return 0;
}