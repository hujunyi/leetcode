#include<iostream>
#include<unordered_map>
using namespace std;
bool isValidSudoku(vector<vector<char>> &board){
	unordered_map<char,bool> row;
	unordered_map<char,bool> col;
	unordered_map<char,bool> grid;
	int length = board.size();
	for(int i=0;i<length;i++){
		row.clear();
		col.clear();
		for(int j=0;j<length;j++){
			if(board[i][j]!='.'){
				if(row[board[i][j]])
					return false;
				else
					row[board[i][j]]=true;
			}
			if(board[j][i]!='.'){
				if(col[board[j][i]])
					return false;
				else
					col[board[j][i]=true;
			}
		}
	}
	for(int m=0;m<length;m+3){
		for(int n=0;n<9;n+=3){
			grid.clear()
			for(int p=m;p<m+3;p++){
				for(int q=n;q<n+3;q++){
					if(grid[board[p][q]])
						return false;
					else
						grid[board[p][q]=true;
				}
			}
		}
	}
	return true;	
}


