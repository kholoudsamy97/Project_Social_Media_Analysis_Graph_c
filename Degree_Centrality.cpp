#include <iostream>
//#include<list>
#include<vector>
using namespace std;
void Degree_Centrality() {
	long n, m;
	cin >> n >> m;
	vector<vector<int> > adj_list(n, vector<int>());
	int a, b, c;
	for (long i = 0; i<m; i++) {
		cin >> a >> b >> c;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		cout << adj_list[i].size() << '\n';
	}
}
 
int main() {
	Degree_Centrality();
	return 0;
}
