#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// DFS function using stack
void dfs(int adj_mat[10][10], int n, int node, int visited[10]) {
    cout << "DFS Traversal:\n";

    stack<int> stk;
    stk.push(node);
    visited[node] = 1;

    while (!stk.empty()) {
        int i = stk.top();
        stk.pop();

        cout << i << " --> ";

        for (int j = n - 1; j >= 0; j--) {
            if (adj_mat[i][j] == 1 && visited[j] != 1) {
                stk.push(j);
                visited[j] = 1;
            }
        }
    }
    cout << "NULL" << endl;
}

// BFS function using queue
void bfs(int adj_mat[10][10], int n, int node, int visited[10]) {
    cout << "BFS Traversal:\n";

    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        cout << i << " --> ";

        for (int j = 0; j < n; j++) {
            if (adj_mat[i][j] == 1 && visited[j] != 1) {
                q.push(j);
                visited[j] = 1;
            }
        }
    }
    cout << "NULL" << endl;
}

int main() {
    int n;
    int adj_mat[10][10] = {0};
    int visited[10] = {0};

    cout << "Enter the total number of nodes in the graph --> ";
    cin >> n;

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            char choice;
            cout << "Do you want to add the edge between " << i << " and " << j << "? (Y/N): ";
            cin >> choice;

            if (choice == 'Y' || choice == 'y') {
                adj_mat[i][j] = 1;
                adj_mat[j][i] = 1;
            }
        }
    }

    int ch;
    do {
        cout << "\nMenu:\n";
        cout << "1. DFS\n";
        cout << "2. BFS\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                for (int i = 0; i < n; i++) visited[i] = 0;
                dfs(adj_mat, n, 0, visited);
                break;

            case 2:
                for (int i = 0; i < n; i++) visited[i] = 0;
                bfs(adj_mat, n, 0, visited);
                break;

            case 0:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }

    } while (ch != 0);

    return 0;
}
