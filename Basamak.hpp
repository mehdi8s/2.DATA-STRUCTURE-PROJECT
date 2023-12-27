/** 
* @file Dosya adı:  Basamak.hpp
* @description : Bassamaklar listesi (Rakam tutuyor)
* @course Dersi aldığınız eğitim türü ve grup:  1.Öğretim C gurubu
* @assignment Kaçıncı ödev olduğu:  1.Ödev
* @date Kodu oluşturduğunuz Tarih: 16.11.2023
* @author Gruptakilerin yazar adları ve mail adresleri: MAHDI SHAHROUEI  mahdi.shahrouei@ogr.sakarya.edu.tr
*/

#ifndef Basamak_hpp
#define Basamak_hpp

class Basamak
{
    public:
    int Rakam;
    Basamak* sonrakiBasamak;
    Basamak(int);
};
#endif