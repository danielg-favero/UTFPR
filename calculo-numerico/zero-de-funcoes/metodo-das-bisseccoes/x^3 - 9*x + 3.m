% Exemplo 1: Método de bissecção
% Dados: f, a, b, tol, max_iter

% Declarar uma função com variável x
f = @(x) x^3 - 9*x + 3;

% Intervalo [a, b]
a = 0;
b = 1;

% Tolerância
tol = 0.00005;

% Número máximo de iterações
max_iter = 10000;

% Melhor aproximação do zero da função, ela começa com um número muito grande
x_aprox = 10000;

for k = 1: max_iter
    x(k) = (a + b) / 2;
    
    if f(a) * f(x(k)) < 0
        b = x(k);
    else
        a = x(k);
    endif
    
    x_aprox = x(k);
    
    % Sair da repetição quando a tolerância for atingida
    if abs(b - a) < tol || f(x(k)) == 0
        break;
    endif
endfor

x_aprox
f(x_aprox)