f = @(x) (4*x - 7) / (x - 2);

a = 1.8;
b = 3;

max_iter = 1000;

tol = 0.00005;

x_aprox = 1000;

% Verificar se a função troca de sinal no intervalo [a, b]
if f(a) * f(b) < 0
    f(a)
    f(b)
endif

% Mesmo trocando de intervalo, não é possível utilizar o método das bissecções, pois dentro do intervalo [a, b] a função é descontínua, mais expecificamente em x = 2 (ao qual resultara o resultado desse algoritmo). Além do fato que o zero da função não pertence a esse intervalo

for k = 1: max_iter
    x(k) = (a + b) / 2;

    if f(a) * f(x(k)) < 0
        b = x(k);
    else
        a = x(k);
    endif

    x_aprox = x(k);

    if abs(b - a) < tol || f(x(k)) == 0
        break
    endif
endfor

x_aprox
f(x_aprox)
