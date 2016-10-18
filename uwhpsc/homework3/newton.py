# $UWHPSC/codes/homework3/test_code.py 
# To include in newton.py

def fvals_sqrt(x):
    """
    Return f(x) and f'(x) for applying Newton to find a square root.
    """
    f = x**2 - 4.
    fp = 2.*x
    return f, fp

def test1(debug_solve=False):
    """
    Test Newton iteration for the square root with different initial
    conditions.
    """
    from numpy import sqrt
    for x0 in [1., 2., 100.]:
        print " "  # blank line
        x,iters = solve(fvals_sqrt, x0, debug=debug_solve)
        print "solve returns x = %22.15e after %i iterations " % (x,iters)
        fx,fpx = fvals_sqrt(x)
        print "the value of f(x) is %22.15e" % fx
        assert abs(x-2.) < 1e-14, "*** Unexpected result: x = %22.15e"  % x

def solve(fvals,x0,debug=False):
    """
    Newtons Method with maxiter = 20 and tolerance to 1e-14
    	solve(fvals,x0,debug=False) where fvals is a function which returns the value of a function and
        its derivate (tuple) in the point passed as argument
    """ 
    maxiter = 20
    tol = 1e-14
    x = x0

    if debug:
        print "Initial guess: x = %22.15e" % x0

    for i in range(maxiter):
        f,df = fvals(x)
        if abs(f) < tol:
            break
        x = x - (f /df)
        if debug:
            print "After %s iterations, x = %22.15e" % (i+1,x)

    if i==maxiter-1:
        f,df = fvals(x)
        if abs(f) > tol:
            print "*** warning: has not yet converged"
        return x, i+1
    else:
        return x, i

