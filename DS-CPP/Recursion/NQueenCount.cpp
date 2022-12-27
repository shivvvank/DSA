    #include<bits/stdc++.h>
    using namespace std;
    bool isSafe(int row,int col,vector<string> &board,int n)
    {
        int drow = row;
        int dcol = col;
        while(row>=0&&col>=0)
        {
            if(board[row][col]=='Q')    return false;
            row--;
            col--;
        }
        row = drow;
        col = dcol;
        while(col>=0)
        {
            if(board[row][col]=='Q')    return false;
            col--;
        }
        row = drow;
        col = dcol;
        while(row<n&&col>=0)
        {
            if(board[row][col]=='Q')    return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(vector<string> board,int n,int col,int &count)
    {
        if(col==n)
        {
            count++;
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col]='Q';
                solve(board,n,col+1,count);
                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board;
        string row="";
        for(int i=0;i<n;i++)
            row+='.';
        for(int i=0;i<n;i++)
            board.push_back(row);
        int count = 0;
        solve(board,n,0,count); 
        return count;
    }
    int main()
    {
        cout<<totalNQueens(9)<<endl;
        return 0;
    }