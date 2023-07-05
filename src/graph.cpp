#include <fstream>
#include <iostream>
#include <sstream>
#include "graph.h"
#include <queue>

Graph::Graph() {}

Graph::~Graph() {}

void Graph::add_node(const std::string& name) {
    if (node_indices.count(name)) {
        return;
    }
    node_indices[name] = adj_list.size();
    node_names.push_back(name);
    adj_list.emplace_back();
}

void Graph::remove_node(const std::string& name) {
    int u = get_node_index(name);
    if (u == -1) {
        return;
    }
    for (int v = 0; v < adj_list.size(); ++v) {
        if (v == u) {
            continue;
        }
        remove_edge(node_names[v], name);
    }
    adj_list.erase(adj_list.begin() + u);
    node_indices.erase(name);
    node_names.erase(node_names.begin() + u);
}

void Graph::add_edge(const std::string& u, const std::string& v, int w) {
    int ui = get_node_index(u);
    int vi = get_node_index(v);
    if (ui == -1 || vi == -1) {
        return;
    }
    adj_list[ui].push_back({ vi, w });
}

void Graph::remove_edge(const std::string& u, const std::string& v) {
    int ui = get_node_index(u);
    int vi = get_node_index(v);
    if (ui == -1 || vi == -1) {
        return;
    }
    for (auto it = adj_list[ui].begin(); it != adj_list[ui].end(); ++it) {
        if (it->first == vi) {
            adj_list[ui].erase(it);
            break;
        }
    }
}

std::vector<std::pair<std::string, int>> Graph::get_neighbors(const std::string& u) const {
    int ui = get_node_index(u);
    if (ui == -1) {
        return {};
    }
    std::vector<std::pair<std::string, int>> neighbors;
    for (auto p : adj_list[ui]) {
        int v = p.first;
        int w = p.second;
        neighbors.push_back({ node_names[v], w });
    }
    return neighbors;
}


void Graph::read_from_file(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "Error: could not open file '" << filename << "' for reading\n";
        return;
    }
    adj_list.clear();
    node_indices.clear();
    node_names.clear();
    std::string line;
    while (std::getline(fin, line)) {
        std::istringstream iss(line);
        std::string u, v;
        int w;
        if (!(iss >> u >> v >> w)) {
            break;
        }
        add_node(u);
        add_node(v);
        add_edge(u, v, w);
    }
}

void Graph::write_to_file(const std::string& filename) const {
    std::ofstream fout(filename);
    if (!fout) {
        std::cerr << "Error: could not open file '" << filename << "' for writing\n";
        return;
    }
    for (int u = 0; u < adj_list.size(); ++u) {
        for (auto p : adj_list[u]) {
            int v = p.first;
            int w = p.second;
            if (u < v) {
                fout << node_names[u] << ' ' << node_names[v] << ' ' << w << '\n';
            }
        }
    }
}


int Graph::get_node_index(const std::string& name) const {
    auto it = node_indices.find(name);
    if (it == node_indices.end()) {
        return -1;
    }
    return it->second;
}

std::vector<std::string> Graph::get_shortest_path(const std::string& start, const std::string& end) const {
    std::unordered_map<std::string, int> dist;
    for (const auto& p : node_indices) {
        dist[p.first] = INT_MAX;
    }
    dist[start] = 0;

    std::unordered_map<std::string, std::string> prev;

    auto cmp = [&](const std::string& u, const std::string& v) {
        return dist[u] > dist[v];
    };
    std::priority_queue<std::string, std::vector<std::string>, decltype(cmp)> pq(cmp);
    pq.push(start);

    while (!pq.empty()) {
        std::string u = pq.top();
        pq.pop();

        for (auto p : get_neighbors(u)) {
            std::string v = p.first;
            int w = p.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push(v);
            }
        }
    }

    std::vector<std::string> path;
    for (std::string v = end; !v.empty(); v = prev[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());

    return path;
}
