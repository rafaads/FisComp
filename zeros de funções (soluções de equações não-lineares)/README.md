# Zeros de funções
(ou soluções de equações não-lineares)

f(x)=0

f(x) = x-1 ...ok
f(x) = x-cos(x) ...?
método gráfico →métodos numéricos
→Na física aparece tipicamente em 3 situações:
– Parte não-analítica de uma solução geral
– EDO com condições de contorno → EDO cond. iniciais
2a

ordem, converter x(t0

)=x0 e x(t1
)=x1
em x(t0

)=x0 e x'(t0
)=v0

– Métodos implícitos para eq. diferenciais parciais


##Zeros de funções (métodos numéricos)#

● Método da bisseção
– Posição falsa
● Método da iteração de ponto-fixo
● Método de Newton-Raphson
– Secante

● Brent (Numerical Recipes)


##Algoritmo método da bisseção##

Definir f(x). Escolher epsilon.
Inicializar x
esq
e xdir.
- Repita enquanto |xesq

- xdir| > epsilon:
1) calcular ponto do meio: xmed=(xesq

+ xdir)/2

2) calcular produto: p=f(xmed)*f(xdir)
3) Se p<0, fazer xesq

=xmed

4) Senão, se p>0, fazer xdir=xmed
*5) Senão, terminar repetição
→ nesse caso p=0 e xmed é a solução (sorte)
- Imprime xmed

→ Aplicar para as seguintes f(x) e intervalos:
(1) cos(x) entre 0 e 2
(2) x-cos(x) entre 0 e 2
(3) x-cos(qx) entre 0 e p/q, para q entre 0.1 e 100

--------------------------------
Definir f(x). Escolher epsilon.
Inicializar (escolher) a e b.
- Repita enquanto |a-b| > epsilon:
1) calcular ponto do meio: c =(a + b)/2
2) calcular produto: p=f(c)*f(b)
3) Se p<0, fazer a=c
4) Senão, se p>0, fazer b=c
*5) Senão, terminar repetição
→ nesse caso p=0 e c é a solução (sorte)
- Imprime c

→ Aplicar para as seguintes f(x) e intervalos:
(1) cos(x) entre 0 e 2
(2) x-cos(x) entre 0 e 2
(3) x-cos(qx) entre 0 e p/q, para q entre 0.1 e 100
--------------------------------

Método da bisseção

