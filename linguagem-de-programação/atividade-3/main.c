#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>


int main()
{

  // Variaveis para armazenar o tamanho de cada frase e o nome
  const char *nomeArquivo = "./frases.txt";
  char frases[5][50];
  char buffer[50];
  int fraseAtual = 0;

  // Abre o arquivo em modo de escrita+
  FILE *arquivo = fopen(nomeArquivo, "w+");

  // Loop para obter as frases
  for (int i = 0; i <= 4; i++) {
    // Pergunta ao usuário a frase pelo numero
    printf("Digite a frase nº %d: ", i + 1);
    fgets(frases[i], 50, stdin);

    // Percorre cada letra da frase e transforma em maiuscula
    for (int j = 0; j <= strlen(frases[i]); j++) {
      int ch = toupper(frases[i][j]);
      frases[i][j] = ch;
    }
    
    // Salva as frases maiusculas no arquivo
    fputs(frases[i], arquivo);
  }

  // Mensagem de aviso
  printf("Frases gravadas.\nLendo frases gravadas...\n");

  // Fecha o arquivo
  fclose(arquivo);
  // Reabre o arquivo, em modo leitura
  fopen(nomeArquivo, "r");

  // Percorre cada linha do arquivo com cada frase
  while(fgets(buffer, 50, arquivo)) {
    fraseAtual += 1;
    // Exibe o numero da linha e a frase
    printf("Frase nº%d: %s", fraseAtual, buffer);
  }

  return 0;
}