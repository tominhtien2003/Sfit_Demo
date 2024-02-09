#include <bits/stdc++.h>
using namespace std;

map<char, vector<char>> adj;
unordered_map<char, int> h;
void HillClimbing(char &start, char &end, ofstream &outputFile)
{
    vector<char> res;
    bool check = false;
    while (!check)
    {
        outputFile << "TT : " << start;
        outputFile << endl;
        res.push_back(start);
        char tmp = start;
        int min_cost = INT_MAX;
        outputFile << "TTK : ";
        for (char c : adj[tmp])
        {
            outputFile << c << " ";
            if (min_cost > h[c])
            {
                min_cost = h[c];
                start = c;
            }
        }
        if (start == end)
        {
            res.push_back(start);
            check = true;
            break;
        }
        outputFile << endl;
        outputFile << endl;
    }
    outputFile << "Duong di can tim la : ";
    for (char c : res)
    {
        outputFile << c << " ";
    }
}

int main()
{
    ifstream inputFile("D:\\git_practice\\Sfit_Demo\\TriTueNhanTaoPractice\\TH2\\inputHill.txt");
    ofstream outputFile("D:\\git_practice\\Sfit_Demo\\TriTueNhanTaoPractice\\TH2\\outputHill.txt");
    string s;
    inputFile >> s;
    string start, end;
    inputFile >> start;
    inputFile >> s;
    inputFile >> end;
    inputFile.ignore();
    getline(inputFile, s);
    string line;
    int valueSt, valueEd;
    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string temp;
        vector<string> save;
        while (ss >> temp)
        {
            save.push_back(temp);
        }
        adj[save[0][0]].push_back(save[2][0]);
        h[save[0][0]] = stoi(save[1]);
        h[save[2][0]] = stoi(save[3]);
    }
    HillClimbing(start[0], end[0], outputFile);
    inputFile.close();
    outputFile.close();
    return 0;
}