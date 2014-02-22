
// consider construct NFA to solve this problem
class Solution {
	public:
		bool isNumber(const char *s) { 
			if(*s == '\0') return false;
			int i = 0;
			int state = 0;
			while(*(s+i) == ' ' ){
				i++;
			}
			if(*(s+i) == '+' || *(s+i) == '-') {
				i++;
				state = 1;
			}
			if(*(s+i) == '\0') {
				state = -1;
				return false;
			}
			if(*(s+i) >= '0' && *(s+i)<='9') {
				state = 2;
				i++;
			}
			else if(*(s+i) == '.') {
				state = 3;
				i++;
				if(*(s+i) == '\0' || *(s+i)<'0' || *(s+i)>'9') {
					return false;
				}
			}
			while(*(s+i) != '\0' && *(s+i) >= '0' && *(s+i)<='9' ) // original state
				i++;
			if(*(s+i) == '.'){ 
				if(state == 3) return false;
				else state = 3;
				i++;//3 state '.' come from 1 or 2 state
				while( *(s+i) !='\0' &&(*(s+i)>='0' && *(s+i)<= '9') )
					i++;
			}
			if(*(s+i) == 'e'){ 
				if(state == 3) {
					if(*(s+i-2)!= '.' && (*(s+i-2)<'0' || *(s+i-2)>'9')) return false;
				}
				else if(state != 2)
					return false;
				state = 4;
				i++;// 4 state 'e', come from 2 state or 3 state
                if(*(s+i) == '+' || *(s+i) == '-') i++;
                else if(*(s+i)<'0' || *(s+i)>'9') return false;

				if(*(s+i)< '0' || *(s+i) > '9') return false;
				while(*(s+i) != '\0' && (*(s+i)>='0' && *(s+i)<='9'))
					i++;
			}
			if(state !=2 && state != 3 && state!=4) return false;
           	while(*(s+i) == ' '){
				i++;
			}
			if(*(s+i) == '\0') return true;
			else return false;
		}	
 };