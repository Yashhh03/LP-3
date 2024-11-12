#include<iostream>
#include<set>
#include<vector>
using namespace std;

void printBoard(vector<vector<char>>& board) {
    for(const auto& row:board) {
        for(const auto& cell:row) {
            cout<<cell<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void queenSolution(int row,int n,vector<vector<char>>& board, set<int>& cols,set<int>& diagonal1,set<int>& diagonal2) {
    if(row == n) {
        printBoard(board);
        return;
    }
    
    for(int col=0;col<n;col++) {
        if(cols.find(col) == cols.end() && diagonal1.find(row - col) == diagonal1.end() && diagonal2.find(row + col) ==  diagonal2.end()) {
            board[row][col]='Q';
            cols.insert(col);
            diagonal1.insert(row - col);
            diagonal2.insert(row + col);
            
            queenSolution(row+1,n,board,cols,diagonal1,diagonal2);
            
            board[row][col]='.';
            cols.erase(col);
            diagonal1.erase(row - col);
            diagonal2.erase(row + col);
        }
    }
}

int main() {
    int n;
    cout<<"enter the size of the board(n): ";
    cin>>n;
    
    vector<vector<char>> board(n,vector<char>(n,'.'));
    
    int firstRow,firstCol;
    cout<<"Enter the first row and rol to place the queen: ";
    cin>>firstRow>>firstCol;
    
    board[firstRow][firstCol]='Q';
    
    
    set<int> cols,diagonal1,diagonal2;
    cols.insert(firstCol);
    diagonal1.insert(firstRow - firstCol);
    diagonal2.insert(firstRow + firstCol);
    
    queenSolution(firstRow+1,n,board,cols,diagonal1,diagonal2);
    return 0;
}