
#include <iostream>
#include <ctime>
#include <fstream>
#include<cstring>
#include<string>
#include <sstream>
using namespace std;
int sayac=0,cikis10=0;
int sayac2=0,sayac3=0,sayac4=0,sayac5=0,sayac6=0,sayac7=0,sayac8=0,sayac10=0,deger=0;
int dosya_sayi=0,kontrol_liste=0;
string dosya_yolu;
string dosya_isim[10];
class liste_sefer{
  public:
   string veri;
   struct liste_sefer*next;
};
class liste_koltuk{
  public:
   string koltuk_veri;
   struct liste_koltuk*next;
};

struct liste_koltuk*start;
struct liste_koltuk*start2;
struct liste_koltuk*new_component;


void koltuk_dosya_liste(string gelen1){

       if(deger==1){
           start=NULL;
           deger=0;
       }

      if(start==NULL)
        {

            start=new liste_koltuk;
            start->koltuk_veri=gelen1;
            start->next=NULL;
        }
    else{
       start2=start;
       new_component=new liste_koltuk;
       while(start2->next!=NULL){
          start2=start2->next;
       }
       start2->next=new_component;
       new_component->koltuk_veri=gelen1;
       new_component->next=NULL;
       }

}

struct liste_koltuk*start3;
void koltuk_liste_yazdir(){
    start3=start;
    while(start3!=NULL){
        cout<<start3->koltuk_veri<<endl;
        cout<<endl;
        start3=start3->next;
    }
}


struct liste_sefer*baslangic;
struct liste_sefer*baslangic2;
struct liste_sefer*yeni_eleman;

void sefer_listeye_ekle(string seferno,string guzergah,string sefertarih,string sefersaat,string kapasite,string plaka,string kaptan, string biletfiyat)
{
     string dugum= seferno+"-"+guzergah+"-"+sefertarih+"-"+sefersaat+"-"+kapasite+"-"+plaka+"-"+kaptan+"-"+biletfiyat;
    if(baslangic==NULL)
    {

        baslangic=new liste_sefer;
        baslangic->veri=dugum;
        baslangic->next=NULL;
    }
    else{
        baslangic2=baslangic   ;
       yeni_eleman=new liste_sefer;
       while(baslangic2->next!=NULL){
          baslangic2=baslangic2->next;
       }
       baslangic2->next=yeni_eleman;
       yeni_eleman->veri=dugum;
       yeni_eleman->next=NULL;
    }

}

struct liste_sefer*bas;
struct liste_sefer*bas2;
struct liste_sefer*yeni_eleman2;

void sefer_dosya_liste(string gelen){
       if(sayac==1 || sayac2==1 || sayac6==1){
         bas=NULL;
         sayac2=0;
         sayac6=0;
       }

      if(bas==NULL)
    {

        bas=new liste_sefer;
        bas->veri=gelen;
        bas->next=NULL;
    }
    else{
       bas2=bas;
       yeni_eleman2=new liste_sefer;
       while(bas2->next!=NULL){
          bas2=bas2->next;
       }
       bas2->next=yeni_eleman2;
       yeni_eleman2->veri=gelen;
       yeni_eleman2->next=NULL;
       }
}
void sefer_ekle(string seferno,string guzergah,string sefertarih,string sefersaat,string kapasite,string plaka,string kaptan, string biletfiyat){
  string node= seferno+"-"+guzergah+"-"+sefertarih+"-"+sefersaat+"-"+kapasite+"-"+plaka+"-"+kaptan+"-"+biletfiyat;
  time_t tarih = time(NULL);
  struct tm *tarih_bilgisi = localtime(&tarih);
  char mTarih[50];
  char yol[50]=".txt";
  strftime(mTarih, sizeof(mTarih), "%d-%m-%Y", tarih_bilgisi);
  ofstream dosya;
  dosya.open(strcat(mTarih,yol),ios::out | ios::app);
  if(dosya.is_open()){
    dosya<<node<<"\n";
    dosya.close();
  }
  else{
      cout<<endl<<"Dosya acilmadi";
    }

}
void koltuk_ekle(string kapasite,string bilet_fiyat,string sefer_no){
  int koltuk_no;
  string yolcu_adi,cinsiyet,durum,fiyat,sefer;
  int yolcu_sayisi;
  std::istringstream(kapasite)>>yolcu_sayisi;
  time_t tarih = time(NULL);
  struct tm *tarih_bilgisi = localtime(&tarih);
  char mTarih[50];
  char yol[50]="koltuk_kayit.txt";
  strftime(mTarih, sizeof(mTarih), "%d-%m-%Y", tarih_bilgisi);
  ofstream dosya2;
  dosya2.open(strcat(mTarih,yol),ios::out | ios::app);
  if(dosya2.is_open()){
    for(int i=1;i<=yolcu_sayisi;i++){
        yolcu_adi="ISIMSIZ";
        koltuk_no=i;
        fiyat=bilet_fiyat;
        sefer=sefer_no;
        durum="BOS";
        cinsiyet="BOS";
        dosya2<<sefer<<"-"<<koltuk_no<<"-"<<yolcu_adi<<"-"<<cinsiyet<<"-"<<durum<<"-"<<fiyat<<"\n";

    }
    dosya2.close();
  }
}

