clear
clc

% INTEGRAÇÃO PELO MÉTODO DOS TRAPÉZIOS

% Função ao qual queremos encontrar a area abaixo
f = @(x) 1 / sqrt(x);

% Intervalo de integração
a = 1;
b = 14;

max_it = 1000;
tol = 0.00001;

% Valor inicial da integral
Itr = 0;

for m = 1: max_it
  h = (b - a) / m; % Tamanho dos intervalos
  
  x(1) = a;
  sum = 0;
  for i = 1: m
      x(i + 1) = a + i * h;
      sum += f(x(i)) + f(x(i + 1));
  endfor
  
  Itr = (h/2) * sum;

  % ESTIMANDO O ERRO OBTIDO
  % precisamos encontrar o valor máximo da segunda derivada da função no intervalo de integração
  % no caso d2f = 3 / (4 * a^(5 / 2));, onde seu valor máximo é d2f(a) = 3 / (4 * a^(5 / 2));

  d2f = @(x) 3 / (4 * x^(5 / 2));

  M2 = abs(d2f(a));

  Etr = ((b - a) * M2 * h^2) / 12;
  
  if abs(Etr) < tol
    break
  endif
endfor

printf("Número de divisões: %d\n", m);
printf("Valor estimado da integral: %d\n", Itr);
printf("Erro: %d\n", Etr);