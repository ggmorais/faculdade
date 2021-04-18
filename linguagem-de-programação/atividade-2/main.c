#include <stdio.h>

// Função para calcular o imposto de renda
float calcularImpostoDeRenda(float salario)
{
  float aliquota = 0;

  // Peso dependendo do salário
  if (salario >= 1637.12 && salario <= 2453.50) {
    aliquota = 7.5;
  } else if (salario >= 2453.51 && salario <= 3271.38) {
    aliquota = 15;
  } else if (salario >= 3271.39 && salario <= 4087.65) {
    aliquota = 22.5;
  } else if (salario >= 4087.65) {
    aliquota = 27.5;
  }

  // Calculo final
  return (salario * aliquota) / 100;
}

int main()
{

  // Variaveis para guardar a entrada do usuário
  char nome[50];
  float salario;

  // Lê o nome do usuário
  printf("Digite seu nome: ");
  scanf("%s", &nome);

  // Impedir que o scanf acima capture o scanf abaixo
  fflush(stdin);
  
  // Lê o salário do usuário
  printf("Digite seu salário: ");
  scanf("%f", &salario);

  // Chama a função de calculo de imposto de renda passando o salário
  float impostoDeRenda = calcularImpostoDeRenda(salario);
  
  // Exibe ao usuário seu nome e imposto de renda, em reais
  printf("Imposto de renda para %s: R$ %0.2f", nome, impostoDeRenda);

  return 0;
}