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
print move(1, 2, 3,2)
