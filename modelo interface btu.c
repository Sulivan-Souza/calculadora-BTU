#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gnuplot_i.h" // Biblioteca gnuplot para exibir gráficos

// Função para calcular a carga térmica do ambiente
float calculaCargaTermica(float largura, float comprimento, float altura, float temp_externa, float temp_interna, int num_pessoas, float pot_equipamentos, float iluminacao) {
    float vol = largura * comprimento * altura;
    float dif_temp = temp_interna - temp_externa;
    float carga_pessoas = num_pessoas * 100; // 100 watts por pessoa
    float carga_equipamentos = pot_equipamentos;
    float carga_iluminacao = iluminacao;
    float carga_termica = (vol * dif_temp * 60) + carga_pessoas + carga_equipamentos + carga_iluminacao;
    return carga_termica;
}

int main() {
    float largura, comprimento, altura, temp_externa, temp_interna;
    int num_pessoas;
    float pot_equipamentos, iluminacao;
    float carga_termica;

    printf("Digite a largura do ambiente em metros: ");
    scanf("%f", &largura);

    printf("Digite o comprimento do ambiente em metros: ");
    scanf("%f", &comprimento);

    printf("Digite a altura do ambiente em metros: ");
    scanf("%f", &altura);

    printf("Digite a temperatura externa em graus Celsius: ");
    scanf("%f", &temp_externa);

    printf("Digite a temperatura interna desejada em graus Celsius: ");
    scanf("%f", &temp_interna);

    printf("Digite o número de pessoas no ambiente: ");
    scanf("%d", &num_pessoas);

    printf("Digite a potência dos equipamentos em Watts: ");
    scanf("%f", &pot_equipamentos);

    printf("Digite a carga de iluminação em Watts: ");
    scanf("%f", &iluminacao);

    // Cálculo da carga térmica
    carga_termica = calculaCargaTermica(largura, comprimento, altura, temp_externa, temp_interna, num_pessoas, pot_equipamentos, iluminacao);

    printf("A carga térmica do ambiente é de %.2f BTU/h\n", carga_termica);

    // Exibição de gráfico de temperatura vs tempo
    gnuplot_ctrl *h;
    h = gnuplot_init();
    gnuplot_set_xlabel(h, "Tempo (minutos)");
    gnuplot_set_ylabel(h, "Temperatura (°C)");
    gnuplot_cmd(h, "set title 'Variação de temperatura no ambiente'");
    gnuplot_cmd(h, "set grid");
    gnuplot_cmd(h, "set term wx");
    gnuplot_cmd(h, "plot '-' with linespoints");
    for (int i = 0; i <= 60; i++) {
        float temp = temp_externa + ((temp_interna - temp_externa) / 60) * i;
        gnuplot_cmd(h, "%d %f", i, temp);
    }
    gnuplot_cmd(h, "e");
    gnuplot_close(h);

   return 0;

}