#ifndef DA_PROJ2_CONTROLLER_H
#define DA_PROJ2_CONTROLLER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
#include "../data_structures/Graph.h"
#include "../includes/CSV_Reader.h"
using namespace std;

/**
 * @file Controller.h
 * @brief Defines the Controller class for handling the main functions of the project.
 */

/**
 * @brief The Controller class processes the main functions.
 */
class Controller {
public:
    /**
     * @brief Construct a new Controller object
     */
    Controller();

    Graph graph; /**< The graph we are working with. */

    /**
     * @brief This function returns our graph.
     */
    Graph get_graph();

    /**
     * @brief This function sets our graph.
     * @param newGraph The new graph.
     */
    void setGraph(Graph newGraph);

    // 4.1 TSP Backtrack
    /**
     * Perform backtracking to find the optimal solution for the Traveling Salesman Problem (TSP).
     * The function recursively explores all possible paths from the current vertex and updates the minimum cost and path.
     *
     * @param current_vertex The current vertex being visited.
     * @param current_cost The current cost of the path.
     * @param num_visited The number of visited vertices.
     * @param min_cost Reference to the minimum cost found so far.
     * @param tsp_path Reference to the vector of vertices representing the TSP path.
     *
     * @complexity O(N!), where N is the number of vertices. The backtracking algorithm explores all possible permutations.
     */
    void tspBacktrack(Vertex* current, double current_cost, int num_visited, double& min_cost, std::vector<Vertex *>& tsp_path);

    /**
     * Solve the Traveling Salesman Problem (TSP) using backtracking.
     * The function initializes the necessary variables, calls the backtracking function,
     * and prints the minimum cost and TSP path.
     *
     * @complexity O(N!), where N is the number of vertices. The backtracking algorithm explores all possible permutations.
     */
    void tspMain();

    // 4.2 Triangular Approximation
    /**
     * This function calls the triangularApproximationHeuristic() function of the graph object and measures the execution time.
     *
     * @complexity O(|V| + |E| log |V|), where |V| is the number of vertices and |E| is the number of edges.
     */
    void triangularApproximation();

    // 4.3 Our Heuristic
    void ourHeuristic();
};

#endif //DA_PROJ2_CONTROLLER_H
