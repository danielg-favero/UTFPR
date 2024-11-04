f = @(x) x^3 + 3*x^2 -1;

a = -4;
b = 0;

max_iter = 1000;

tol = 0.00005;

x_aprox = 1000;

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
