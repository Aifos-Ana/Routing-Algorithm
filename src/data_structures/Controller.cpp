#include "Controller.h"

Controller::Controller() = default;

Graph Controller::get_graph() {
    return this->graph;
}

void Controller::setGraph(Graph newGraph) {
    this->graph = newGraph;
}

void Controller::tspBacktrack(Vertex* current_vertex, double current_cost, int num_visited, double& min_cost, std::vector<Vertex *>& tsp_path) {
    bool vi = false;
    double auxCost = 0;

    if (num_visited == graph.getNumVertex()) {
        for(Edge* edge: current_vertex->get_adj()){
            Vertex* w = edge->get_dest();

            if(w==graph.findVertex(0)){
                auxCost = edge->get_weight();
                vi=true;
            }
        }

        if(vi==false) return;

        double cost = current_cost + auxCost;

        if (cost < min_cost) {
            min_cost = cost;
            tsp_path.clear();
            tsp_path.push_back(current_vertex);

            for (Edge* e = current_vertex->get_path(); e->get_source()->get_id() != graph.findVertex(0)->get_id(); e = e->get_source()->get_path()) {
                tsp_path.push_back(e->get_source());
            }
            std::reverse(tsp_path.begin(), tsp_path.end());
        }
        return;
    }

    for (Edge* edge: current_vertex->get_adj()) {
        Vertex* w = edge->get_dest();

        if (!w->isVisited()) {
            w->setVisited(true);
            w->setPath(edge);
            tspBacktrack(w, current_cost + edge->get_weight(), num_visited + 1, min_cost, tsp_path);
            w->setVisited(false);
            w->setPath(nullptr);
        }
    }
}

void Controller::tspMain() {
    clock_t start = clock();
    std::vector<Vertex *> tsp_path;

    for (auto& i: graph.getVertexSet()) {
        i.second->setVisited(false);
        i.second->setPath(nullptr);
    }

    double min_cost = std::numeric_limits<double>::max();
    auto init = graph.findVertex(0);
    init->setVisited(true);

    tspBacktrack(init, 0, 1, min_cost, tsp_path);

    cout << "TSP Backtrack" << endl;
    cout << "Minimum Cost: "<< min_cost << endl;
    clock_t end = clock();
    cout << '0'<< " -> ";

    for (auto e : tsp_path) {
        cout << e->get_id() << " -> ";
    }
    cout << '0' << endl;
    cout << "Execution Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
}

void Controller::triangularApproximation() {
    clock_t start = clock();
    this->graph.triangularApproximationHeuristic();
    clock_t end = clock();
    cout << "Triangular Approx" << endl;
    cout << "Execution Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
}

void Controller::ourHeuristic() {
    clock_t start = clock();

    auto initialNode =  graph.getVertexSet()[0];
    auto currentNode = graph.getVertexSet()[0];

    vector<Edge*> path;
    int graphSize = graph.getNumVertex();
    double distance = 0;

    graph.nearestNeighbor(initialNode, currentNode, path, graphSize,distance);

    clock_t end = clock();
    cout << "Our Heuristic" << endl;
    cout << "Execution Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
}
