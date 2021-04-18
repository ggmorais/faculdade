#include <stdio.h>
#include <math.h>


struct Ponto2d pontoInicial;
struct Ponto2d pontoFinal;

// Estrutura de dados
struct Ponto2d {
  float x;
  float y;
};

void lerPontoInicial()
{
  // Valor do ponto inicial X
  printf("Digite o valor X do ponto inicial: ");
  scanf("%f", &pontoInicial.x);

  // Valor do ponto inicial Y
  printf("Digite o valor Y do ponto inicial: ");
  scanf("%f", &pontoInicial.y);
}

void lerPontoFinal()
{
  // Valor do ponto final X
  printf("Digite o valor X do ponto final: ");
  scanf("%f", &pontoFinal.x);

  // Valor do ponto final Y
  printf("Digite o valor Y do ponto Final: ");
  scanf("%f", &pontoFinal.y);
}

void medirDistancia()
{
  // Potêncialização e calculo final entre os dois pontos
  float distancia = pow(pontoInicial.x - pontoFinal.x, 2) + pow(pontoInicial.y - pontoFinal.y, 2);

  // Imprime a raiz do calculo final
  printf("A distancia é: %0.2f\n", sqrt(distancia));
}

float exibirValor(float valor)
{
  // Exibe o valor do ponto informado na tela
  if (valor) {
    return valor;
  } else {
    return 0;
  }
}

int main()
{ 
  int opcaoSelecionada;

  // Mapeamento de alternativas disponiveis
  void (*funcoes[4])();
  funcoes[0] = lerPontoInicial;
  funcoes[1] = lerPontoFinal;
  funcoes[2] = medirDistancia;

  // Exibir menu de seleção para o usuário
  while (opcaoSelecionada != 4) {
    printf("\nO que deseja fazer?\n");
    printf("[1] Digitar os valores do primeiro ponto. (x: %0.2f, y: %0.2f)\n", exibirValor(pontoInicial.x), exibirValor(pontoInicial.y));
    printf("[2] Digitar os valores do segundo ponto. (x: %0.2f, y: %0.2f)\n", exibirValor(pontoFinal.x), exibirValor(pontoFinal.y));
    printf("[3] Mostrar a distância entre os pontos.\n");
    printf("[4] Sair.\n");

    // Guarda o numero selecionado
    scanf("%d", &opcaoSelecionada);

    // Se a opção é 4 (Sair) encerra o programa
    if (opcaoSelecionada == 4) break;

    if (opcaoSelecionada < 1 || opcaoSelecionada > 4) {
      // Se a opção selecionada não é valida, mostra um aviso ao usuário
      printf("Opção invalida.\n\n");
    } else {
      // Se for valido, chama a função rêferente ao numero selecionado
      funcoes[opcaoSelecionada - 1]();
    }
  }

  return 0;
}