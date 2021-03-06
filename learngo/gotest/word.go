package word

import "unicode"

//Talker interface
type Talker interface {
	SayHello(word string) (response string)
}

//Company struct
type Company struct {
	Usher Talker
}

//NewCompany func
func NewCompany(t Talker) *Company {
	return &Company{
		Usher: t,
	}
}

//Meeting member func
func (c *Company) Meeting(guestName string) string {
	return c.Usher.SayHello(guestName)
}

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

//StringSliceEqual 字符串切片相等判断
func StringSliceEqual(a, b []string) bool {
	if len(a) != len(b) {
		return false
	}

	if (a == nil) != (b == nil) {
		return false
	}

	for i, v := range a {
		if v != b[i] {
			return false
		}
	}
	return true
}
