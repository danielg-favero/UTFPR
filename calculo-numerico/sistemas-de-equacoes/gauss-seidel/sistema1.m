clear
clc

% método de iterativo  de jacobi
A = [1 5 -3; 2 -1 -9; 7 2 -5];
b = [-40  -26  -18];
n = length(b);

% chute inicial
x(:, 1) = [0 0 0];

% tolerância da solução do sistema
tol = 0.0005;

% máximo de iterações
max_it = 100;

% ALGORITMO DE GAUSS-SEIDEL
for k = 1: max_it
  for i = 1: n
    soma = b(i);
  
    for j = 1: i - 1
      soma = soma - A(i, j) * x(j, k);
    endfor
    
    for j = i + 1: n
      soma = soma - A(i, j) * x(j, k);
    endfor
    
    x(i, k + 1) = soma / A(i, i);
  endfor
  
  d = max(abs(x(:, k + 1) - x(:, k)));
  
  if d < tol
    break
  endif
endfor

% solução aproximada do sistema
x(:, k)