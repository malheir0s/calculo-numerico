import math
import numpy as np

erro_absoluto = pow(10, -4)

# def f(x):
#   return (x - math.tan(math.exp(-x)))

#f: arctg x = e ^ -x
#x = ln(1/arctg x)

def f(x):
  return (np.arctan(x) - math.exp(-x))

def d_f(x):
  return (math.exp(-x) + 1/(1+pow(x,2)))
#arctang(x) = e^-x + x

1/1+x^2 + e^-x = 0 : no intervalo [0,1]
1/1+x}2 +e^-x < 1


def bissecao():  
    ponto_inferior = 0
    ponto_superior = 1
    ponto_medio = (ponto_inferior + ponto_superior) / 2
    f_pmedio = f(ponto_medio)
    f_a = f(ponto_inferior)
    print("{:<6} {:<30} {:<30} {:<30} {:<30} {:<30}".format('N', 'a_n', 'b_n', 'ponto médio', 'f(a)', 'f(ponto-medio)'))
    n=0
    while (abs(f_pmedio) > erro_absoluto and f_pmedio != 0):
        print("{:<6} {:<30} {:<30} {:<30} {:<30} {:<30}".format(n, ponto_inferior, ponto_superior, ponto_medio, f_a, f_pmedio))
        if (f_a * f_pmedio > 0):  
            ponto_inferior = ponto_medio  
            f_a = f_pmedio
        else:  
            ponto_superior = ponto_medio
        ponto_medio = (ponto_inferior + ponto_superior) / 2
        f_pmedio = f(ponto_medio)
        n+=1
        
    

def secantes():
  x = 0 # x  representará a iteração n-1
  x_n = 1 # x_n -> iteração n
  erro_relativo = abs(x_n - x)
  n = 0
  f_x = f(x) 
  f_x_n = f(x_n)
  print("{:<6} {:<30} {:<30} {:<30} {:<30} {:<30} {:<30}".format('N', 'x_n-1', 'x_n', 'x_n+1', 'f(x_n-1)', 'f(x_n)', 'erro relativo'))
  while (erro_relativo > erro_absoluto):
    x_n_1 = x_n - (f_x_n * (x_n - x)/(f_x_n - f_x))
    print("{:<6} {:<30} {:<30} {:<30} {:<30} {:<30} {:<30}".format(n, x, x_n, x_n_1, f(x), f(x_n), erro_relativo))
    ## proxima iteração...
    n+=1
    x = x_n
    x_n = x_n_1
    f_x = f(x)
    f_x_n = f(x_n)    
    erro_relativo = abs(x_n - x)
    
    
def newton_raphson():
  x = 0 # x  representará a iteração n-1
  x_n = 1 # x_n -> iteração n
  erro_relativo = abs(x_n - x)
  n = 0
  f_x_n = f(x_n)
  d_f_x_n = d_f(x_n) # derivada
  print("{:<6} {:<30} {:<30} {:<30} {:<30} {:<30} {:<30}".format('N', 'x_n-1', 'x_n', 'x_n+1', 'f(x_n)', 'f\'(x_n)', 'erro relativo'))
  while (erro_relativo > erro_absoluto):
    x_n_1 = x_n - (f_x_n/d_f_x_n)
    print("{:<6} {:<30} {:<30} {:<30} {:<30} {:<30} {:<30}".format(n, x, x_n, x_n_1, f(x_n), d_f(x_n), erro_relativo))
    ## proxima iteração...
    n+=1
    x = x_n
    x_n = x_n_1
    f_x_n = f(x_n)
    d_f_x_n = d_f(x_n)
    erro_relativo = abs(x_n - x)

def ponto_fixo():
  x = 1 # nosso ponto fixo
  x_n = f(x)
  erro_relativo = abs(x_n - x)
  n = 0
  print("{:<6} {:<30} {:<30} {:<30}".format('N', 'x_n-1', 'x_n', 'erro relativo'))
  while (erro_relativo > erro_absoluto):
    print("{:<6} {:<30} {:<30} {:<30}".format(n, x, x_n, erro_relativo))
    ## proxima iteração...
    n+=1
    x = x_n
    x_n = f(x)
    erro_relativo = abs(x_n - x)


print("Método da Bisseção: ")
bissecao()


print("Método do Ponto Fixo: ")
ponto_fixo()

print("Método das Secantes: ")
secantes()

print("Método de Newton-Raphson: ")
newton_raphson()
