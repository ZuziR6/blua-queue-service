#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50

typedef struct Node {
    char nome[MAX_NAME];
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

typedef struct Stack {
    Node* top;
} Stack;

// ================= FILA =================

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, char nome[]) {

    Node* novo = malloc(sizeof(Node));

    strcpy(novo->nome, nome);
    novo->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = novo;
        q->rear = novo;
    } else {
        q->rear->next = novo;
        q->rear = novo;
    }

    printf("\nPaciente %s entrou na fila.\n", nome);
}

char* dequeue(Queue* q) {

    if (isQueueEmpty(q)) {
        return NULL;
    }

    Node* temp = q->front;

    char* nome = malloc(MAX_NAME);

    strcpy(nome, temp->nome);

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);

    return nome;
}

void peekQueue(Queue* q) {

    if (isQueueEmpty(q)) {
        printf("\nFila vazia.\n");
        return;
    }

    printf("\nPróximo paciente: %s\n", q->front->nome);
}

// ================= PILHA =================

void initStack(Stack* s) {
    s->top = NULL;
}

int isStackEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, char nome[]) {

    Node* novo = malloc(sizeof(Node));

    strcpy(novo->nome, nome);

    novo->next = s->top;
    s->top = novo;
}

void showHistory(Stack* s) {

    if (isStackEmpty(s)) {
        printf("\nHistórico vazio.\n");
        return;
    }

    Node* atual = s->top;

    printf("\n===== HISTÓRICO =====\n");

    while (atual != NULL) {
        printf("%s\n", atual->nome);
        atual = atual->next;
    }
}

// ================= MAIN =================

int main() {

    Queue filaNormal;
    Queue filaEmergencia;
    Stack historico;

    initQueue(&filaNormal);
    initQueue(&filaEmergencia);
    initStack(&historico);

    int opcao;
    char nome[MAX_NAME];

    while (1) {

        printf("\n=========================\n");
        printf(" SISTEMA BLUA CARE PLUS\n");
        printf("=========================\n");

        printf("1 - Adicionar paciente normal\n");
        printf("2 - Adicionar emergência\n");
        printf("3 - Atender paciente\n");
        printf("4 - Ver próximo paciente\n");
        printf("5 - Ver histórico\n");
        printf("0 - Sair\n");

        printf("\nEscolha: ");
        scanf("%d", &opcao);

        getchar();

        switch(opcao) {

            case 1:

                printf("Nome do paciente: ");
                fgets(nome, MAX_NAME, stdin);

                nome[strcspn(nome, "\n")] = 0;

                enqueue(&filaNormal, nome);

                break;

            case 2:

                printf("Nome da emergência: ");
                fgets(nome, MAX_NAME, stdin);

                nome[strcspn(nome, "\n")] = 0;

                enqueue(&filaEmergencia, nome);

                break;

            case 3: {

                char* atendido;

                if (!isQueueEmpty(&filaEmergencia)) {

                    atendido = dequeue(&filaEmergencia);

                    printf("\n[EMERGÊNCIA] %s atendido.\n", atendido);

                } else if (!isQueueEmpty(&filaNormal)) {

                    atendido = dequeue(&filaNormal);

                    printf("\n%s atendido.\n", atendido);

                } else {

                    printf("\nFila vazia.\n");
                    break;
                }

                push(&historico, atendido);

                free(atendido);

                break;
            }

            case 4:

                if (!isQueueEmpty(&filaEmergencia)) {

                    printf("\nEmergência:\n");
                    peekQueue(&filaEmergencia);

                } else {

                    printf("\nFila normal:\n");
                    peekQueue(&filaNormal);
                }

                break;

            case 5:

                showHistory(&historico);

                break;

            case 0:

                printf("\nSistema encerrado.\n");
                return 0;

            default:

                printf("\nOpção inválida.\n");
        }
    }
}