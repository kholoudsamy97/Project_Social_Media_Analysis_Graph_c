#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <iterator>
#include <utility>
#include <iomanip>


# define INF 100000000




using namespace std;



vector <int> shortest_path(int src, vector <vector <pair <int, int> > > adj_list)
{

	priority_queue < pair <int, pair <int, int> >,
		vector < pair <int, pair <int, int> > >,
		greater < pair <int, pair <int, int> > > > nodes_q;

	int n = adj_list.size();
	vector<int> d(n, INF);
	vector<int> p(n, -1);

	nodes_q.push({ 0, {src, src} });
	while (!nodes_q.empty())
	{
		pair <int, pair <int, int> > p1 = nodes_q.top();
		nodes_q.pop();
		int cur_node = p1.second.first;
		int cur_prev_node = p1.second.second;
		int cur_dis = p1.first;

		if (d[cur_node] != INF)
			continue;

		d[cur_node] = cur_dis;
		p[cur_node] = cur_prev_node;

		for (int i = 0; i < adj_list[cur_node].size(); i++)
		{
			int next_node = adj_list[cur_node][i].first;
			int weight = adj_list[cur_node][i].second;
			if (d[next_node] != INF)
				continue;

			/*if (d[next_node] > d[cur_node] + weight)
			{
				d[next_node] = d[cur_node] + weight;
				nodes_q.push({ d[next_node] , {next_node, cur_node} });
			}
			*/
			nodes_q.push({ cur_dis + weight , {next_node, cur_node} });

		}
	}
	return d;
}


int main()
{
	int n, m, a, b, c;
	cin >> n >> m;

	vector<vector <pair <int, int> > > adj_list(n, vector <pair <int, int> > ());

	for (int i = 0;i < m;i++)
	{
		cin >> a >> b >> c;
		adj_list[a].push_back({b, c});
		adj_list[b].push_back({a, c});
	}
	//cout << "enjy" << endl;
	for (int i = 0; i < n; i++)
	{
		vector<int> d = shortest_path(i, adj_list);
		double sum = 0;
		double connected =0;
		for (vector<int>::iterator it = d.begin(); it != d.end(); it++)
		{
			//cout << "ddddd  " << *it << endl;
			sum += *it;
			connected++;
		}
		double closeness_centrality = (connected - 1) / (sum);

		//cout << "the closeness centrality of node " << i << " equal " << closeness_centrality << endl;

		cout << setprecision(12) << fixed <<  closeness_centrality << endl;

		sum = 0;
		connected = 0;
	}

	return 0;
}
