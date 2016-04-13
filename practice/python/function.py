#!/usr/bin/python 
#_*_utf-8_*_
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

L = []	
n = 1
while n < 99:
	L.append(n)
	n += 2
print L

d = {"a":1, "b":2, "c":3}
for key in d:
	print key 

for i, value in enumerate(["A","B","C"]):
	print i, value

for x, y in [(1, 2), (2, 3), (3, 4)]:
	print x, y

L = []

for x in range(1,11):
	L.append(x*x)
print L

#List of formula
print [x*x for x in range(1,11)]

print [m + n for m in "ABC" for n in "XYZ"]

print [x * x for x in range(1, 11) if x % 2 ==0]

import os#input os module
print [d for d in os.listdir(".")]#list the current dir's filenames

d = {"A":1, "B":2, "C":3}
for k, v in d.iteritems():
	print k, "=", v

d = {"A":'1', "B":'2', "C":'3'}
print [k + "=" + v for k, v in d.iteritems()]#only use string

L = ["Hello", "World", "!"]
print [s.lower() for s in L]

#creat a generator
L = [x * x for x in range(1, 11)]
g = (x * x for x in range(1, 11))
print L
#print g.next()
#call a generator
for a in g:
	print a

def fib(max):
	n, a, b = 0, 0, 1
	while n < max:
		print b
		a, b = b, a + b
		n = n + 1
def fibb(max):
	n, a, b = 0, 0, 1
	while n < max:
		yield b
		a, b = b, a + b
		n = n + 1
for x in fibb(6):
	print x
print fibb(6)

def add(x, y, f):
	return f(x) + f(y)
print add(-10, 10, abs)

print map(abs, [-1,-2,-3,-4,-5])
print map(str, [1, 2, 3, 5])

def m(x, y):
	return x * y

def x(L):
	print reduce(lambda x, y: x * y, L)
x([1,2,3,4,5])

def updown(s):
	return s.title()
L = map(lambda s:s.title(), ["af", "XBN", "xSg"])
print L

def is_odd(n):
	return n % 2 == 1
print filter(is_odd, [1,2,3,4,5,6])

def primer(s):
	if s == 1:
		return 0
	for x in range(2, s):
		if s % x == 0: 
			return 1
	else:
		return 0
print filter(primer, range(1, 101))#filter the number
print filter(lambda x:any(map(lambda y:x%y == 0,range(2,x))), range(1,101))
print sorted(["a", "c", "z","b"])
def reversed_cmp(x, y):
	if x > y:
		return -1
	if x < y:
		return 1
	return 0
print sorted([5, 2, 6,18, 1,12], reversed_cmp)

def calc_sum(*aasum):
	def sum():
		asum = 0
		for ax in aasum:
			asum = asum + ax	
		return asum
	return sum
f = calc_sum(1,2,3,4,5,6)
print f()

def count():
	fs = []
	for i in range(1,4):
		def f(j):
			def g():
				return j * j
			return g
		fs.append(f(i))
	return fs
f1, f2, f3 = count()
print f1()
print f2()
print f3()

a,b,c = [(lambda j = i:j * j) for i in range(1,4)]
print a(), b(), c()

#decorator
import functools
def log(func):
	@functools.wraps(func)
	def wrapper(*args, **kw):
		print "call %s():" %func.__name__
		func()
		return func(*args, **kw)
	return wrapper
@log
def now():
	print "2016.04.07"
now()

def log(text):
	def decorator(func):
		@functools.wraps(func)
		def wrapper(*args, **kw):
			print "%s %s():" %(text, func.__name__)
			return func(*args, **kw)
		return wrapper
	return decorator
@log("Hell world")
def x():
	print "2016.04.07"
x()

import functools
def log(text):
	if callable(text):
		@functools.wraps(text)
		def wrapper(*args, **kw):
			 print "begin call" +text.__name__
			 text(*args, **kw)
			 print "end call" +text.__name__
		return wrapper
	else:
		def decorator(func):
			@functools.wraps(func)
			def wrapper(*args, **kw):
				print "Here" 
				print "begin call %s" %func.__name__ 
				func(*args, **kw)
				print "end call" +text
			return wrapper
		return decorator
@log("here")
def test1():
	print "doing1"
test1()
#test1()
def int2(x, base = 2):
	return int(x, base)
print int2("10")
import functools
int2 = functools.partial(int, base = 2)
print int2("10")
