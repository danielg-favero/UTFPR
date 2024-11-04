% Exemplo 2 método de Newton
clc
clear

f = @(x) x^2 - 2;
df = @(x) 2 * x;
x(1) = 1;
tol = 0.0001;
max_iter = 1000;

for k = 1: max_iter
    x(k+1) = x(k) - f(x(k)) / df(x(k));
    
    if abs(x(k+1) - x(k)) < tol && abs(f(x(k))) < tol
      break
    endif
endfor

x(k)
f(x(k))
