#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

bool is_seller(const string& name) {
	if (!name.empty())
		return name.back() == 'm';
	else
		return false;
}

template <typename T>
bool BFS(const T& name, const unordered_map<T, vector<T>>& graph) {
	queue<T> search_queue;
	unordered_set<T> searched;

	// add all friends to search queue
	for (auto&& friend_name : graph.find(name)->second)
		search_queue.push(friend_name);

	while (!search_queue.empty()) {
		T person = search_queue.front();
		search_queue.pop();

		// only search this person if you haven't already searched them.
		if (searched.find(person) == searched.end()) {
			if (is_seller(person)) {
				cout << person << " is a mango seller!" << endl;
				return true;
			}

			// add all friends of a person to search queue
			for (auto&& friend_name : graph.find(person)->second)
				search_queue.push(friend_name);

			// mark this person as searched
			searched.insert(person);
		}
	}

	return false;

}

int main() {
	unordered_map<string, vector<string>> graph;
	graph.insert({ "you", {"alice", "bob", "claire"} });
	graph.insert({ "bob", {"anuj", "peggy"} });
	graph.insert({ "alice", {"peggy"} });
	graph.insert({ "claire", {"thom", "jonny"} });
	graph.insert({ "anuj", {} });
	graph.insert({ "peggy", {} });
	graph.insert({ "thom", {} });
	graph.insert({ "jonny", {} });

	string name = "you";
	bool result = BFS(name, graph);
	cout << "Found mango seller: " << result << endl;
}