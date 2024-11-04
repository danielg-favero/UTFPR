clc
clear

%Encontrar uma aproximação para o ponto da curva mais próximo de (2, 1)

#{
  A estratégia é a sequinte:da
  
  - Queremos encontrar a distância mínima entre o ponto (a, b) e a função f(x)
  - A distância entre (a, b) e (x, y) é dada por:
        d = sqrt((a - x) ^ 2 + (b - y) ^ 2)
        d(x) = sqrt((a - x) ^ 2 + (b - f(x)) ^ 2)
        d^2(x) = (a - x) ^ 2 + (b - f(x)) ^ 2
        
   - Podemos definir uma função g(x), tal que
         g(x) = d^2(x) = (a - x) ^ 2 + (b - f(x)) ^ 2
         
   - Queremos obter g(x) mínimo, ou seja, g'(x):
          g'(x) = 2(a - x) + 2(b - f(x)) * f'(x) = 0
          
    - Usar o método da secante para resolver g'(x) = 0
#}


% Ponto (2, 1) do exercício
a = 2;
b = 1;

% função f(x)
f = @(x) 1 / x;
df = @(x)  (-1) / (x * x);

% função g'(x)
dg = @(x) 2 * (a - x) + 2 * (b - f(x)) * df(x);

% aproximações iniciais
x(1) = 1;
x(2) = 3;

tol = 0.0001;
max_iter = 1000;

for k = 1: max_iter
      x(k + 2) = (x(k) * dg(x(k + 1)) - x(k + 1) * dg(x(k))) / (dg(x(k + 1)) - dg(x(k)));
      
      if abs(x(k + 1) - x(k + 2)) < tol && abs(dg(x(k + 2))) < tol
          break
      endif
endfor

printf("Iterações: %d\n", k)
printf("x = %d\n", x(k))
printf("f = %d\n", f(x(k)))
