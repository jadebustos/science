! $MYHPSC/homework3/functions.f90

module functions

contains

real(kind=8) function f_sqrt(x)
    implicit none
    real(kind=8), intent(in) :: x

    f_sqrt = x**2 - 4.d0

end function f_sqrt


real(kind=8) function fprime_sqrt(x)
    implicit none
    real(kind=8), intent(in) :: x
    
    fprime_sqrt = 2.d0 * x

end function fprime_sqrt

real(kind=8) function g1(x)
    implicit none
    real(kind=8), intent(in) :: x

    real, parameter :: Pi = 3.1415927

    g1 = x * cos(pi*x)

end function g1

real(kind=8) function g1der(x)
    implicit none
    real(kind=8), intent(in) :: x

    real, parameter :: Pi = 3.1415927

    g1der = cos(Pi*x) - x*Pi*sin(Pi*x)

end function g1der

real(kind=8) function g2(x)
    implicit none
    real(kind=8), intent(in) :: x

    g2 = 1 - 0.6*x*x

end function g2

real(kind=8) function g2der(x)
    implicit none
    real(kind=8), intent(in) :: x

    g2der = -1.2*x

end function g2der


real(kind=8) function f(x)
    implicit none
    real(kind=8), intent(in) :: x

    f = g1(x)-g2(x)

end function f

real(kind=8) function fder(x)
    implicit none
    real(kind=8), intent(in) :: x

    fder = g1der(x)-g2der(x)

end function fder
end module functions
