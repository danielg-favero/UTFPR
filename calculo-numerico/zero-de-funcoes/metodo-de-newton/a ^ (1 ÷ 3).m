clc
clear

%Encontrar a raiz cúbica de um número a qualquer
% ou seja, queremos resolver a equação x^3 - a = 0

a = 3;
f = @(x) x^3 - a;
df = @(x) 3*x^2;

x(1) = 0.5;

tol = 0.0005;
max_iter = 1000;

for k = 1: max_iter
  x(k + 1) = x(k) - f(x(k)) / df(x(k));
  
  if abs(x(k) - x(k + 1)) < tol && abs(f(x(k + 1))) < tol
    break
  endif
endfor

printf("Iterações: %d\n", k)
printf("cbrt(%d) = %d\n", a, x(k))