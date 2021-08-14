#include "Program.h"

// lazım olması takdirinde bir dizinin boyutunu bulabileceğimiz fonksiyon
int katar_boyutu_bul(char katar[])
{
    int t;
    for (t = 0; katar[t] != '\0'; t++)
        ;

    return t;
}
// algoritmanın kurulduğu işlemlerin gerçekleştiği yer
void luhnAlgoritmasi(int cardNo[], int boyut, int sira)
{
    int basamakToplam = 0; // 3. adımdaki basamakların toplamı için kullanılacak
    int *ptr;
    ptr = malloc(16 * sizeof(int));
    for (int k = 0; k < boyut; k++)
    {
        ptr[k] = cardNo[k]; // karttaki değişkenler heapte bir değişkende oluşturuldu
    }
    int byt = 0;
    byt = boyut - 2;
    for (int i = 0; i < 8; i++)
    {
        ptr[byt] = 2 * ptr[byt];

        if (ptr[byt] > 9)
        {
            int tmp = 0;
            int tmp2 = 0;

            tmp = ptr[byt];  // 10 dan buyuk olan sayıyı tmp ye atıyoz
            tmp2 = tmp % 10; // modunu alıp tmp2 ye atıyoz tmp2 birler basamağını tutuyor
            tmp = tmp2 + 1;  // onlar basamağı her türlü 1 olacağı için tmp2 ye 1 ekliyoz
            ptr[byt] = tmp;
        }

        byt = byt - 2;
    }

    byt = boyut - 2;
    for (int i = 0; i < 16; i++)
    {
        basamakToplam = basamakToplam + ptr[i];
    }
    free(ptr);

    int gg = gecerligecersiz(basamakToplam);
    ekranaYaz(cardNo,KARTRAKAMSAYISI,sira,gg);
}
// kartın gecerli olup olmadığını döndüren fonksiyon
int gecerligecersiz(int toplam)
{
    if (toplam % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// son olarak verileri ekrana yazdıran fonksiyon
void ekranaYaz(int cardNo[], int boyut, int sira,int gecerligecersiz){
    
    printf("|< %d >|  Kart Numarasi: ",sira);
    for (int p = 0; p < 16; p++)
    {
        printf("%d", cardNo[p]);
    }
    if (gecerligecersiz == 1)
    {
        printf("  |--> ONAYLANDI <--|");
        printf("\n");
    }
    else
    {
        printf("  |--> HATA .... <--|");
        printf("\n");
    }

}












/*
printf("karakter%d: %c\n", u, karakter);
if ((karakter < 48 || karakter > 57))
                {

                    printf("\n**********************************************\n");
                    printf("GECERSIZ KARAKTER BULUNDU PROGRAM SONLANDIRILDI");
                    printf("\n***********************************************\n");

                    return 0;
                }

*/