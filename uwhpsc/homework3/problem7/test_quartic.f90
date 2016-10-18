
program test_quartic

    use newton, only: solve, tol
    use functions, only: f_quartic, fprime_quartic, epsilon

    implicit none
    real(kind=8) :: x, x0, fx, xstar
    real(kind=8) :: tolvals(3), epsvals(3)
    integer :: iters, i1, j1
        logical :: debug

    x0 = 6.d0
    print 10 ,x0
10  format("Starting with initial guess ", es22.15,/)
    debug = .false.

    ! values to test as epsilon:
    epsvals = (/1.d-6, 1.d-10, 1.d-14/)

    ! values to test as tol:
    tolvals = (/1.d-6, 1.d-10, 1.d-14/)

    print 11 
11  format("    epsilon        tol    iters          x                 f(x)        x-xstar")

    do i1=1,3
        epsilon = epsvals(i1)
        xstar = 1.d0 + epsilon**(0.25d0)
        do j1=1,3

        tol = tolvals(j1)

        call solve(f_quartic, fprime_quartic, x0, x, iters, debug)

        fx = f_quartic(x)
        print 12, epsilon, tol, iters, x, fx, x-xstar
12      format(2es13.3, i4, es24.15, 2es13.3)

        enddo
                print *, ' '
    enddo


end program test_quartic
