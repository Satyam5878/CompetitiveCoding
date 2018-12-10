#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<list>
#include<map>
using namespace std;

vector<pair<string, int>> path;
map<string, bool> visited;
set<string> uniqueCity;
map<string, map<string, int>> m;

void dfs(string src, string dest) {
	path.push_back(make_pair(src,0));
	visited[src] = true;
	if (src == dest) {
		// do some thing;
	}
	for (auto it: uniqueCity) {
		
		if (m.find(src,dest) == m.end()) {
			if (color[I] == false) {
				dfs(I, dst);

				color[I] = false;
t
				size--;

				//remove that node at index "size" from list
				list.remove(size);
			}
		}
	}
}
int main() {
	/*int N=20;
	string src, dest;
	set<string> uniqueCity;
	

	cin >> src >> dest;
	vector<string>  srcCity, destCity;
	vector<int> costCity;
	string s, d;
	int cost;

	for (int i = 0;i < N;++i) {
		cin >> s >> d>>cost;
		uniqueCity.insert(src);
		uniqueCity.insert(dest);
		srcCity.push_back(s);
		destCity.push_back(dest);
		costCity.push_back(cost);
	}
	int costMatrix[20][20];
	vector<string> uniqueCityList(uniqueCity.begin(), uniqueCity.end());
	for (int i = 0;i < srcCity.size();++i) {

	}
	*/

	int N = 20,cost;
	string src, dest;;
	string s, d;
	cin >> src >> dest;
	//set<string> uniqueCity;
	//map<string, map<string, int>> m;
	for (int i = 0;i < N;++i) {
		cin >> s >> d >> cost;
		uniqueCity.insert(s);
		uniqueCity.insert(d);
		m[s][d] = cost;
	}
	for (auto it : uniqueCity) {
		visited[it] = false;
	}

	dfs(src, dest);

}