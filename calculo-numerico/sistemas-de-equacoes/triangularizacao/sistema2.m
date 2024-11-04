clc
clear

% para n = 5, 10, 20, 50
n1 = 5;
n2 = 10;
n3 = 20;
n4 = 50;

%n = 5

% iniciar a matriz dos coeficientes e o vetor de soluções
for i = 1: n1
  for j = 1: n1
     A(i, j) = 1 / (i + j - 1);
  endfor
  b(i) = 1 / i;
endfor

disp("Matriz gerada 5x5")
A

for k = 1: n1 - 1
  for i = k + 1: n1
    m(i, k) = A(i, k) / A(k, k);
    A(i, k) = 0;
    
    for j = k + 1: n1
      A(i, j) = A(i, j) - m(i, k) * A(k, j);
    endfor
    
    b(i) = b(i) - m(i, k) * b(k); 
  endfor
endfor

for i = n1: -1: 1
  sum = b(i);
  
  for k = i + 1: n1
    sum = sum - A(i, k) * x1(k);
  endfor
  
  x1(i) = sum / A(i, i);
endfor


% n = 10

for i = 1: n2
  for j = 1: n2
     A(i, j) = 1 / (i + j - 1);
  endfor
  b(i) = 1 / i;
endfor

for k = 1: n2 - 1
  for i = k + 1: n2
    m(i, k) = A(i, k) / A(k, k);
    A(i, k) = 0;
    
    for j = k + 1: n2
      A(i, j) = A(i, j) - m(i, k) * A(k, j);
    endfor
    
    b(i) = b(i) - m(i, k) * b(k); 
  endfor
endfor

for i = n2: -1: 1
  sum = b(i);
  
  for k = i + 1: n2
    sum = sum - A(i, k) * x2(k);
  endfor
  
  x2(i) = sum / A(i, i);
endfor


% n = 20

for i = 1: n3
  for j = 1: n3
     A(i, j) = 1 / (i + j - 1);
  endfor
  b(i) = 1 / i;
endfor

for k = 1: n3 - 1
  for i = k + 1: n3
    m(i, k) = A(i, k) / A(k, k);
    A(i, k) = 0;
    
    for j = k + 1: n3
      A(i, j) = A(i, j) - m(i, k) * A(k, j);
    endfor
    
    b(i) = b(i) - m(i, k) * b(k); 
  endfor
endfor

for i = n3: -1: 1
  sum = b(i);
  
  for k = i + 1: n3
    sum = sum - A(i, k) * x3(k);
  endfor
  
  x3(i) = sum / A(i, i);
endfor


% n = 50

for i = 1: n4
  for j = 1: n4
     A(i, j) = 1 / (i + j - 1);
  endfor
  b(i) = 1 / i;
endfor

for k = 1: n4 - 1
  for i = k + 1: n4
    m(i, k) = A(i, k) / A(k, k);
    A(i, k) = 0;
    
    for j = k + 1: n4
      A(i, j) = A(i, j) - m(i, k) * A(k, j);
    endfor
    
    b(i) = b(i) - m(i, k) * b(k); 
  endfor
endfor

for i = n4: -1: 1
  sum = b(i);
  
  for k = i + 1: n4
    sum = sum - A(i, k) * x4(k);
  endfor
  
  x4(i) = sum / A(i, i);
endfor
  

x1
x2
x3
x4