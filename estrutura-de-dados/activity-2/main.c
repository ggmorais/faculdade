#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tamanho fixo da hash table
#define TAMANHO_TABELA 50

// Estrutura para armazenamento dos dados do aluno
typedef struct Aluno {
    char RU[8];
    char email[40];
    char nome[40];
} aluno_t;

// Criação do array que funcionara como uma hash table
aluno_t *alunos_hash_table[TAMANHO_TABELA];

// Função hash para obter o index a partir do tamanho da tabela e do RU do aluno´
// Realiza a soma de todos os caracteres do RU retorna operação soma_ascii MOD n_tabela
int funcaoHash(int tamanhoTabela, char RU[8])
{
    // Soma dos valores dos caracteres ASCII
    int ascii_soma = 0;

    // Percorre todos os caracteres do RU e incrementa no ascii_soma
    for (int i = 0; i < 7; i++) {
        ascii_soma += RU[i];
    }

    // Retorna a soma dos caracteres ascii modulo (mod) tamanho da hash table
    return ascii_soma % tamanhoTabela;
}

int main()
{
    // Dados predefinidos dos alunos, RU, email e nome
    aluno_t alunos[10] = { 
        { "1111111", "email1@teste.com", "Pessoa 1"},
        { "2222222", "email2@teste.com", "Pessoa 2"},
        { "3333333", "email3@teste.com", "Pessoa 3"},
        { "4444444", "email4@teste.com", "Pessoa 4"},
        { "5555555", "email5@teste.com", "Pessoa 5"},
        { "6666666", "email6@teste.com", "Pessoa 6"},
        { "7777777", "email7@teste.com", "Pessoa 7"},
        { "8888888", "email8@teste.com", "Pessoa 8"},
        { "9999999", "email9@teste.com", "Pessoa 9"},
        { "3323756", "gusxmorais@gmail.com", "Gustavo Morais"}
    };

    // Inserção dos dados dos alunos na hash table
    for (int i = 0; i < 10; i++) {
        int hashPos = funcaoHash(TAMANHO_TABELA, alunos[i].RU);

        // Caso a posição na hash table já esteja em uso, informa para o usuário
        // Possível solução é aumentar o tamanho fixo da tabela
        if (alunos_hash_table[hashPos] != NULL) {
            printf("Posição %d já em uso! Tente aumentar o tamanho da tabela.\n", hashPos);
            continue;
        }

        // Exibe a posíção que o aluno vai ficar na hash table
        printf("Aluno RU %s inserido na posição %d\n", alunos[i].RU, hashPos);

        // Insere o aluno na hash table pela posição calculada
        alunos_hash_table[hashPos] = &alunos[i];
    }

    // Loop para exibir o menu
    while (1) {
        // Opções
        printf("\n\n-------- MENU -------");
        printf("\n1. Buscar usuário\n2. Sair\n");

        // Variável para armazenar a opção selecionada
        int option;
        scanf("%d", &option);

        // Validação da opção selecionada
        if (option == 1) {
            // Caso 1, inicia o processo de busca do aluno pelo RU
            // Utilizando a função hash para obter o index
            char ru_aluno[8];

            // RU do aluno
            printf("\nInsira o RU do aluno: ");
            scanf("%s", ru_aluno);

            // Chamada da função hash
            int pos = funcaoHash(TAMANHO_TABELA, ru_aluno);

            // Verificar se existe algum dado na posição obtida
            if (alunos_hash_table[pos] == NULL) {
                printf("\nAluno não encontrado!");
            } else {
                // Caso exista, exibe o nome e email do aluno
                printf("\nAluno encontrado!\n");
                printf("Nome: %s\nEmail: %s", alunos_hash_table[pos]->nome, alunos_hash_table[pos]->email);
            }  
        } else if (option == 2) {
            // Caso 2, encerra o programa
            printf("\nSaindo...");
            exit(0);
        } else {
            // Opção invalida, continua o loop
            printf("\nOpção invalida.");
        }
    }

    return 0;
}