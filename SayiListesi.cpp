/** 
* @file Dosya adı:  SayiListesi.cpp
* @description : SayiListesi adında cpp dosyamız ve Düğümleri sayı listemizden oluşuyor. sayılar arasında işlemleri içeriyor
* @course Dersi aldığınız eğitim türü ve grup:  1.Öğretim C gurubu
* @assignment Kaçıncı ödev olduğu:  1.Ödev
* @date Kodu oluşturduğunuz Tarih: 16.11.2023
* @author Gruptakilerin yazar adları ve mail adresleri: MAHDI SHAHROUEI  mahdi.shahrouei@ogr.sakarya.edu.tr
*/


#include "SayiListesi.hpp"
#include "Sayi.hpp"
#include "Basamak.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>

using namespace std;

SayiListesi::SayiListesi()
{
    ilkSayi = 0;
    SayiAdet = 0;
}

void SayiListesi::SayiEkle(Sayi* SayiAdresi)
{
    if (ilkSayi == nullptr) {
        // Eğer liste boşsa, yeni sayıyı listenin başına ekle
        ilkSayi = SayiAdresi;
    } 
    else {
        // Liste boş değilse, listenin sonuna kadar git
        Sayi* gec = ilkSayi;
        while (gec->sonrakiSayi != nullptr) {
            gec = gec->sonrakiSayi;
        }
        // Yeni sayıyı listenin sonuna ekle
        gec->sonrakiSayi = SayiAdresi;
    }
}

 void SayiListesi::SayiYazdir() 
{   
    if(SayiAdet == 0 )
    {   cout<<"Listede Sayi yoktur"<<endl<<endl;
        cout<<"1. Tek Basamaklari Basa Al"<<endl;
        cout<<"2. Basamaklari Tersle"<<endl;
        cout<<"3. En Buyuk Cikar"<<endl;
        cout<<"4. Cikis"<<endl;
        return;
    }

    Sayi* gec = ilkSayi;
    Basamak* kopyaIlkBasamak;

    while (gec != nullptr)
    {   
        for(int i = 0; i < 10; i++)
        {
            cout<<"#";
        }
        cout<<"     ";
        for(int i = 0; i <gec->BasamakAdet; i++)
        {
            cout<<"*******"<<"  ";
        }
        cout<<endl;
        
        cout<<"#"<<gec<<"#"<<"    ";

        kopyaIlkBasamak = gec->ilkBasamak;
        for(int i = 0; i <gec->BasamakAdet; i++)
        {
            //cout<<"*"<<" ";
        
            uintptr_t adres = reinterpret_cast<uintptr_t>(kopyaIlkBasamak);
            cout<<" #"<<right<<setw(5)<< adres % 1000 <<"#"<<" ";
            kopyaIlkBasamak = kopyaIlkBasamak->sonrakiBasamak;
           // cout<<"*"<<" ";
        }

        cout<<endl<<"#";
        for(int i = 0; i < 8; i++)
        {
            cout<<"-";
        }
        cout<<"#"<<"     ";
        for(int i = 0; i <gec->BasamakAdet; i++)
        {
            cout<<"*******"<<"  ";
        }
        cout<<endl;

        kopyaIlkBasamak = gec->ilkBasamak;
        cout<<"#";
        for(int j = 0; j < 8 - gec->BasamakAdet; j++)
        {
              cout<<" ";
        }
        gec->BasamakYazdir();
        cout<<"#"<<"    ";
         for(int i = 0; i <gec->BasamakAdet; i++)
        {  
            cout<<" #"<<right<<setw(5)<<kopyaIlkBasamak->Rakam<<"#"<<" ";
            kopyaIlkBasamak = kopyaIlkBasamak->sonrakiBasamak;

        }

        cout<<endl;

        for(int i = 0; i < 10; i++)
        {
            cout<<"#";
        }
        cout<<"     ";
        for(int i = 0; i <gec->BasamakAdet; i++)
        {
            cout<<"*******"<<"  ";
        }

       // gec->BasamakYazdir();
        //cout<<"#";
        gec = gec->sonrakiSayi;
        cout<<endl<<endl;

       
       
    }
    cout<<"1. Tek Basamaklari Basa Al"<<endl;
    cout<<"2. Basamaklari Tersle"<<endl;
    cout<<"3. En Buyuk Cikar"<<endl;
    cout<<"4. Cikis"<<endl;

    
}

