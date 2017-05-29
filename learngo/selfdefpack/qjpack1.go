package qjpack1

type qjName struct{
	chineseName string
	englishName string
}

func GetQjName () *qjName{
	return &qjName{"QiaoJian", "Leo"}
}
