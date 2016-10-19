This software is licensed under GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
  (c) 2013 Jose Angel de Bustos Perez <jadebustos@gmail.com>

All source code is signed with my gpg key associated at my email address.

These simple examples were used for me long time ago to show people how choosing the
right algorithm can speed up a process.

These can also be useful to show how error can be reduced by reducing the number of
floating point operations.

The polynomial used in these examples is:

```
p(x)=1-2*x+3*x^2+4*x^3+5*x^4-3*x^5+2*x^6
```

Points where the above polynomial are going to be evaluated are equally distributed points across [1,10] where:

```
x_0 = 1
x_i = x_{i-1} + h * i where i in [0,n - 1]
x_n =10
```

n is the total amount of points you want evaluate the polynomial and it is supplied as an argument. So:

```
h = (10 - 1)/(n - 1)
```

eval-pol.c  
==========

This example shows the traditional way to evaluate a polynomial.

eval-pol-opt.c  
==============

This example shows how to use distributive property to evaluate a polynomial:

```
p(x) = 1-2*x+3*x^2+4*x^3+5*x^4-3*x^5+2*x^6 = 1+(-2+3*x+4*x^2+5*x^3-3*x^4+2*x^5)*x = ..
     = 1+(-2+(3+4*x+5*x^2-3*x^3+2*x^4)*x)*x = ... 
```

eval-pol-opt-rec.c
==================

This example shows a recursive way to evaluate a polynomial.

Compiling
=========

```
[jadebustos@dedalo eval-pol]$ make all
```

Evaluating
==========

Evaluation in 10000000 points:


```
[jadebustos@dedalo eval-pol]$ time ./eval-pol.bin 10000000

real0m2.553s
user0m2.553s
sys0m0.000s
[jadebustos@dedaloalo eval-pol]$ time ./eval-pol-opt-rec.bin 10000000

real0m0.332s
user0m20m0.331s
sys0m0.001s
[jadebustos@dedalo eval-pol]$ time ./eval-pol-operationst.bin 10000000

real0m0.161s
user0m0.160s
sys0m0.001s
[jadebustos@dedalo eval-pol]$
```
