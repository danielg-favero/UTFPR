clc
clear

A = [];
b = [];
n = 10;

% iniciar a matriz A e o vetor b
for i = 1: n
  for j = 1: n
    A(i, j) = 1 / (i + j - 1);
  endfor
  
  b(i) = 1 / i;
endfor

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
       
   endfor
endfor

% matriz U que é a matriz A triangularizada
U = A

% matriz triangular inferior L com lij = mij (multiplicadores usados na troca das linhas da matriz A)
for i = 1: n
  
  for j = 1: i
    if i == j
        L(i, j) = 1;
    else
        L(i,j) = m(i,j);
    endif
    
  endfor
endfor
L

% Resolvendo o sistema Ly = b
for i = 1: n
  sum = 0;
  
  for j = 1: i - 1
    sum = sum + L(i, j) * y(j);
  endfor
  
  y(i) = (b(i) - sum) / L(i, i);
endfor

% Resolvendo o sistema Ux = b
for i = n: -1: 1
   sum = 0;
  
  for j = i + 1: n
    sum = sum + U(i, j) * x(j);
  endfor
  
  x(i) = (y(i) - sum) / U(i, i);
endfor

% Solução do sistema
x