
"""
Demonstration module for quadratic interpolation.
Update this docstring to describe your code.
Modified by: ** Jose Angel de Bustos Perez **
"""


import numpy as np
import matplotlib.pyplot as plt
from numpy.linalg import solve

def quad_interp(xi,yi):
    """
    Quadratic interpolation.  Compute the coefficients of the polynomial
    interpolating the points (xi[i],yi[i]) for i = 0,1,2.
    Returns c, an array containing the coefficients of
      p(x) = c[0] + c[1]*x + c[2]*x**2.

    """

    # check inputs and print error message if not valid:
    error_message = "xi and yi should have type numpy.ndarray"
    if (type(xi) != np.ndarray) | (type(yi) != np.ndarray) :
	print error_message
	return

    error_message = "xi and yi should have length 3"
    if (len(xi) != 3) | (len(yi) != 3):
	print error_message
	return

    # Set up linear system to interpolate through data points:
    A = np.vstack([np.ones(3),xi,xi**2]).T
    b = yi

    ### Fill in this part to compute c ###
    c = solve(A,b)
    return c

def plot_quad(xi,yi):
    """
    Function to create a graph of points and its interpolation polinomial
    as quadratic.png
    """
    
    # check inputs and print error message if not valid:
    error_message = "xi and yi should have type numpy.ndarray"
    if (type(xi) != np.ndarray) | (type(yi) != np.ndarray) :
        print error_message
        return

    error_message = "xi and yi should have length 3"
    if (len(xi) != 3) | (len(yi) != 3):
        print error_message
        return

    # solution
    c = quad_interp(xi,yi)
    # points to evaluate polynomial to draw it
    x = np.linspace(xi.min() - 1,  xi.max() + 1, 1000)
    # polynomial evaluated in x 
    y = c[0] + c[1]*x + c[2]*x**2

    plt.figure(1)       # open plot figure window
    plt.clf()           # clear figure
    plt.plot(x,y,'b-')  # connect points with a blue line

    # Add data points  (polynomial should go through these points!)
    plt.plot(xi,yi,'ro')   # plot as red circles
    plt.ylim(y.min() - 1,y.max() + 1)         # set limits in y for plot

    plt.title("Data points and interpolating polynomial")

    plt.savefig('quadratic.png')   # save figure as .png file

def cubic_interp(xi,yi):
    """
    Cubic interpolation.  Compute the coefficients of the polynomial
    interpolating the points (xi[i],yi[i]) for i = 0,1,2,3.
    Returns c, an array containing the coefficients of
      p(x) = c[0] + c[1]*x + c[2]*x**2 + c[3]*x**3.

    """

    # check inputs and print error message if not valid:
    error_message = "xi and yi should have type numpy.ndarray"
    if (type(xi) != np.ndarray) | (type(yi) != np.ndarray) :
        print error_message
        return

    error_message = "xi and yi should have length 3"
    if (len(xi) != 4) | (len(yi) != 4):
        print error_message
        return

    # Set up linear system to interpolate through data points:
    A = np.vstack([np.ones(4),xi,xi**2,xi**3]).T
    b = yi

    ### Fill in this part to compute c ###
    c = solve(A,b)
    return c

def plot_cubic(xi,yi):
    """
    Function to create a graph of points and its interpolation polinomial
    as quadratic.png
    """

    # check inputs and print error message if not valid:
    error_message = "xi and yi should have type numpy.ndarray"
    if (type(xi) != np.ndarray) | (type(yi) != np.ndarray) :
        print error_message
        return

    error_message = "xi and yi should have length 3"
    if (len(xi) != 4) | (len(yi) != 4):
        print error_message
        return

    # solution
    c = cubic_interp(xi,yi)
    # points to evaluate polynomial to draw it
    x = np.linspace(xi.min() - 1,  xi.max() + 1, 1000)
    # polynomial evaluated in x
    y = c[0] + c[1]*x + c[2]*x**2 + c[3]*x**3

    plt.figure(1)       # open plot figure window
    plt.clf()           # clear figure
    plt.plot(x,y,'b-')  # connect points with a blue line

    # Add data points  (polynomial should go through these points!)
    plt.plot(xi,yi,'ro')   # plot as red circles
    plt.ylim(y.min() - 1,y.max() + 1)         # set limits in y for plot

    plt.title("Data points and interpolating polynomial")

    plt.savefig('cubic.png')   # save figure as .png file

def poly_interp(xi,yi):
    """
    General interpolation.  Compute the coefficients of the polynomial
    interpolating the points (xi[i],yi[i]) for i = 0,1,2,...,n.
    Returns c, an array containing the coefficients of
      p(x) = c[0] + c[1]*x + c[2]*x**2 + ... + c[n-1]*x**(n-1).

    """
    # check if both arrays has the same number of elements
    if len(xi) != len(yi):
    	print "Both arrays must have the same number of elements"
    	return

    # Set up linear system to interpolate through data points:
    dim = len(xi)
    A = np.vstack([np.ones(dim),xi])
    for i in range(2,dim):
        A=np.vstack([A,xi**i])

    A=A.T
    b = yi

    ### Fill in this part to compute c ###
    c = solve(A,b)
    return c

