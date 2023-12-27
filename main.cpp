/** 
* @file Dosya adı:  main.cpp
* @description : Ana kaynak Dosyamız
* @course Dersi aldığınız eğitim türü ve grup:  1.Öğretim C gurubu
* @assignment Kaçıncı ödev olduğu:  1.Ödev
* @date Kodu oluşturduğunuz Tarih: 16.11.2023
* @author Gruptakilerin yazar adları ve mail adresleri: MAHDI SHAHROUEI  mahdi.shahrouei@ogr.sakarya.edu.tr
*/

#include "Sayi.hpp"
#include "SayiListesi.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


int main()
{  
    SayiListesi ornekListe;
     string DosyaAdi = "Sayilar.txt";
    ornekListe.DosyaOkuma(DosyaAdi);
    //Menu
  
    char Deger = 0;
    while(Deger != '4')
    {
    switch (Deger)
    {
    case '1':
        ornekListe.TekBasamaklariBasaAl();
        break;
    case '2':
        ornekListe.BasamaklariTersle();
        break;
    case '3':
        ornekListe.EnBuyukSayiCikar();
        break;
    
    case '4':
        cout<<"program sonladiriyor"<<endl;
        break;

        
    default:
        break;
    }
    ornekListe.SayiYazdir();
    cin>>Deger;
    }












    
    
   /* ornekListe.SayiYazdir();

    cout<<"patlama"<<endl<<endl;
    //ornekListe.ilkSayi->BasamakDegistir(0,0);
   // ornekListe.ilkSayi->BasamakDegistir(1,2);
    //ornekListe.ilkSayi->BasamakDegistir(2,4);
    
   ornekListe.TekBasamaklariBasaAl();
    ornekListe.SayiYazdir();*/
    

    

    return 0;
}

//2. gun sayilar listesiadina bir bagli liste ki sayilari barindirsin
//text dosyassini okumak v projenin istedigi gibi dosyadaki butun sayilari ekrana yazmak
//dosyadi rakamlarin sayisi farkli olabiliris