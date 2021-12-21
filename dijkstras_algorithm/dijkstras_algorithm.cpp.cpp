#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <limits>
using namespace std;

int main()
{
	using node_t = string;
	using node_cost_t = unordered_map<node_t, unsigned int>;
	using graph_t = unordered_map<node_t, node_cost_t>;
	using parent_graph = unordered_map<node_t, node_t>;

	// Setup graph
	graph_t graph;
	graph.reserve(4U);
	graph.emplace("start", node_cost_t{ {"a", 6}, {"b", 2} });
	graph.emplace("a", node_cost_t{ {"finish", 1} });
	graph.emplace("b", node_cost_t{ {"a", 3}, {"finish", 5} });
	graph.emplace("finish", node_cost_t{});
	// Setup costs table
	node_cost_t costs{ {"a", 6}, {"b", 2}, {"finish", numeric_limits<unsigned int>::max()} };
	// Setup parents table
	parent_graph parents{ {"a", "start"}, {"b", "start"} };

	// A vector of processed nodes
	vector<node_t> processed;
	processed.reserve(3U);
	// A lambda function to find the lowest cost node
	const auto find_lowest_cost_node = [&processed](const node_cost_t& costs)
	{
		auto lowest_cost = numeric_limits<unsigned int>::max();
		node_t lowest_cost_node{};
		// Go through each node in the costs graph
		for (const auto& nodeCost : costs)
		{
			const auto& cost = nodeCost.second;
			const auto& node = nodeCost.first;
			// Check if this node is processed or not.
			bool isNotProcessed = find(processed.cbegin(), processed.cend(), node) == processed.cend();
			// Find the lowest cost node
			if (cost < lowest_cost && isNotProcessed)
			{
				lowest_cost = cost;
				lowest_cost_node = node;
			}
		}
		return lowest_cost_node;
	};

	// node is "b" at this time
	auto node = find_lowest_cost_node(costs);
	while (!node.empty())
	{
		const auto costSoFar = costs[node];
		const auto& neighbours = graph[node];
		// Loop through all the nodes
		for (const auto& neighbour : neighbours)
		{
			const auto newCost = costSoFar + neighbour.second;
			const auto& currentNeighbourName = neighbour.first;
			// If it is cheaper than the cost registered in the costs graph, update the costs graph.
			if (newCost < costs[currentNeighbourName])
			{
				costs[currentNeighbourName] = newCost;
				parents[currentNeighbourName] = node;
			}
		}
		// Mark the current node as processed
		processed.push_back(node);
		// Find the next node to process. If they are all processed, this will return am empty string.
		node = find_lowest_cost_node(costs);
	}
	cout << "Cost from the start to each node:" << endl;
	// prints finish 6 b 2 a 5
	for (const auto& cost : costs)
		cout << cost.first << " " << cost.second << endl;
	return 0;
}