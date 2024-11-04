clear
clc

% INTEGRAÇÃO PELO MÉTODO DOS TRAPÉZIOS

% Função ao qual queremos encontrar a area abaixo
f = @(x) 1 / (1 + x);

% Intervalo de integração
a = 0;
b = 0.6;

% Valor inicial da integral
Itr(1) = 0;

% Tolerância desejada
tol = 10^(-3);

% Iterações máximas
max_it = 100;

% Como queremos encontrar o valor da integral com precisão de 3 casas decimais
% Vamos começar a resolução com 1 trapézio até encontrarmos a precisão desejada

for m = 1: max_it
  % Altura de cada trapézio
  h = (b - a) / m;
  
  x(1) = a;
  
  sum = 0;
  for i = 1: m
      x(i + 1) = a + i * h;
      sum += f(x(i)) + f(x(i + 1));
  endfor
  
  Itr(m + 1) = (h / 2) * sum;
  
  % Comparar dois resultados consecutivos das integrais
  % Caso Itr(m + 1) - Itr(m) < tol, temos a tolerância desejada
  d = abs(Itr(m + 1) - Itr(m));
  
  if d < tol
    break;
  endif
endfor

% ESTIMANDO O ERRO OBTIDO
% precisamos encontrar o valor máximo da segunda derivada da função no intervalo de integração
% no caso d2f = 2 / (1 + x)^3, onde seu valor máximo é d2f(a) = 2 / (1 + a)^3

d2f = @(x) 2 / (1 + x)^3;

M2 = abs(d2f(a));

Etr = ((b - a) * M2 * h^2) / 12;
printf("Area aproximada abaixo do gráfico da função: %d\n", Itr(m))
printf("Erro estimado <= %d\n", Etr)
