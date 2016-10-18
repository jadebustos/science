! $MYHPSC/homework3/intersections.f90

program intersections

    use newton, only: solve
    use functions, only: f, fder

    implicit none
    real(kind=8) :: x, x0, fx
    real(kind=8) :: x0vals(4)
    integer :: iters, itest
	logical :: debug         ! set to .true. or .false.

    debug = .false.

    ! values to test as x0:
    x0vals = (/-2.2d0, -1.6d0, -0.8d0, 1.45d0 /)

    do itest=1,4
        x0 = x0vals(itest)
		print *, ' '  ! blank line
        call solve(f, fder, x0, x, iters, debug)

        print 11, x0
11      format('With initial guess x0 = ', e22.15)

	print 12, x, iters
12	format('      solve returns x = ', e22.15,' after ', i3, ' iterations')

        fx = f(x)
        print 13, fx
13      format('    f(x) = ', e22.15)
	enddo

end program intersections
