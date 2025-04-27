#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Node class representing a puzzle state
class Node {
public:
    vector<vector<int>> data; // Puzzle state
    int level;                // Depth of the node
    int fval;                 // f = g + h (cost + heuristic)

    Node(vector<vector<int>> data, int level, int fval)
        : data(data), level(level), fval(fval) {}

    // Find the blank (0) position
    pair<int, int> findBlank() {
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[i].size(); j++) {
                if (data[i][j] == 0)
                    return {i, j};
            }
        }
        return {-1, -1}; // Shouldn't happen
    }

    // Generate child nodes by moving the blank
    vector<Node> generateChildren() {
        vector<Node> children;
        pair<int, int> blank = findBlank();
        int x = blank.first, y = blank.second;

        // Possible moves: right, left, down, up
        vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (auto move : moves) {
            int newX = x + move.first, newY = y + move.second;
            if (newX >= 0 && newX < data.size() && newY >= 0 && newY < data[0].size()) {
                vector<vector<int>> newData = data;
                swap(newData[x][y], newData[newX][newY]);
                children.emplace_back(newData, level + 1, 0);
            }
        }

        return children;
    }
};

// Heuristic: Count of misplaced tiles
int calculateH(const vector<vector<int>>& current, const vector<vector<int>>& goal) {
    int h = 0;
    for (int i = 0; i < current.size(); i++) {
        for (int j = 0; j < current[i].size(); j++) {
            if (current[i][j] != goal[i][j] && current[i][j] != 0) {
                h++;
            }
        }
    }
    return h;
}

// Display the puzzle state
void display(const vector<vector<int>>& state) {
    for (const auto& row : state) {
        for (int val : row) {
            if (val == 0)
                cout << "_ ";
            else
                cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// A* algorithm implementation
void solvePuzzle(vector<vector<int>> start, vector<vector<int>> goal) {
    auto compare = [](Node& a, Node& b) { return a.fval > b.fval; };
    priority_queue<Node, vector<Node>, decltype(compare)> open(compare);

    Node startNode(start, 0, calculateH(start, goal));
    open.push(startNode);

    while (!open.empty()) {
        Node current = open.top();
        open.pop();

        cout << "Current State:\n";
        display(current.data);

        // Check if goal is reached
        if (current.data == goal) {
            cout << "Goal state reached!\n";
            return;
        }

        // Generate children and add to open list
        vector<Node> children = current.generateChildren();
        for (Node& child : children) {
            child.fval = child.level + calculateH(child.data, goal);
            open.push(child);
        }
    }

    cout << "No solution found.\n";
}

int main() {
    vector<vector<int>> start(3, vector<int>(3));
    vector<vector<int>> goal(3, vector<int>(3));

    cout << "Enter the start state (use 0 for blank):\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> start[i][j];

    cout << "Enter the goal state:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> goal[i][j];

    solvePuzzle(start, goal);
    return 0;
}