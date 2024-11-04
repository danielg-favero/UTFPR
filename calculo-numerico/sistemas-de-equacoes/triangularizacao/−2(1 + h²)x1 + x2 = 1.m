clc
clear

% valor de h
h = 0.1;

% número de iterações
n = 5;

% definição das equações
b(1) = 1;

for i = 1: n
  for j = 1: n
    A(i, j) = 0;
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

% resolução do sistema
for k = 1: n - 1
  for i = k + 1: n
    
    % zerar os elementos abaixo da diagonal principal
     m(i, k) = A(i, k) / A(k, k);
     A(i, k) = 0;
   
      for j = k + 1: n
        % realizar as operações de alteração da linha
        A(i, j) = A(i, j) - m(i, k) * A(k, j);
      endfor
      
      % alterar o vetor de soluções da
      b(i) = b(i) - m(i, k) * b(k);
  endfor
endfor

% substituição regressiva dos valores
% inicia-se na última posição pois é aquela que temos a solução de cara
for i = n: -1: 1
  sum = b(i);
  
  for k = i + 1: n
    sum = sum - A(i, k) * x(k);
  endfor
  
  x(i) = sum / A(i, i);
endfor

x
