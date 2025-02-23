#include "../includes/CSV_Reader.h"

CSV_Reader::CSV_Reader(){
    this->graph=Graph();
}

Graph CSV_Reader::get_graph() {
    return this->graph;
}

void CSV_Reader::read_Extra_Fully_Connected_Graphs(int input) {
    string filename;
    switch(input){
        case 1:
            filename = "../datasets/Extra_Fully_Connected_Graphs/edges_25.csv";
            break;
        case 2:
            filename = "../datasets/Extra_Fully_Connected_Graphs/edges_50.csv";
            break;
        case 3:
            filename = "../datasets/Extra_Fully_Connected_Graphs/edges_75.csv";
            break;
        case 4:
            filename = "../datasets/Extra_Fully_Connected_Graphs/edges_100.csv";
            break;
        case 5:
            filename = "../datasets/Extra_Fully_Connected_Graphs/edges_200.csv";
            break;
        case 6:
            filename = "../datasets/Extra_Fully_Connected_Graphs/edges_300.csv";
            break;
        case 7:
            filename = "../datasets/Extra_Fully_Connected_Graphs/edges_400.csv";
            break;
        case 8:
            filename = "../datasets/Extra_Fully_Connected_Graphs/edges_500.csv";
            break;
        case 9:
            filename = "../datasets/Extra_Fully_Connected_Graphs/edges_600.csv";
            break;
        case 10:
            filename = "../datasets/Extra_Fully_Connected_Graphs/edges_700.csv";
            break;
        case 11:
            filename = "../datasets/Extra_Fully_Connected_Graphs/edges_800.csv";
            break;
        case 12:
            filename = "../datasets/Extra_Fully_Connected_Graphs/edges_900.csv";
            break;
        default:
            cout << "Invalid input" << endl;
            return;
    }
    ifstream file(filename);
    string line;
    while(getline(file, line)){
        stringstream ss(line);
        string t;
        vector<string> aux;
        while (getline(ss, t, ',')) {
            aux.push_back(t);
        }

        int node1= stoi(aux[0]);
        int node2= stoi(aux[1]);
        double w=stod(aux[2]);
        this->graph.add_vertex(node1);
        this->graph.add_vertex(node2);
        this->graph.add_edge(node1, node2, w);
        this->graph.add_edge(node2, node1, w);
    }
    file.close();
}

void CSV_Reader::read_Real_World_Graphs(int input) {
    string filename_edges;
    string filename_nodes;
    switch (input) {
        case 1:
            filename_edges = "../datasets/Real-world Graphs/graph1/edges.csv";
            filename_nodes = "../datasets/Real-world Graphs/graph1/nodes.csv";
            break;
        case 2:
            filename_edges = "../datasets/Real-world Graphs/graph2/edges.csv";
            filename_nodes = "../datasets/Real-world Graphs/graph2/nodes.csv";
            break;
        case 3:
            filename_edges = "../datasets/Real-world Graphs/graph3/edges.csv";
            filename_nodes = "../datasets/Real-world Graphs/graph3/nodes.csv";
            break;
        default:
            cout << "Invalid input" << endl;
            return;
    }

    ifstream file_nodes(filename_nodes);
    string line_nodes;

    getline(file_nodes, line_nodes);
    while (getline(file_nodes, line_nodes)) {
        stringstream ss(line_nodes);
        string nodeId, lon, lat;
        getline(ss, nodeId, ',');
        getline(ss, lon, ',');
        getline(ss, lat, '\0');

        int id1 = stoi(nodeId);
        double lat2 = stod(lat);
        double lon2 = stod(lon);
        this->graph.add_vertex(id1, lon2, lat2);
    }

    ifstream file_edges(filename_edges);
    string line_edges;

    getline(file_edges,line_edges);
    while (getline(file_edges, line_edges)) {
        stringstream ss(line_edges);
        string node1;
        string node2;
        string weight;
        getline(ss, node1, ',');
        getline(ss, node2, ',');
        getline(ss, weight, '\0');

        int node1_ = stoi(node1);
        int node2_ = stoi(node2);
        double weight_ = stod(weight);
        this->graph.add_edge(node1_, node2_, weight_);
        this->graph.add_edge(node2_, node1_, weight_);
    }
    file_nodes.close();
    file_edges.close();
}

void CSV_Reader::read_Toy_Graphs(int input) {
    string filename;
    switch (input) {
        case 1:
            filename= "../datasets/Toy-Graphs/shipping.csv";
            break;
        case 2:
            filename= "../datasets/Toy-Graphs/stadiums.csv";
            break;
        case 3:
            filename= "../datasets/Toy-Graphs/tourism.csv";
            break;
    }

    ifstream file(filename);

    if(!file.is_open())cout<<"Couldn't open the file!"<<endl;
    string line;
    int i= 0;
    getline(file,line);
    if (input == 3){
        while(getline(file,line)){
            stringstream ss(line);
            string t;
            vector<string>aux;
            while(getline(ss,t,',')){
                aux.push_back(t);
            }
            int node1 = stoi(aux[0]);
            int node2 = stoi(aux[1]);
            double w = stod (aux[2]);
            string name1 = aux[3];
            string name2 = aux[4];
            this->graph.add_vertex(node1, name1);
            this->graph.add_vertex(node2, name2);
            this->graph.add_edge(node1, node2, w);
            this->graph.add_edge(node2, node1, w);
        }
    }
    else{
        while (getline(file, line)) {
            stringstream ss(line);
            string t;
            vector<string> aux;
            while (getline(ss, t, ',')) {
                aux.push_back(t);
            }
            int node1 = stoi(aux[0]);
            int node2 = stoi(aux[1]);
            double weight = stod(aux[2]);

            this->graph.add_vertex(node1);
            this->graph.add_vertex(node2);
            this->graph.add_edge(node1, node2, weight);
            this->graph.add_edge(node2, node1, weight);
        }
    }
    file.close();
}
