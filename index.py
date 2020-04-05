class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if len(p) == 0: return len(s) == 0
        if len(p) == 1: return len(s) == 1 and (p[0] == s[0] or p[0] == '.')
        if p[1] != '*':
        	if len(s) == 0: return False
        	return (p[0] == s[0] or p[0] == '.') and self.isMatch(s[1:len(s)], p[1:len(p)])
        while len(s) and (p[0] == s[0] or p[0] == '.'):
        	# skip c*
        	if self.isMatch(s, p[2:len(p)]): return True
        	s = s[1:len(s)]
        return self.isMatch(s, p[2:len(p)])
        	
my_test = Solution()
s = ["aa", "aa", "abbbbbcd", "aaaaaaab", "mississippi", "dbcdasd", "ab", "abc", "abc", "abc"]
p = ["a", "a*", ".*", "c*a*b", "mis*is*p*.", "a.*", ".*c", ".*c", ".*c*", ".*c.*"]
a = [False, True, True, True, False, False, False, True, True, True]

for i, m in enumerate(s):
  print("%s %s => %r (%r)" % (m, p[i], my_test.isMatch(m, p[i]), a[i]))
