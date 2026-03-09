//Precisa do <stdlib.h>
void lerarquivo () //obs: se o tamanho é diferente é só mudar no inteiro tam
{
    int tam = 100;
    int n = 0;
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
}
