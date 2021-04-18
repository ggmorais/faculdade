#include <stdio.h>
#include <stdlib.h>


// Node da lista encadeada para armazenamento da musica
typedef struct Node
{
    char author[40]; // Autor/banda da musica
    char title[40]; // Titulo/nome da musica
    float length; // Duração da musica em segundos
    struct Node *next; // Próximo node (musica)
} node_t;

// Cabeçalho da lista encadeada
node_t *head = NULL;


// Função para adicionar musicas lendo o input do usuário
void addMusic()
{
    fflush(stdin);

    // Novo node para armazenamento de uma nova musica
    node_t *new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    // Leitura dos dados da musica
    printf("Autor da musica: ");
    // scanf("%s[^\n]", &new_node->author);
    fgets(new_node->author, 40, stdin);

    printf("Nome da musica: ");
    // scanf("%s[^\n]", &new_node->title);
    fgets(new_node->title, 40, stdin);

    printf("Duração da musica: ");
    scanf("%f", &new_node->length);

    // Verificar se o cabeçalho da lista encadeada já existe
    // Caso não exista, definimos o valor do cabeçalho como o valor da musica
    if (head == NULL) {
        head = new_node;
        head->next = NULL;

        // Retornamos pois não é necessário realizar mais nenhuma etapa
        return;
    }

    // Caso o cabeçalho da lista já exista, trocamos a posição dele 
    // como próximo item da lista (segundo item)
    new_node->next = head;
    head = new_node;
}


// Função para percorrer a lista encadeada e exibir as musicas
void showMusics()
{
    // A listagem começa a partir do cabeçalho da lista
    // Então definimos o valor inicial sendo o cabeçalho
    node_t *node = head;

    // Enquanto o valor do node não for nulo, continuaremos avançando na lista
    while (node != NULL) {
        // Exibição dos dados da musica
        printf("\nAutor: %s\nTitulo: %s\nDuração: %.2f\n", 
            node->author, 
            node->title, 
            node->length
        );

        // Variavel para armazenamento da opção escolhida pelo usuário
        int option;

        // Caso o próximo node seja vazio (não há mais músicas)
        // Limitamos as opções de entrada do usuário para reiniciar ou voltar ao menu
        if (node->next == NULL) {
            printf("\nFim da lista\n");
            printf("\n2. Inicio da lista\n3. Voltar ao menu\n");
        } else {
        // Caso ainda existam musicas a serem exibidas
        // Damos a opção de ir para a próxima musica, reiniciar a lista ou voltar ao menu
            printf("\n1. Próxima musica\n2. Inicio da lista\n3. Voltar ao menu\n");
        }

        // Ler a escolha do usuário
        scanf("%d", &option);

        // Realizar uma ação dependendo da escolha do usuário
        // 3. Encerar função e voltar ao menu
        if (option == 3) return;

        // 2. Reiniciar a lista apontando o node para o cabeçalho da lista
        if (option == 2) node = head;

        // 3. Apontar o node para o próximo item da lista, caso seja possível
        if (option == 1 && node->next) node = node->next;
    }
}


// Função para exibição do menu e chamada das outras funções
void menu()
{
    // Loop infinito para exibição do menu
    while (1)
    {   
        fflush(stdin);
        // Exibição das opções
        printf("\n-------- MENU --------\n");
        printf("1. Ver musicas\n2. Adicionar musica\n9. Sair\n");

        // Variável para armazenamento da escolha do usuário
        int option;
    
        scanf("%d", &option);
        
        // Switch usando a opção do usuário
        switch (option)
        {
            // Caso 1, exibimos as musicas
            case 1:
                showMusics();
                break;

            // Caso 2, adicionamos uma nova musica
            case 2:
                addMusic();
                break;

            // Caso 9, encerramos o programa
            case 9:
                printf("Saindo...");
                exit(0);
                break;                

            // Padrão, nada inserido, opção invalida
            default:
                printf("Opção invalida.");
                break;
        }
    }
}

int main()
{
    // Exibir menu e iniciar o programa
    menu();

    return 0;
}