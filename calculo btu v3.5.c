#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h> 


float calcular_potencia_necessaria(float area,float fator_regiao, int portas, float quant_equipamentos, float pot_equipamentos, 
float altura,int num_lampadas, float temp_desejada,float temp_media,float lajes, int num_pessoas,int num_janelas_sol,int num_janelas,
 float num_equipamentos, float fator_atividade) {
  
  float potencia;
  potencia = area * altura * (temp_desejada - temp_media) ;
  potencia += num_pessoas * 500;// 500 BTU's por pessoa
  potencia += num_equipamentos + quant_equipamentos * 500;// 500 BTU's por equipamento
  potencia += pot_equipamentos  * 0.1;// 10% da potencia do equipamento
  potencia *= fator_atividade;// * 1.0 leve, 1.2 moderado, 1.5 intenso
  potencia += lajes;// com lajes + 160, sem lajes + 315
  potencia += num_lampadas * 50;// 50 BTU's por lampada
  potencia += num_janelas_sol * 500;// 500 BTU's por janela
  potencia += num_janelas * 100;// 100 BTU's por janela
  potencia += portas * 100;// 100 BTU's por porta
  potencia *= fator_regiao;// * 1.0 regi?o quente, regi?o amena 1.1, regi?o moderada 1.2, 1.3 regi?o fria, 1.4 regi?o muito fria
  return potencia;
  }

