#ifndef DA_PROJ2_MENU_H
#define DA_PROJ2_MENU_H

/**
 * @file Menu.h
 * @brief A class to handle the user interface menu.
 *
 * This file contains the definition of the `Menu` class, which handles the user interface menu.
 */

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "../data_structures/Graph.h"
#include "../data_structures/Controller.h"
#include "../includes/Auxiliar.h"
#include "../includes/CSV_Reader.h"
using namespace std;

/**
 * @class Menu
 * @brief A class to handle the user interface menu.
 *
 * The `Menu` class handles the user interface menu.
 */
class Menu {
private:
    int state = 0; /**< The current state of the menu. */
    std::vector<std::string> functioningSubOptions = {"Backtracking Algorithm", "Triangular Approximation Heuristic", "Other Heuristics", "TSP in the Real World" , "Exit"}; /**< Options for te functioning of the program. */
    std::vector<std::string> toyGraphsSubOptions = {"Shipping", "Stadiums", "Tourism", "Exit"}; /**< Options for the toy graphs. */
    std::vector<std::string> datasetSubOptions = {"Toy Graphs", "Extra Fully Connected Graphs", "Real World Graphs", "Exit"}; /**< Options for selecting a data set. */
    std::vector<std::string> extraFullyConnectedGraphsSubOptions = {"25 nodes Graph", "50 nodes Graph", "75 nodes Graph", "100 nodes Graph", "200 nodes Graph", "300 nodes Graph", "400 nodes Graph", "500 nodes Graph", "600 nodes Graph", "700 nodes Graph", "800 nodes Graph", "900 nodes Graph", "Exit"}; /**< Options for the extra fully connected graphs. */
    std::vector<std::string> realWorldGraphsSubOptions = {"Graph 1", "Graph 2", "Graph 3", "Exit"}; /**< Options for the real world graphs. */

    /**
    * @brief Displays options for the toy graphs data set.
    *
    */
    void toyGraphsOptions();

    /**
    * @brief Displays options for the toy graphs data set.
    *
    */
    void toyGraphsOptions2();

    /**
    * @brief Displays options for the toy graphs data set.
    *
    */
    void toyGraphsOptions3();

    /**
    * @brief Displays options for the extra fully connected graphs data set.
    *
    */
    bool datasetOptions();

    /**
    * @brief Displays the 2nd options for the extra fully connected graphs data set.
    *
    */
    bool datasetOptions2();

    /**
    * @brief Displays the 3rd options for the extra fully connected graphs data set.
    *
    */
    void extraFullyConnectedGraphsOptions();

    /**
    * @brief Displays the 4th options for the extra fully connected graphs data set.
    *
    */
    void extraFullyConnectedGraphsOptions2();

    /**
    * @brief Displays options for the real world graphs data set.
    *
    */
    void realWorldGraphsOptions();

    /**
    * @brief Displays options for the real world graphs data set.
    *
    */
    void realWorldGraphsOptions2();

    /**
    * @brief Displays the main menu.
    *
    */
    void mainMenu();
public:
    /**
     * @brief Constructs a `Menu` object with the initial state set to 0.
     *
     */
    Menu();

    /**
     * @brief Returns `true` if there is a next state, `false` otherwise.
     *
     *
     * @return `true` if there is a next state, `false` otherwise.
     */
    bool nextState(int key);
};

#endif // DA_PROJ2_MENU_H
