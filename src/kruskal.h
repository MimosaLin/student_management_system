#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;

// 定义边的结构体
struct Edge {
    string source;
    string destination;
    int weight;
};

// 克鲁斯卡尔算法计算最小生成树
vector<Edge> kruskalMST(vector<Edge>& edges, vector<string>& vertices);

