#include <iostream>
#include <vector>
#include <set>
using namespace std;

void printSolution(vector<vector<char>>& board) {
    for(const auto& row:board) {
        for(const auto& cell : row) {
            cout<<cell<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void solveQueens(int row,int n,vector<vector<char>>& board,set<int>& cols,set<int>& diagonal1,set<int>& diagonal2) {
    if(row==n) {
        printSolution(board);
        return;
    }
    for(int col = 0;col<n;col++) {
        if(cols.find(col) == cols.end() && diagonal1.find(row-col) == diagonal1.end() && diagonal2.find(row+col) == diagonal2.end()) {
            board[row][col] ='Q';
            cols.insert(col);
            diagonal1.insert(row-col);
            diagonal2.insert(row+col);
            
            solveQueens(row+1,n,board,cols,diagonal1,diagonal2);
            
            board[row][col] = '.';
            cols.erase(col);
            diagonal1.erase(row-col);
            diagonal2.erase(row+col);
        }
    }
}

int main() {
    int n;
    cout<<"Enter the number of Queens: ";
    cin>>n;
    
    vector<vector<char>> board(n,vector<char>(n,'.'));
    set<int> cols;
    set<int> diagonal1;
    set<int> diagonal2;
    
    cout<<"Solution to the "<<n<<" Queens problem: "<<endl;
    solveQueens(0,n,board,cols,diagonal1,diagonal2);
    
    return 0;
}