● Convergência (http://mathworld.wolfram.com/Bisection.html)
 sendo a solução exata (desconhecida): x*
 erro absoluto inicial: ε0

:= |x0

med - x*|⩽(x0
dir-x
0
esq
)/2

na 1a

repetição: ε1

:= |x1

med - x*|⩽(x0
dir-x
0
esq
)/22

 na n-ésima repetição: εn ⩽ (x0
dir-x
0
esq
)/2n+1
→ significa: εn ~ 2

-n-1 ou, n ~ -log2
(εn
)

 Taxa de convergência é linear: εn+1 ⩽ c εn

m com c=1⁄2 e m=1
a convergência é exponencial (acima), mas taxa significa que o custo
computacional cresce linearmente com ganho sucessivo de precisão.
● Optimização: guardar valor da função do lado que permaneceu -
invés de 2n, função é chamada apenas n+1 vezes

-----------

##Método da posição falsa##

ou regula falsi

● Egípcios - papiro de Rhind

(2000 A.C. - problema 26 de 85)

– Um montão, mais a sua metade, seus dois terços, todos juntos são 26. Diga-
me, quanto é esse montão?

– Tomando 18 como valor falso, sua metade (9) e seus dois terços (12), logo:
18+9+12=39
Ajuste: 18 está para x, assim como 39 está para 26, portanto x= (18*26)/39,
x=12 .... 12 é o valor do montão.

● Solução de ax=b por semelhança de triângulos
(1+1/2+2/3) x = 26
13/6 x = 26

---------------------

##Método da posição falsa##

Semelhança triângulos (x_upper e x_lower):


Algoritmo:
- inicializar epsilon e passo= xu-xl
- repetir enquanto passo>epsilon:
calcular xr
verificar se f(xr)*f(xu)<0
Sim: passo=|xl-xr|
xl= xr
Não: passo=|xu-xr|
xu = xr
- imprime xr

-------------------------------
● Convergência (linear?)
garantida, em geral
mais rápido que
bisseção

● Exemplo de
convergência lenta:
f(x) = x10 - 1 →

------------------------------

##Método de iteração do ponto fixo##


f(x) = 0 → x = G(x)

→ x, G(x), G(G(x)),G(G(G(x))), ...
● Iteração / Relação de recorrência: x(n+1) = G(x(n))
● Algoritmo básico:
– inicialização x
– repetir para sempre:
→ while(1)
x = G(x)
imprime x
getchar( );
– para parar execução:
ctrl+c

● Exemplo: x - cos(x) = 0

--------------------------------------------------------

f(x) = 0 → x = G(x)
→ x, G(x), G(G(x)),G(G(G(x))), ...
● Iteração / Relação de recorrência: x(n+1) = G(x(n))
● Critério de parada: |x(n+1) – x(n)|< e
● Algoritmo:
– Escolha e e inicialização x, D
– Enquanto D > e
xnovo = G(x)
D = |xnovo – x|
x = xnovo
– Imprime x

● Exemplo: x - cos(x) = 0
gnuplot: with steps

------------------------------------------------------------

● Dado f(x)=0 : infinitas escolhas para G(x) em x=G(x)
● Converge (taxa linear) para ponto fixo se |G'(x*)|<1
(ou pelo menos na região aproximada para x*)
→ Convergência mais rápida para |G'(x*)|pequena
● A equação pode ter mais de uma solução. Pode convergir para uma
e não para outra: depende da condição inicial.
→ Se converge para qlq condição inicial x(0)  [a,b] a essa região
chamamos bacia de atração do ponto fixo.

● Prática: achar solução de
– x2+x-6=0 com x0=1.5
– log x + x2 – 1 = 0
– cos(x) = x - tomando G(x) = 0.4 x + 0.6 cos(x) e x0=0.5

------------------------------------------------------------

##Convergência##

● Sendo x(n+1) = G(x(n)) e a solução exata (ponto fixo): x* = limn→∞ x(n)
erro da n-ésima iteração: εn
:= x(n)
- x* e taxa convergência: Dn

= x(n+1) – x(n)

● Método é linear: εn+1 = c εn

(e também Dn+1 = c Dn ) com c=G'(x*)

→ converge quando |G'(x*)|<1, de maneira alternante se G'(x*)<0 e monótona se G'(x*)>0
● Quanto o critério Dn < e garante proximidade da solução?
– O erro devido truncar no n-ésimo passo:
en
≈ Dn
/ (1/G'(x*) - 1)

diferença entre usar en < e e Dn < e será mais importante quando G'(x*) → 1.
– Exemplo: sin(x)=x com x(0)=1.0 com critério de parada D<e=1e-8
acaba em x(195735) = 3.91485405e-03 enquanto x*=0
Erro: 1e-8/(1/cos(3.91485405e-03)-1) ~0.001 ...ok

● Para usar critério de parada mais rigoroso en<e é preciso saber G'. Alternativa caso seja
difícil de calcular, ou computacionalmente pesado, ou G pode ser desconhecida:
en+1 ≈ D2

n+1/(1- Dn-1/Dn

) = (x(n)-x(n+1))2/(2x(n) - x(n+1) - x(n-1))

-----------------------------------------------------------

● Superlinear: en+1 = en

2 [-1⁄2 f''(x)/f'(x)]

– Quadrática: muito mais rápido, a cada passo duplica dígitos
– Convergência gaussiana exp(-n2)
– Derivada segunda nula f''(x*)=0: convergência rápida (en+1~0en
2)

● Problemas:
– Longe da solução, max/min local (divisão por 0) joga iteração para
longe ou entra em um ciclo
– Funções descontínuas/ derivada não bem definida
– Dificuldade em saber a derivada. Possível adaptação/aprox:
f '(x) ~ f(x+dx)-f(x)
dx

--------------------------------------------------------
##Método de Brent##
(Van Wijngaarden-Dekker-Brent)

● Bisseção sempre converge, mas é linear.
– Secante e posição falsa são superlineares, mas tem
casos em que bisseção mais rápido. Secante nem
sempre converge.

● Combina convergência incondicional com taxa
superlinear usando: enquadramento, bisseção e
interpolação quadrática inversa.
● É a escolha mais popular quando em dúvida
sobre convergência de métodos mais tradicionais.
● Usar como função pronta do Numerical Recipes:
precisa saber passar uma função para outra
-------------------------------------------------------

##Passando uma função para outra##

memória guarda não só valores, mas nomes de
variáveis... e instruções do próprio programa.

● Ponteiros para funções:
– Definição: int (*pf)();

()'s para diferenciar de int *pf() = função que retorna
um ponteiro para um inteiro

– Uso igual a vetores: pf = &cos;

int divisor (int);
main(){
int (*pf)();
pf = &divisor;
y = pf(3);
--------------------------------------------------------------

Exemplo:

double deriv(double (*f)(double),double x, double dx){
return((f(x+dx) -f(x))/dx);
}

main(){
double x=0.0,dx=0.001;
printf("%f\n",deriv(cos,x,dx));
}
