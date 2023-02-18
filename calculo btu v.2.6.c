//** 2º Semestre - Lab. Desenvolvimento II - Calculo BTU - v.2.6 - 2023/02/17 - 16:00
//** Autores: Sulivan Souza -- Luiz Pasqualetto --- Nathacha Assis
//** Descrição: Calculo de BTU para ar condicionado
//** Observações e mudanças do código:
//** 1. Adicionado a opção de calcular a BTU para residências, casas e apartamentos.
//** 2. Adicionado a opção de calcular a BTU para lajes suspensas.
//** 3. Adicionado a opção de calcular a BTU para UPS.
//** 4. Adicionado a opção de calcular a BTU para luzes.
//** 5. Adicionado a opção de calcular a BTU para equipamentos eletricos.
//** 6. Adicionado a opção de calcular a BTU para janelas.
//** 7. Adicionado a opção de calcular a BTU para pessoas.
//** 8. Adicionado a opção de calcular a BTU para regiões.
//** 9. Adicionado a opção de calcular a BTU para largura, comprimento e altura da sala.
//** 10. Adicionado a opção de calcular a BTU para área do BTU.
//** 11. Adicionado a opção de calcular a BTU para janelas com sol.
//** 12. Adicionado a opção de calcular a BTU para janelas sem sol.
//** 13. Adicionado a opção de calcular a BTU para portas.
//** 14. Adicionado a opção de calcular a BTU para aparelhos.
//** 15. Adicionado a opção de calcular a BTU para carga de equipamentos.
//** 16. Adicionado a opção de calcular a BTU para comercio.
//** 17. Temperatura desejada não é mais necessária.
//** 18. Tempo de desligamento do ar condicionado não é mais necessária?
//** 19. Tempo de desenvolvimento do código: 4 meses.


#include <stdio.h>
#include <ctype.h> // para usar a função isdigit()
#include <stdlib.h>
#include <string.h> // para usar a função fgets()
#include <locale.h> // para aceitar acentos

