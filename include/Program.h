#ifndef PROGRAM_H
#define PROGRAM_H

#include <stdio.h>
#include <stdlib.h>
#define KARTRAKAMSAYISI 16 // kart sayisi sabit oldugu için kullanılabilir
#define true 1  // c de true  false yok 
#define false 0

//  dizinin boyutunu bulmaya çalışıyoruz
int katar_boyutu_bul(char[]); 
// son olarak kartın true false döndurmesi durumu
int gecerligecersiz(int); 
// hesaplamalar burda yapılıyoruz kartın onaylanması
void luhnAlgoritmasi(int [], int , int ); 
// son olarak kartı ekrana yazdırıyoruz 
void ekranaYaz(int [],int ,int ,int ); 

#endif