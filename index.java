import java.lang.*;
import java.util.*;

class Solution {
  public boolean isMatch(String s, String p) {
  	if(p.length()==0) return s.length() == 0;
  	if(p.length()==1) return s.length() == 1 && (p.charAt(0) == s.charAt(0) || p.charAt(0) == '.');
  	if(p.charAt(1) != '*') {
  		if(s.length() == 0) return false;
  		return (p.charAt(0) == s.charAt(0) || p.charAt(0) == '.') && isMatch(s.substring(1), p.substring(1));
  	}
  	while(s.length() > 0 && (p.charAt(0) == s.charAt(0) || p.charAt(0) == '.')) {
  		if(isMatch(s, p.substring(2))) return true;
  		s = s.substring(1);
  	}
  	return isMatch(s, p.substring(2));
  }
}

public class index {

	public static void main(String[] args) {
		String [] s = new String [] {"aa", "aa", "abbbbbcd", "aaaaaaab", "mississippi", "dbcdasd", "ab", "abc", "abc", "abc"};
		String [] p = new String [] {"a", "a*", ".*", "c*a*b", "mis*is*p*.", "a.*", ".*c", ".*c", ".*c*", ".*c.*"};
		Boolean [] a = new Boolean [] {false, true, true, true, false, false, false, true, true, true};

    Solution demo = new Solution();
    for(int i=0; i<s.length; i++) {
    	System.out.printf("%b %b => %b\n", a[i], demo.isMatch(s[i], p[i]), a[i] == demo.isMatch(s[i], p[i]));
    }
	}
}