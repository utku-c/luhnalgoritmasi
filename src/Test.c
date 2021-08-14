#include "Program.h"

int main()
{
    FILE *dosya; // dosya okuma açma işlemi
    dosya = fopen("./doc/iban.txt", "r");
    char karakter;
    int kartNo[16];
    int siraNo = 0;
    if (dosya != NULL)
    {
        while (!feof(dosya))
        {
            siraNo++;
            int u = 0;
            karakter = 't'; // for'un içine girmesi için kullanıyoruz
            for (int i = 0; karakter != '\0'; i++)
            {
                fscanf(dosya, "%c", &karakter);
                if (karakter == ' ')
                {
                    continue;
                }
                if (karakter == 32)
                {
                    printf("\n\n\n\nBEKLENMEYEN SONLANDIRMA\n\n\n\n");
                    return 0;
                }
                
                if (karakter < 47 || karakter > 57)
                {

                    printf("\n\n\n\nBEKLENMEYEN KARAKTER\n\n\n\n");
                    printf("GELEN KARAKTER: %c",karakter);
                    printf("\n\n");
                    return 0;
                }
                
                // burada char olarak gelen sayıyı int'e çeviririz
                kartNo[u] = atoi(&karakter);
                u++;
            }
            luhnAlgoritmasi(kartNo, KARTRAKAMSAYISI, siraNo);
        }
    }
    else
    {
        printf("Dosya bulunamadi...");
    }
    fclose(dosya); // dosya kapatma
    return 0;
}