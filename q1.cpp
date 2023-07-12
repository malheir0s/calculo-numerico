#include <iostream>
#include <iomanip>
using namespace std;


double calcula_diferenca_dividida (double xn, double xn_1, double yn, double yn_1){
  return ((yn_1 - yn) / (xn_1 - xn));
}


void exibe_polinomio (double** coeficientes, double* x, double y0, int linhas){
  cout << "\nP(x) = " << y0 << " + \n";
  for(int i=0; i< linhas; i++){
    cout<< coeficientes[0][i] << " ";
    for (int j=0; j<i+1; j++){
      char sinal;

      if ( x[j] < 0 ) sinal = '+';
      else sinal = '-';
      cout<< "(x " << sinal << " " << x[j] << ")";
    }
    if(i+1 < linhas ) cout<< " + \n";
    else cout << "\n";
  }
}

double calcula_pn (double** coeficientes, double* x, double y0, int linhas, double x_n){
  double pn = y0;
  for(int i=0; i< linhas; i++){
    double c = coeficientes[0][i];
    for (int j=0; j<i+1; j++){
      c = c*(x_n - x[j]);
    }
    pn += c;
  }
  return pn;
}


int main(){
  // pontos pré-definidos
  std::cout.precision(12); // colocando as casas decimais
  int x_inicial[] = {-2, 0, 1, 2, 4, 5};
  int y_inicial[] = {5, 1, 3, -1, -1, 0};
  
  int n;
  

  cout << "Digite quantos pontos deseja adicionar: \n";
  cin >> n ;
  int linhas = n + 5; // quantidade de linhas da tabela dividida. vai ser a quantidade de pontos novos + 5


  // colocando os pontos novos + pontos pré-definidos em novas variaveis
  double* x = (double*) malloc((n+6) * sizeof(double));
  double* y = (double*) malloc((n+6) * sizeof(double));
  
  // colocando os pontos pré-definidos nas variáveis novas
  for (int i = 0; i < 6; ++i) {
    x[i] = x_inicial[i];
    y[i] = y_inicial[i];
  }

  // recebendo os novos pontos. já temos 6 pontos, então será o 7 ponto em diante.
  for (int i = 6; i < n+6; ++i) {
    cout << "Digite x_" << i+1 << "\n";
    cin >> x[i];
    cout << "Digite y_" << i+1 << "\n";
    cin >> y[i];
  }
  
  // criando uma matriz para armazenar a tabela de diferenças divididas.
  double** tabela_diferencas = (double **) malloc(linhas * sizeof(double*));

  //for(int i = 0; i < linhas; i++) tabela_diferencas[i] = (double *) malloc((linhas-i) * sizeof(double));
  for(int i = 0; i < linhas; i++) tabela_diferencas[i] = (double *) malloc((linhas-i) * sizeof(double));
  
  // calculando a diverença dividida e inserindo na matriz. 
  for(int i = 0; i < linhas; i++){
    int indice = i+1;
    for(int j = 0; j < (linhas-i); j++){
      double delta_y;
      if (i == 0){
        delta_y = calcula_diferenca_dividida(x[j], x[j+1], y[j], y[j+1]);
      }
      else{
        delta_y = calcula_diferenca_dividida(x[j], x[indice], tabela_diferencas[j][i-1], tabela_diferencas[j+1][i-1]);
        indice+=1;
      }

      tabela_diferencas[j][i] = delta_y;
    }
  }
 
  cout << "Tabela das Diferenças Divididas: \n";
  for(int i = 0; i < linhas; i++){
    for(int j=0; j < (linhas-i) ; j++){
       if(j==0) cout << setw(10) << tabela_diferencas[i][j]; 
       else cout << setw(30) << tabela_diferencas[i][j]; 
    }
    cout <<  "\n"; 
  }
  
  exibe_polinomio(tabela_diferencas, x, y[0], linhas);
  double p_3 = calcula_pn(tabela_diferencas, x, y[0], linhas, 3.0);
  cout << "\n \nP(3) = " <<  p_3 << " \n";
  
  return 0;
}