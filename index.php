<?php
ini_set('memory_limit', '1024M');

class Solution {

  /**
   * @param String $s
   * @param String $p
   * @return Boolean
   */
  function isMatch($s, $p) {
  	if(strlen($p) == 0) return strlen($s) == 0;
  	if(strlen($p) == 1) return strlen($s) == 1 and ($p[0] == $s[0] or $p[0] == '.');
  	if($p[1] != '*') {
  		if(strlen($s) == 0) return false;
  		return ($p[0] == $s[0] or $p[0] == '.') and $this->isMatch(substr($s, 1, strlen($s)-1), substr($p, 1, strlen($p)-1));
  	}
  	while(strlen($s) and ($p[0] == $s[0] or $p[0] == '.')) {
  		# skip c*
  		if($this->isMatch($s, substr($p, 2, strlen($p)-2))) return true;
  		$s = substr($s, 1, strlen($s)-1);
  	}
  	return $this->isMatch($s, substr($p, 2, strlen($p)-2));
  }
}

$s = array("aa", "aa", "abbbbbcd", "aaaaaaab", "mississippi", "dbcdasd", "ab", "abc", "abc", "abc");
$p   = array("a", "a*", ".*", "c*a*b", "mis*is*p*.", "a.*", ".*c", ".*c", ".*c*", ".*c.*");
$a = array(False, True, True, True, False, False, False, True, True, True);
$testSolution = new Solution();
for($i=0; $i<count($s); $i++) {
	echo ($a[$i] ? 'true' : 'false') .' vs. '.($testSolution->isMatch($s[$i], $p[$i]) ? 'true' : 'false')." => ". 
	     ($a[$i] == $testSolution->isMatch($s[$i], $p[$i])). "\n";
}
?>