// Word Ladder
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> graph;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        // bfs
        // 如果 endWord 不在字典裡，直接 return 0
        if (!wordSet.count(endWord)) return 0;

        // 對 wordList + beginWord 建立 pattern map
        wordSet.insert(beginWord);
        for (const string& word : wordSet) {
            for (int i = 0; i < word.length(); ++i) {
                string pattern = word;
                pattern[i] = '*';
                graph[pattern].push_back(word);
            }
        }

        // BFS 初始化
        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({beginWord, 1});
        visited.insert(beginWord);

        // BFS 主迴圈
        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            for (int i = 0; i < word.length(); ++i) {
                string pattern = word;
                pattern[i] = '*';

                for (const string& neighbor : graph[pattern]) {
                    if (neighbor == endWord) {
                        return steps + 1;
                    }

                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push({neighbor, steps + 1});
                    }
                }
            }
        }

        return 0; // 找不到 endWord
    }
};

class Solution1 {
public:
// dfs
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 確保 endWord 存在於 wordList 中，否則無解
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        // 建立 pattern 圖
        unordered_map<string, vector<string>> graph;
        wordSet.insert(beginWord); // 確保 beginWord 也在圖中

        for (const string& word : wordSet) {
            for (int i = 0; i < word.length(); ++i) {
                string pattern = word;
                pattern[i] = '*';
                graph[pattern].push_back(word);
            }
        }

        unordered_set<string> used;
        int ans = INT_MAX;

        used.insert(beginWord); // 起點先標記為已拜訪
        dfs(beginWord, endWord, graph, used, 1, ans);

        return ans == INT_MAX ? 0 : ans;
    }

    void dfs(string curWord, string endWord,
             unordered_map<string, vector<string>>& graph,
             unordered_set<string>& used,
             int pathLen, int& ans)
    {
        // 找到目標，更新答案
        if (curWord == endWord) {
            ans = min(ans, pathLen);
            return;
        }

        // 剪枝：路徑已經比目前答案長，就沒必要繼續了
        if (pathLen >= ans) return;

        for (int i = 0; i < curWord.length(); ++i) {
            string pattern = curWord;
            pattern[i] = '*';

            for (const string& neighbor : graph[pattern]) {
                if (!used.count(neighbor)) {
                    used.insert(neighbor);        // 標記已使用
                    dfs(neighbor, endWord, graph, used, pathLen + 1, ans);
                    used.erase(neighbor);         // 回溯
                }
            }
        }
    }
};


