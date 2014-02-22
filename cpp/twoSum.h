#pragma once
#include <vector>
using namespace std;
class Solution{

public:
	vector<int> twoSum(vector<int> &numbers, int target){
		vector<int> two_vector;
		int len = numbers.size();
		vector<int> tmp_vector(len);
		vector<int> indices(len);
		for(int i = 0;i<len;i++){
			tmp_vector[i] = target - numbers[i];
			indices[i] = i;
			//cout<<numbers[i]<< " ";
		}
		QuickSort(numbers,indices,0,len-1); // 注意此处排序时，原来的下标也要跟着变化
			int idx;
		for(int i = 0;i<len;i++){
			if(tmp_vector[i] > 0){
				idx = BS(numbers,0,len-1,tmp_vector[i]);
				if(idx > -1 ){
					idx = indices[idx]; // get the original index
					if(idx != i){
						if(idx<i){
							two_vector.push_back(idx+1);
							two_vector.push_back(i+1);
						}
						two_vector.push_back(i+1);
						two_vector.push_back(idx+1);
						return two_vector;
					}
				}
			}
			
		}
//		return two_vector;
}
	int BS(vector<int> &numbers, int lf, int rt, int x){
		if(lf > rt) return -1;
		int mid = (rt+lf)/2;
		if(numbers[mid]==x) return mid;
		else if(numbers[mid]>x)
				return BS(numbers,lf,mid-1,x);
		else
			return BS(numbers,mid+1,rt,x);
	}
	void QuickSort(vector<int>& numbers, vector<int>& indices, int lf, int rt){
		if(lf>=rt)return;
		int key = numbers[lf];
		int i = lf, j = rt+1;
		while(1){
			while(numbers[++i]<=key) {
				if(i==rt) break;
			}
			while(numbers[--j]>key) {
				if(j==lf) break;
			}
			if(i<j){
				swap(numbers,i,j);
				swap(indices,i,j);
			}
			else 
				break;
		}
		swap(numbers,lf,j);
		swap(indices,lf,j);
		QuickSort(numbers,indices,lf,j-1);
		QuickSort(numbers,indices,j+1,rt);
	}
	void swap(vector<int>& numbers, int i, int j){
		int tmp = numbers[i];
		numbers[i] = numbers[j];
		numbers[j] = tmp;
	}

};