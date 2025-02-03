# 🚢 Routing Algorithm for Ocean Shipping and Urban Deliveries

## 📌 Project Overview

This project tackles the **Travelling Salesperson Problem (TSP)** in real-world scenarios, including **urban deliveries** and **ocean shipping**. Given the intractability of TSP, we explore both **exact** and **heuristic** approaches to find optimal or near-optimal delivery routes.

## 🎯 Objectives

- Implemented a **backtracking** algorithm for small graphs.
- Developed and analyzed **approximate heuristics** to solve TSP efficiently.
- Compared heuristic results against optimal solutions.
- Handles **real-world graphs** that may not be fully connected.
- Provides a **user-friendly interface** for data loading and execution.


## 🏗️ Implemented Features

### 1️⃣ **Backtracking Algorithm**
- Computes the **exact** optimal TSP solution.
- Used for **small graphs** due to high computational cost.
- Execution time is plotted to illustrate feasibility.

### 2️⃣ **Triangular Approximation Heuristic**
- Uses **triangular inequality** to provide a **2-approximation**.
- Ensures a fully connected graph using **Haversine distance**.
- Compared against the backtracking method.

### 3️⃣ **Custom Heuristic**
- An efficient heuristic tailored for **large graphs**.
- Uses techniques such as **divide-and-conquer** or **clustering**.
- Balances **runtime performance** and **solution quality**.

### 4️⃣ **TSP in Real-World Graphs**
- Handles **disconnected graphs** from real-world datasets.
- Allows **user-defined starting points**.
- Ensures a feasible path if one exists.

## 📊 Dataset

The project utilizes **18 datasets**, categorized as:

- **Toy Graphs (3)**: Small graphs for testing optimal solutions.
- **Medium-Sized Graphs (12)**: Fully connected graphs (25–900 nodes).
- **Real-World Graphs (3)**: Large graphs (up to **10,000 nodes, 10M edges**).
<br>
<hr>
This project was developed for Algorithms Design course @FEUP
