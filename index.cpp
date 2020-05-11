#include <iostream>
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
  	if(p.size() == 0) return s.size() == 0;
  	if(p.size() == 1) return s.size() == 1 && (p[0] == s[0] || p[0] == '.');
  	if(p[1] != '*') {
  		if(s.size() == 0) return false;
  		return (p[0] == s[0] || p[0] == '.') && isMatch(s.substr(1, s.size()-1), p.substr(1, p.size()-1));
  	}
  	while(s.size() > 0 && (p[0] == s[0] || p[0] == '.')) {
  		if(isMatch(s, p.substr(2, p.size()-2))) return true;
  		s = s.substr(1, s.size()-1);
  	}
  	return isMatch(s, p.substr(2, p.size()-2));
  }
};

int main(int argc, char *argv[]) {
	string s[] = {"aa", "aa", "abbbbbcd", "aaaaaaab", "mississippi", "dbcdasd", "ab", "abc", "abc", "abc"};
	string p[] = {"a", "a*", ".*", "c*a*b", "mis*is*p*.", "a.*", ".*c", ".*c", ".*c*", ".*c.*"};
	bool a[] ={false, true, true, true, false, false, false, true, true, true}; 
	
	Solution mySolution;
	for(int i=0; i<sizeof(a)/sizeof(a[0]); i++) {
		cout << a[i] << ", " << mySolution.isMatch(s[i], p[i]) << " => " << 
		(a[i] == mySolution.isMatch(s[i], p[i]))
		<< endl;
	}
}