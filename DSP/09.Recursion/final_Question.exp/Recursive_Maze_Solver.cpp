//미로 탐색
#include <iostream>
#define N 5

bool isSafe(int maze[N][N], int x, int y, bool visited[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0 && !visited[x][y]);
}

bool solveMaze(int maze[N][N], int x, int y, int destX, int destY, bool visited[N][N]) {
    if (x == destX && y == destY) {
        return true;
    }

    visited[x][y] = true;

    // 이동 방향: 아래, 오른쪽, 위, 왼쪽
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isSafe(maze, nextX, nextY, visited) && solveMaze(maze, nextX, nextY, destX, destY, visited)) {
            return true;
        }
    }

    visited[x][y] = false; // 백트래킹
    return false;
}

int main() {
    int maze[N][N] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}
    };
    bool visited[N][N] = {false};

    if (solveMaze(maze, 0, 0, 4, 4, visited)) {
        std::cout << "Path Found\n";
    } else {
        std::cout << "No Path Found\n";
    }

    return 0;
}
