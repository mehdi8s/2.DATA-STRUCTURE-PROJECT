/** 
* @file Dosya adı:  Basamak.cpp
* @description : Bassamaklar listesi kaynak kodu 
* @course Dersi aldığınız eğitim türü ve grup:  1.Öğretim C gurubu
* @assignment Kaçıncı ödev olduğu:  1.Ödev
* @date Kodu oluşturduğunuz Tarih: 16.11.2023
* @author Gruptakilerin yazar adları ve mail adresleri: MAHDI SHAHROUEI  mahdi.shahrouei@ogr.sakarya.edu.tr
*/

#include "Basamak.hpp"

Basamak::Basamak(int Rakam)
{
    this -> Rakam = Rakam;
    this -> sonrakiBasamak = 0;
}