void SayiListesi::DosyaOkuma(string& DosyaAdi)
{   
    char karakter = 0;
    bool kontrol = true;
    Sayi* SayiDugumu = new Sayi();

    ifstream DosyaOkuma("Sayilar.txt");
    while (DosyaOkuma.get(karakter)) 
    {
        if (isdigit(karakter)) 
        { 
          if(kontrol == true)
            {
                SayiDugumu = new Sayi();  
                SayiEkle(SayiDugumu); 
                kontrol = false;     
                SayiAdet++;
            }
            SayiDugumu->BasamakEkle(karakter - 48);
            SayiDugumu->BasamakAdet++;
        } 
        else{
            //cout<<SayiDugumu->BasamakAdet<<endl;
            kontrol = true;
        }

    }
    DosyaOkuma.close();
}

void SayiListesi::BasamaklariTersle()
{
     Sayi* gec = ilkSayi;
     while(gec != nullptr)
     {
     if(gec->BasamakAdet %2 == 0)
     {
        for(int i = 0; i < gec->BasamakAdet / 2; i++)
        {
            gec->BasamakDegistir(i, gec->BasamakAdet - 1 - i);
        }
     }
      else
     {
        for(int i = 0; i < gec->BasamakAdet / 2; i++)
        {
            gec->BasamakDegistir(i, gec->BasamakAdet - 1 - i);
        }
     }
        gec = gec->sonrakiSayi;
        
     }
}

void SayiListesi::EnBuyukSayiCikar()
{
    if(SayiAdet == 0 )
    {   cout<<"Listede Sayi yoktur"<<endl;
        return;
    }
    Sayi* gec = ilkSayi->sonrakiSayi;
    Sayi* EnBuyukSayi = ilkSayi;
    int Sayac = 0;
    int EnBuyukSayiIndeksi = 0;

    while(gec != nullptr)
    {
        if(gec->BasamakAdet > EnBuyukSayi->BasamakAdet)
        {
            EnBuyukSayi = gec;
            EnBuyukSayiIndeksi = Sayac+1;
        }
        else if(gec->BasamakAdet == EnBuyukSayi->BasamakAdet)
        {   
            Basamak* gec2 = gec->ilkBasamak;
            while(gec2 != nullptr)
            {

                if(gec2->Rakam > EnBuyukSayi->ilkBasamak->Rakam)
                {
                    EnBuyukSayi = gec;
                    EnBuyukSayiIndeksi = Sayac+1;

                    break;
                }
                else if(gec2->Rakam < EnBuyukSayi->ilkBasamak->Rakam)
                {
                    break;
                } 
                gec2 = gec2->sonrakiBasamak;
                
           }
        }

        Sayac++;
        gec = gec->sonrakiSayi;
        
    }   

        //EnbuyukSayi Cikart islemi
        gec = ilkSayi;
        int sayac2 = 0;
        Sayi* SilinecekSayiniOnceki = ilkSayi;
        while(sayac2 < EnBuyukSayiIndeksi - 1)
        {
        gec = gec->sonrakiSayi;
        sayac2++;
        }

        SilinecekSayiniOnceki = gec;

  
        if(EnBuyukSayiIndeksi == 0)
        {
            ilkSayi = gec->sonrakiSayi;
        }
        else
        {
        gec = gec->sonrakiSayi;
        SilinecekSayiniOnceki->sonrakiSayi = gec->sonrakiSayi;
        }
        gec->sonrakiSayi = nullptr;
        delete gec;
        SayiAdet--;
}

void SayiListesi::TekBasamaklariBasaAl()
{
        if(SayiAdet == 0 )
    {   cout<<"Listede Sayi yoktur"<<endl;
        return;
    }
    Sayi* gec = ilkSayi;
    int GosterilenIndeks = 0;
    Basamak* BasamakPointer = gec->ilkBasamak;
    int BasamakPointerIndeksi = 0;
    while (gec != nullptr)
    {
        GosterilenIndeks = 0;
        BasamakPointer = gec->ilkBasamak;
        BasamakPointerIndeksi = 0;
        while(BasamakPointer != nullptr){
            if(BasamakPointer->Rakam % 2 == 1){
                gec->BasamakDegistir(GosterilenIndeks,BasamakPointerIndeksi);
                for(int i = 0 ; i < BasamakPointerIndeksi-GosterilenIndeks; i++){
                   BasamakPointer = BasamakPointer->sonrakiBasamak;
                }
                GosterilenIndeks++;
            }
            BasamakPointerIndeksi++;
            BasamakPointer = BasamakPointer->sonrakiBasamak;
        }
        gec = gec->sonrakiSayi;  
    }    
}