def plot_poly(xi,yi):
    """
    Function to create a graph of points and its interpolation polinomial
    as poly.png
    """
    # check if both arrays has the same number of elements
    if len(xi) != len(yi):
        print "Both arrays must have the same number of elements"
        return
    # solution
    dim = len(xi)
    c = poly_interp(xi,yi)
    # points to evaluate polynomial to draw it
    x = np.linspace(xi.min() - 1,  xi.max() + 1, 1000)
    # polynomial evaluated in x
    y = c[dim-1]
    for j in range(dim-1, 0, -1):
    	y = y*x + c[j-1]

    plt.figure(1)       # open plot figure window
    plt.clf()           # clear figure
    plt.plot(x,y,'b-')  # connect points with a blue line

    # Add data points  (polynomial should go through these points!)
    plt.plot(xi,yi,'ro')   # plot as red circles
    plt.ylim(y.min() - 1,y.max() + 1)         # set limits in y for plot

    plt.title("Data points and interpolating polynomial")

    plt.savefig('poly.png')   # save figure as .png file

def test_poly1():
    """
    Test code 2, no return value or exception if test runs properly.
    """
    xi = np.array([-1.,  0.,  2., 4.])
    yi = np.array([ 1., -1.,  7., 3.])
    c = poly_interp(xi,yi)
    for i in range(4):
        y = c[0] + (c[1]+(c[2]+(c[3])*xi[i])*xi[i])*xi[i]
        if abs (y - yi[i]) > 0.001:
                print "Incorrect result evaluating polynomial at %s" % xi[i]
                return

def test_poly2():
    """
    Test code 2, no return value or exception if test runs properly.
    """
    xi = np.array([-1.,  0.,  2., 5.,1.])
    yi = np.array([ 1., -1.,  -5., 3.,3.])
    c = poly_interp(xi,yi)
    for i in range(5):
        y = c[0] + (c[1]+(c[2]+(c[3]+(c[4]*xi[i]))*xi[i])*xi[i])*xi[i]
        if abs (y - yi[i]) > 0.001:
                print "Incorrect result evaluating polynomial at %s" % xi[i]
                return

def test_quad1():
    """
    Test code, no return value or exception if test runs properly.
    """
    xi = np.array([-1.,  0.,  2.])
    yi = np.array([ 1., -1.,  7.])
    c = quad_interp(xi,yi)
    c_true = np.array([-1.,  0.,  2.])
    print "c =      ", c
    print "c_true = ", c_true
    # test that all elements have small error:
    assert np.allclose(c, c_true), \
        "Incorrect result, c = %s, Expected: c = %s" % (c,c_true)
        
def test_quad2():
    """
    Test code 2, no return value or exception if test runs properly.	
    """
    xi = np.array([-1.,  0.,  2.])
    yi = np.array([ 1., -1.,  7.])
    c = quad_interp(xi,yi)
    for i in range(3):
	y = c[0] + (c[1]+(c[2]*xi[i]))*xi[i]
    	assert abs(y - yi[i]) < 0.001, "Incorrect result evaluating polynomial at %s" % xi[i]

def test_cubic1():
    """
    Test code 2, no return value or exception if test runs properly.
    """
    xi = np.array([-1.,  0.,  2., 4.])
    yi = np.array([ 1., -1.,  7., 3.])
    c = cubic_interp(xi,yi)
    for i in range(4):
    	y = c[0] + (c[1]+(c[2]+(c[3])*xi[i])*xi[i])*xi[i]
    	assert abs(y - yi[i]) < 0.001, "Incorrect result evaluating polynomial at %s" % xi[i]

def test_poly1():
    """
    Test code 2, no return value or exception if test runs properly.
    """
    xi = np.array([-1.,  0.,  2., 4.])
    yi = np.array([ 1., -1.,  7., 3.])
    c = poly_interp(xi,yi)
    for i in range(4):
        y = c[0] + (c[1]+(c[2]+(c[3])*xi[i])*xi[i])*xi[i]
    	assert abs(y - yi[i]) < 0.001 , "Incorrect result evaluating polynomial at %s" % xi[i]

def test_poly2():
    """
    Test code 2, no return value or exception if test runs properly.
    """
    xi = np.array([-1.,  0.,  2., 5.,1.])
    yi = np.array([ 1., -1.,  -5., 3.,3.])
    c = poly_interp(xi,yi)
    for i in range(5):
        y = c[0] + (c[1]+(c[2]+(c[3]+(c[4]*xi[i]))*xi[i])*xi[i])*xi[i]
    	assert abs(y - yi[i]) < 0.001, "Incorrect result evaluating polynomial at %s" % xi[i]

if __name__=="__main__":
    # "main program"
    # the code below is executed only if the module is executed at the command line,
    #    $ python demo2.py
    # or run from within Python, e.g. in IPython with
    #    In[ ]:  run demo2
    # not if the module is imported.
    print "Running test..."
    test_quad1()

