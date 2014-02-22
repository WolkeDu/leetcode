#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<int> > res;
		vector<int> cur(3) ;
		int len = num.size(),cut = -1;
		QuickSort(num,0,len-1);
		for(int i = 0;i<len;i++){
			if(num[i]>=0){
				cut = i; // boundary between positive and negative values
				break;
			}	
		}

		//search from the boudnary point
		for(int i = 0;i<len-2;i++){
			if(i>cut) break;
			for(int j = i+1;j<len-1;j++)
				for(int k = j+1;k<len;k++){
					if(k<cut) k = cut;
					if((num[i] + num[j] + num[k]) == 0)
					{ 
						cur[0] = num[i];cur[1]= num[j]; cur[2] = num[k];
						if(non_exist(res,cur))
							res.push_back(cur);
					}
				}
		}
    return res;    
    }
	bool non_exist(vector<vector<int> >& strs, vector<int>& str){ // determine whether exists a same triplet
		int len1 = strs.size(),len2 = str.size();
		int i = 0,j=0;
		for(i = 0;i< len1;i++)
		{
			for(j = 0;j<len2;j++)
				if(strs[i][j] != str[j])
					break;
			if(j == len2) return false;
		}
		if(i == len1) 
			return true;
	}
	void QuickSort(vector<int>& num, int lf, int rt){
		if(lf>=rt) return;
		int i = lf, j = rt + 1,k = lf;
		int key = num[lf];
		while(1){
			while(num[++k]<=key){
				if(k == rt) break;
			} // left hand

			while(num[--j]>key){
				if(j == lf) break;
			}// right hand
			if(k >= j) break;
			else 
			swap(num,k,j);
		}
		swap(num,lf,j);
		QuickSort(num,lf,j-1);
		QuickSort(num,j+1,rt);
	}
	void swap(vector<int>& num,int x, int y){
		int tmp = num[x];
		num[x] = num[y];
		num[y] = tmp;
	}
};