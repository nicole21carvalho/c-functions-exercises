#!/usr/bin/env bash
# Compila todos os exercícios e confere cada caso de teste em tests/.
#
# Cada caso é um par de arquivos:
#   tests/<exercicio>.<caso>.in   → o que é digitado no teclado
#   tests/<exercicio>.<caso>.out  → o que o programa deve mostrar
#
# Uso: ./run_tests.sh        (CC=clang ./run_tests.sh para trocar o compilador)
set -u

CC="${CC:-gcc}"
CFLAGS="-std=c11 -Wall -Wextra -Wpedantic -Werror -O2"
cd "$(dirname "$0")"
mkdir -p build

falhas=0
total=0

for fonte in src/ex*.c; do
    nome="$(basename "$fonte" .c)"
    if ! $CC $CFLAGS -o "build/$nome" "$fonte" -lm; then
        echo "✖ $nome não compilou"
        falhas=$((falhas + 1))
    fi
done

for entrada in tests/*.in; do
    caso="$(basename "$entrada" .in)"
    programa="build/${caso%%.*}"
    esperado="tests/$caso.out"
    total=$((total + 1))

    obtido="$("$programa" < "$entrada" | tr -d '\r')"
    if [ "$obtido" == "$(tr -d '\r' < "$esperado")" ]; then
        echo "✔ $caso"
    else
        echo "✖ $caso"
        diff <(echo "$obtido") <(tr -d '\r' < "$esperado") | sed 's/^/    /'
        falhas=$((falhas + 1))
    fi
done

echo
if [ "$falhas" -eq 0 ]; then
    echo "Todos os $total casos passaram."
else
    echo "$falhas falha(s) em $total casos."
    exit 1
fi