int main() 
{
  

  int tipo_ambiente,portas,regiao, ambiente, opcao, num_pessoas, tipo_atividade,possui_lajes,num_lampadas, num_janelas_sol, num_janelas, janelas;
  float comprimento,fator_regiao, pot_equipamentos, largura,num_equipamentos, quant_equipamentos, altura, area,lajes, temp_desejada, temp_media, potencia_total, fator_atividade;
  char buffer[256] ; 
  char s = 's';
  char n = 'n';
  char  continuar = s;
  int inicio = 1;

  while(continuar != n)
  {
    system("cls");

    
    while (inicio)  {
    
   
    printf("\n%30s Calculadora de Potencia de Ar Condicionado\n",""); 
  
   
    printf("\n%48s 2023 \n","");
    Sleep(3500);
    system("cls");
   
      printf("%30s Por favor, informe os dados solicitados a seguir:\n\n","");
      printf("\n%30s pressione qualquer tecla para continuar\n","");
      
       Sleep(2000);
        printf("\n%30s Aguardando o usuario ........","");
      Sleep(3000);
      
      system("cls");
      
      if (_kbhit()){
        inicio = 0;
        getchar();
        }
     }
      
    system("cls");  
    

    //tipo de ambiente/residencial/comercial
    printf("O local e Residencial ou Comercial (1 para Residencial, 2 para Comercial): ");
    fgets(buffer, sizeof(buffer), stdin);

    tipo_ambiente = strtol(buffer, NULL, 10);

    while(tipo_ambiente != 1 && tipo_ambiente != 2) 
    {
      printf("Tipo de Local invalido. Por favor, informe novamente (1 para Residencial, 2 para Comercial): ");
      fgets(buffer, sizeof(buffer), stdin);

      tipo_ambiente = strtol(buffer, NULL, 10);
    }

    //codigo residencial/casa/apartamento
    if(tipo_ambiente == 1)
    { 
      system("cls");

      printf(" Casa ou Apartamento? (1 para Casa, 2 para Apartamento): ");
      fgets(buffer, sizeof(buffer), stdin);

      ambiente = strtol(buffer, NULL, 10);
              
      while(ambiente != 1 && ambiente != 2)
      { 
        printf("Escolha invalida. Por Favor tente novamente (1 para Casa, 2 para Apartamento): ");
        fgets(buffer, sizeof(buffer), stdin);

        ambiente = strtol(buffer, NULL, 10);
      }
            
      //codigo ambiente/residencial/casa
      if(ambiente == 1)
      { 
        system("cls");

        printf("A Casa possui lajes suspensas (1 possui lajes, 2 Nao possui lajes): ");
        fgets(buffer, sizeof(buffer), stdin);

        possui_lajes = strtol(buffer, NULL, 10);
        
        while(possui_lajes != 1 && possui_lajes != 2 )
        {
          printf(" Escolha invalida, Por favor tente novamente (1 para Possui, 2 para Nao possui): ");
          fgets(buffer, sizeof(buffer), stdin);
          possui_lajes = strtol(buffer, NULL, 10);
        }

        if(possui_lajes == 1)
        { 
          lajes = 160;
        }
        if(possui_lajes == 2)
        { 
          lajes = 315;
        }
      } 
      
      //codigo ambiente/residencial/apartamento
      if(ambiente == 2)
      {
        lajes = 160;
      }          
    }

    //codigo tipo ambiente/comercial/lajes suspensas
    if(tipo_ambiente == 2)
    {  
      system("cls");
      printf("O Comercial possui lajes suspensas (  1 possui lajes,  2 Nao possui lajes): ");
      fgets(buffer, sizeof(buffer), stdin);
      
      possui_lajes = strtol(buffer, NULL, 10);
      
      while(possui_lajes != 1 && possui_lajes != 2 )
      {
        printf(" Escolha invalida, Por favor tente novamente (1 para Possui, 2 para Nao possui): ");
        fgets(buffer, sizeof(buffer), stdin);

        possui_lajes = strtol(buffer, NULL, 10);
      }

      if(possui_lajes == 1)
      {
        lajes = 160;
      }
      if(possui_lajes == 2)
      { 
        lajes = 315;
      }
    }
    
    //equipamentos UPS/quantidade de equipamentos UPS/potencia do equipamento UPS
    system("cls");

    printf("Possui equipamentos com fonte de alimentacao ininterrupta? (1 para Sim, 2 para Nao): ");
    fgets(buffer, sizeof(buffer), stdin);

    opcao = strtol(buffer, NULL, 10);
    
    while(opcao != 1 && opcao != 2)
    {
      printf("Opcao invalida, Por favor tente novamente (1 para Sim, 2 para Nao): ");
      fgets(buffer, sizeof(buffer), stdin);

      opcao = strtol(buffer, NULL, 10);
    }

    //codigo para ter equipamentos UPS
    if(opcao == 1)
    {
      system("cls");
      printf("Qual a quantidade de equipamentos UPS possui: ");
      fgets(buffer, sizeof(buffer), stdin);

      quant_equipamentos = strtol(buffer, NULL, 10);

      while(quant_equipamentos < 0)
      {
        printf("Quantidade invalida, Por favor tente novamente: ");
        fgets(buffer, sizeof(buffer), stdin);

        quant_equipamentos = strtol(buffer, NULL, 10);
      }

      //codigo para potencia do equipamento UPS
      system("cls");

      printf("Qual a  potencia somada de todos equipamento UPS: ");
      fgets(buffer, sizeof(buffer), stdin);

      pot_equipamentos = strtol(buffer, NULL, 10);

      while(pot_equipamentos < 0)
      {
        printf("Potencia invalida, Por favor tente novamente: ");
        fgets(buffer, sizeof(buffer), stdin);

        pot_equipamentos = strtol(buffer, NULL, 10);
      }
    }
                
    //codigo para nao ter equipamentos UPS
    if(opcao == 2)
    {
      quant_equipamentos = 0;
    }

    //codigo area do ambiente

    //comprimento
    system("cls");

    printf("Informe o comprimento do ambiente em metros: ");
    fgets(buffer, sizeof(buffer), stdin);

    comprimento = strtol(buffer, NULL, 10);

    while(comprimento < 0)
    {
      printf("Informacao invalida, Por favor tente novamente: ");
      fgets(buffer, sizeof(buffer), stdin);

      comprimento = strtol(buffer, NULL, 10);
    }

    //largura
    system("cls");

    printf("Informe a largura do ambiente em metros: ");
    fgets(buffer, sizeof(buffer), stdin);

    largura = strtol(buffer, NULL, 10);

    while(largura < 0)
    {
      printf("Informacao invalida, Por favor tente novamente ");
      fgets(buffer, sizeof(buffer), stdin);

      largura = strtol(buffer, NULL, 10);
    }

    //altura
    system("cls");

    printf("Informe a altura do ambiente em metros: ");
    fgets(buffer, sizeof(buffer), stdin);

    altura = strtol(buffer, NULL, 10);

    while(altura < 0)
    {
      printf(" Informacao invalida, Por favor tente novamente ");
      fgets(buffer, sizeof(buffer), stdin);

      altura = strtol(buffer, NULL, 10);
    }
    
    area = comprimento * largura;

    //codigo para temperatura ambiente
    //temperatura desejada
    system("cls");

    printf("Informe qual a temperatura desejada ambiente, em graus Celsius: ");
    fgets(buffer, sizeof(buffer), stdin);

    temp_desejada = strtol(buffer, NULL, 10);

    while(temp_desejada < 0 || temp_desejada > 45)
    {
      printf("Temperatura invalida, Por favor tente novamente: ");
      fgets(buffer, sizeof(buffer), stdin);

      temp_desejada = strtol(buffer, NULL, 10);
    }
    
    //temperatura ambiente
    system("cls");

    printf("Informe a temperatura media do ambiente, em graus Celsius: ");
    fgets(buffer, sizeof(buffer), stdin);

    temp_media = strtol(buffer, NULL, 10);

    while(temp_media < 0 || temp_media > 45)
    {
      printf("Temperatura invalida, Por favor tente novamente: ");
      fgets(buffer, sizeof(buffer), stdin);

      temp_media = strtol(buffer, NULL, 10);
    }
    
    //codigo para quantidade de pessoas
    system("cls");

    printf("Informe a quantidade media de pessoas que circulara no ambiente: ");
    fgets(buffer, sizeof(buffer), stdin);
    
    num_pessoas = strtol(buffer, NULL, 10);
    
    while(num_pessoas < 0)
    {
      printf("Quantidade invalida, Por favor tente novamente: ");
      fgets(buffer, sizeof(buffer), stdin);
                
      num_pessoas = strtol(buffer, NULL, 10);
    }

    //codigo para quantidade de lampadas
    system("cls");

    printf("Informe a quantidade de lampadas: ");
    fgets(buffer, sizeof(buffer), stdin);

    num_lampadas = strtol(buffer, NULL, 10);

    while(num_lampadas < 0)
    {
        printf("Quantidade invalida, Por favor tente novamente: ");
        fgets(buffer, sizeof(buffer), stdin);

        num_lampadas = strtol(buffer, NULL, 10);
    }

    //codigo para equipamentos eletronicos
    system("cls");

    printf("Informe a quantidade de equipamentos eletronicos('computadores, TV , etc...'): ");
    fgets(buffer, sizeof(buffer), stdin);

    num_equipamentos = strtol(buffer, NULL, 10);

    while(num_equipamentos < 0)
    {
        printf("Quantidade invalida, Por favor tente novamente: ");
        fgets(buffer, sizeof(buffer), stdin);

        num_equipamentos = strtol(buffer, NULL, 10);
    }

    //codigo para tipo de uso do ambiente
    system("cls");

    printf("Informe o tipo de atividade no ambiente (1 para Leve, 2 para Moderado, 3 para Intenso): ");
    fgets(buffer, sizeof(buffer), stdin);

    tipo_atividade = strtol(buffer, NULL, 10);

    while(tipo_atividade != 1 && tipo_atividade != 2 && tipo_atividade != 3)
    {
        printf("Tipo de atividade inv?lido. Por favor, informe novamente (1 para Leve, 2 para Moderado, 3 para Intenso): ");
        fgets(buffer, sizeof(buffer), stdin);

        tipo_atividade = strtol(buffer, NULL, 10);
    }

    switch(tipo_atividade) 
    {
        case 1:
        fator_atividade = 1.0;
        break;

        case 2:
        fator_atividade = 1.2;
        break;

        case 3:
        fator_atividade = 1.5;
        break;

        default:
        printf("Tipo de atividade inv?lido. Usando fator de atividade Moderado\n");
        fator_atividade = 1.2;
        break;
    }

    //codigo para quantidade de janelas
    system("cls");

    printf("O Ambiente possuiu janelas: ( 1 - Sim  2 - Nao ): ");
    fgets(buffer, sizeof(buffer), stdin);

    janelas = strtol(buffer, NULL, 10);

    while(janelas != 1 && janelas != 2)
    {
        printf("Opcao invalida, Por favor tente novamente: ");
        fgets(buffer, sizeof(buffer), stdin);

        janelas = strtol(buffer, NULL, 10);
    }
    if(janelas == 1)
    { 
        system("cls");
        
        printf("Informe a quantidade de janelas: ");
        fgets(buffer, sizeof(buffer), stdin);

        num_janelas = strtol(buffer, NULL, 10);

        while(num_janelas < 0)
        {
            printf("Quantidade invalida, Por favor tente novamente: ");
            fgets(buffer, sizeof(buffer), stdin);

            num_janelas = strtol(buffer, NULL, 10);
        }

        system("cls");

        printf(" Quantas janelas tem insidencia direta de sol: ");
        fgets(buffer, sizeof(buffer), stdin);

        num_janelas_sol = strtol(buffer, NULL, 10);

        while(num_janelas_sol < 0 || num_janelas_sol > num_janelas)
        {
            printf("Quantidade invalida, Por favor tente novamente: ");
            fgets(buffer, sizeof(buffer), stdin);

            num_janelas_sol = strtol(buffer, NULL, 10);
        }
    }
    else
    {
    num_janelas = 0;
    }

    //codigo para quantidade de portas
    system("cls");

    printf("Quantas portas possui o ambiente:");
    fgets(buffer, sizeof(buffer), stdin);

    portas = strtol(buffer, NULL, 10);
    
    while(portas <= 0 )
    {
        printf("Opcao invalida, Por favor tente novamente: ");
        fgets(buffer, sizeof(buffer), stdin);

        portas = strtol(buffer, NULL, 10);
    }

    //codigo para regiao
    system("cls");

    printf("Informe a regiao do pais (1 para Norte, 2 para Nordeste, 3 para Centro-Oeste, 4 para Sudeste, 5 para Sul): ");
    fgets(buffer, sizeof(buffer), stdin);

    regiao = strtol(buffer, NULL, 10);

    while(regiao != 1 && regiao != 2 && regiao != 3 && regiao != 4 && regiao != 5)
    {
        printf("Regiao invalida, Por favor tente novamente: ");
        fgets(buffer, sizeof(buffer), stdin);

        regiao = strtol(buffer, NULL, 10);
    }

    switch (regiao) 
    {
        case 1:
        fator_regiao = 1.0;
        break;

        case 2:
        fator_regiao = 1.1;
        break;

        case 3:
        fator_regiao = 1.2;
        break;

        case 4:
        fator_regiao = 1.3;
        break;
                
        case 5:
        fator_regiao = 1.4;
        break;
                
        default:
        printf("Regiao invalida. Usando fator de regiao Sudeste\n");
        fator_regiao = 1.3;
        break;
    } 

          
    //calculo de potencia
    potencia_total = calcular_potencia_necessaria
    (area,portas,fator_regiao, num_lampadas,altura,temp_media,temp_desejada,num_pessoas,num_equipamentos,fator_atividade, 
    pot_equipamentos,quant_equipamentos,lajes, num_janelas_sol,num_janelas);

    system("cls");
    printf(" \n Voce ira precisar de um equipamento com: ");
    if(potencia_total <  7000 )
    {
        printf("7 MIL" ); 
    }

    if(potencia_total >  7000 )
    {
        if(potencia_total <= 9000 )
        {
            printf("9 MIL" );
        }
    }

    if(potencia_total >  9000 )
    {
        if(potencia_total <= 12000)
        {
            printf("12 MIL");
        }
    }

    if(potencia_total >  12000)
    {
        if(potencia_total <= 17000)
        {
            printf("17 MIL");
        }
    }

    if(potencia_total >  17000)
    {
        if(potencia_total <= 18000)
        {
            printf("18 MIL");
        }
    }

    if(potencia_total >  18000)
    {
        if(potencia_total <= 22000)
        {
            printf("22 MIL");
        }
    }

    if(potencia_total >  22000)
    {
        if(potencia_total <= 24000)
        {
            printf("24 MIL");
        }
    }

    if(potencia_total >  24000)
    {
        if(potencia_total <= 30000)
        {
            printf("30 MIL");
        }
    }

    if(potencia_total >  30000)
    {
        if(potencia_total <= 48000)
        {
            printf("32 MIL");
        }
    }

    if(potencia_total >  48000)
    {
        if(potencia_total <= 50000)
        {
            printf("50 MIL");
        }
    }

    if(potencia_total >  50000)
    {
        if(potencia_total <= 60000)
        {
            printf("60 MIL");
        }
    }

    if(potencia_total >  60000)
    {
        if(potencia_total <= 70000)
        {
            printf("70 MIL");
        }
    }

    if(potencia_total >  70000)
    {
        if(potencia_total <= 80000)
        {
            printf("80 MIL");
        }
    }

    if(potencia_total >  80000)
    {
        if(potencia_total <= 90000)
        {
            printf("90 MIL");
        }
    }

    if(potencia_total >  90000)
    {
        if(potencia_total <= 100000)
        {
            printf("100 MIL");
        }
    }

    if(potencia_total >  100000)
    {
       {
            printf("mais de 100 MIL");
        }
    }
        
    printf(" BTUs/h\n");
          
    // Converte BTU/h para watt
    float kilowatts = potencia_total * 0.00029307107;
    printf(" Potencia Total do equipamento em Kw/h e de: %.2f\n\n", kilowatts);

    printf("pressione enter para continuar\n");
    getchar();

    system("cls");  

    printf("\nDeseja Realizar outro calculo ? (s/n):");
    scanf("%c", &continuar);

    while (continuar != 's' && continuar != 'n') 
    {
        printf("Resposta invalida. Deseja calcular novamente? (s/n) ");
        scanf(" %c", &continuar);
    }
  }//while return

  return 0;
}/*main*/


