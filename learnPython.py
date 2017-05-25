#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# encoding: utf-8

s = 'Python-中文'
print(s)
b = s.encode('utf-8')
print(b)
print(b.decode('utf-8'))

classmates = ('Michael', 'Bob', 'Tracy')
print('classmates =', classmates)
print('len(classmates) =', len(classmates))
print('classmates[0] =', classmates[0])
print('classmates[1] =', classmates[1])
print('classmates[2] =', classmates[2])
print('classmates[-1] =', classmates[-1])

classmates = ['Kobe', 'James', 'Rose']
classmates.pop()
print('classmates =', classmates)

t = ('a', 'b', ['A', 'B'])
t[2][0] = 'X'
t[2][1] = 'Y'
print(t)

# 注意:
# input()返回的是字符串
# 必须通过int()将字符串转换为整数
# 才能用于数值比较:
age = int(input('Input your age: '))

if age >= 18:
	print('adult')
elif age >= 6:
	print('teenager')
else:
	print('kid')

print(list(range(5)))

sum = 0
for x in range(100): 
	sum = sum + x
print(sum)

n = 0
while n < 10:
	n = n + 1
	if n % 2 == 0: # 如果n是偶数，执行continue语句
		continue # continue会直接继续下一轮循环，后续的print()语句不会执行
	print(n)

d = {
'Michael': 95,
'Bob': 75,
'Tracy': 85
}
print('Thomas' in d)
print('d[\'Bob\'] =', d['Bob'])
print('d.get(\'Thomas\', -1) =', d.get('Thomas', -1))
d.pop('Bob')
print(d)

s1 = set([1, 1, 2, 2, 3, 3])
print(s1)
s2 = set([2, 3, 4])
print(s2)
print(s1 & s2)
print(s1 | s2)

#function
func_alias = max
print(func_alias(0, -7, 3))

def my_abs(x):
	if not isinstance(x, (int, float)):
		raise TypeError('bad operand type')
	if x >= 0:
		return x
	else:
		return -x

def nop():
	pass

print(my_abs(-7))	
print(nop())

import math

def move(x, y, step, angle=0):
	nx = x + step * math.cos(angle)
	ny = y - step * math.sin(angle)
	return nx, ny
x, y = move(100, 100, 60, math.pi / 6)
print(x, y)
z = move(100, 100, 60, math.pi / 6)
print(z)

#可变参数
def calc(*numbers):
	sum = 0
	for n in numbers:
		sum = sum + n * n
	return sum
nums = [1, 2, 3]
print(calc(*nums))

#关键字参数
def person(name, age, **kw):
	print('name:', name, 'age:', age, 'other:', kw)
(person('Michael', 30))
(person('Adam', 45, gender='M', job='Engineer'))
extra = {'city': 'Beijing', 'job': 'Engineer'}
(person('Jack', 24, **extra))

#命名关键字参数
#def person(name, age, *, city, job):
#	print(name, age, city, job)

def person(name, age, *args, city, job):
	print(name, age, args, city, job)
person('Jack', 24, city='Beijing', job='Engineer')

#命名关键字参数可以有缺省值
def person(name, age, *, city='Beijing', job):
	print(name, age, city, job)
person('Jack', 24, job='Engineer')

#参数定义的顺序必须是：必选参数、默认参数、可变参数、命名关键字参数和关键字参数
def person(name, age, marriage = 'FALSE', *, city = 'ChengDu', job):
	print('name: ', name, 'age: ', age, 'marriage: ', marriage, 'city: ', city, 'job: ', job)
person('qiaojian', 28, job = 'NoJob')

#对于任意函数，都可以通过类似func(*args, **kw)的形式调用它，无论它的参数是如何定义的
def f1(a, b, c=0, *args, **kw):
	print('a =', a, 'b =', b, 'c =', c, 'args =', args, 'kw =', kw)

def f2(a, b, c=0, *, d, **kw):
	print('a =', a, 'b =', b, 'c =', c, 'd =', d, 'kw =', kw)
f1(1, 2)
f1(1, 2, c=3)
f1(1, 2, 3, 'a', 'b')
f1(1, 2, 3, 'a', 'b', x=99)
f2(1, 2, d=99, ext=None)

args = (1, 2, 3, 4)
kw = {'d': 99, 'x': '#'}
f1(*args, **kw)

args = (1, 2, 3)
kw = {'d': 99, 'x': '#'}
f2(*args, **kw)

#recursive
def fact(n):
	if n==1:
		return 1
	return n * fact(n - 1)
print(fact(100))

#slice
L = list(range(20))
print(L)
print(L[:3])
print(L[-3:])
print(L[3:6])
print(L[:10:2])
print(L[::5])
print(L[::])
print(L[:])

print((0,1,2,3,4,5)[:3])
print('abcdefg'[::2])

#iterator
dic = {'a':1, 'b':2, 'c':3}
for key in dic:
	print(key)

for value in dic.values():
	print(value)

for k,v in dic.items():
	print(k,v)

for i, value in enumerate(['A', 'B', 'C']):
	print(i, value)
#judge can iterator or not
from collections import Iterable
print( isinstance('abc', Iterable) ) #str是否可迭代

#list comprehension
print ( [x * x for x in range(1, 11)] )
print ( [x * x for x in range(1, 11) if x % 2 == 0] )
print ( [m + n for m in 'ABC' for n in 'XYZ'] ) 
L = ['Hello', 'World', 123, 'IBM', 'Apple']
print ( [s.lower() for s in L if isinstance(s, str)] ) 


