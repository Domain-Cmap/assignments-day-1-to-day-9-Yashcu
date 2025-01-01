#include <vector>
#include <queue>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int nextGroupId = m;
        vector<vector<int>> groupItems(n + m);
        vector<int> itemInDegrees(n, 0);
        vector<int> groupInDegrees(n + m, 0);
        vector<vector<int>> itemGraph(n);
        vector<vector<int>> groupGraph(n + m);

        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = nextGroupId++;
            }
            groupItems[group[i]].push_back(i);
        }

        for (int i = 0; i < n; ++i) {
            for (int j : beforeItems[i]) {
                if (group[i] == group[j]) {
                    ++itemInDegrees[i];
                    itemGraph[j].push_back(i);
                } else {
                    ++groupInDegrees[group[i]];
                    groupGraph[group[j]].push_back(group[i]);
                }
            }
        }
      vector<int> entities(n + m);
        iota(entities.begin(), entities.end(), 0);
  auto topoSort = [](const vector<vector<int>>& graph, vector<int>& inDegrees, vector<int>& entities) -> vector<int> {
            queue<int> queue;
            for (int entity : entities) {
                if (inDegrees[entity] == 0) {
                    queue.push(entity);
                }
            }
            vector<int> sorted;
            while (!queue.empty()) {
                int current = queue.front();
                queue.pop();
                sorted.push_back(current);
                for (int next : graph[current]) {
                    if (--inDegrees[next] == 0) {
                        queue.push(next);
                    }
                }
            }
            return sorted.size() == entities.size() ? sorted : vector<int>();
        };
        vector<int> sortedGroups = topoSort(groupGraph, groupInDegrees, entities);
        if (sortedGroups.empty()) {
            return {};
        }

        vector<int> result;
      
        
        for (int groupId : sortedGroups) {
            entities = groupItems[groupId]; // Get items in current group
            vector<int> sortedItems = topoSort(itemGraph, itemInDegrees, entities);
            if (sortedItems.size() != entities.size()) {
                return {};
            }
            
            result.insert(result.end(), sortedItems.begin(), sortedItems.end());
        }
        return result;
    }
};
