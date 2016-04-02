#!/usr/bin/python 
#-*-utf-8-*-
#Filename:function.py
def my_abs(x):#define a function 
	if x >= 0:
		return x
	else:
		return -x
import math

def move(x, y, step, angle = 0):
	nx = x + step * math.cos(angle)
	ny = y + step * math.cos(angle)
	return nx, ny

def enroll(name, gender, age = 6, city = "Beijing"):#default parameter
	print "name:", name
	print "gender:", gender
	print "age:", age
	print "city:", city

def add_end(L = []):
	L.append("END")
	return L
L =  add_end(["abcdefg"])

def add_end(L = None):
	if L is None:
		L = []
	L.append("END")
	return L
L =  add_end(["abcdefg"])

def power(x, n = 2):
	s = 1
	while n > 0:
		s = s * x
		n = n-1
	return s
s2 = power(5, 3)
s3 = power(5)

def calc(numbers):
	s = 0
	for number in numbers:
		s = s + number * number
	return s

s4 = calc([1, 2, 3, 4])


def calcnext(*numberd):#you can input vars
	s = 0
	for number in numberd:
		s = s + number * number
	return s
s = calcnext()
print "s5 = ", s

def person(name, age, **kw):
	print "name: ", name, "age: ", age, "other: ", kw
person("zhang", 24, city = "Beijing")

def func(a, b, c = 0, *argc, **kw):
	print "a = ", a,"b = ", b, "c = ", c, "*argc = ", argc, "other = ", kw
func(1, 3)

def fact(n):
	if n == 1:
		return 1
	return n * fact(n - 1)
n = fact(10)
print "n = ", n

def fact(n):
	return fact_iter(n, 1)

def fact_iter(n, product):
	if n == 1: 
		return product
	return	fact_iter(n - 1, n * product) 
s = fact(100)
print "s = ", s

	
