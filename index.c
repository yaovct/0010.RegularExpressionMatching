#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_STRING_SIZE 40

bool isMatch(char *s, char *p){
	int slen = 0;
	int plen = 0;
	char *m = s;while(*m++) slen++;
	char *n = p;while(*n++) plen++;
	if(plen == 0) return slen == 0;
	if(plen == 1) return slen == 1 && (p[0] == s[0] || p[0] == '.');
	if(p[1] != '*') {
		if(slen == 0) return false;
		return (p[0] == s[0] || p[0] == '.') && isMatch(&s[1], &p[1]);
	}
	while(slen > 0 && (p[0] == s[0] || p[0] == '.')) {
		if(isMatch(s, &p[2])) return true;
		s = &s[1];
		slen = 0;char *o = s;while(*o++) slen++;
	}
	return isMatch(s, &p[2]);
}

int main(int argc, char *argv[]) {

	char s[][MAX_STRING_SIZE] = {"aa", "aa", "abbbbbcd", "aaaaaaab", "mississippi", "dbcdasd", "ab", "abc", "abc", "abc"};
	char p[][MAX_STRING_SIZE] = {"a", "a*", ".*", "c*a*b", "mis*is*p*.", "a.*", ".*c", ".*c", ".*c*", ".*c.*"};
	bool a[] = {false, true, true, true, false, false, false, true, true, true};
  for(int i=0; i<sizeof(a); i++) {
		printf("%d, %d => %d\n", a[i], isMatch(s[i],p[i]), a[i] == isMatch(s[i],p[i]));
	}
}