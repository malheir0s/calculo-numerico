#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double calcula_fn (double x){
  double numerador = ( (4 * pow(x, 5) ) -1);
  double denominador = pow ((pow(x, 5) + x + 1), 2);
  return (numerador/denominador);
}


double calcula_derivada_fn (double x){
  double h = pow(10, -9);  // calcula a derivada : f'(x) = ( f(x+h) - f(x))/h onde h-> 0
  double numerador = (calcula_fn(x+h) - calcula_fn(x)); 
  return numerador/h; 
}

double calcula_erro_simpson (double b, double a, int n){
  double h = (b - a) / (2*n);
  double derivada_n_f = (b+a)/2; // o ponto inicial é o ponto médio
  for (int i=1; i<=4; i++){
    derivada_n_f = calcula_derivada_fn(derivada_n_f); // irá calcular a enesima derivada de f, pra n=4
  }
  double erro = (((b-a)*pow(h,4))/180)*(-derivada_n_f); // fórmula do erro de simpson
  return erro;
}

double metodo_trapezio (double b, double a, double n, double fa, double fb){
  double h = (b - a) / n; // calculando o h para a divisao dos intervalos
 
  double somatorio_fn = 0;
  for (int i=1; i<= n; i++){
    double xn = a + (h*i);
    somatorio_fn = somatorio_fn + (2 * calcula_fn(xn));
  }

  somatorio_fn = h*(fa + somatorio_fn + fb)/2;
  return somatorio_fn;
}

double metodo_simpson (double b, double a, double n, double fa, double fb){
  double h = (b - a) / (2*n);
  
  double somatorio_fn = 0;
  for (int i=1; i<= (2*n); i++){
    double xn = a + (h*i);
    int coeficiente; 
    if (i % 2 == 0) coeficiente = 2; // para numero par o coeficiente é 2, para impar é 4
    else coeficiente = 4;
    somatorio_fn = somatorio_fn + (coeficiente * calcula_fn(xn));
  }

  somatorio_fn = h*(fa + somatorio_fn + fb)/3;
  return somatorio_fn;
}

int main(){
  std::cout.precision(12); // colocando as casas decimais

  int n;
  cout << "Digite o numero de intervalos n: \n";
  cin >> n ;
  
  // intervalo pré-definido :
  double b = 2;
  double a = 1;
  
  // calculando f (a) e f(b)
  double fa = calcula_fn(a);
  double fb = calcula_fn(b);

  
  cout << "\nRegra dos Trapézios : \n";
  cout << "\nI_t = " << metodo_trapezio(b, a, n, fa, fb) << "\n";

  cout << "\nMétodo de Simpson : \n";
  cout << "\nI_t = " << metodo_simpson(b, a, n, fa, fb) << "\n";


  cout << "\nErro do Método de Simpson : \n";
  cout << "\n E = " << calcula_erro_simpson(b, a, n) << "\n";
  return 0;
}