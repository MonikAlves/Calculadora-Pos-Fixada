# Calculadora de Notação Polonesa Pós-Fixada (RPN)

## Descrição
Este projeto implementa uma calculadora que utiliza a **Notação Polonesa Pós-Fixada** (ou **Reverse Polish Notation**, RPN). A calculadora permite realizar operações matemáticas básicas como adição, subtração, multiplicação, divisão e exponenciação utilizando uma pilha para processar as expressões.

### Operações suportadas:
- `+` (adição)
- `-` (subtração)
- `*` (multiplicação)
- `/` (divisão)
- `^` (exponenciação)

### Exemplo de expressões pós-fixadas:
- `3 4 +` → (Resultado: 7)
- `5 9 2 * +` → (Resultado: 23)
- `9 5 3 + 2 4 ^ - +` → (Resultado: 1)

## Como Executar

1. Clone o repositório para sua máquina local:
    ```bash
   git clone https://github.com/MonikAlves/PostFix-Calculator
    ```

2. Compile o programa utilizando o GCC:
    ```bash
    gcc main.c -o calculator -lm
    ```

3. Execute o programa no terminal:
    ```bash
    ./calculator
    ```
