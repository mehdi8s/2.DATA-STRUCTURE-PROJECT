/** 
* @file Dosya adı:  SayiListesi.hpp
* @description : SayiListesi adında hpp dosyamız ve Düğümleri sayı listemizden oluşuyor
* @course Dersi aldığınız eğitim türü ve grup:  1.Öğretim C gurubu
* @assignment Kaçıncı ödev olduğu:  1.Ödev
* @date Kodu oluşturduğunuz Tarih: 16.11.2023
* @author Gruptakilerin yazar adları ve mail adresleri: MAHDI SHAHROUEI  mahdi.shahrouei@ogr.sakarya.edu.tr
*/

#ifndef SayiListesi_hpp
#define SayiListesi_hpp
#include "Sayi.hpp"
#include "Basamak.hpp"
#include <string>
using namespace std;

class SayiListesi
{
public:
    Sayi* ilkSayi;
    int SayiAdet;
    SayiListesi();
    void SayiEkle(Sayi*);
    void DosyaOkuma(string&); 
    void SayiYazdir();
    void BasamaklariTersle();
    void EnBuyukSayiCikar();
    void TekBasamaklariBasaAl();


};

#endif
