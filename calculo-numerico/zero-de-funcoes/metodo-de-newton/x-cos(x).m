clc
clear

f = @(x) x - cos(x);
df = @(x) 1 + sin(x);

x(1) = pi / 4;

tol = 0.00005;

max_iter = 1000;

for k = 1: max_iter
    x(k + 1) = x(k) - f(x(k)) / df(x(k));
    
    if abs(x(k) - x(k + 1)) < tol && abs(f(x(k))) < tol
        break
    endif
endfor

printf("Iterações: %d\n", k)
printf("x = %d\n", x(k))
printf("f(x) = %d\n", f(x(k)))