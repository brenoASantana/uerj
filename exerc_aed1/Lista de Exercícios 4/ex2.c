#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15

// Definição da estrutura da pilha
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Função para inicializar a pilha
void initialize(Stack *s) {
    s->top = -1;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Função para verificar se a pilha está cheia
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Função para inserir um elemento na pilha
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Erro: pilha cheia\n");
        return;
    }
    s->items[++s->top] = value;
}

// Função para remover um elemento da pilha
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Erro: pilha vazia\n");
        exit(1);
    }
    return s->items[s->top--];
}

int main() {
    Stack s;
    initialize(&s);

    int i, num;
    printf("Digite 15 números:\n");
    for (i = 0; i < 15; i++) {
        scanf("%d", &num);

        if (num % 2 == 0) {
            // Se o número for par, insere na pilha
            push(&s, num);
        } else {
            // Se o número for ímpar, retira um número da pilha
            if (!isEmpty(&s)) {
                pop(&s);
            } else {
                printf("Erro: tentativa de remover de pilha vazia\n");
                exit(1);
            }
        }
    }

    // Imprime os elementos restantes na pilha
    printf("Elementos restantes na pilha:\n");
    while (!isEmpty(&s)) {
        printf("%d\n", pop(&s));
    }

    return 0;
}
