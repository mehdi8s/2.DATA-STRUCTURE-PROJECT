/** 
* @file Dosya adı:  Sayi.hcpp
* @description : Sayi listesi ve Düğümleri Basamak Listesinden oluşuyor ve basamaklar arasında işlemleri içeriyor
* @course Dersi aldığınız eğitim türü ve grup:  1.Öğretim C gurubu
* @assignment Kaçıncı ödev olduğu:  1.Ödev
* @date Kodu oluşturduğunuz Tarih: 16.11.2023
* @author Gruptakilerin yazar adları ve mail adresleri: MAHDI SHAHROUEI  mahdi.shahrouei@ogr.sakarya.edu.tr
*/

#include "Sayi.hpp"
#include <iostream>
#include <iomanip>
using namespace std;


Sayi::Sayi()
{
  
    this->sonrakiSayi = 0;
    ilkBasamak = 0;
    BasamakAdet = 0;
}

void Sayi::BasamakEkle(int Rakam)                          //ekle fonk
{
    Basamak* yeni = new Basamak(Rakam);
    if(ilkBasamak == 0)
    {
        ilkBasamak = yeni;
    }
    else
    {
        Basamak* gec = ilkBasamak;
        while(gec->sonrakiBasamak != 0)
        {
            gec = gec->sonrakiBasamak;
        }
        gec->sonrakiBasamak = yeni;
    }
}

void Sayi::BasamakYazdir()                       //SayiYazdir fonk
{
   
    Basamak* gec = ilkBasamak;
    while(gec != 0)
    { 
    cout<<gec->Rakam;
    gec = gec->sonrakiBasamak;
    }
}

void Sayi::BasamakDegistir(int indeks1, int indeks2)
{
    if(indeks1 == indeks2)
      return;
   Basamak* gec = ilkBasamak;
   Basamak* indeks1Basamak = 0;
   Basamak* indeks1OncekiBasamak = 0;
   Basamak* indeks2Basamak = 0;
   Basamak* indeks2OncekiBasamak = 0;
   Basamak* indeks2SonrakiBasamak = 0;

   int sayac = 0;
        while(sayac != indeks1)
        {
            gec = gec->sonrakiBasamak;
            sayac++;
        }
        indeks1Basamak = gec;
        sayac = 0;
        gec = ilkBasamak;

         while(sayac != indeks1 - 1 && indeks1 != 0)
        {
            gec = gec->sonrakiBasamak;
            sayac++;
        }
        indeks1OncekiBasamak = gec;
        sayac = 0;
        gec = ilkBasamak;

         while(sayac != indeks2)
        {
            gec = gec->sonrakiBasamak;
            sayac++;
        }
        indeks2Basamak = gec;
        sayac = 0;
        gec = ilkBasamak;
    
        
         while(sayac != indeks2 - 1)
        {
            gec = gec->sonrakiBasamak;
            sayac++;
        }
        indeks2OncekiBasamak = gec;
        indeks2SonrakiBasamak = indeks2Basamak->sonrakiBasamak;

        if( indeks1 != 0 )
        {
        indeks1OncekiBasamak->sonrakiBasamak = indeks2Basamak;
        
        }
        else
        {
            ilkBasamak = indeks2Basamak;
        }
        if( indeks2 - indeks1 != 1)
        {
        indeks2Basamak->sonrakiBasamak = indeks1Basamak->sonrakiBasamak;
        indeks2OncekiBasamak->sonrakiBasamak = indeks1Basamak;
        indeks1Basamak->sonrakiBasamak = indeks2SonrakiBasamak;
        }
        else
        {
        indeks1Basamak->sonrakiBasamak = indeks2SonrakiBasamak;
        indeks2Basamak->sonrakiBasamak = indeks1Basamak;
        }
        
}


