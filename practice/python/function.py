#!/usr/bin/python 
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
print L
print add_end()
print add_end()
print add_end()
print add_end()
print add_end()
print add_end()
print add_end()