int main(void)
{
    int     temp_desejada, regiao, residencial = 0, casa = 0, apartamento = 0, lajes = 0, class_ups = 0, num_ups = 0, lampadas , equipamentos;
    float janelas_sol_manha, janelas_sol_tarde,  carga_equip, janelas, altura_sala, area_sala, btu_janela_manha , btu_janela_tarde ,
          btu_lajes_suspensas = 0, btu_sem_lajes_suspensas = 0, btu_janelas, btu_pessoa , btu_equipamentos , btu_ups , btu_lampadas , btu_total , btu_portas, 
          pessoas, portas,comprimento_sala, largura_sala;
    char buffer[256];
    //char string[100];
    setlocale(LC_ALL, "pt_BR.UTF-8"); //configurar a localidade para acentos

    //leitura de variaveis
    
    printf("Informe a temperatura desejada: ");
    fgets(buffer, sizeof(buffer), stdin);
    temp_desejada = strtol(buffer, NULL, 10);

    while (temp_desejada < 12 || temp_desejada > 30)
    {
        printf("Temperatura invalida. Informe uma temperatura entre 12 e 30 graus Celsius: ");
        fgets(buffer, sizeof(buffer), stdin);
        temp_desejada = strtol(buffer, NULL, 10);
    }

    printf("Informe a regiao geografica (1 - Norte, 2 - Sul, 3 - Leste, 4 - Oeste, 5 - Centro): ");
    fgets(buffer, sizeof(buffer), stdin);
    regiao = strtol(buffer, NULL, 10);
    while (regiao < 1 || regiao > 5){
        printf("Regiao invalida. Informe uma regiao entre 1 e 5: ");
        fgets(buffer, sizeof(buffer), stdin);
        regiao = strtol(buffer, NULL, 10); 
    }               

    printf("Informe se o local é residencial ou comercial? (1 - residencial, 2 - comercial): ");
        fgets(buffer, sizeof(buffer), stdin);
        residencial = strtol(buffer, NULL, 10);

    while (residencial < 1 || residencial > 2)
    {
        printf("Opcao invalida. Informe uma opcao ' 1 ' ou ' 2 ': ");
        fgets(buffer, sizeof(buffer), stdin);
        residencial = strtol(buffer, NULL, 10);
    }

    if (residencial == 1)
    {
        printf("É uma casa ou apartamento? (1 - casa, 2 - apartamento): ");
        fgets(buffer, sizeof(buffer), stdin);
        casa = strtol(buffer, NULL, 10);
        apartamento = strtol(buffer, NULL, 10);

        while (casa < 1 || casa > 2 || apartamento < 1 || apartamento > 2)
        {
            printf("Opcao invalida. Informe uma opcao ' 1 ' ou ' 2 ': ");
            fgets(buffer, sizeof(buffer), stdin);
            casa = strtol(buffer, NULL, 10);
            apartamento = strtol(buffer, NULL, 10);
        }
        lajes = strtol(buffer, NULL, 10);
             if (lajes == 1) {
            btu_lajes_suspensas = 315;
            btu_sem_lajes_suspensas = 160;
        } else {
            btu_lajes_suspensas = 0;
            btu_sem_lajes_suspensas = 0;
        }

        } else {
        printf("Informe a classificacao de potencia dos seus sistemas UPS: ");
        fgets(buffer, sizeof(buffer), stdin);
        class_ups = strtol(buffer, NULL, 10);
        printf("Informe o numero de UPS que ira utilizar: ");
        fgets(buffer, sizeof(buffer), stdin);
        num_ups = strtol(buffer, NULL, 10);
        printf("Informe a carga em watts do seu equipamento eletrico: ");
        fgets(buffer, sizeof(buffer), stdin);
        carga_equip = strtol(buffer, NULL, 10);
    }
    btu_ups = 300 * class_ups * num_ups;
    btu_equipamentos = 300 * carga_equip;


    printf("Informe quantas pessoas estarao no ambiente: ");
            fgets(buffer, sizeof(buffer), stdin);
                pessoas = strtol(buffer, NULL, 10);
                while (pessoas < 1 || pessoas > 100)
                {
                    printf("Numero de pessoas invalido. Informe um numero de pessoas entre 1 e 100: ");
                    fgets(buffer, sizeof(buffer), stdin);
                    pessoas = strtol(buffer, NULL, 10);
                }
        pessoas = pessoas - 1 * 600;
        if (pessoas < 0){
            pessoas = 0;
        }
    printf("Informe quantas janelas tem no ambiente: ");
        fgets(buffer, sizeof(buffer), stdin);
        janelas = strtol(buffer, NULL, 10);
        while (janelas < 1 || janelas > 100)
        {
            printf("Numero de janelas invalido. Informe um numero de janelas entre 1 e 50: ");
            fgets(buffer, sizeof(buffer), stdin);
            janelas = strtol(buffer, NULL, 10);
        }
    printf("Informe quantas janelas tem sol pela manhâ : ");
        fgets(buffer, sizeof(buffer), stdin);
        janelas_sol_manha = strtol(buffer, NULL, 10);
            while (janelas_sol_manha < 0)
        {
            printf("Numero de janelas invalido. Informe um numero de janelas menor ou igual ao numero de janelas do ambiente: ");
        }
    printf("Informe quantas janelas tem sol pela tarde : ");
        fgets(buffer, sizeof(buffer), stdin);
        janelas_sol_tarde = strtol(buffer, NULL, 10);
            while (janelas_sol_tarde < 0)
        {
            printf("Numero de janelas invalido. Informe um numero de janelas menor ou igual ao numero de janelas do ambiente: ");
        }
       
        switch (regiao){
            case 1://norte
                btu_janela_manha = 40 * janelas_sol_manha ;
                btu_janela_tarde = 30 * janelas_sol_tarde ;
                break;
            case 2://sul
                btu_janela_manha = 40 * janelas_sol_manha ;
                btu_janela_tarde = 30 * janelas_sol_tarde ;
                break;
            case 3://leste
                btu_janela_manha = 50 * janelas_sol_manha;
                btu_janela_tarde = 40 * janelas_sol_tarde ;
                break;
            case 4://oeste
                btu_janela_manha = 50 * janelas_sol_manha;
                btu_janela_tarde = 40 * janelas_sol_tarde
                 ;
                break;
            case 5://centro
                btu_janela_manha = 40 * janelas_sol_manha;
                btu_janela_tarde = 40 * janelas_sol_tarde;
                break;
            }
            btu_janelas = btu_janela_manha + btu_janela_tarde;

    printf("Informe a altura aproximada do ambiente: ");
        fgets(buffer, sizeof(buffer), stdin);
        altura_sala = strtol(buffer, NULL, 10);
            while(altura_sala < 2 || altura_sala > 10){
                printf("Altura invalida. Informe uma altura entre 2 e 10: ");
                fgets(buffer, sizeof(buffer), stdin);
                altura_sala = strtol(buffer, NULL, 10);
            }
        
    printf("Informe a largura do ambiente: ");
        fgets(buffer, sizeof(buffer), stdin);
        largura_sala = strtol(buffer, NULL, 10);
            while(largura_sala < 1 || largura_sala > 10){
                printf("Largura invalida. Informe uma largura entre 2 e 10: ");
                fgets(buffer, sizeof(buffer), stdin);
                largura_sala = strtol(buffer, NULL, 10);
            }
    printf("Informe o comprimento do ambiente: ");
        fgets(buffer, sizeof(buffer), stdin);
        comprimento_sala = strtol(buffer, NULL, 10);
            while(comprimento_sala < 2 || comprimento_sala > 10){
                printf("Comprimento invalido. Informe um comprimento entre 2 e 10: ");
                fgets(buffer, sizeof(buffer), stdin);
                comprimento_sala = strtol(buffer, NULL, 10);
            }
    printf("Informe a quantidade de portas do ambiente: ");
        fgets(buffer, sizeof(buffer), stdin);
        portas = strtol(buffer, NULL, 10);
            while(portas < 0 || portas > 10){
                printf("Numero de portas invalido. Informe um numero de portas entre 1 e 10: ");
                fgets(buffer, sizeof(buffer), stdin);
                portas = strtol(buffer, NULL, 10);
            }
    printf("Informe a quantidade de equipamentos eletronicos: ");
        fgets(buffer, sizeof(buffer), stdin);
        equipamentos = strtol(buffer, NULL, 10);
            while(equipamentos < 0 || equipamentos > 50){
                printf("Numero de equipamentos invalido. Informe um numero de equipamentos entre 1 e 50: ");
                fgets(buffer, sizeof(buffer), stdin);
                equipamentos = strtol(buffer, NULL, 10);
            }
    printf("Informe o numero de lampadas que ira utilizar: ");
        fgets(buffer, sizeof(buffer), stdin);
        lampadas = strtol(buffer, NULL, 10);
            while(lampadas < 0 || lampadas > 100){
                printf("Numero de lampadas invalido. Informe um numero de lampadas entre 1 e 50: ");
                fgets(buffer, sizeof(buffer), stdin);
                lampadas = strtol(buffer, NULL, 10);
            }

    //calculo de variaveis

    area_sala = altura_sala * largura_sala * comprimento_sala * 600;
    btu_pessoa = 600 * pessoas;
    btu_lampadas = 5 * lampadas;
    btu_equipamentos = 500 * equipamentos;
    btu_portas = 5 * portas;
    btu_janelas = 5 * janelas;
    btu_total = (area_sala + btu_pessoa + btu_lampadas + btu_equipamentos + btu_portas + btu_janelas + btu_lajes_suspensas + btu_sem_lajes_suspensas + btu_ups );
   
    printf(" Calculo de Btu total e de: ");
        if (btu_total <  7000 )                 {printf("7 MIL" ); }
        if (btu_total >  7000 ){if(btu_total <= 9000 ){printf("9 MIL" );}}
        if (btu_total >  9000 ){if(btu_total <= 12000){printf("12 MIL");}}
        if (btu_total >  12000){if(btu_total <= 17000){printf("17 MIL");}}
        if (btu_total >  17000){if(btu_total <= 18000){printf("18 MIL");}}
        if (btu_total >  18000){if(btu_total <= 22000){printf("22 MIL");}}
        if (btu_total >  22000){if(btu_total <= 24000){printf("24 MIL");}}
        if (btu_total >  24000){if(btu_total <= 30000){printf("30 MIL");}}
        if (btu_total >  30000){if(btu_total <= 31000){printf("31 MIL");}}
        if (btu_total >  31000){printf("32 MIL")                 ; }
        printf(" Btus\n");

        printf("\n Autores:\n\n Sulivan Souza\n Luiz Pasqualetto\n Nathacha Assis\n");
}

       
