clear
clc

% método de iterativo jacobi
A = [];
b = [];

% tolerância da solução do sistema
tol = 0.0001;

% máximo de iterações
max_it = 100;

% valor de h
h = 0.1;

% número de iterações
n = 10;

% definição das equações
b(1) = 1;

for i = 1: n
  for j = 1: n
    A(i, j) = 0;
    
    % chute inicial
    x(i, j) = 0;
  endfor
  
  if i > 1
    A(i, i - 1) = 1;
    b(i) = 0;
  endif
  
   A(i, i) = -2 * (1 + h^2);
   
   if i < n - 1
     A(i, i + 1) = 1;   
   endif 
   

endfor

% primeira equação
A(1, 1) = -2 * (1 + h^2);
A(1, 2) = 1;

% última equação
A(n, n-1) = 1;
A(n, n) = -2 * (1 + h^2);

b(n) = 1;

A
b  

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
  
    x(i, k + 1) = soma / A(i, i);
  endfor
  
  d = max(abs(x(:,k+1)-x(:,k)));
  
  if d < tol
    break
  endif
endfor

% solução aproximada do sistema
x(:, k)