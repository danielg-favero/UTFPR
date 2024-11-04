clear
clc

f = @(x) cos(x);
d4fx = @(x) cos(x);
a = 0; % ponto inicial da integral
b = pi/2; % ponto final da integral
tol = 10^-3;

isr = 0; % integral de Simpson repetida
N = abs(d4fx(a)); % N representa o maior valor da função f4(x)

m = ceil(((N * (b-a)^5 ) / (180 * tol))^(1/4)) % quantidade de divisões
if mod(m, 2) == 0
  m = m + 1;
endif
h = (b - a) / m % variação em x entre cada parte

for i=1:(m/2)
   % cálculo da integral por soma de trapézios
   isr = isr + f(a + ((2*i - 2) * h)) + 4*f(a + (2*i - 1) *h) + f(a + (2*i*h)); 
end

% resultados finais
isr = isr * h/3
N
esr = (b-a) * N * h^4 / 180