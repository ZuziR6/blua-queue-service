# Sprint - Estruturas de Dados Aplicadas à Saúde Digital

## Descrição

Projeto desenvolvido para simular o gerenciamento de atendimentos remotos da plataforma Blua da Care Plus.

O sistema utiliza:

- Fila FIFO para pacientes normais
- Fila prioritária para emergências
- Pilha LIFO para histórico de consultas

Todas as estruturas foram implementadas manualmente utilizando listas encadeadas em linguagem C.

---

## Funcionalidades

- Adicionar pacientes na fila normal
- Adicionar pacientes em emergência
- Atender pacientes
- Visualizar próximo atendimento
- Visualizar histórico de consultas

---

## Estruturas utilizadas

### Fila (FIFO)
Primeiro a entrar, primeiro a sair.

Operações:
- enqueue
- dequeue
- peek
- is_empty

### Pilha (LIFO)
Último a entrar, primeiro a sair.

Operações:
- push
- pop
- peek
- is_empty

---

## Tecnologias

- Linguagem C
- Ponteiros
- Listas encadeadas
- Alocação dinâmica com malloc

---

## Como executar

1. Compile o arquivo `main.c`
2. Execute o programa
3. Utilize o menu interativo

---

## Cenários demonstrados

1. Atendimento FIFO
2. Emergência prioritária
3. Histórico de consultas utilizando pilha
