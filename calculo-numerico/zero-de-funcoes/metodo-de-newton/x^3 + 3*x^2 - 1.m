clc
clear

f = @(x) x^3 + 3*x^2 - 1;
df = @(x) 3*x^2 + 6*x;

tol = 0.00005;

max_iter = 1000;

x(1) = 1;

for k = 1: max_iter
    x(k + 1) = x(k) - f(x(k)) / df(x(k));
    
    if abs(x(k + 1) - x(k)) < tol && abs(f(x(k))) < tol
        break
    endif
endfor

printf("número de iterações: %d\n", k)
printf("x = %d\n", x(k))
printf("f(x) = %df\n", f(x(k)))