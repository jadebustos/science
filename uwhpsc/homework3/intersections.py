#!/usr/bin/python
""" 
Script to plot g1 and g2 graph and their intersections
"""
from newton import solve
from numpy import linspace, pi, cos, sin, abs, where
import matplotlib.pyplot as plt

def g1(x):
    g1x =  x*cos(pi*x)
    g1px =  cos(pi*x) - x*pi*sin(pi*x)
    return g1x, g1px

def g2(x):
    g2x = 1. - 0.6*x**2
    g2px = -1.2*x
    return g2x, g2px


def f(x):
    g1x,g1px = g1(x)
    g2x,g2px = g2(x)
    fx = g1x - g2x
    fpx = g1px - g2px
    return fx, fpx

# Points
xi = linspace(-5,5,1000)
g1xi, g1pxi = g1(xi)
g2xi, g2pxi = g2(xi)
fxi, fpxi = f(xi)

# Functions
plt.figure(1)
plt.clf()
plt.plot(xi, g1xi, 'b')
plt.plot(xi, g2xi, 'r')
plt.legend(['g1(x)=x*cos(pi*x)','g2(x)=1-0.6*x**2'])
plt.figure(1)

# Intersection points
for x0 in [-2.2, -1.6, -0.8, 1.45]:
    x,iters = solve(f, x0)
    print "\nWith initial guess x0 = %22.15e," % x0
    print "      solve returns x = %22.15e after %i iterations " % (x,iters)
    g1xi,g1pxi = g1(x)
    fxi,fpxi = f(x)
    print "    f(x) = %22.15e" % fxi
    plt.plot(x,g1xi,'ko')

plt.savefig('intersections.png')
