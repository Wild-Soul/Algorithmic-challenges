package leetcode

// there are total of 2n places to be filled, where n is the number of pairs of parentheses
// at any position we have two choices as well and we'll assign +1 to '(' and -1 to ')'
// the choice will be based on the value of curSum, following scenarios arise:
// cur_sum == 0 - opening bracket is the only choice for this position.
// cursum < pos -- closing bracket is the only choice.
// cur_sum > 0 - anything works.
// add produced byte array to ans only at the end of recursion and only if we have curSum == 0
func recur(pos, length, curSum int, stringSoFar *[]byte, ans *[]string) {
	if pos == length {
		if curSum == 0 {
			*ans = append(*ans, string(*stringSoFar))
		}
		return
	}

	if curSum == 0 {
		// opening bracket is the only choice for valid parentheses.
		(*stringSoFar)[pos] = '('
		recur(pos+1, length, curSum+1, stringSoFar, ans)
	} else if pos < curSum {
		// closing bracket is the only choice for valid parentheses.
		(*stringSoFar)[pos] = ')'
		recur(pos+1, length, curSum-1, stringSoFar, ans)
	} else {
		// both parentheses are an option.
		(*stringSoFar)[pos] = '('
		recur(pos+1, length, curSum+1, stringSoFar, ans) // opening

		(*stringSoFar)[pos] = ')'
		recur(pos+1, length, curSum-1, stringSoFar, ans) // closing
	}
}

func generateParenthesis(n int) []string {
	var ans []string
	sb := make([]byte, 2*n)

	recur(0, 2*n, 0, &sb, &ans)

	return ans
}
