func wordBreak(s string, wordDict []string) bool {
	// return func1(s, wordDict);
	// return func2(s, 0, len(s)-1, wordDict);
	// return func3(s, wordDict);
	// return func4(s, wordDict);
	// return func5(s, wordDict);
	// return func6(s, wordDict);
	// return func7(s, wordDict);
	// return func8(s, wordDict);
	return func9(s, wordDict);
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
// !!ERROR, can't guarantee when calculate m[i][j] already got
// m[i][k]...m[k+1][j]
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

// 6. iterative 2D + string-optimize + use-map-instead-of-array
// Use substring size iterate 1,2,3..., O(n^3) time 
func func6(s string, wordDict []string) bool {
	N := len(s);
	memo := make([][]bool, N);
	for i := 0; i < N; i++ {
		memo[i] = make([]bool, N);
	}
	wordMap := make(map[string]bool);
	for i:= 0; i < len(wordDict); i++ {
		wordMap[wordDict[i]] = true;
	}

	// size == 1
	for i := 0; i < N; i++ {
		if _, ok := wordMap[s[i:i+1]]; ok {
			memo[i][i] = true;
		}
	}
	// size >= 2
	for sz := 2; sz <= N; sz++ {
		for lo, hi := 0, sz-1; hi < N; lo, hi = lo+1, hi+1 {
			if _, ok := wordMap[s[lo:hi+1]]; ok {
				memo[lo][hi] = true;
				continue;
			}
			for mid := lo; mid < hi; mid++ {
				if memo[lo][mid] && memo[mid+1][hi] {
					memo[lo][hi] = true;
					break;
				}
			}
		}
	}

	return memo[0][N-1]; 
}

// 7. A different thought, F[0...n] = F[0...x] && isWord(x+1..n)
// recursive solution
func func7(s string, wordDict []string) bool {
	N := len(s)
	wordMap := make(map[string]bool);
	for i:= 0; i < len(wordDict); i++ {
		wordMap[wordDict[i]] = true;
	}

	return helper7(s, N-1, wordMap);
}
func helper7(s string, end int, wordMap map[string]bool) bool {
	if end < 0 {
		return true;
	}

	for i := end; i >= 0; i-- {
		if _, ok := wordMap[s[i:end+1]]; ok {
			if helper7(s, i-1, wordMap) {
				return true;
			}
		}
	}

	return false;
}

// 8. same 7, but with memo
func func8(s string, wordDict []string) bool {
	N := len(s)
	// 0=init, 1=false, 2=true
	memo := make([]int, N);
	wordMap := make(map[string]bool);
	for i := 0; i < len(wordDict); i++ {
		wordMap[wordDict[i]] = true;
	}

	return helper8(s, N-1, wordMap, memo);
}
func helper8(s string, end int, wordMap map[string]bool, memo []int) bool {
	if end < 0 {
		return true;
	}
	if memo[end] != 0 {
		return memo[end] == 2;
	}
	for i := end; i >= 0; i-- {
		if _, ok := wordMap[s[i:end+1]]; ok {
			if helper8(s, i-1, wordMap, memo) {
				memo[end] = 2;
				return true;
			}
		}
	}
	memo[end] = 1;
	return false;
}

// 9. same 7, finially, bottom-up, 1D, O(n^2) solution
func func9(s string, wordDict []string) bool {
	N := len(s)
	memo := make([]bool, N);
	wordMap := make(map[string]bool);
	for i := 0; i < len(wordDict); i++ {
		wordMap[wordDict[i]] = true;
	}

	for i := 0; i < N; i++ {
		if _, ok := wordMap[s[0:i+1]]; ok {
			memo[i] = true;
			continue;
		}
		for j := i; j >= 0; j-- {
			if _, ok := wordMap[s[j:i+1]]; ok && memo[j-1] {
				memo[i] = true;
				break;
			}
		}
	}

	return memo[N-1];
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