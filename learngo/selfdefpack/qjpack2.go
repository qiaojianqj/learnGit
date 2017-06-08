package qjpack

func SetMyName(){
	MyName.chineseName = "QiaoJian"
	MyName.englishName = "Leo"
}

func GetMyName() *qjName {
	return &MyName
}
