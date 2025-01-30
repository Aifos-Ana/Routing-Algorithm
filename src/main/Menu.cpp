#include "../includes/Menu.h"

void Menu::mainMenu() {
    title("Main Menu");
    showMenu(functioningSubOptions);

    int key = getInt("Choose an option");
    while (key < 1 || key > 5) key = getInt("Not a valid option. Choose a valid option.");

    switch (key) {
        case 1:
            state = 1;
            break;
        case 2:
            state = 2;
            break;
        case 3:
            state = 3;
            break;
        case 4:
            state = 10;
            break;
        case 5:
            state = 10;
            break;
        default:
            state = 4;
    }
}

bool Menu::nextState(int key) {
    CSV_Reader readfiles = CSV_Reader();
    clearSCR();

    std::string option;
    switch (state) {
        case 0:
            mainMenu();
            return true;
        case 1:
            toyGraphsOptions();
            state = 10;
            return true;
        case 2:
            datasetOptions();
            return true;
        case 3:
            datasetOptions2();
            return true;
        case 4:
            toyGraphsOptions2();
            state = 10;
            return true;
        case 5:
            extraFullyConnectedGraphsOptions();
            state = 10;
            return true;
        case 6:
            realWorldGraphsOptions();
            state = 10;
            return true;
        case 7:
            toyGraphsOptions3();
            state = 10;
            return true;
        case 8:
            extraFullyConnectedGraphsOptions2();
            state = 10;
            return true;
        case 9:
            realWorldGraphsOptions2();
            state = 10;
            return true;
        default:
            return false;
    }
}

void Menu::toyGraphsOptions() {
    title("Choose the number of the file you wish to run.");
    showMenu(toyGraphsSubOptions);

    int key = getInt("Choose an option.");
    if(key == 4) {
        return;
    }
    while (key < 1 || key > 4) {
        key = getInt("Not a valid option. Choose a valid option.");
    }

    CSV_Reader readfiles = CSV_Reader();
    Controller controller = Controller();

    readfiles.read_Toy_Graphs(key);

    Graph graph = readfiles.get_graph();
    controller.setGraph(graph);

    controller.tspMain();

    cout << "Thanks for using our program!" << endl;
    cout << "Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

void Menu::toyGraphsOptions2() {
    title("Choose the number of the file you wish to run.");
    showMenu(toyGraphsSubOptions);

    int key = getInt("Choose an option.");
    if(key == 4) {
        return;
    }
    while (key < 1 || key > 4) {
        key = getInt("Not a valid option. Choose a valid option.");
    }

    CSV_Reader readfiles = CSV_Reader();
    Controller controller = Controller();

    readfiles.read_Toy_Graphs(key);

    Graph graph = readfiles.get_graph();
    controller.setGraph(graph);

    controller.triangularApproximation();

    cout << "Thanks for using our program!" << endl;
    cout << "Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

void Menu::toyGraphsOptions3() {
    title("Choose the number of the file you wish to run.");
    showMenu(toyGraphsSubOptions);

    int key = getInt("Choose an option.");
    if(key == 4) {
        return;
    }
    while (key < 1 || key > 4) {
        key = getInt("Not a valid option. Choose a valid option.");
    }

    CSV_Reader readfiles = CSV_Reader();
    Controller controller = Controller();

    readfiles.read_Toy_Graphs(key);

    Graph graph = readfiles.get_graph();
    controller.setGraph(graph);

    controller.ourHeuristic();

    cout << "Thanks for using our program!" << endl;
    cout << "Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

bool Menu::datasetOptions() {
    title("Choose the folder of files you wish to test:");
    showMenu(datasetSubOptions);

    int key = getInt("Choose an option");
    if(key == 4) {
        state = 10;
        return false;
    }
    while (key < 1 || key > 3) {
        key = getInt("Not a valid option. Choose a valid option.");
    }

    switch (key) {
        case 1:
            state = 4;
            return true;
        case 2:
            state = 5;
            return true;
        case 3:
            state = 6;
            return true;
        default:
            return false;
    }
}

bool Menu::datasetOptions2() {
    title("Choose the folder of files you wish to test:");
    showMenu(datasetSubOptions);

    int key = getInt("Choose an option");
    if(key == 4) {
        state = 10;
        return false;
    }
    while (key < 1 || key > 3) {
        key = getInt("Not a valid option. Choose a valid option.");
    }

    switch (key) {
        case 1:
            state = 7;
            return true;
        case 2:
            state = 8;
            return true;
        case 3:
            state = 9;
            return true;
        default:
            return false;
    }
}

void Menu::extraFullyConnectedGraphsOptions() {
    title("Choose the number of the file you wish to run.");
    showMenu(extraFullyConnectedGraphsSubOptions);

    int key = getInt("Choose an option.");
    if(key == 13) {
        return;
    }
    while (key < 1 || key > 12) {
        key = getInt("Not a valid option. Choose a valid option.");
    }

    CSV_Reader readfiles = CSV_Reader();
    Controller controller = Controller();

    readfiles.read_Extra_Fully_Connected_Graphs(key);

    Graph graph = readfiles.get_graph();
    controller.setGraph(graph);

    controller.triangularApproximation();

    cout << "Thanks for using our program!" << endl;
    cout << "Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

void Menu::extraFullyConnectedGraphsOptions2() {
    title("Choose the number of the file you wish to run.");
    showMenu(extraFullyConnectedGraphsSubOptions);

    int key = getInt("Choose an option.");
    if(key == 13) {
        return;
    }
    while (key < 1 || key > 12) {
        key = getInt("Not a valid option. Choose a valid option.");
    }

    CSV_Reader readfiles = CSV_Reader();
    Controller controller = Controller();

    readfiles.read_Extra_Fully_Connected_Graphs(key);

    Graph graph = readfiles.get_graph();
    controller.setGraph(graph);

    controller.ourHeuristic();

    cout << "Thanks for using our program!" << endl;
    cout << "Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

void Menu::realWorldGraphsOptions() {
    title("Choose the graph you wish to run.");
    showMenu(realWorldGraphsSubOptions);

    int key = getInt("Choose an option.");
    if(key == 4) {
        return;
    }
    while (key < 1 || key > 3) {
        key = getInt("Not a valid option. Choose a valid option.");
    }

    CSV_Reader readfiles = CSV_Reader();
    Controller controller = Controller();

    readfiles.read_Real_World_Graphs(key);

    Graph graph = readfiles.get_graph();
    controller.setGraph(graph);

    controller.triangularApproximation();

    cout << "Thanks for using our program!" << endl;
    cout << "Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

void Menu::realWorldGraphsOptions2() {
    title("Choose the graph you wish to run.");
    showMenu(realWorldGraphsSubOptions);

    int key = getInt("Choose an option.");
    if(key == 4) {
        return;
    }
    while (key < 1 || key > 3) {
        key = getInt("Not a valid option. Choose a valid option.");
    }

    CSV_Reader readfiles = CSV_Reader();
    Controller controller = Controller();

    readfiles.read_Real_World_Graphs(key);

    Graph graph = readfiles.get_graph();
    controller.setGraph(graph);

    controller.ourHeuristic();

    cout << "Thanks for using our program!" << endl;
    cout << "Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

Menu::Menu() {
    mainMenu();
}
