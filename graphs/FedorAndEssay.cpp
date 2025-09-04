#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

unordered_map<string,vector<string>> graph;
unordered_map<string,pair<int,int>> wordInfo; // maps string->(rcount,length)


string toLower(const string &s) {
    string res = s;
    for (char &c : res) c = tolower(c);
    return res;
}
int countR(const string& s){
    int count=0;
    for(char c:s){
        if(c=='r' || c=='R') count++; 
    }
    return count;
}
bool isbetter(const string& a,const string& b){
    auto [r1, len1] = wordInfo[a];
    auto [r2, len2] = wordInfo[b];
    return (r1 < r2) || (r1 == r2 && len1 < len2);
}


unordered_map<string, string> memoBestWord; // maps string->best word -> chaches the best word for each string
unordered_map<string, int> vis; // 0 = unvisited, 1 = visiting, 2 = visited

string findBest(const string& word){
    if(memoBestWord.count(word)) return memoBestWord[word];// if already computed, return cached value
    if (vis[word] == 1) return word;  // cycle detected, return itself
    if (vis[word] == 2) return memoBestWord[word];


    vis[word] = 1; // mark the word as being visiting

    string best = word;
    for(auto n:graph[word]){
        string candidate = findBest(n);
        if(isbetter(candidate, best)) best = candidate;
    }
    vis[word] = 2; // mark as visited
    return memoBestWord[word] = best; // cache the result before returning
}


int main(){
    int m;cin>>m;
    vector<string> essay(m);
    for(int i=0;i<m;i++){
        cin>>essay[i];
        essay[i]= toLower(essay[i]);
        if(wordInfo.count(essay[i])==0){
            wordInfo[essay[i]]= {countR(essay[i]), (int)essay[i].length()};
        }
    }
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string x,y;cin>>x>>y;
        x = toLower(x);
        y = toLower(y);
        graph[x].pb(y);
        if(wordInfo.count(x)==0) wordInfo[x]= {countR(x), (int)x.length()};
        if(wordInfo.count(y)==0) wordInfo[y]= {countR(y), (int)y.length()};
    }
    ll totalR=0,totalLen=0;

    for (auto& [word, _] : wordInfo) findBest(word); //-> ensure all words are processed-> this will fill the memoBestWord and vis maps
    for(string word:essay){
        string bestword= memoBestWord[word];
        totalR += wordInfo[bestword].first;
        totalLen += wordInfo[bestword].second;
    }
    cout << totalR << " " << totalLen << endl;
    return 0;
}