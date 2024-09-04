#include <iostream>
#include "maze.h"

/* Funcion prototipo */
bool pointsAreEqual(Maze::Point a, Maze::Point b) {
    return a.x == b.x && a.y == b.y;
}

// Recursive function to solve the maze using backtracking
bool solveMaze(Maze& maze, Maze::Point current) {
    // Base case: if we reached the exit, return true
    if (pointsAreEqual(current, maze.getExit())) {
        maze.markPath(current); // Mark the exit as part of the solution path
        return true;
    }

    // Mark the current position as visited
    maze.markVisited(current);

    // Get all valid neighbors (up, down, left, right)
    std::vector<Maze::Point> neighbors = maze.getNeighbors(current);
    
    for (const auto& neighbor : neighbors) {
        if (maze.isValid(neighbor.x, neighbor.y) && !maze.isWall(neighbor) && !maze.isVisited(neighbor)) {
            if (solveMaze(maze, neighbor)) {
                maze.markPath(current); // Mark the current cell as part of the solution path
                return true;
            }
        }
    }

    // If no path found, backtrack
    return false;
}

int main() {
    int N, M;  // Solo funcionan enteros impares
    N = 21;
    M = 23;
    Maze maze(N, M);
    maze.display();
    std::cout << "----SOLUCION-----" << std::endl;
    solveMaze(maze, maze.getEntry());
    maze.display();
    return 0;
}