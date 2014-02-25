#include<iostream>
#include<vector>
using namespace std;
void solveSudoku(vector<vector<char> > &board){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(board[i][j]=='.')
					for(int k=1;k<=9;k++){
						board[i][j] = '0'+k;
						if(solveSudoku(board) && isValid(board,i,j)
							return true;
					}
			}
		}
		return false;
	}
bool isValid(vector<vector<char> > &board, int x,int y){
	for(int i=0;i<9;i++){
		if(i!=x && board[i][y] == board[x][y])
			return false;
		if(i!=y && board[x][i] == board[x][y])
			return false;
	}
	for(int m=(x/3)*3;m<(x/3+1)*3;m++){
		for(int n=(y/3)*3;n<(y/3+1)*3;n++){
			if(m!=x && n!=y && board[m][n]== board[x][y])
				return false;
		}
	}


