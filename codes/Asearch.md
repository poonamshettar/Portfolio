#include <bits/stdc++.h>
using namespace std;

#define ROW 9
#define COL 10
typedef pair<int, int> Pair;
typedef pair<double, pair<int, int>> pPair;

struct cell {
int parent_i, parent_j;
double f, g, h;
};

bool isValid(int row, int col) {
return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

bool isUnBlocked(int grid[][COL], int row, int col) {
return grid[row][col] == 1;
}

bool isDestination(int row, int col, Pair dest) {
return row == dest.first && col == dest.second;
}

double calculateHValue(int row, int col, Pair dest) {
return ((double)sqrt((row - dest.first) _ (row - dest.first) + (col - dest.second) _ (col - dest.second)));
}

void tracePath(cell cellDetails[][COL], Pair dest) {
printf("\nThe Path is ");
int row = dest.first;
int col = dest.second;
stack<Pair> Path;
while (!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col)) {
Path.push(make_pair(row, col));
int temp_row = cellDetails[row][col].parent_i;
int temp_col = cellDetails[row][col].parent_j;
row = temp_row;
col = temp_col;
}
Path.push(make_pair(row, col));
while (!Path.empty()) {
pair<int, int> p = Path.top();
Path.pop();
printf("-> (%d,%d) ", p.first, p.second);
}
return;
}

void aStarSearch(int grid[][COL], Pair src, Pair dest) {
if (!isValid(src.first, src.second) || !isValid(dest.first, dest.second) || !isUnBlocked(grid, src.first, src.second) || !isUnBlocked(grid, dest.first, dest.second)) {
printf("Invalid input\n");
return;
}

    if (isDestination(src.first, src.second, dest)) {
        printf("We are already at the destination\n");
        return;
    }

    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));

    cell cellDetails[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cellDetails[i][j].f = FLT_MAX;
            cellDetails[i][j].g = FLT_MAX;
            cellDetails[i][j].h = FLT_MAX;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }
    }

    int i = src.first, j = src.second;
    cellDetails[i][j].f = 0.0;
    cellDetails[i][j].g = 0.0;
    cellDetails[i][j].h = 0.0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;

    set<pPair> openList;
    openList.insert(make_pair(0.0, make_pair(i, j)));

    bool foundDest = false;

    while (!openList.empty()) {
        pPair p = *openList.begin();
        openList.erase(openList.begin());

        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;

        double gNew, hNew, fNew;

        if (isValid(i - 1, j) && isDestination(i - 1, j, dest)) {
            cellDetails[i - 1][j].parent_i = i;
            cellDetails[i - 1][j].parent_j = j;
            printf("The destination cell is found\n");
            tracePath(cellDetails, dest);
            foundDest = true;
            return;
        }
        else if (isValid(i - 1, j) && !closedList[i - 1][j] && isUnBlocked(grid, i - 1, j)) {
            gNew = cellDetails[i][j].g + 1.0;
            hNew = calculateHValue(i - 1, j, dest);
            fNew = gNew + hNew;
            if (cellDetails[i - 1][j].f == FLT_MAX || cellDetails[i - 1][j].f > fNew) {
                openList.insert(make_pair(fNew, make_pair(i - 1, j)));
                cellDetails[i - 1][j].f = fNew;
                cellDetails[i - 1][j].g = gNew;
                cellDetails[i - 1][j].h = hNew;
                cellDetails[i - 1][j].parent_i = i;
                cellDetails[i - 1][j].parent_j = j;
            }
        }

        if (isValid(i + 1, j) && isDestination(i + 1, j, dest)) {
            cellDetails[i + 1][j].parent_i = i;
            cellDetails[i + 1][j].parent_j = j;
            printf("The destination cell is found\n");
            tracePath(cellDetails, dest);
            foundDest = true;
            return;
        }
        else if (isValid(i + 1, j) && !closedList[i + 1][j] && isUnBlocked(grid, i + 1, j)) {
            gNew = cellDetails[i][j].g + 1.0;
            hNew = calculateHValue(i + 1, j, dest);
            fNew = gNew + hNew;
            if (cellDetails[i + 1][j].f == FLT_MAX || cellDetails[i + 1][j].f > fNew) {
                openList.insert(make_pair(fNew, make_pair(i + 1, j)));
                cellDetails[i + 1][j].f = fNew;
                cellDetails[i + 1][j].g = gNew;
                cellDetails[i + 1][j].h = hNew;
                cellDetails[i + 1][j].parent_i = i;
                cellDetails[i + 1][j].parent_j = j;
            }
        }

        if (isValid(i, j + 1) && isDestination(i, j + 1, dest)) {
            cellDetails[i][j + 1].parent_i = i;
            cellDetails[i][j + 1].parent_j = j;
            printf("The destination cell is found\n");
            tracePath(cellDetails, dest);
            foundDest = true;
            return;
        }
        else if (isValid(i, j + 1) && !closedList[i][j + 1] && isUnBlocked(grid, i, j + 1)) {
            gNew = cellDetails[i][j].g + 1.0;
            hNew = calculateHValue(i, j + 1, dest);
            fNew = gNew + hNew;
            if (cellDetails[i][j + 1].f == FLT_MAX || cellDetails[i][j + 1].f > fNew) {
                openList.insert(make_pair(fNew, make_pair(i, j + 1)));
                cellDetails[i][j + 1].f = fNew;
                cellDetails[i][j + 1].g = gNew;
                cellDetails[i][j + 1].h = hNew;
                cellDetails[i][j + 1].parent_i = i;
                cellDetails[i][j + 1].parent_j = j;
            }
        }

        if (isValid(i, j - 1) && isDestination(i, j - 1, dest)) {
            cellDetails[i][j - 1].parent_i = i;
            cellDetails[i][j - 1].parent_j = j;
            printf("The destination cell is found\n");
            tracePath(cellDetails, dest);
            foundDest = true;
            return;
        }
        else if (isValid(i, j - 1) && !closedList[i][j - 1] && isUnBlocked(grid, i, j - 1)) {
            gNew = cellDetails[i][j].g + 1.0;
            hNew = calculateHValue(i, j - 1, dest);
            fNew = gNew + hNew;
            if (cellDetails[i][j - 1].f == FLT_MAX || cellDetails[i][j - 1].f > fNew) {
                openList.insert(make_pair(fNew, make_pair(i, j - 1)));
                cellDetails[i][j - 1].f = fNew;
                cellDetails[i][j - 1].g = gNew;
                cellDetails[i][j - 1].h = hNew;
                cellDetails[i][j - 1].parent_i = i;
                cellDetails[i][j - 1].parent_j = j;
            }
        }

        if (isValid(i - 1, j + 1) && isDestination(i - 1, j + 1, dest)) {
            cellDetails[i - 1][j + 1].parent_i = i;
            cellDetails[i - 1][j + 1].parent_j = j;
            printf("
