#include <stdio.h>
#include <stdlib.h>

int fifo(int frameSize, char *referenceString)
{
    int pageFaults = 0;
    char frames[frameSize];
    char found = 0;
    int i, j, k = 0;

    for (i = 0; i < frameSize; i++)
    {
        frames[i] = 'x';
    }

    i = 0;
    while (referenceString[i] != '\0')
    {

        for (j = 0; j < frameSize; j++)
        {
            if (frames[j] == referenceString[i])
                found = 1;
        }

        if (!found)
        {
            frames[k] = referenceString[i];
            pageFaults++;
            k = (k + 1) % frameSize;
        }
        found = 0;
        i++;

        // Imprime os frames
        for (j = 0; j < frameSize; j++)
        {
            printf("%c\t", frames[j]);
        }
        printf("\n");
    }

    return pageFaults;
}

int lru(int frameSize, char *referenceString)
{
    int pageFaults = 0;
    char frames[frameSize];
    int frameCounter[frameSize];
    int maxCounter = 0;
    int replaceIndex = 0;
    char found = 0;
    int i, j;

    for (i = 0; i < frameSize; i++)
    {
        frames[i] = 'x';
        frameCounter[i] = 0;
    }

    i = 0;
    while (referenceString[i] != '\0')
    {

        for (j = 0; j < frameSize; j++)
            frameCounter[j]++;

        for (j = 0; j < frameSize; j++)
        {
            if (frames[j] == referenceString[i])
            {
                found = 1;
                frameCounter[j] = 0;
            }
        }

        if (!found)
        {
            maxCounter = frameCounter[0];
            replaceIndex = 0;
            for (j = 1; j < frameSize; j++)
            {
                if (frameCounter[j] > maxCounter)
                {
                    maxCounter = frameCounter[j];
                    replaceIndex = j;
                }
            }
            frames[replaceIndex] = referenceString[i];
            frameCounter[replaceIndex] = 0;

            pageFaults++;
        }
        found = 0;
        i++;

        // Imprime os frames
        for (j = 0; j < frameSize; j++)
        {
            printf("%c\t", frames[j]);
        }
        printf("\n");
    }

    return pageFaults;
}

int optimal(int frameSize, char *referenceString)
{
    int pageFaults = 0;
    char frames[frameSize];
    int frameCounter[frameSize];
    int replaceIndex = 0;
    char found = 0;
    int i, j, k;

    for (i = 0; i < frameSize; i++)
    {
        frames[i] = 'x';
        frameCounter[i] = 0;
    }

    i = 0;
    while (referenceString[i] != '\0')
    {

        for (j = 0; j < frameSize; j++)
        {
            if (frames[j] == referenceString[i])
            {
                found = 1;
            }
        }

        if (!found)
        {
            for (j = 0; j < frameSize; j++)
            {
                k = i + 1;
                while (referenceString[k] != '\0' && referenceString[k] != frames[j])
                {
                    k++;
                }
                frameCounter[j] = k;
            }

            replaceIndex = 0;
            for (j = 1; j < frameSize; j++)
            {
                if (frameCounter[j] > frameCounter[replaceIndex])
                    replaceIndex = j;
            }

            frames[replaceIndex] = referenceString[i];
            pageFaults++;
        }
        found = 0;
        i++;

        // Imprime os frames
        for (j = 0; j < frameSize; j++)
        {
            printf("%c\t", frames[j]);
        }
        printf("\n");
    }

    return pageFaults;
}

int main(int argc, char *argv[])
{
    int frameSize;
    char *referenceString;

    if (argc > 1)
    {
        frameSize = atoi(argv[1]);
        referenceString = argv[2];
        printf("Quantidade de frames: %d\n", frameSize);
        printf("String de referência: %s\n", referenceString);
    }

    printf("Número de faltas de página (FIFO): %d\n", fifo(frameSize, referenceString));
    printf("Número de faltas de página (LRU): %d\n", lru(frameSize, referenceString));
    printf("Número de faltas de página (Ótimo): %d\n", optimal(frameSize, referenceString));
    return 0;
}