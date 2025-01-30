cmake_minimum_required(VERSION 3.28)
project(DA_PROJ2)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(projeto2
        src/includes/Auxiliar.h
        src/includes/CSV_Reader.h
        src/includes/Menu.h
        src/main/Auxiliar.cpp
        src/main/CSV_Reader.cpp
        src/main/main.cpp
        src/main/Menu.cpp
        src/data_structures/Graph.h
        src/data_structures/VertexEdge.cpp
        src/data_structures/VertexEdge.h
        src/data_structures/Graph.cpp
        src/data_structures/Controller.cpp
        src/data_structures/Controller.h)
