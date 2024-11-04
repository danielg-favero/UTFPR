clear
clc

% método de iterativo  de jacobi
A = [10 2 1; 1 5 1; 2 3 10];
b = [7 -8 6];
n = length(b);

% chute inicial
x(:, 1) = [0 2 0];

% tolerância da solução do sistema
tol = 0.001;

% máximo de iterações
max_it = 100;

% ALGORITMO DE JACOBI
for k = 1: max_it
  for i = 1:n
    soma = b(i);
    
    for j = 1: i - 1
      soma = soma - A(i, j) * x(j, k);
    endfor
  
    for j = i + 1: n
      soma = soma - A(i, j) * x(j, k);
    endfor
  
    % nova aproximação do sistema
    x(i, k + 1) = soma / A(i, i);
  endfor
  
  % critério de parada
  d = max(abs(x(:,k+1)-x(:,k)));
  
  if d < tol
    break
  endif
endfor

% solução aproximada do sistema
x(:, k)