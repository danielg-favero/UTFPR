clc
clear

f = @(x) x - cos(x);

x(1) = 0;
x(2) = pi / 4;

tol = 0.00005;

max_iter = 1000;

for k = 1: max_iter
    x(k + 2) = (x(k) * f(x(k + 1)) - x(k + 1) * f(x(k))) / (f(x(k + 1)) - f(x(k)));
    
    if abs(x(k + 2) - x(k + 1)) < tol && abs(f(x(k+2))) < tol
        break
    endif
endfor

printf("Iterações: %d\n", k)
printf("x = %d\n", x(k))
printf("f(x) = %d\n", f(x(k)))
