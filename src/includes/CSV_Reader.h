#ifndef DA_PROJ2_CSV_READER_H
#define DA_PROJ2_CSV_READER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "../data_structures/Graph.h"
#include "../data_structures/VertexEdge.h"
using namespace std;

/**
 * @file CSV_Reader.h
 * @brief Defines the CSV_Reader class for reading all the files.
 */

/**
 * @brief The CSV_Reader class reads all the files.
 */
class CSV_Reader {
private:
    Graph graph; /**< The graph we are working with. */

public:
    /**
     * @brief Construct a new CSV_Reader object.
     */
    CSV_Reader();

    /**
     * @brief This function returns our graph.
     */
    Graph get_graph();

    /**
     * @brief This function reads a graph from the Extra Fully Connected Graphs directory.
     * @param input The input that corresponds to a file.
     */
    void read_Extra_Fully_Connected_Graphs(int input);

    /**
     * @brief This function reads a graph from the Real World Graphs directory.
     * @param input The input that corresponds to a file.
     */
    void read_Real_World_Graphs(int input);

    /**
     * @brief This function reads a graph from the Toy Graphs directory.
     * @param input The input that corresponds to a file.
     */
    void read_Toy_Graphs(int input);
};

#endif // DA_PROJ2_CSV_READER_H
