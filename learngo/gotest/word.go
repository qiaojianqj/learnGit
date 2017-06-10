package word

import "unicode"

//IsPalindrome 回文判断
func IsPalindrome(s string) bool {
	letters := make([]rune, 0, len(s))
	//	var letters []rune
	for _, r := range s {
		if unicode.IsLetter(r) {
			letters = append(letters, unicode.ToLower(r))
		}
	}
	for i := range letters {
		if letters[i] != letters[len(letters)-1-i] {
			return false
		}
	}
	return true
}
