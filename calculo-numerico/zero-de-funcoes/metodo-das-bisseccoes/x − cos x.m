f = @(x) x - cos(x);

a = 0;
b = pi / 2;

max_iter = 1000;

tol = 0.00005;

x_aprox = 10000;

for k = 1: max_iter
    x(k) = (a + b) / 2;

    if f(a) * f(x(k)) < 0
        b = x(k);
    else
        a = x(k);
    endif

    x_aprox = x(k);

    if abs(a - b) < tol || f(x(k)) == 0
        break
    endif
endfor

x_aprox
f(x_aprox)
