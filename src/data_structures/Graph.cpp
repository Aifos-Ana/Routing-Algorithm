#include "Graph.h"

Graph::Graph() {
    this->numVertex = 0;
}

Graph::Graph(int numVertex) {
    this->numVertex = numVertex;
}

bool Graph::add_vertex(const int &id) {
    if (findVertex(id) != nullptr)
        return false;
    auto *v1 = new Vertex(id);
    vertexMap[id] = v1;
    return true;
}

bool Graph::add_vertex(const int &id, double longitude, double latitude) {
    if(findVertex(id) != nullptr)
        return false;
    auto *v1 = new Vertex(id, longitude, latitude);
    vertexMap.insert(make_pair(id, v1));
    return true;
}

bool Graph::add_vertex(const int &id, string name) {
    if(findVertex(id) != nullptr)
        return false;
    auto *v1 = new Vertex(id, name);
    vertexMap[id] = v1;
    return true;
}

bool Graph::add_edge(const int &source, const int &dest, double w) const {
    Vertex *v1 = findVertex(source);
    Vertex *v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;

    v1->addEdge(v2, w);
    return true;
}

bool Graph::remove_vertex(const int &id) {
    for (auto it = vertexMap.begin(); it != vertexMap.end(); ++it) {
        if (it->second->get_id() == id) {
            vertexMap.erase(it);
            return true;
        }
    }
    return false;
}

int Graph::getNumVertex() const {
    return vertexMap.size();
}

unordered_map<int, Vertex*> Graph::getVertexSet() const {
    return vertexMap;
}

Vertex *Graph::findVertex(const int &id) const {
    auto it = vertexMap.find(id);
    if (it == vertexMap.end())
        return nullptr;
    return it->second;
}

void Graph::dfs(const vector<Edge*> &mst, Vertex* v, vector<bool> &visited, vector<int> &path) {
    visited[v->get_id()] = true;
    cout << v->get_id() << " -> ";
    path.push_back(v->get_id());

    for (const auto &e: mst) {
        if (!visited[e->get_dest()->get_id()] && e->get_source()->get_id() == v->get_id()) {
            dfs(mst, e->get_dest(), visited, path);
        }
    }
}

vector<Edge*> Graph::prim_MST() {
    vector<Edge*> mst;
    priority_queue<Edge*, vector<Edge*>, CompareWeight> pq;
    vector<bool> visited(vertexMap.size(), false);
    Vertex* vertex = this->vertexMap[0];
    visited[vertex->get_id()] = true;

    for (const auto& e : vertex->get_adj()) {
        pq.push(e);
    }

    while (!pq.empty()) {
        Edge* edge = pq.top();
        pq.pop();
        Vertex* v = edge->get_dest();

        if (visited[v->get_id()]) {
            continue;
        }

        visited[v->get_id()] = true;
        mst.push_back(edge);

        for (auto e : v->get_adj()) {
            if (!visited[e->get_dest()->get_id()]) {
                pq.push(e);
            }
        }
    }
    return mst;
}

bool Graph::hasEdge(int source, int dest) {
    for (const auto& vertex : vertexMap) {
        if (vertex.second->get_id() == source) {
            for (auto edge : vertex.second->get_adj()) {
                if (edge->get_dest()->get_id() == dest) {
                    return true;
                }
            }
            break;
        }
    }
    return false;
}

double Graph::haversine(double lat1, double lon1, double lat2, double lon2) {
    double R = 6371e3;
    double phi1 = lat1 * M_PI/180;
    double phi2 = lat2 * M_PI/180;
    double deltaPhi = (lat2-lat1) * M_PI/180;
    double deltaLambda = (lon2-lon1) * M_PI/180;
    double a = sin(deltaPhi/2) * sin(deltaPhi/2) +
               cos(phi1) * cos(phi2) *
               sin(deltaLambda/2) * sin(deltaLambda/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = R * c;

    return d;
}

double Graph::calculate_total_distance(const vector<int> &path) {
    double result = 0.0;
    int n = path.size();

    for (int i = 0; i < n - 1 ;i++) {
        int ve1 = path[i];
        int ve2 = path[i+1];
        if(!hasEdge(ve1, ve2)){
            result += haversine(vertexMap[ve1]->get_latitude(), vertexMap[ve1]->get_longitude(),
                                vertexMap[ve2]->get_latitude(), vertexMap[ve2]->get_longitude());
            continue;
        }
        else {
            Vertex *v = vertexMap[ve1];
            for(auto edge: v->get_adj()){
                if(edge->get_dest()->get_id() == ve2){
                    result += edge->get_weight();
                    break;
                }
            }
        }
    }

    int f = path.back();

    if(!hasEdge(f, path[0])){
        result += haversine(vertexMap[f]->get_latitude(), vertexMap[f]->get_longitude(),
                            vertexMap[path[0]]->get_latitude(), vertexMap[path[0]]->get_longitude());
    }
    else{
        Vertex *v = vertexMap[f];
        if (v != nullptr){
            for(auto edge: v->get_adj()){
                if(edge->get_dest()->get_id() == path[0]){
                    result += edge->get_weight();
                }
            }
        }
    }
    return result;
}

void Graph::triangularApproximationHeuristic() {
    double total_distance = 0;
    vector<Edge*>mst = prim_MST();

    cout<< "Preorder is: ";
    vector<bool> visited(vertexMap.size(), false);
    vector<int> preorder (vertexMap.size());

    dfs(mst, mst[0]->get_source(), visited, preorder);

    cout << '0' <<endl;
    total_distance = calculate_total_distance(preorder);
    cout << "Distance: " << total_distance <<endl;
}

double Graph::nearestNeighbor(Vertex* initialNode, Vertex* currentNode, vector<Edge*>& path, int graphSize, double distance) {
    if (currentNode == initialNode && path.size() == graphSize) {
        return distance;
    }

    currentNode->setVisited(true);

    Edge* minEdge = findMinEdge(currentNode);
    if (minEdge) {
        path.push_back(minEdge);
        return nearestNeighbor(initialNode, minEdge->get_dest(), path, graphSize, distance + minEdge->get_weight());
    }

    auto edge = path[0];

    for (auto e : path) {
        cout << e->get_source()->get_id() << " -> ";
        edge = e;
    }

    cout << edge->get_dest()->get_id() << " -> ";
    cout << "0" << endl;
    cout << "Distance: " << distance << endl;
    return distance;
}

Edge* Graph::findMinEdge(Vertex* currentNode) {
    Edge* minEdge = nullptr;
    double minEdgeWeight = numeric_limits<double>::max();

    for (auto edge : currentNode->get_adj()) {
        if (!edge->get_dest()->isVisited() && edge->get_weight() < minEdgeWeight) {
            minEdge = edge;
            minEdgeWeight = edge->get_weight();
        }
    }
    return minEdge;
}
