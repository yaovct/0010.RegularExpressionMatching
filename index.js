/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
	if(p.length == 0) return s.length == 0;
	if(p.length == 1) return s.length == 1 && (p.charAt(0) == s.charAt(0) || p.charAt(0) == '.');
	if(p.charAt(1) != '*') {
		if(s.length == 0) return false;
		return (p.charAt(0) == s.charAt(0) || p.charAt(0) == '.') && isMatch(s.substr(1, s.length-1), p.substr(1, p.length-1));
	}
	while(s.length > 0 && (p.charAt(0) == s.charAt(0) || p.charAt(0) == '.')) {
		// skip c*
		if(isMatch(s, p.substr(2, p.length-2))) return true;
		s = s.substr(1, s.length-1);
	}
	return isMatch(s, p.substr(2, p.length-2));
};

var s = ["aa", "aa", "abbbbbcd", "aaaaaaab", "mississippi", "dbcdasd", "ab", "abc", "abc", "abc"];
var p = ["a", "a*", ".*", "c*a*b", "mis*is*p*.", "a.*", ".*c", ".*c", ".*c*", ".*c.*"];
var a = [false, true, true, true, false, false, false, true, true, true]

for(var i=0; i<a.length; i++) {
	console.log(a[i] + ", " + isMatch(s[i], p[i]) + " => " + (a[i] == isMatch(s[i], p[i])));
}