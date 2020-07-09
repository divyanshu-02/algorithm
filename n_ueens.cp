#include <bits/stdc++.h> 
using namespace std;
void printsolution(int board[4][4])
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool issafe(int board[4][4],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        if(board[i][col]==1)
            return false;
    }
    for(i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
    {
        if(board[i][j]==1)
            return false;
    }
    for(i=row-1,j=col+1;i>=0&&j<4;i--,j++)
    {
        if(board[i][j]==1)
            return false;
    }
    return true;
}
bool solvefull(int board[4][4],int row)
{
    int i;
    if(row>=4)
        return true;
    for(i=0;i<4;i++)
    {
        if(issafe(board,row,i)==true)
        {
            board[row][i]=1;
            if(solvefull(board,(row+1))==true)
                return true;
            board[row][i]=0;    
        }
    }
    return false;
}
bool solveNQ() 
{ 
    int board[4][4] = { { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 } }; 
  
    if (solvefull(board, 0) == false) { 
        cout<<"Solution does not exist"; 
        return false; 
    } 
  
    printsolution(board); 
    return true; 
} 
  
// driver program to test above function 
int main() 
{ 
    solveNQ(); 
    return 0; 
}
