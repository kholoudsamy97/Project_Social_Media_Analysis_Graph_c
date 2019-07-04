#include <iostream>
//#include<list>
#include<vector>
#include<stack>
#include<queue>
#define INF 1e9
#include <functional>
//#include <iomanip> 
using namespace std;
vector<vector<int>> shortest_paths(int src, vector<vector<pair<int, int> > > adj_list) {
	priority_queue<pair<int, pair<int, int> >,
		vector<pair<int, pair<int, int>> >,
		greater<pair<int, pair<int, int> > > >q;
	int n = adj_list.size();
	vector<int> d(n, INF);
	vector<vector<int>> p(n, vector<int>());
	q.push({ 0 ,{ src , src } });
	while (!q.empty()) {
		pair< int, pair<int, int> > cur_p = q.top();
		q.pop();
		int cur_node = cur_p.second.first;
		int cur_prev_node = cur_p.second.second;
		int cur_dis = cur_p.first;
		//int grand_pa = cur_p.second.second;
		bool flag = 0;

		if (d[cur_node] != INF&& d[cur_node] != cur_dis)
			continue;
		for (int i = 0; i < p[cur_node].size(); i++) {
			if (p[cur_node][i] == cur_prev_node)
				flag = 1;
		}
		if (!flag) {
			d[cur_node] = cur_dis;
			p[cur_node].push_back(cur_prev_node);
			//grandParent[cur_node] = grand_pa;
		}
		flag = 0;

		// Add the nodes connected to current one
		for (int i = 0;
			i< adj_list[cur_node].size();
			i++)
		{
			int next_node = adj_list[cur_node][i].first;
			int weight = adj_list[cur_node][i].second;
			if (d[next_node] != INF)
				continue;
			q.push({ cur_dis + weight,
			{ next_node  , cur_node } });
		}
	}

	return  p;
}
/*void print_path(int src, int des, vector<vector<int>> p, vector<int> grand_pa) {
int max_short_paths = 0;
for (int i = 0; i < des; i++) {
if (p[i].size() > max_short_paths)
max_short_paths = p[i].size;
}
vector<vector<int>>short_paths(max_short_paths);
for (int i = 0; i < short_paths.size(); i++) {
int parent, count = 0;
stack<int> path_nodes;
int node = des;
path_nodes.push(node);
vector<bool> visited (p[des].size(),0);
while (p[node][count] != node) {
if (grand_pa[p[node][count]] == p[p[node][count]][count]) {
node = p[node][count];
path_nodes.push(node);
}


int j = 0;
if(grand_pa[node]== parent[parent[node][j]][j])

}

}
}
}*/
/*void print_path(int src, int des, vector<vector<int>> p, vector<int> &shortest_paths) {
//vector<int>shortest_paths();
if (des == src){
shortest_paths.push_back(src);
return;
}
for (int i = 0; i < p[des].size(); i++) {
print_path(src, p[des][i], p, shortest_paths);
shortest_paths.push_back(des);
}
}*/
void paths(int src, int des, vector<vector<int>> p, vector<int> &shortest_paths, stack<int>parents) {
	//vector<int>shortest_paths();
	if (des == src) {
		shortest_paths.push_back(src);
		while (parents.size())
		{
			shortest_paths.push_back(parents.top());
			parents.pop();
		}
		return;
	}
	for (int i = 0; i < p[des].size(); i++) {
		parents.push(des);
		paths(src, p[des][i], p, shortest_paths, parents);
		if (parents.size()) { parents.pop(); }
	}
}
vector<vector<int>> print_every_path(vector<int> shortest_paths, int src) {
	int  j = 0;
	vector<vector<int>> all_single_path(100);
	for (int i = 0; i < shortest_paths.size(); i++) {
		if (i == 0) {
			all_single_path[j].push_back(shortest_paths[i]);
			continue;
		}
			if (shortest_paths[i] != src )
				all_single_path[j].push_back(shortest_paths[i]);
			else {
			j++;
			all_single_path[j].push_back(shortest_paths[i]);
		}
	}
	return all_single_path;
}
int main() {
	//Degree_Centrality();
	//Betweenness_Centrality();
	long n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>> > adj_list(n, vector<pair<int, int>>());
	int a, b, c;
	for (long i = 0; i<m; i++) {
		cin >> a >> b >> c;
		adj_list[a].push_back({ b, c });
		adj_list[b].push_back({ a, c });
	}
	vector<int>k;
	stack<int>s;
	vector<vector<int>> single_short_paths;
	vector<vector<int>>  p = shortest_paths(0, adj_list);
	paths(0, 6, p, k, s);
	single_short_paths = print_every_path(k, 0);
	return 0;
}