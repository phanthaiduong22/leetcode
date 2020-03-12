#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
	int V = 0, E = 0;
	bool topologicalSort(vector<vector<int>>& graph) {
		vector<int>indegree(V, 0);
		queue<int> zero_indegree;
		for (int u = 0; u < V; u++) {
			vector<int>::iterator it;
			for (it = graph[u].begin(); it != graph[u].end(); it++) {
				indegree[*it]++;
			}
		}

		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				zero_indegree.push(i);
			}
		}

		while (!zero_indegree.empty()) {
			int u = zero_indegree.front();
			zero_indegree.pop();
			vector<int>::iterator it;
			for (it = graph[u].begin(); it != graph[u].end(); it++) {
				indegree[*it]--;
				if (indegree[*it] == 0) {
					zero_indegree.push(*it);
				}
			}
		}

		for (int i = 0; i < V; i++) {
			if (indegree[i] != 0) {
				return false;
			}
		}
		return true;
	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		V = numCourses;
		vector<vector<int>>graph;
		graph.assign(V, vector<int>());
		for (int i = 0; i < prerequisites.size(); i++) {
			graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
		}
		E = prerequisites.size();
		return topologicalSort(graph);
	}
};

int main() {
	Solution s;
	vector<vector<int>> v = { {1,0}, {0,1} };
	cout << s.canFinish(2, v);
}
