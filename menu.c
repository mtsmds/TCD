#include <stdio.h>
int main()
{
    int Numero, NumeroSub;
    int n, acaofeita = 0, algoritmoexecutado = 0;
    int V[100], tam = 100;

    do
    {
        
    printf ("\n1. Carregar arquivo de dados\n2. Buscar elemento\n3. Ordenar dados\n4. Gerar relatorio (Log)\n5. Sair\n");
    scanf ("%d",&Numero);
    if (Numero == 1)
    {
        FILE *file = fopen("dados.txt", "r"); //função para ler o arquivo "r" para ler ele
        if (file == NULL) //verifica se está vazio
        {
            printf("Arquivo Nulo\n");
        } 
        else 
        {
            int i = 0;
            while (fscanf(file, "%d", &V[i]) != EOF && i < tam) //Vai colocar no vetor cada numero EOF para ler os dados até o final do arquivo
                {
                    i++; //incrementa
                }
            n = i;
            fclose(file);
            printf("Arquivo Carregado! %d numeros lidos.\n", i); //avisa que está carregado e quantos numeros
        }
        acaofeita = 1;
    }
    if (acaofeita == 1 && Numero == 2)
    {
        printf ("\n01.Linear \n02.Binária (Apenas se estiver ordenado)\n");
        scanf ("%d",&NumeroSub);
        switch (NumeroSub) 
        {
            case 1:
 
                break;
            case 2:
                    
                break;
            default:
                printf("Invalido!");
        }

    }
    if (acaofeita == 1 && Numero == 3)
    {    
        printf ("\n 01.Insert.\n02.Bubble\n03.Selection\n04.Merge\n05.Quick\n06.EXTRA\n");
        scanf ("%d",&NumeroSub);
        switch (NumeroSub) 
        {
            case 1:

            algoritmoexecutado = 1;
                break;
            case 2:

            algoritmoexecutado = 1;     
                break;
            case 3:

            algoritmoexecutado = 1;  
                break;
            case 4:

            algoritmoexecutado = 1;  
                break;
            case 5:

            algoritmoexecutado = 1;
                break;
            case 6:

            algoritmoexecutado = 1;  
                break;
            default:
                printf("Invalido!");
        }

    }
    if (algoritmoexecutado == 1 && Numero == 4)
    {    
      
    }

    free (V);
    } while (Numero != 5);
}
