#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

class Graph {
public:
    Graph();
    ~Graph();
    void add_node(const std::string& name);
    void remove_node(const std::string& name);
    void add_edge(const std::string& u, const std::string& v, int w);
    void remove_edge(const std::string& u, const std::string& v);
    std::vector<std::pair<std::string, int>> get_neighbors(const std::string& u) const;
    std::vector<std::string> get_shortest_path(const std::string& start, const std::string& end) const;
    void read_from_file(const std::string& filename);
    void write_to_file(const std::string& filename) const;
private:
    int get_node_index(const std::string& name) const;
    std::vector<std::vector<std::pair<int, int>>> adj_list;
    std::unordered_map<std::string, int> node_indices;
    std::vector<std::string> node_names;
};

#endif
