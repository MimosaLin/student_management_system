#include "kruskal.h"
#include <algorithm>

// 查找父节点
string findParent(map<string, string>& parent, string vertex) {
    if (parent[vertex] != vertex)
        parent[vertex] = findParent(parent, parent[vertex]);
    return parent[vertex];
}

// 合并集合
void unionSets(map<string, string>& parent, string x, string y) {
    string xRoot = findParent(parent, x);
    string yRoot = findParent(parent, y);
    parent[xRoot] = yRoot;
}

// 自定义比较函数用于边的排序
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// 克鲁斯卡尔算法计算最小生成树
vector<Edge> kruskalMST(vector<Edge>& edges, vector<string>& vertices) {
    // 存储最小生成树的边
    vector<Edge> mst;

    // 对边按权重进行升序排序
    sort(edges.begin(), edges.end(), compareEdges);

    // 存储每个顶点的父节点
    map<string, string> parent;
    for (const auto& vertex : vertices)
        parent[vertex] = vertex;

    int edgeCount = 0;
    int index = 0;

    // 遍历每条边，直到最小生成树的边数等于顶点数减一
    while (edgeCount < vertices.size() - 1 && index < edges.size()) {
        const Edge& currentEdge = edges[index++];
        string sourceParent = findParent(parent, currentEdge.source);
        string destinationParent = findParent(parent, currentEdge.destination);

        // 如果两个顶点的父节点不同，则添加当前边到最小生成树，并合并两个集合
        if (sourceParent != destinationParent) {
            mst.push_back(currentEdge);
            unionSets(parent, sourceParent, destinationParent);
            edgeCount++;
        }
    }

    return mst;
}
