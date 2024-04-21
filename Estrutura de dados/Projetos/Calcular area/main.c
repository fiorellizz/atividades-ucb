#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "funcoes.c"

int main() {

    FILE *arquivo;
    int ponto;

    arquivo = fopen("pontos.txt", "r");
    system("cls");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(ERRO);
    }

    fscanf(arquivo, "%d", &ponto);
    struct pontos vertices[ponto];
    
    for (int i = 0; i < ponto; i++) fscanf(arquivo, "%f %f", &vertices[i].x, &vertices[i].y);

    float area = areaTriangulo(vertices, ponto);

    printf("A área do polígono é %.0f", area);
    fclose(arquivo);

    return 0;
}