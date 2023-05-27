#include <stdio.h>
#include <stdlib.h>

float calcula_btus(float area, float altura, float temp_desejada, float temp_media, int pessoas, int equipamentos, float fator_atividade) {
    float btus;
    btus = area * altura * (temp_desejada - temp_media) * 60;
    btus += pessoas * 600;
    btus += equipamentos * 600;
    btus *= fator_atividade;
    return btus;
}

int main() {
    int tipo_ambiente, pessoas, equipamentos, tipo_atividade;
    float comprimento, largura, altura,area_ambiente, temp_desejada, temp_media, btus_totais, fator_atividade;

    char buffer[10];

    printf("Informe o tipo de ambiente (1 para residencial, 2 para comercial): ");
        fgets(buffer, sizeof(buffer), stdin);
        tipo_ambiente = strtol(buffer, NULL, 10);

    if (tipo_ambiente == 1) {
        printf("Informe a largura do ambiente em metros: ");
        fgets(buffer, sizeof(buffer), stdin);
        largura = strtof(buffer, NULL);

        printf("Informe o comprimento do ambiente em metros: ");
        fgets(buffer, sizeof(buffer), stdin);
        comprimento = strtof(buffer, NULL);

        //printf("A área do ambiente é: %.2f metros quadrados\n", largura * comprimento);
        area_ambiente = largura * comprimento;

    } else if (tipo_ambiente == 2) {
        printf("Informe a altura do ambiente em metros: ");
        fgets(buffer, sizeof(buffer), stdin);
        altura = strtof(buffer, NULL);

        printf("Informe a temperatura desejada em graus Celsius: ");
        fgets(buffer, sizeof(buffer), stdin);
        temp_desejada = strtof(buffer, NULL);

        printf("Informe a temperatura média em graus Celsius: ");
        fgets(buffer, sizeof(buffer), stdin);
        temp_media = strtof(buffer, NULL);

        printf("Informe o número de pessoas que frequentam o ambiente: ");
        fgets(buffer, sizeof(buffer), stdin);
        pessoas = strtol(buffer, NULL, 10);

        printf("Informe o número de equipamentos elétricos presentes no ambiente: ");
        fgets(buffer, sizeof(buffer), stdin);
        equipamentos = strtol(buffer, NULL, 10);

        printf("Informe o tipo de atividade realizada no ambiente (1 para escritório, 2 para loja, 3 para restaurante): ");
        fgets(buffer, sizeof(buffer), stdin);
        tipo_atividade = strtol(buffer, NULL, 10);

        if (tipo_atividade == 1) {
            fator_atividade = 1.0;
        } else if (tipo_atividade == 2) {
            fator_atividade = 1.1;
        } else if (tipo_atividade == 3) {
            fator_atividade = 1.5;
        } else {
            printf("Tipo de atividade inválido!\n");
            return 1; // retorna valor diferente de zero para indicar erro
        }

        btus_totais = calcula_btus(largura * comprimento, altura, temp_desejada, temp_media, pessoas, equipamentos, fator_atividade);

        printf("A quantidade de BTUs necessária é: %.2f BTUs\n", btus_totais);
    } else {
        printf("Tipo de ambiente inválido!\n");
        return 1; // retorna
    }

    return 0; // retorna zero para indicar sucesso
}