struct liste_sefer*baslangic4;
void liste_yazdir(){
    baslangic4=bas;
    while(baslangic4!=NULL){
        cout<<baslangic4->veri<<endl;
        baslangic4=baslangic4->next;
    }
}
int b=0;
void dosya_adlari(){

        b=0;
      ifstream dosya_adlar("dosya_isim.txt",ios::in);
      while(true){
        dosya_adlar>>dosya_isim[b];
        ++b;
        if(dosya_adlar.eof()){
            break;
        }

      }
      dosya_adlar.close();
      dosya_sayi=b;



}
void dosya_adi_ekle(){
      int kontrol=0;
      ofstream dosya_ad_yaz("dosya_isim.txt",ios::out| ios::app);
      time_t tarih = time(NULL);
      struct tm *tarih_bilgisi = localtime(&tarih);
      char mTarih[50];
      char yol[50]=".txt";
      strftime(mTarih, sizeof(mTarih), "%d-%m-%Y", tarih_bilgisi);
      string dosya_adi=strcat(mTarih,yol);
      for(int c=0 ;c<dosya_sayi;c++){
        if(dosya_isim[c]==dosya_adi){
            kontrol=1;
            break;
        }
      }
      if(kontrol==0){
         dosya_ad_yaz<<dosya_adi<<"\n";
      }
      dosya_ad_yaz.close();
}
int main()
{
    dosya_adlari();
    string delimiter = "-";
    string parca,dosya_adi,satir,koltuklar,satir2,satir3,gelen_tarih,row1,yeni_kaptan;
    int  pos = 0,pos2=0,pos3=0,pos4=0;
    int  get_days,get_months,get_years,toplam_sefer_sayisi=0,cikis2=0;
    int f=0,cikis=0,t=0,gelir_toplam=0,fiyat=0;
    int ana_menu_secim=-1;
    int sefer_menu_secim=-1;
    int bilet_menu_secim=-1;
    string koltuk_numara_islem,yolcu_adi_islem,yolcu_cinsiyet_islem,bilet_durum;
    string kapasite_hesap="",plaka_hesap="",kaptan_hesap="",fiyat_hesap="";
    string bilet_secim_tarih,bilet_secim_saat,bilet_secim_guzergah;
    string iptal_sad,iptal_starih,iptal_ssaat,koltuk_numara_iptal;
    string seferno_yeni,guzergah_yeni,tarih_yeni,saat_yeni,kapasite_yeni,plaka_yeni,bilet_fiyat_yeni;
    string guzergah_hesap,tarih_hesap,saat_hesap,seferno_hesap,sefer_no1,koltuk_durum,bilet_fiyat;
    string kaptan_tarih,kaptan_saat,kaptan_guzergah;
    string silno,silguzergah,siltarih,silsaat;
    string kaptanguzergah,kaptantarih,kaptansaat;
    string hesap_tarih,hesap_saat,hesap_guzergah,satirim;
    string gelen_gun,gelen_ay,gelen_yil;
    string bilet_seferno,bilet_yolcu_adi,bilet_yolcu_cins,bilet_koltukno;
    string sil_tarih,sil_saat,sil_guzergah,sil_sefer_no;
    string seferler,seferler2,seferler8,koltuklar2,seferler10;
    string biletfiyat,kapasite,seferno,seferno2,satir4="";
    string guzergah,sefertarih,sefersaat,plaka,kaptan,bos,koltuk_satir;
    while(ana_menu_secim!=0){
    int sefer_menu_secim=-1;
    bilet_menu_secim=-1;
    cout<<"1) Sefer islemleri icin 1'i tuslayiniz"<<endl;
    cout<<"2) Bilet satis islemleri icin 2'yi tuslayiniz"<<endl;
    cout<<"3) Sistemden cikis icin 0'i tuslayiniz"<<endl;
    cin>>ana_menu_secim;
    cout<<"--------------------------------------------------------------------"<<endl;
    if(ana_menu_secim==1){
        while(sefer_menu_secim!=0){
        cout<<endl;
        cout<<"1) Sefer eklemek icin 1'i tuslayiniz"<<endl;
        cout<<"2) Sefer silmek icin 2'yi tuslayiniz"<<endl;
        cout<<"3) Sefer listelemek icin 3'yi tuslayiniz"<<endl;
        cout<<"4) Gecmis seferleri listelemek icin 4'u tuslayiniz"<<endl;
        cout<<"5) Kaptan degistirmek icin 5'i tuslayiniz"<<endl;
        cout<<"6) Tum sefer sayisini ogrenmek icin 6'yi tuslayiniz"<<endl;
        cout<<"7) Sefer gelirini hesaplamak icin 7 yi tuslayiniz"<<endl;
        cout<<"8) Ana menuye donus yapmak icin 0'i tuslayiniz"<<endl;
        cin>>sefer_menu_secim;
        cout<<"-----------------------------------------------------------------"<<endl;
        if(sefer_menu_secim==1){
              getline(cin,bos);
              cout<<"Sefer no giriniz :";
              getline(cin,seferno);
              cout<<"Guzergah bilgisini giriniz:";
              getline(cin,guzergah);
              cout<<"Sefer tarihini giriniz:";
              getline(cin,sefertarih);
              cout<<"Sefer saatini giriniz:";
              getline(cin,sefersaat);
              cout<<"Yolcu kapasitesini giriniz:";
              getline(cin,kapasite);
              cout<<"Plakasini giriniz:";
              getline(cin,plaka);
              cout<<"Kaptani giriniz:";
              getline(cin,kaptan);
              cout<<"Bilet Fiyatini giriniz:";
              getline(cin,biletfiyat);
              sefer_ekle(seferno,guzergah,sefertarih,sefersaat,kapasite,plaka,kaptan,biletfiyat);
              dosya_adi_ekle();
              sefer_listeye_ekle(seferno,guzergah,sefertarih,sefersaat,kapasite,plaka,kaptan,biletfiyat);
              liste_yazdir();
              koltuk_ekle(kapasite,biletfiyat,seferno);
              sayac=1;

        }
         if(sefer_menu_secim==2){
            dosya_adlari();
            cout<<"Silmek istediginiz sefer no giriniz:";
            cin>>sil_sefer_no;
            cout<<"Silmek istediginiz seferin yapilacagi tarihi giriniz:";
            cin>>sil_tarih;
            cout<<"Silmek istediginiz seferin saatini giriniz:";
            cin>>sil_saat;
            cout<<"Silmek istediginiz seferin guzergah bilgisini giriniz:";
            cin>>sil_guzergah;
            sayac4=0;
            cikis=0;
            while(sayac4<dosya_sayi-1){
                const char*isim2=dosya_isim[sayac4].c_str();
                ifstream sefer_oku2(isim2,ios::in);
                 while(true){

                   sefer_oku2>>seferler2;
                   if( sefer_oku2.eof() ) break;
                   cout<<seferler2<<endl;

                   while(f<8){
                   pos=seferler2.find(delimiter);
                   parca=seferler2.substr(0,pos);
                   //cout<<parca<<endl;
                   seferler2.erase(0,pos+1);
                   if(f==0){
                    silno=parca;
                   }
                   if(f==1){
                    silguzergah=parca;
                   }
                   if(f==2){
                    siltarih=parca;
                   }
                   if(f==3){
                    silsaat=parca;
                   }
                   ++f;
                 }
                    cout<<silno<<"-"<<silguzergah<<"-"<<siltarih<<"-"<<silsaat<<endl;
                   f=0;
                  if(silno==sil_sefer_no&& silguzergah==sil_guzergah&&siltarih==sil_tarih&&silsaat==sil_saat){
                    cikis=1;
                    dosya_adi=dosya_isim[sayac4];
                    break;
                  }

                 }
                sefer_oku2.close();
                ++sayac4;
                if(cikis==1){
                    break;
                }


            }
            cout<<dosya_adi<<endl;
            const char*yol2=dosya_adi.c_str();
            ofstream test_dosya_yaz("test_dosya.txt",ios::out|ios::app);
            ifstream sefer_dosya_oku(yol2,ios::in);
            f=0;
            while(true){
                  sefer_dosya_oku>>seferler2;
                  satir=seferler2;
                   if( sefer_dosya_oku.eof() ) break;
                   //cout<<seferler2<<endl;

                   while(f<8){
                   pos=seferler2.find(delimiter);
                   parca=seferler2.substr(0,pos);
                   //cout<<parca<<endl;
                   seferler2.erase(0,pos+1);
                   if(f==0){
                    silno=parca;
                   }
                   if(f==1){
                    silguzergah=parca;
                   }
                   if(f==2){
                    siltarih=parca;
                   }
                   if(f==3){
                    silsaat=parca;
                   }
                   ++f;
                 }
                 f=0;
                 if(silno==sil_sefer_no&& silguzergah==sil_guzergah&&siltarih==sil_tarih&&silsaat==sil_saat){

                     continue;
                 }
                 else{
                    test_dosya_yaz<<satir<<"\n";
                 }

            }
            sefer_dosya_oku.close();
            test_dosya_yaz.close();
            remove(yol2);
            rename("test_dosya.txt",yol2);

            ofstream koltuk_dosya_sil("test2_dosya.txt",ios::out|ios::app);
            pos2=dosya_adi.find(".txt");
            string kyol=dosya_adi.substr(0,pos2);
            string koltuk_yol=kyol+"koltuk_kayit.txt";
            const char*yol3=koltuk_yol.c_str();
            ifstream koltuk_dosya_al(yol3,ios::in);
            t=0;
            while(true){
                koltuk_dosya_al>>koltuklar;
                satir2=koltuklar;
                if( koltuk_dosya_al.eof() ) break;
                 while(t<6){
                   pos=koltuklar.find(delimiter);
                   parca=koltuklar.substr(0,pos);
                   koltuklar.erase(0,pos+1);
                   if(t==0){
                    silno=parca;
                   }
                   ++t;
                 }
                  t=0;
                 if(silno==sil_sefer_no){
                     continue;
                 }
                 else{
                   koltuk_dosya_sil<<satir2<<"\n";
                 }

            }
            koltuk_dosya_al.close();
            koltuk_dosya_sil.close();
            remove(yol3);
            rename("test2_dosya.txt",yol3);

         }
         if(sefer_menu_secim==3){
                  dosya_adlari();
                  cout<<dosya_sayi;
                 sayac3=0;
                 while(sayac3<dosya_sayi-1){
                 const char*isim=dosya_isim[sayac3].c_str();
                 ifstream sefer_oku(isim,ios::in);
                 while(true){
                  sefer_oku>>seferler;
                 if( sefer_oku.eof() ) break;
                 sefer_dosya_liste(seferler);
                 sayac=0;//Listeyi sýfýrlayýp tekrardan ayný þeyleri yazdýrmasýn diye sayac=0 olduðunda devamýna yazsýn diye 1 olduðunda null çetkim baþlangýcý

                 }
                 sefer_oku.close();
                 liste_yazdir();
                 sayac2=1;//Listeyi sýfýrlayýp tekrardan ayný þeyleri yazdýrmasýn diye sayac2=1 olduðunda baþlangýcý null çektik
                 ++sayac3;
                }



          }
         if(sefer_menu_secim==4){
          dosya_adlari();
          int days,months,years;
          time_t tarih3 = time(NULL);
          struct tm *tarih_bilgisi3 = localtime(&tarih3);
          char mTarih3[50];
          // char yol3[50]=".txt";
          strftime(mTarih3, sizeof(mTarih3), "%d-%m-%Y", tarih_bilgisi3);
          string guncel_tarih=mTarih3;
          string gun=guncel_tarih.substr(0,2);
          string ay=guncel_tarih.substr(3,2);
          string yil=guncel_tarih.substr(6,4);
          istringstream(gun)>>days;
          istringstream(ay)>>months;
          istringstream(yil)>>years;
          sayac5=0;
            while(sayac5<dosya_sayi-1){
                 const char*isim5=dosya_isim[sayac5].c_str();
                 ifstream dosya_oku5(isim5,ios::in);
                 f=0;
                 while(true){
                       dosya_oku5>>satir3;
                       row1=satir3;
                       if(dosya_oku5.eof())break;
                        while(f<8){
                       pos=satir3.find(delimiter);
                       parca=satir3.substr(0,pos);
                       satir3.erase(0,pos+1);
                       if(f==2){
                        gelen_tarih=parca;
                        break;
                       }
                        ++f;
                       }
                       gelen_gun=gelen_tarih.substr(0,2);
                       gelen_ay=gelen_tarih.substr(3,2);
                       gelen_yil=gelen_tarih.substr(6,4);
                       istringstream(gelen_gun)>>get_days;
                       istringstream(gelen_ay)>>get_months;
                       istringstream(gelen_yil)>>get_years;
                       //cout<<get_days<<" "<<get_months<<" "<<get_years<<endl;
                       if(years>get_years){
                           //cout<<get_days<<" "<<get_months<<" "<<get_years<<endl;
                           sefer_dosya_liste(row1);
                       }
                       else if(years==get_years && months>get_months){
                          // cout<<get_days<<" "<<get_months<<" "<<get_years<<endl;
                            sefer_dosya_liste(row1);
                       }
                       else if(years==get_years && get_months==months && days>get_days){
                           //cout<<get_days<<" "<<get_months<<" "<<get_years<<endl;
                            sefer_dosya_liste(row1);
                       }
                       f=0;

                 }
                 ++sayac5;
           }
           liste_yazdir();
           sayac6=1;

        }
         if(sefer_menu_secim==5){
            dosya_adlari();
            cout<<"Kaptanini degistirmek istediginiz seferin yapilacagi tarihi giriniz:";
            cin>>kaptan_tarih;
            cout<<"Kaptanini degistirmek istediginiz seferin saatini giriniz:";
            cin>>kaptan_saat;
            cout<<"Kaptanini degistirmek istediginiz seferin guzergah bilgisini giriniz:";
            cin>>kaptan_guzergah;
            cout<<"Yeni kaptanin adi ve soyadini giriniz";
            cin>>yeni_kaptan;
            sayac10=0;
            cikis10=0;
            f=0;
            while(sayac10<dosya_sayi-1){
                const char*isim10=dosya_isim[sayac10].c_str();
                ifstream sefer_oku10(isim10,ios::in);
                 while(true){

                   sefer_oku10>>seferler10;
                   if( sefer_oku10.eof() ) break;
                   //cout<<seferler10<<endl;

                   while(f<8){
                   pos=seferler10.find(delimiter);
                   parca=seferler10.substr(0,pos);
                   //cout<<parca<<endl;
                   seferler10.erase(0,pos+1);
                   if(f==1){
                    kaptanguzergah=parca;
                   }
                   if(f==2){
                    kaptantarih=parca;
                   }
                   if(f==3){
                    kaptansaat=parca;
                   }
                   ++f;
                 }

                   f=0;
                  if( kaptanguzergah==kaptan_guzergah&&kaptantarih==kaptan_tarih&&kaptansaat==kaptan_saat){
                    cikis10=1;
                    dosya_adi=dosya_isim[sayac10];
                    break;
                  }

                 }
                sefer_oku10.close();
                ++sayac10;
                if(cikis10==1){
                    break;
                }


            }
            cout<<dosya_adi;
            const char*yol6=dosya_adi.c_str();
            ofstream test_dosya_yaz2("test_dosya2.txt",ios::out|ios::app);
            ifstream sefer_dosya_oku10(yol6,ios::in);
            f=0;
            while(true){
                  sefer_dosya_oku10>>seferler10;
                  satir=seferler10;
                  if( sefer_dosya_oku10.eof() ) break;
                      while(f<8){
                   pos=seferler10.find(delimiter);
                   parca=seferler10.substr(0,pos);
                   //cout<<parca<<endl;
                   seferler10.erase(0,pos+1);
                   if(f==0){
                    seferno_yeni=parca;
                   }
                   if(f==1){
                    guzergah_yeni=parca;
                   }
                   if(f==2){
                    tarih_yeni=parca;
                   }
                   if(f==3){
                    saat_yeni=parca;
                   }
                   if(f==4){
                    kapasite_yeni=parca;
                   }
                   if(f==5){
                    plaka_yeni=parca;
                   }
                   if(f==7){
                    bilet_fiyat_yeni=parca;
                   }
                   ++f;
                 }
                 if(guzergah_yeni==kaptan_guzergah&&tarih_yeni==kaptan_tarih&&saat_yeni==kaptan_saat)
                 {
                     test_dosya_yaz2<<seferno_yeni<<"-"<<guzergah_yeni<<"-"<<tarih_yeni<<"-"<<saat_yeni<<"-"<<kapasite_yeni<<"-"<<plaka_yeni<<"-"<<yeni_kaptan<<"-"<<bilet_fiyat_yeni<<"\n";
                 }
                 else{
                    test_dosya_yaz2<<satir<<"\n";
                 }

                 f=0;
            }
            sefer_dosya_oku10.close();
            test_dosya_yaz2.close();
            remove(yol6);
            rename("test_dosya2.txt",yol6);

        }
         if(sefer_menu_secim==6){
                 dosya_adlari();
                 sayac7=0;
                 while(sayac7<dosya_sayi-1){
                 const char*isim7=dosya_isim[sayac7].c_str();
                 ifstream sefer_oku7(isim7,ios::in);
                 while(true){
                 sefer_oku7>>seferler;
                 if( sefer_oku7.eof() ) break;
                    toplam_sefer_sayisi=toplam_sefer_sayisi+1;
                 }
                 sefer_oku7.close();
                 ++sayac7;
                }
                cout<<endl<<dosya_sayi-1<<" adet dosyada toplam da " <<toplam_sefer_sayisi<< " tane sefer sayisi bulunmaktadir"<<endl;
        }
         if(sefer_menu_secim==7){
            dosya_adlari();
            cout<<"Ilgili seferin tarihini giriniz:";
            cin>>hesap_tarih;
            cout<<"Ilgili seferin saatini giriniz:";
            cin>>hesap_saat;
            cout<<"Ilgili seferin guzergah bilgisini giriniz:";
            cin>>hesap_guzergah;
            sayac8=0;
            cikis2=0;
            f=0;
            while(sayac8<dosya_sayi-1){
                const char*isim8=dosya_isim[sayac8].c_str();
                ifstream sefer_oku8(isim8,ios::in);
                 while(true){

                   sefer_oku8>>seferler8;
                   if( sefer_oku8.eof() ) break;
                   //cout<<seferler8<<endl;

                   while(f<8){
                   pos=seferler8.find(delimiter);
                   parca=seferler8.substr(0,pos);
                   seferler8.erase(0,pos+1);
                   if(f==0){
                    seferno_hesap=parca;
                   }
                   if(f==1){
                    guzergah_hesap=parca;
                   }
                   if(f==2){
                    tarih_hesap=parca;
                   }
                   if(f==3){
                    saat_hesap=parca;
                   }
                   ++f;
                 }

                   f=0;
                  if(hesap_guzergah==guzergah_hesap&&hesap_tarih==tarih_hesap&&hesap_saat==saat_hesap){
                    cikis2=1;
                    sefer_no1=seferno_hesap;
                    dosya_adi=dosya_isim[sayac8];
                    break;
                  }

                 }
                sefer_oku8.close();
                ++sayac8;
                if(cikis2==1){
                    break;
                }

            }
            //cout<<sefer_no1<<" "<<dosya_adi;
            pos3=dosya_adi.find(".txt");
            string kyol2=dosya_adi.substr(0,pos3);
            string koltuk_yol2=kyol2+"koltuk_kayit.txt";
            const char*yol5=koltuk_yol2.c_str();
            ifstream koltuk_dosya_al2(yol5,ios::in);
            t=0;
            while(true){
                koltuk_dosya_al2>>koltuklar2;
                 if( koltuk_dosya_al2.eof() ) break;
                 while(t<6){
                   pos=koltuklar2.find(delimiter);
                   parca=koltuklar2.substr(0,pos);
                   koltuklar2.erase(0,pos+1);
                   if(t==0){
                    seferno2=parca;
                   }
                   if(t==4){
                    koltuk_durum=parca;
                   }
                   if(t==5){
                    bilet_fiyat=parca;
                   }
                   ++t;
                 }
                  istringstream(bilet_fiyat)>>fiyat;
                     if(seferno2==sefer_no1 && koltuk_durum=="BOS"){
                        gelir_toplam=gelir_toplam+0;
                     }
                     if(seferno2==sefer_no1 && koltuk_durum=="DOLU"){
                        gelir_toplam=gelir_toplam+fiyat;
                     }

                  t=0;
            }
            koltuk_dosya_al2.close();
            cout<<hesap_tarih<<" tarihinde saat "<< hesap_saat<<" de "<< hesap_guzergah<<" olan seferinizin gelir toplami: "<<gelir_toplam<<" TL"<<endl;
            gelir_toplam=0;

        }
        if(sefer_menu_secim==0){
          break;
        }

        }
    }
    if(ana_menu_secim==2){

          while(bilet_menu_secim!=0){
            cout<<endl;
            cout<<"1)Mevcut seferleri listelemek icin 1'i tuslayiniz"<<endl;
            cout<<"2)Sefer secimi yaparak otobus-koltuk bilgileri listelemek icin 2'yi tuslayiniz"<<endl;
            cout<<"3)Rezervasyon veya satis yapabilmek icin 3'u tuslayiniz"<<endl;
            cout<<"4)Satis iptali yapabilmek icin 4'u tuslayiniz"<<endl;
            cout<<"5)Ana menuye donus yapmak icin 0'i tuslayiniz"<<endl;
            cin>>bilet_menu_secim;
             cout<<"-----------------------------------------------------------------------"<<endl;
            if(bilet_menu_secim==1){
                dosya_adlari();
                 sayac3=0;
                 while(sayac3<dosya_sayi-1){
                 const char*isim11=dosya_isim[sayac3].c_str();
                 ifstream sefer_oku11(isim11,ios::in);
                 while(true){
                  sefer_oku11>>seferler;
                 if( sefer_oku11.eof() ) break;
                 sefer_dosya_liste(seferler);
                 sayac=0;//Listeyi sýfýrlayýp tekrardan ayný þeyleri yazdýrmasýn diye sayac=0 olduðunda devamýna yazsýn diye 1 olduðunda null çetkim baþlangýcý

                 }
                 sefer_oku11.close();
                 liste_yazdir();
                 sayac2=1;//Listeyi sýfýrlayýp tekrardan ayný þeyleri yazdýrmasýn diye sayac2=1 olduðunda baþlangýcý null çektik
                 ++sayac3;
                }

            }
            if(bilet_menu_secim==2){
                kontrol_liste=0;
                dosya_adlari();
                cout<<"Secmek istediginiz seferin tarihini giriniz:";
                cin>>bilet_secim_tarih;
                cout<<"Secmek istediginiz seferin saatini giriniz:";
                cin>>bilet_secim_saat;
                cout<<"Secmek istediginiz seferin guzergahini giriniz:";
                cin>>bilet_secim_guzergah;
                 sayac8=0;
                 cikis2=0;
                 f=0;
              while(sayac8<dosya_sayi-1){
                const char*isim12=dosya_isim[sayac8].c_str();
                ifstream sefer_oku12(isim12,ios::in);
                 while(true){

                   sefer_oku12>>seferler8;
                   if( sefer_oku12.eof() ) break;
                   //cout<<seferler8<<endl;

                   while(f<8){
                   pos=seferler8.find(delimiter);
                   parca=seferler8.substr(0,pos);
                   seferler8.erase(0,pos+1);
                   if(f==0){
                    seferno_hesap=parca;
                   }
                   if(f==1){
                    guzergah_hesap=parca;
                   }
                   if(f==2){
                    tarih_hesap=parca;
                   }
                   if(f==3){
                    saat_hesap=parca;
                   }
                   if(f==4){
                    kapasite_hesap=parca;
                   }
                   if(f==5){
                    plaka_hesap=parca;
                   }

                   if(f==6){
                    kaptan_hesap=parca;
                   }
                   if(f==7){
                    fiyat_hesap=parca;
                   }
                   ++f;
                 }

                   f=0;
                  if(bilet_secim_guzergah==guzergah_hesap&&bilet_secim_tarih==tarih_hesap&&bilet_secim_saat==saat_hesap){
                    cikis2=1;
                    sefer_no1=seferno_hesap;
                    dosya_adi=dosya_isim[sayac8];
                    break;
                  }

                 }
                sefer_oku12.close();
                ++sayac8;
                if(cikis2==1){
                    break;
                }

            }
            cout<<endl<<"--------------SECTIGINIZ SEFER BILGILERI-----------------------"<<endl;
            cout<<"Sefer No:"<<seferno_hesap<<endl;
            cout<<"Sefer Guzergahi:"<<guzergah_hesap<<endl;
            cout<<"Sefer Tarihi:"<<tarih_hesap<<endl;
            cout<<"Sefer Saati:"<<saat_hesap<<endl;
            cout<<"Sefer Kapasitesi:"<<kapasite_hesap<<endl;
            cout<<"Sefer Plakasi:"<<plaka_hesap<<endl;
            cout<<"Sefer Kaptani:"<<kaptan_hesap<<endl;
            cout<<"Seferin Bilet Ucreti:"<<fiyat_hesap<<endl;
            cout<<"--------------SECTIGINIZ SEFERIN KOLTUK BILGILERI--------------"<<endl;
            pos4=dosya_adi.find(".txt");
            string kyol4=dosya_adi.substr(0,pos4);
            string koltuk_yol4=kyol4+"koltuk_kayit.txt";
            dosya_yolu=koltuk_yol4;
            const char*yol14=koltuk_yol4.c_str();
            ifstream koltuk_dosya_al4(yol14,ios::in);
            t=0;
            while(true){
                koltuk_dosya_al4>>koltuklar2;
                 if( koltuk_dosya_al4.eof() ) break;
                 while(t<6){
                   pos=koltuklar2.find(delimiter);
                   parca=koltuklar2.substr(0,pos);
                   koltuklar2.erase(0,pos+1);
                   if(t==0){
                    bilet_seferno=parca;
                   }
                    if(t==1){
                    bilet_koltukno=parca;
                   }

                    if(t==2){
                    bilet_yolcu_adi=parca;
                   }
                    if(t==3){
                    bilet_yolcu_cins=parca;
                   }
                   if(t==4){
                    koltuk_durum=parca;
                   }
                   if(t==5){
                    bilet_fiyat=parca;
                   }
                   ++t;
                 }
                  if(sefer_no1==bilet_seferno){
                    koltuk_satir="Sefer No:"+bilet_seferno+"\n"+"Koltuk No:"+bilet_koltukno+"\n"+"Yolcu Adi:"+bilet_yolcu_adi+"\n"+"Koltuk Durum:"+koltuk_durum+"\n"+"Cinsiyet:"+bilet_yolcu_cins;
                    koltuk_dosya_liste(koltuk_satir);

                  }
                 t=0;

            }
            koltuk_dosya_al4.close();
            koltuk_liste_yazdir();
            kontrol_liste=1;
            deger=1;
            cout<<"----------------------------------------------------------------------"<<endl;
            }
            if(bilet_menu_secim==3){

              if(kontrol_liste==1){
                const char*koltuk_yolu=dosya_yolu.c_str();
                //cout<<sefer_no1<<""<<dosya_yolu;
                cout<<"Koltuk numarasini giriniz:";
                cin>>koltuk_numara_islem;
                cout<<"Yolcu adini giriniz:";
                cin>>yolcu_adi_islem;
                cout<<"Cinsiyet bilgisi giriniz:";
                cin>>yolcu_cinsiyet_islem;
                cout<<" Satis yapmak icin 1'i tuslayin, rezarvasyon icin 2 'yi tuslayiniz:";
                cin>>bilet_durum;
                ifstream koltuk_bilgisi_cek(koltuk_yolu,ios::in);
                ofstream test3_dosya_yaz("test_dosya3.txt",ios::out|ios::app);
                t=0;
             while(true){
                  koltuk_bilgisi_cek>>koltuklar2;
                   satir4=koltuklar2;
                 if( koltuk_bilgisi_cek.eof() ) break;

                 while(t<6){
                   pos=koltuklar2.find(delimiter);
                   parca=koltuklar2.substr(0,pos);
                   koltuklar2.erase(0,pos+1);
                   if(t==0){
                    bilet_seferno=parca;
                   }
                    if(t==1){
                    bilet_koltukno=parca;
                   }

                    if(t==2){
                    bilet_yolcu_adi=parca;
                   }
                    if(t==3){
                    bilet_yolcu_cins=parca;
                   }
                   if(t==4){
                    koltuk_durum=parca;
                   }
                   if(t==5){
                    bilet_fiyat=parca;
                   }
                   ++t;
                 }
                  if(sefer_no1==bilet_seferno && bilet_koltukno==koltuk_numara_islem && koltuk_durum=="BOS"){
                    if(bilet_durum=="1"){
                    test3_dosya_yaz<<bilet_seferno<<"-"<<bilet_koltukno<<"-"<<yolcu_adi_islem<<"-"<<yolcu_cinsiyet_islem<<"-"<<"DOLU"<<"-"<<bilet_fiyat<<"\n";
                    }
                    if(bilet_durum=="2"){
                    test3_dosya_yaz<<bilet_seferno<<"-"<<bilet_koltukno<<"-"<<yolcu_adi_islem<<"-"<<yolcu_cinsiyet_islem<<"-"<<"REZERVASYON"<<"-"<<bilet_fiyat<<"\n";
                    }

                  }
                  else{
                    test3_dosya_yaz<<satir4<<"\n";
                  }
                 t=0;

            }
            test3_dosya_yaz.close();
           koltuk_bilgisi_cek.close();
           remove(koltuk_yolu);
           rename("test_dosya3.txt",koltuk_yolu);

            }
              if(kontrol_liste==0){
                cout<<"Satis veya rezarvasyon yapabilmek icin oncelikle sefer secimi yapiniz."<<endl;
                cout<<"---------------------------------------------------------------------"<<endl;


             }

            }
            if(bilet_menu_secim==4){
                dosya_adlari();
                cout<<"Satis iptali yapilacak biletin sefer guzergahani giriniz : ";
                cin>>iptal_sad;
                cout<<"Satis iptali yapilacak biletin sefer tarihini giriniz : ";
                cin>>iptal_starih;
                cout<<"Satis iptali yapilacak biletin sefer saatini giriniz : ";
                cin>>iptal_ssaat;
                cout<<"Satis iptali yapilacak biletin koltuk numarasini giriniz:";
                cin>>koltuk_numara_iptal;
                sayac8=0;
                cikis2=0;
                f=0;
              while(sayac8<dosya_sayi-1){
                const char*biletyol=dosya_isim[sayac8].c_str();
                ifstream bilet_iptal(biletyol,ios::in);
                 while(true){

                   bilet_iptal>>seferler8;
                   if( bilet_iptal.eof() ) break;
                   //cout<<seferler8<<endl;

                   while(f<8){
                   pos=seferler8.find(delimiter);
                   parca=seferler8.substr(0,pos);
                   seferler8.erase(0,pos+1);
                   if(f==0){
                    seferno_hesap=parca;
                   }
                   if(f==1){
                    guzergah_hesap=parca;
                   }
                   if(f==2){
                    tarih_hesap=parca;
                   }
                   if(f==3){
                    saat_hesap=parca;
                   }

                   ++f;
                 }

                   f=0;
                  if(iptal_sad==guzergah_hesap&&iptal_starih==tarih_hesap&&iptal_ssaat==saat_hesap){
                    cikis2=1;
                    sefer_no1=seferno_hesap;
                    dosya_adi=dosya_isim[sayac8];
                    break;
                  }

                 }
                bilet_iptal.close();
                ++sayac8;
                if(cikis2==1){
                    break;
                }

            }
            pos4=dosya_adi.find(".txt");
            string iptal1=dosya_adi.substr(0,pos4);
            string iptal_yol=iptal1+"koltuk_kayit.txt";
           // dosya_yolu=koltuk_yol4;
            const char*yol_iptal=iptal_yol.c_str();
            ifstream koltuk_bilgisi(yol_iptal,ios::in);
            ofstream test5_dosya_yaz("test_dosya5.txt",ios::out|ios::app);
            t=0;
              while(true){
                koltuk_bilgisi>>koltuklar2;
                satirim=koltuklar2;
                 if( koltuk_bilgisi.eof() ) break;
                 while(t<6){
                   pos=koltuklar2.find(delimiter);
                   parca=koltuklar2.substr(0,pos);
                   koltuklar2.erase(0,pos+1);
                   if(t==0){
                    bilet_seferno=parca;
                   }
                    if(t==1){
                    bilet_koltukno=parca;
                   }

                    if(t==2){
                    bilet_yolcu_adi=parca;
                   }
                    if(t==3){
                    bilet_yolcu_cins=parca;
                   }
                   if(t==4){
                    koltuk_durum=parca;
                   }
                   if(t==5){
                    bilet_fiyat=parca;
                   }
                   ++t;
                 }
                  if(sefer_no1==bilet_seferno && bilet_koltukno==koltuk_numara_iptal){
                    test5_dosya_yaz<<bilet_seferno<<"-"<<bilet_koltukno<<"-"<<"ISIMSIZ"<<"-"<<"BOS"<<"-"<<"BOS"<<"-"<<bilet_fiyat<<"\n";

                  }
                  else{
                    test5_dosya_yaz<<satirim<<"\n";
                  }
                 t=0;

            }
            test5_dosya_yaz.close();
            koltuk_bilgisi.close();
             remove(yol_iptal);
             rename("test_dosya5.txt",yol_iptal);
             cout<<"Satis iptali basari ile gerceklesti"<<endl;
            }
            if(bilet_menu_secim==0){
                break;
            }
          }
    }
    if(ana_menu_secim==0){
        break;
    }
    }
    return 0;
}
