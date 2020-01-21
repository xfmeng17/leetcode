func wordBreak(s string, wordDict []string) bool {
	// return func1(s, wordDict);
	// return func2(s, 0, len(s)-1, wordDict);
	// return func3(s, wordDict);
	// return func4(s, wordDict);
	return func5(s, wordDict);
}

// 1. recursive
func func1(s string, wordDict []string) bool {
	if len(s) == 0 {
		return true;
	}
	for pos := 0; pos <= len(s); pos++ {
		for _, word := range wordDict {
			if s[0:pos] == word && func1(s[pos:], wordDict) {
				return true;
			}
		}
	}
	return false;
}

// 2. recursive + string-optimize
func func2(s string, lo int, hi int, wordDict []string) bool {
	if (lo > hi) {
		return true;
	}

	for pos := lo; pos <= hi; pos++ {
		for _, word := range wordDict {
			if strCompHelper(s, lo, pos, word) && func2(s, pos+1, hi, wordDict) {
				return true;
			}
		}
	}

	return false;
}

// 3. recursive + string-optimize + memo
func func3(s string, wordDict []string) bool {
	N := len(s);
	// 0=init, 1=false, 2=true
	memo := make([][]int, N);
	for i := 0; i < N; i++ {
		memo[i] = make([]int, N);
	}
	return helper3(s, 0, N-1, wordDict, memo);
}
func helper3(s string, lo int, hi int, wordDict []string, memo [][]int ) bool {
	if (lo > hi) {
		return true;
	}
	if memo[lo][hi] == 1 {
		return false;
	} else if memo[lo][hi] == 2 {
		return true;
	}

	for pos := lo; pos <= hi; pos++ {
		for _, word := range wordDict {
			if strCompHelper(s, lo, pos, word) && helper3(s, pos+1, hi, wordDict, memo) {
				memo[lo][hi] = 2;
				return true;
			}
		}
	}
	memo[lo][hi] = 1;
	return false;
}

// 4. recursive + string-optimize + memo + use-map-instead-of-array
func func4(s string, wordDict []string) bool {
	N := len(s);
	// 0=init, 1=false, 2=true
	memo := make([][]int, N);
	for i := 0; i < N; i++ {
		memo[i] = make([]int, N);
	}
	wordMap := make(map[string]bool);
	for i:= 0; i < len(wordDict); i++ {
		wordMap[wordDict[i]] = true;
	}
	
	return helper4(s, 0, N-1, wordMap, memo);
}
func helper4(s string, lo int, hi int, wordMap map[string]bool, memo [][]int) bool {
	if (lo > hi) {
		return true;
	}
	if memo[lo][hi] == 1 {
		return false;
	} else if memo[lo][hi] == 2 {
		return true;
	}

	for pos := lo; pos <= hi; pos++ {
		if _, ok := wordMap[s[lo:pos+1]]; ok {
			if helper4(s, pos+1, hi, wordMap, memo) {
				memo[lo][hi] = 2;
				return true;
			}
		}
	}
	memo[lo][hi] = 1;
	return false;
}

// 5. iterative 2D + string-optimize + use-map-instead-of-array
func func5(s string, wordDict []string) bool {
	N := len(s);
	memo := make([][]bool, N);
	for i := 0; i < N; i++ {
		memo[i] = make([]bool, N);
	}
	wordMap := make(map[string]bool);
	for i:= 0; i < len(wordDict); i++ {
		wordMap[wordDict[i]] = true;
	}
	for i := 0; i < N; i++ {
		for j := i; j < N; j++ {
			if _, ok := wordMap[s[i:j+1]]; ok {
				memo[i][j] = true;
				continue;
			}
			for k := i; k < j; k++ {
				if memo[i][k] && memo[k+1][j] {
					memo[i][j] = true;
					break;
				}
			}
		}
	}
	return memo[N-1][N-1];
}


func strCompHelper(s string, lo int, hi int, word string) bool {
	m := hi - lo + 1;
	n := len(word);
	if m != n {
		return false;
	}

	for i := lo; i <= hi; i++ {
		if s[i] != word[i-lo] {
			return false;
		}
	}

	return true;
}