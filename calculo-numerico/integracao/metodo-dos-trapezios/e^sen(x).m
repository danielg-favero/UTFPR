clear
clc

% INTEGRAÇÃO PELO MÉTODO DOS TRAPÉZIOS

% Função ao qual queremos encontrar a area abaixo
f = @(x) e^sin(x);

% Intervalo de integração
a = 0;
b = pi;

% Valor inicial da integral
Itr(1) = 0;

% Tolerância desejada
tol = 0.001;

% Iterações máximas
max_it = 100;

% Como queremos encontrar o valor da integral com tolerância de 5*10^-4
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
  
  d2f = @(x) exp(sin(x))* cos(x)^2 - exp(sin(x))*sin(x);
  M2 = abs(d2f(a));
  Etr = ((b - a) * M2 * h^2) / 12;
  
  if abs(Etr) < tol
    break;
  endif
endfor

printf("Número de divisões: %d\n", m);
printf("Valor estimado da integral: %d\n", Itr(m + 1));
printf("Erro: %d\n", Etr);