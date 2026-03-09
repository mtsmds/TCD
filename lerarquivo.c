//Precisa do <stdlib.h>
void lerarquivo ()
{
        FILE *file = fopen("dados.txt", "r"); //função para ler o arquivo "r" para ler ele
        if (file == NULL) //verifica se está vazio
        {
            printf("Arquivo Nulo\n");
        } else {
            int i = 0;
            while (fscanf(file, "%d", &V[i]) i < n) //Vai colocar no vetor cada numero
            {
                i++; //incrementa
            }
            fclose(file);
            printf("Arquivo Carregado! %d numeros lidos.\n", i); //avisa que está carregado e o tamanho do vetor
        }
}
