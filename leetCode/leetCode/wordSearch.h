#include <vector>
#include <string>
#include<iostream>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( word == "") return true;
		int mask[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
		vector<vector<int> > marked;
		vector<int> tmp ;
		marked.clear();tmp.clear();
		for(int i = 0; i< board[0].size();++i)
			tmp.push_back(0);
		for(int i = 0;i<board.size();++i)
			marked.push_back(tmp);
		for(int i = 0; i< board.size(); ++i){
			for(int j = 0; j< board[i].size(); j++){
				if(board[i][j] == word[0]){
					vector<int> cord; cord.push_back(i); cord.push_back(j);
					marked[i][j] = 1;
					//cout << i <<" " <<j<< "  ";
					if(findWord( 1, cord, marked, word, mask, board))
						return true;
					//cout<<endl;
					marked[i][j] = 0;
				}
			}
		}
		return false;
    }
	bool findWord(int idx, vector<int> cord, vector<vector<int> > marked,string& word, int(*mask)[2], vector<vector<char> > & board){
		if(idx == word.size()) return true;
		char cur = word[idx];
		for(int i = 0; i< 4;i++){
			//cout<<mask[i][0]<<" "<<mask[i][1]<<endl;
			int r = cord[0], c = cord[1];
			r += mask[i][0]; c += mask[i][1];
			if(r >=0 && c >=0 && r< board.size() && c < board[r].size())
				if(board[r][c]== cur){
					if(marked[r][c] == 1) continue;
					marked[r][c] = 1;
					//cout << r <<" " <<c<< "  ";
					vector<int> newc;newc.push_back(r);newc.push_back(c);
					if(findWord( idx+1, newc, marked, word, mask, board))
						return true;
					marked[r][c] = 0;
				}
		}
		return false;

	}
};