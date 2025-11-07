// ---------------------------------------------------------------Backtracking------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

//safe function 
bool isSafe(int row, int col, vector<vector<int>>board, int n){
    //creating duplicates 
    int dupRow = row;
    int dupCol = col;

    //right bottom to left top up 
    while(row>=0 && col>=0){
        if(board[row][col]==1) return false;
        row--;
        col--;
    }
    row=dupRow;
    col= dupCol;

    //right top to left bottom down 
    while(row<n && col>=0){
        if(board[row][col]==1) return false;
        row++;
        col--;
    }
    row=dupRow;
    col= dupCol;

    while(col>=0){
        if(board[row][col]==1) return false;
        col--;
    }

    return true;

}

//solve function
void solve(int col,int n, vector<vector<int>>&board, vector<vector<vector<int>>>&ans){
    //base case
    if(col==n){
         
        ans.push_back(board);
        return;
    }
    //calling out all the rows 
    for(int row=0;row<n;row++){
        //if safe then place it 
        if(isSafe(row,col,board,n)){
            //place it 
            board[row][col] = 1;
            solve(col+1,n,board,ans);
            board[row][col] = 0; //backtracking 
        }
    }

}

//backtracking code 
int main(){
    vector<vector<vector<int>>> ans;
    int n; 
    cout<<"Enter n: "; cin>>n;
    cout<<endl;
    vector<vector<int>> board(n,vector<int>(n,0));
    solve(0,n,board,ans);
    
    for(int i=0;i<ans.size();i++){
        //this is matrix below 
        vector<vector<int>> b = ans[i];
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cout<<b[j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<endl;
    }
    
}

                      