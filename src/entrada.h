/*
 * entrada.h: leitura segura do teclado, compartilhada pelos exercícios.
 *
 * O scanf("%d") puro entra em loop infinito quando a pessoa digita uma letra
 * e não aceita vírgula como separador decimal. Estas funções leem a linha
 * inteira, validam e pedem de novo quando o valor é inválido.
 */
#ifndef ENTRADA_H
#define ENTRADA_H

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

/* Faz o console do Windows mostrar acentos corretamente (UTF-8). */
static inline void configurar_console(void) {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}

/* Lê uma linha sem o '\n' final. Encerra o programa se a entrada acabar. */
static inline void ler_linha(const char *mensagem, char *destino, size_t tamanho) {
    printf("%s", mensagem);
    fflush(stdout);
    if (fgets(destino, (int)tamanho, stdin) == NULL) {
        printf("\nEntrada encerrada.\n");
        exit(EXIT_FAILURE);
    }
    destino[strcspn(destino, "\r\n")] = '\0';
}

static inline int linha_vazia_depois(const char *fim) {
    while (isspace((unsigned char)*fim)) fim++;
    return *fim == '\0';
}

static inline int ler_int(const char *mensagem) {
    char linha[128];
    for (;;) {
        ler_linha(mensagem, linha, sizeof linha);
        char *fim;
        errno = 0;
        long valor = strtol(linha, &fim, 10);
        if (fim != linha && linha_vazia_depois(fim) && errno == 0 &&
            valor >= INT_MIN && valor <= INT_MAX) {
            return (int)valor;
        }
        printf("Valor inválido. Digite um número inteiro.\n");
    }
}

/* Aceita tanto "7.5" quanto "7,5". */
static inline double ler_double(const char *mensagem) {
    char linha[128];
    for (;;) {
        ler_linha(mensagem, linha, sizeof linha);
        for (char *c = linha; *c; c++) {
            if (*c == ',') *c = '.';
        }
        char *fim;
        errno = 0;
        double valor = strtod(linha, &fim);
        if (fim != linha && linha_vazia_depois(fim) && errno == 0) {
            return valor;
        }
        printf("Valor inválido. Digite um número.\n");
    }
}

/* Lê um único caractere entre as opções permitidas (sem diferenciar maiúscula). */
static inline char ler_opcao(const char *mensagem, const char *opcoes) {
    char linha[128];
    for (;;) {
        ler_linha(mensagem, linha, sizeof linha);
        char *c = linha;
        while (isspace((unsigned char)*c)) c++;
        char escolha = (char)toupper((unsigned char)*c);
        if (escolha != '\0' && linha_vazia_depois(c + 1) && strchr(opcoes, escolha) != NULL) {
            return escolha;
        }
        printf("Opção inválida. Use uma destas: %s\n", opcoes);
    }
}

#endif
