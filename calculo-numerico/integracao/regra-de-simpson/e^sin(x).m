clc
clear

% INTEGRAÇÃO POR MÉTODO DE SIMPSON

% Intervalo de integração
a = 0;
b = pi;

% Função a ser integrada no intervalo
f = @(x) e^sin(x);

max_it = 1000;
tol = 0.0001;

% Valor inicial da integral
Isr = 0;

for m = 2: 2:max_it
  h = (b - a) / m; % Tamanho dos intervalos
  
  sum = 0;
  for i = 1: (m / 2)
    x(2 * i + 1) = a + 2 * i * h;
    x(2 * i) = a + (2 * i - 1) * h;
    x(2 * i - 1) = a + (2 * i - 2) * h;
    sum += f(x(2 * i - 1)) + 4 * f(x(2 * i)) + f(x(2 * i + 1)); 
  endfor
  
  Isr = sum * h / 3;
  
  % Calculando o erro obtido ao calcular a integral
  d4f = @(x) exp(sin(x))*(sin(x)*(3*sin(x) + 1) + cos(x)^4 - 2*(3*sin(x) + 2) * cos(x)^2);
  M4 = abs(d4f(a));
  Esr = ((b - a) * M4 * h^4) / 180;
  
  if abs(Esr) < tol
    break
  endif
endfor

printf("Número de divisões: %d\n", m);
printf("Valor estimado da integral: %d\n", Isr);
printf("Erro: %d\n", Esr);