#include <stdio.h>
#include <ctype.h>


int main()
{
  // Mapeamento de peças
  char *pecas[7] = {"vazio", "peão", "cavalo", "torre", "bispo", "rei", "rainha"};
  // Mapeamento de posições 
  char alf[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

  // Define o tabuleiro
  int tabuleiro[8][8];

  printf("Peças: \n");
  
  // Loop para exibir o ID de cada peça
  for (int i = 0; i <= 6; i++) {
    printf("[%d] %s\n", i, pecas[i]);
  }

  // Loop para preencher o tabuleiro
  for (int i = 0; i <= 7; i++) {
    for (int j = 0; j <= 7; j++) {
      int nInserido = -1;

      // Enquanto a peça inserida for invalida, pergunta ao usuário a peça para a posição
      while (nInserido > 7 || nInserido < 0) {
        printf("Posição %c%d: ", alf[j], i + 1);
        scanf("%d", &nInserido);  
      }

      tabuleiro[i][j] = nInserido;
    }
  }

  printf("\nTabuleiro:\n   ");

  // Exibe cada letra do tabuleiro na tela
  for (int j = 0; j <= 7; j++) {
    printf("%c ", alf[j]);
  }

  printf("\n");

  // Exibe cada numero do tabuleiro por linha
  for (int i = 0; i <= 7; i++) {
    printf("%d| ", i + 1);

    // Exibe cada peça em sua posição pelo ID
    for (int j = 0; j <= 7; j++) {
      printf("%d ", tabuleiro[i][j]);
    }

    printf("\n");
  }

  printf("\nContagem de peças:\n");

  // Exibe a contagem de peças por tipo
  for (int i = 1; i <= 6; i++) {
    int somaPecas = 0;

    // Loop para obter a quantia exata de cada tipo de peça
    for (int j = 0; j <= 7; j++) {
      for (int k = 0; k <= 7; k++) {
        if (tabuleiro[j][k] == i) somaPecas += 1;
      }
    }

    printf("%s: %d peças\n", pecas[i], somaPecas);
  }

  return 0;
}