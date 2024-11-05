#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>

#define TAM 256

typedef unsigned char byte;

typedef struct noLista
{
    byte caracter;            
    unsigned int frequencia;  
    struct noLista *esquerda;
    struct noLista *direita; 
    struct noLista *proximo;  
} noLista;

typedef struct
{
    noLista *inicio; 
    int tamanho;     
} Lista;

//FUNCOES PARA MANIPULAÇÃO DA LISTA
void iniciar_lista(Lista *lista);
void inserir_na_lista(noLista *novo, Lista *lista);
noLista *remover_da_lista(Lista *lista);
void preencher_lista(Lista *lista, unsigned int *tabela_frequencias);
void libera_lista(Lista *lista);

//FUNCOES QUE MANIPULAM A ARVORE 
noLista *construir_arvore_huffman(Lista *lista);
void gerar_codigos_huffman(noLista *raiz, char *codigo_atual, int profundidade, char codigos[TAM][TAM]);
void serializar_arvore(FILE *arquivo, noLista *raiz);
noLista *desserializar_arvore(FILE *arquivo);

//FUNCOES PARA COMPRESSAO E DESCOMPRESSAO
void codificar(char codigos[TAM][TAM], const char *nome_arquivo_comprimido, FILE *arquivo_original, noLista *raiz);
void descompactar(const char *nome_arquivo_comprimido);

#endif 
