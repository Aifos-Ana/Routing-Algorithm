#ifndef DA_PROJ2_AUXILIAR_H
#define DA_PROJ2_AUXILIAR_H

/**
 * @file Auxiliar.h
 * @brief A collection of utility functions for the project.
 *
 * This file contains the definitions of several utility functions for the project.
 */

#include <vector>
#include <string>
#include <iostream>
#include <climits>
using namespace std;

/**
 * @brief Clears the screen.
 */
void clearSCR();

/**
 * @brief Displays a title with an optional string.
 *
 *
 * @param str The optional `string` to display.
 */
void title(const std::string& str = "");

/**
 * @brief Displays a menu with a given list of options.
 *
 * Displays a menu with a given list of `options`, and an optional `settingsOp` parameter.
 *
 * @param options The list of menu options.
 * @param settingsOp An optional parameter to set the selected option to a default value.
 */
void showMenu(const std::vector<std::string>& options, int settingsOp = 0);

/**
 * @brief Gets the user's option as an integer.
 *
 * Gets the user's option as an integer with an optional `text` and `text2`.
 *
 * @param text The optional introductory `text` to display.
 * @param text2 The optional concluding `text2` to display.
 * @return The user's option as an integer.
 */
int getInt(const std::string& text = "", const std::string& text2 = "");

/**
 * @brief Gets the user's option as a double.
 *
 * Gets the user's option as a double with an optional `text` and `text2`.
 *
 * @param text The optional introductory `text` to display.
 * @param text2 The optional concluding `text2` to display.
 * @return The user's option as a double.
 */
double getDouble(const std::string& text = "", const std::string& text2 = "");

/**
 * @brief Gets the user's option as a string.
 *
 * Gets the user's option as a string with an optional `text`.
 *
 * @param text The optional introductory `text` to display.
 * @return The user's option as a string.
 */
std::string getString(const std::string& text = "");

#endif // DA_PROJ2_AUXILIAR_H
