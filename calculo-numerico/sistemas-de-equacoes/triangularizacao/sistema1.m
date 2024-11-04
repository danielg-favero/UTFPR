clc
clear

% matriz que contém os coeficientes das equações do nosso sistema
A = [7 2 -5; 1 5 -3; 2 -1 -9];

% vetor de soluções do sistema
b = [-18 -40 -26];

% número de iterações (quantidade de linhas da matriz)
n = length(b);

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