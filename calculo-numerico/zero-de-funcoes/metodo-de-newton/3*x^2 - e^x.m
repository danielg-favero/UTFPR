clc
clear

f = @(x) 3*x^2 - e^x;
df = @(x) 6*x - e^x;

x1(1) = -1;
x2(1) = 2;
x3(1) = 3;

tol = 0.00001;

max_iter = 1000;

% Encontrar a primeira solução
for k = 1: max_iter
    x1(k + 1) = x1(k) - f(x1(k)) / df(x1(k));
    
    if abs(x1(k) - x1(k + 1)) < tol && abs(f(x1(k))) < tol
        break
    endif
endfor

printf("Primeira solução")
printf("Total de iterações: %d\n", k)
printf("Solução 1: %d\n", x1(k))
printf("Valor da função: %d\n\n", f(x1(k)))

% Encontrar a segunda solução
for k = 1: max_iter
    x2(k + 1) = x2(k) - f(x2(k)) / df(x2(k));
    
    if abs(x2(k) - x2(k + 1)) < tol && abs(f(x2(k))) < tol
        break
    endif
endfor

printf("Primeira solução")
printf("Total de iterações: %d\n", k)
printf("Solução 1: %d\n", x2(k))
printf("Valor da função: %d\n\n", f(x2(k)))


% Encontrar a terceira solução
for k = 1: max_iter
    x3(k + 1) = x3(k) - f(x3(k)) / df(x3(k));
    
    if abs(x3(k) - x3(k + 1)) < tol && abs(f(x3(k))) < tol
        break
    endif
endfor

printf("Primeira solução")
printf("Total de iterações: %d\n", k)
printf("Solução 1: %d\n", x3(k))
printf("Valor da função: %d\n", f(x3(k)))

