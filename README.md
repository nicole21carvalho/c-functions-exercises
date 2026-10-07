# 🔧 Funções em C

[![CI](https://github.com/nicole21carvalho/c-functions-exercises/actions/workflows/ci.yml/badge.svg)](https://github.com/nicole21carvalho/c-functions-exercises/actions/workflows/ci.yml)

Exercícios de **funções em linguagem C**: parâmetros, retorno, recursão e validação de entrada. Cada programa separa a lógica numa função própria, lê o teclado de forma segura e tem casos de teste automatizados, rodando no CI com **GCC e Clang**.

## 📚 Exercícios

| # | Arquivo | O que faz | Conceito |
|---|---|---|---|
| 1 | [`ex01_menor.c`](src/ex01_menor.c) | Mostra o menor entre dois números | operador ternário |
| 2 | [`ex02_distancia.c`](src/ex02_distancia.c) | Distância euclidiana entre dois pontos | `math.h` (`hypot`) |
| 3 | [`ex03_potencia.c`](src/ex03_potencia.c) | Base elevada a um expoente | recursão |
| 4 | [`ex04_absoluto.c`](src/ex04_absoluto.c) | Valor absoluto de 5 números | função dentro de laço |
| 5 | [`ex05_soma_divisores.c`](src/ex05_soma_divisores.c) | Soma dos divisores de 5 números positivos | validação e otimização |
| 6 | [`ex06_medias.c`](src/ex06_medias.c) | Média aritmética, ponderada ou harmônica de 3 notas | parâmetro de saída (ponteiro) |
| 7 | [`ex07_par_impar.c`](src/ex07_par_impar.c) | Diz se um número é par ou ímpar | `bool` |
| 8 | [`ex08_sinal.c`](src/ex08_sinal.c) | Diz se um número é positivo, negativo ou zero | retorno com código |

## 🧠 Decisões técnicas

- **Leitura segura do teclado ([`entrada.h`](src/entrada.h)):** o `scanf("%d")` entra em loop infinito quando alguém digita uma letra. As funções `ler_int`, `ler_double` e `ler_opcao` leem a linha inteira com `fgets`, validam com `strtol`/`strtod` e pedem o valor de novo quando ele é inválido. Também aceitam vírgula como separador decimal (`7,5`).
- **Sem "valor mágico" de erro:** a média do exercício 6 devolve `bool` e grava o resultado por ponteiro. Antes, `-1` significava erro, mas `-1` também pode ser uma média de verdade.
- **Casos especiais tratados:** média harmônica com nota zero (divisão por zero), potência com expoente 0 e resultados que não cabem num `int` (`long long`).
- **Soma de divisores em O(√n):** só testa até a raiz quadrada, somando cada divisor e o seu par (`n / i`).
- **Acentos no Windows:** os arquivos estão em UTF-8 e o programa configura o console com `SetConsoleOutputCP`, para os acentos aparecerem certos.

## ✅ Testes

Cada caso em [`tests/`](tests) é um par de arquivos: o `.in` tem o que é digitado no teclado e o `.out` tem a saída esperada. O [`run_tests.sh`](run_tests.sh) compila tudo com `-Wall -Wextra -Wpedantic -Werror` e compara as saídas. São **21 casos**, incluindo entradas inválidas.

```bash
./run_tests.sh               # com GCC
CC=clang ./run_tests.sh      # com Clang
```

## 🚀 Como executar um exercício

```bash
gcc -std=c11 -Wall -o ex06 src/ex06_medias.c -lm
./ex06
```

## 📁 Estrutura

```
src/       → exercícios e o cabeçalho de leitura segura
tests/     → entradas e saídas esperadas de cada caso
run_tests.sh
.github/workflows/ci.yml   → CI com GCC e Clang
```
