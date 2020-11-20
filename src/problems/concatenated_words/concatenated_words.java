// Written by "songly" on LeetCode on September 14, 2020 10:53 PM
// Source: https://leetcode.com/problems/concatenated-words/discuss/95652/Java-DP-Solution/697079

public List<String> findAllConcatenatedWordsInADict(String[] words) {
    List<String> ans = new ArrayList();
    Set<String> dict = new HashSet(Arrays.asList(words));
    for(String word : words) {
        if(word.length() == 0) continue;
        dict.remove(word);
        if(wordBreak(word, dict)) ans.add(word);
        dict.add(word);
    }
    return ans;
}

public boolean wordBreak(String s, Set<String> dict) {
    // dp[i] means the first i characters of s can be split
    boolean[] dp = new boolean[s.length()+1];
    dp[0] = true; // base case
    for(int i=1; i<=s.length(); i++) {
        for(int j=0; j<i; j++) {
            if(dp[j] && dict.contains(s.substring(j, i))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.length()];
}
