/**Van Eck Sequence algorithm by Cinglair Capello, Daniel Gustavo Favero e Jeferson Souza
  *Universidade Federal Tecnológica do Paraná - Câmpus Pato Branco
  *Credits from Numberfile </https://www.youtube.com/watch?v=etMJxB-igrc&t=79s>
  */

#include <stdio.h>

int main(void){
    int terms;
    int timesBehind = 0;
    int i;
    int j;

    printf("Insert the number of terms for the sequence: ");
    scanf("%d", &terms);

    int sequence[terms];

    sequence[0] = 0;
    sequence[1] = 0;

    for(i = 1; i < terms; i++){
        for(j = i - 1; j >= 0; j--){
            timesBehind++;

            if(sequence[i] == sequence[j]){
                sequence[i + 1] = timesBehind;

                j = 0;
            } else {
                sequence[i + 1] = 0;
            }
        }

        timesBehind = 0;
    }


    printf("\nVan Eck sequence: ");
    for(i = 0; i < terms; i++){
        printf("%d\t", sequence[i]);
    }

    printf("\n\n");
}

