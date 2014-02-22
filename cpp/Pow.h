class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n == 0) return 1;
		if(x == 0)
			if(n == 0) return 1;
			else return 0;
		bool flag = false;
		if (n < 0 ){
			n = -n;
			flag = true;
		}
	double base = x;
	int t = n;
	double res = 1;
	while(t/2){
		if(t%2){
		res = res*base;
		}
		base = base*base;
		t = t/2;
	}
	res = res*base;
	 if(flag == true)
		 res = 1/res;
	 return res;
    }
};