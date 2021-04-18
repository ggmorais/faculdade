#include <stdio.h>
#include <math.h>


// Função para calcular a área e o perimetro de um hexagono
void calc_hexa(float L, float *area, float *perimetro)
{
  // Calculos
  *area = (3 * pow(L, 2) * sqrt(3)) / 2;
  *perimetro = 6 * L;
}

int main()
{ 
  // Variaveis necessarias
  float lado;
  float area;
  float perimetro;

  // Loop para perguntar o valor de L
  while (1) {
    printf("Valor de L (lado) do hexágono: ");
    scanf("%f", &lado);

    // Se o valor digitado for menor que 0, encerra o loop e o programa
    if (lado < 0) {
      printf("Encerrando...");
      break;
    }

    // Chama a função para o lado digitado
    calc_hexa(lado, &area, &perimetro);

    // Exibe na tela o valor da área e do perimetro
    printf("Perimetro: %0.2f\n", perimetro);
    printf("Área: %0.2f\n\n", area);
  }

  return 0;
}