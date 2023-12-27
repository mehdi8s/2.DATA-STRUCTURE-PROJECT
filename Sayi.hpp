/** 
* @file Dosya adı:  Sayi.hpp
* @description : Sayi listesi ve Düğümleri Basamak Listesinden oluşuyor
* @course Dersi aldığınız eğitim türü ve grup:  1.Öğretim C gurubu
* @assignment Kaçıncı ödev olduğu:  1.Ödev
* @date Kodu oluşturduğunuz Tarih: 16.11.2023
* @author Gruptakilerin yazar adları ve mail adresleri: MAHDI SHAHROUEI  mahdi.shahrouei@ogr.sakarya.edu.tr
*/

#ifndef Sayi_hpp
#define Sayi_hpp
#include "Basamak.hpp"

class Sayi
{
    public:
    Sayi* sonrakiSayi;
    Basamak* ilkBasamak;
    int BasamakAdet;
    Sayi();
    void BasamakEkle(int);
    void BasamakYazdir();
    void BasamakDegistir(int, int);
};
#endif