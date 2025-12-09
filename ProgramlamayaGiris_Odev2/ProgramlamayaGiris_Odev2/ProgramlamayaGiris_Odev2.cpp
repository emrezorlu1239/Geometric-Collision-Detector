/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				         PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...: 02
**				ÖĞRENCİ ADI......:Emre Zorlu
**				ÖĞRENCİ NUMARASI.: B241210037
**				DERS GRUBU ......: A grubu
**
****************************************************************************/


//Kütüphaneler
#include <iostream> //Giriş çıkış işlemleri için 
#include <cmath> // Karekök ve trigonometrik işlemler için
#include <clocale> // Türkçe karakter desteği için
#include <limits> // Giriş tamponunu temizlemek için
#include <cstdlib> // Rastgele sayı üretimi (rand, srand) için
#include <ctime> // Rastgelelik çekirdeği (time) için

//Namespaceler
using namespace std;

// Rastgele sayı üretmek için yardımcı makro (Min ve Max arasında double üretir)
#define RASTGELE(min, max) (min + (rand() / (double)RAND_MAX) * (max - min))


// KOORDİNAT SİSTEMİ SINIFLARI                                 

// 2 boyutlu koordinat sistemi sınıfı
class N2b {

    public:

        // Üye değişkenler
        double x_ekseni, y_ekseni;

        // Kurucu fonksiyon ile eksen değerlerinin atanması
        N2b(double x_konum = 0, double y_konum = 0) : x_ekseni(x_konum), y_ekseni(y_konum) {}


        // Toplama operatörünün aşırı yüklenmesi
        N2b operator+(N2b diger_nesne) {

			// Yeni bir N2b nesnesi döndürülür
            return N2b(x_ekseni + diger_nesne.x_ekseni, y_ekseni + diger_nesne.y_ekseni);

        }

};


// 3 boyutlu koordinat sistemi sınıfı
class N3b : public N2b {

    public:

        // Üye değişkenler
        double z_ekseni;

        // Kurucu fonksiyon ile eksen değerlerinin atanması
         N3b(double x_konum = 0, double y_konum = 0, double z_konum = 0) : N2b(x_konum, y_konum), z_ekseni(z_konum) {}


        // Toplama operatörünün aşırı yüklenmesi
        N3b operator+(N3b diger_nesne) {
            
			// Yeni bir N3b nesnesi döndürülür
            return N3b(x_ekseni + diger_nesne.x_ekseni, y_ekseni + diger_nesne.y_ekseni, z_ekseni + diger_nesne.z_ekseni);

        }

};


// GEOMETRİK ŞEKİL SINIFLARI                                  

//2 boyutlu geometrik şekil sınıfı
class Geo2D {

    public:

        //2 boyutlu geometrik cisimler için geometrik şekil sınıfı
        N2b agirlik_merkezi;

        //kurucu fonksiyon ile ağırlık merkezinin atanması
        Geo2D(double x_konumu = 0, double y_konumu = 0) :
        agirlik_merkezi(x_konumu, y_konumu) { }
        
};

//3 boyutlu geometrik şekil sınıfı
class Geo3D {

    public:

        //3 boyutlu geometrik cisimler için geometrik şekil sınıfı
        N3b agirlik_merkezi;

        //kurucu fonksiyon ile ağırlık merkezinin atanması
        Geo3D(double x_konumu = 0, double y_konumu = 0, double z_konumu = 0) :
        agirlik_merkezi(x_konumu, y_konumu, z_konumu) { }

};

// Kare özelliklerini belirleme sınıfı
class Kare : public Geo2D {

    public:

        // Üye değişkenler
        double kenar;

        // Kurucu fonksiyon ile kenar uzunluğunun ve ağırlık merkezinin atanması
        Kare(double kenar_uzunluk, double x_konumu = 0, double y_konumu = 0) :
        Geo2D(x_konumu, y_konumu), kenar(kenar_uzunluk) { }

};

// Dikdörtgen özelliklerini belirleme sınıfı
class Dikdortgen : public Geo2D {

    public:

        // Üye değişkenler
        double uzun_kenar, kisa_kenar;

        // Kurucu fonksiyon ile kenar uzunluklarının ve ağırlık merkezinin atanması
        Dikdortgen(double uzunKenar_uzunluk, double kisaKenar_uzunluk, double x_konumu = 0, double y_konumu = 0) :
        Geo2D(x_konumu, y_konumu), uzun_kenar(uzunKenar_uzunluk), kisa_kenar(kisaKenar_uzunluk) {  }

};

// Çember özelliklerini belirleme sınıfı
class Cember : public Geo2D {

    public:

        // Üye değişkenler
        double yaricap;

        // Kurucu fonksiyon ile yarıçapın ve ağırlık merkezinin atanması
        Cember(double yaricap_uzunluk, double x_konumu = 0, double y_konumu = 0) :
        Geo2D(x_konumu, y_konumu), yaricap(yaricap_uzunluk) { }

};

// Küre özelliklerini belirleme sınıfı
class Kure : public Geo3D {

    public:

        // Üye değişkenler
        double yaricap;

        // Kurucu fonksiyon ile yarıçapın ve ağırlık merkezinin atanması
        Kure(double yaricap_uzunluk, double x_konumu = 0, double y_konumu = 0, double z_konumu = 0) :
        Geo3D(x_konumu, y_konumu, z_konumu), yaricap(yaricap_uzunluk) { }

};

// Silindir özelliklerini belirleme sınıfı
class Silindir : public Geo3D {

    public:

         // Üye değişkenler
        double yaricap, yukseklik;
        // Kurucu fonksiyon ile yarıçapın, yüksekliğin ve ağırlık merkezinin atanması

        Silindir(double yaricap_uzunluk, double yukseklik_uzunluk, double x_konumu = 0, double y_konumu = 0, double z_konumu = 0) :
        Geo3D(x_konumu, y_konumu, z_konumu), yaricap(yaricap_uzunluk), yukseklik(yukseklik_uzunluk) { }

};


// KOORDİNATLARI BİRBİRİNE DÖNŞTÜRME SINIFLARI                        

// Polar ve Silindirik koordinat sistemi ile kartezyen sistemi arasında dönüşüm yapma sınıfı
class KoordinatDonustur {

    public:

        // Polar dönüşüm için 2 boyutlu struct tanımı 
        struct polar_2b_dizi {

             double mesafe = 0;
             double aci = 0;

        };

        // Silindirik koordinat sistemi (r, theta, z) yapısındadır.
        struct silindirik_dizi {

            double mesafe = 0;      // r (radius)
            double aci_xy = 0;      // theta (açı)
            double z_yukseklik = 0; // z (yükseklik)

        };

        // 2 boyutlu kartezyen koordinatları polar koordinatlara dönüştürme fonksiyonu
        static polar_2b_dizi K2btoK2bpolar(N2b tutulacak_deger) {

             polar_2b_dizi polar_dizi;
             polar_dizi.mesafe = sqrt(tutulacak_deger.x_ekseni * tutulacak_deger.x_ekseni + tutulacak_deger.y_ekseni * tutulacak_deger.y_ekseni);
             polar_dizi.aci = atan2(tutulacak_deger.y_ekseni, tutulacak_deger.x_ekseni);
             return polar_dizi;

        }

        // 2 boyutlu polar koordinatları kartezyen koordinatlara dönüştürme fonksiyonu
        static N2b K2bpolartoK2bk(double mesafe, double aci) {

             double x = mesafe * cos(aci);
             double y = mesafe * sin(aci);
             return N2b(x, y);

        }

        // 3 boyutlu kartezyen koordinatları silindirik koordinatlara dönüştürme fonksiyonu
         static silindirik_dizi K3BtoK3bsilindir(N3b tutulacak_deger) {

             silindirik_dizi silindirik_veri;
             silindirik_veri.mesafe = sqrt(tutulacak_deger.x_ekseni * tutulacak_deger.x_ekseni + tutulacak_deger.y_ekseni * tutulacak_deger.y_ekseni);
             silindirik_veri.aci_xy = atan2(tutulacak_deger.y_ekseni, tutulacak_deger.x_ekseni);
             silindirik_veri.z_yukseklik = tutulacak_deger.z_ekseni;
             return silindirik_veri;

         }

         // 3 boyutlu silindirik koordinatları kartezyen koordinatlara dönüştürme fonksiyonu
         static N3b K3bsilindirtoK3B(double mesafe, double aci_xy, double z_yukseklik) {
    
             double x = mesafe * cos(aci_xy);
             double y = mesafe * sin(aci_xy);
             double z = z_yukseklik;
             return N3b(x, y, z);

         }

};


// ÇARPIŞMALARI KONTROL ETME SINIFLARI                            

class Carpisma {

public:


    //2 karenin çarpışmasının kontrol edilmesi
    static bool karelerCarpisma(Kare k1, Kare k2) {

        // İki karenin sınırlarını kontrol et
        // X ekseni üzerindeki çakışma kontrolü
        bool cakisma_x = abs(k1.agirlik_merkezi.x_ekseni - k2.agirlik_merkezi.x_ekseni) <
            (k1.kenar / 2 + k2.kenar / 2);

        // Y ekseni üzerindeki çakışma kontrolü
        bool cakisma_y = abs(k1.agirlik_merkezi.y_ekseni - k2.agirlik_merkezi.y_ekseni) <
            (k1.kenar / 2 + k2.kenar / 2);

        // Çakışma durumu kontrolünü döndür
        return cakisma_x && cakisma_y;

    }


    //2 dikdörtgenin çarpışmasının kontrol edilmesi
    static bool dikdortgenlerCarpisma(Dikdortgen d1, Dikdortgen d2) {

        // İki dikdörtgenin sınırlarını kontrol et
        // X ekseni üzerindeki çakışma kontrolü
        bool cakisma_x = abs(d1.agirlik_merkezi.x_ekseni - d2.agirlik_merkezi.x_ekseni) <
            (d1.uzun_kenar / 2 + d2.uzun_kenar / 2);

        // Y ekseni üzerindeki çakışma kontrolü
        bool cakisma_y = abs(d1.agirlik_merkezi.y_ekseni - d2.agirlik_merkezi.y_ekseni) <
            (d1.kisa_kenar / 2 + d2.kisa_kenar / 2);

        // Çakışma durumu kontrolünü döndür
        return cakisma_x && cakisma_y;

    }

    //2 çemberin çarpışmasının kontrol edilmesi
    static bool cemberlerCarpisma(Cember c1, Cember c2) {

        // İki çemberin merkezleri arasındaki mesafeyi hesapla
        double x_mesafeFark = c1.agirlik_merkezi.x_ekseni - c2.agirlik_merkezi.x_ekseni;
        double y_mesafeFark = c1.agirlik_merkezi.y_ekseni - c2.agirlik_merkezi.y_ekseni;

        // Merkezler arasındaki mesafeyi değişkene ata
        double mesafe = sqrt(x_mesafeFark * x_mesafeFark + y_mesafeFark * y_mesafeFark);

        // Çakışma durumu kontrolünü döndür
        return mesafe < (c1.yaricap + c2.yaricap);

    }


    //2 kürenin çarpışmasının kontrol edilmesi
    static bool kurelerCarpisma(Kure k1, Kure k2) {

        // İki kürenin merkezleri arasındaki mesafeyi hesapla
        double x_mesafeFark = k1.agirlik_merkezi.x_ekseni - k2.agirlik_merkezi.x_ekseni;
        double y_mesafeFark = k1.agirlik_merkezi.y_ekseni - k2.agirlik_merkezi.y_ekseni;
        double z_mesafeFark = k1.agirlik_merkezi.z_ekseni - k2.agirlik_merkezi.z_ekseni;

        // Merkezler arasındaki mesafeyi değişkene ata
        double mesafe = sqrt(x_mesafeFark * x_mesafeFark + y_mesafeFark * y_mesafeFark + z_mesafeFark * z_mesafeFark);

        // Çakışma durumu kontrolünü döndür
        return mesafe < (k1.yaricap + k2.yaricap);

    }

    //2 silindirin çarpışmasının kontrol edilmesi
    static bool silindirlerCarpisma(Silindir s1, Silindir s2) {

        // 1. ADIM: Çember Çarpışması Kontrolü (X ve Y düzlemi)
        double dx = s1.agirlik_merkezi.x_ekseni - s2.agirlik_merkezi.x_ekseni;
        double dy = s1.agirlik_merkezi.y_ekseni - s2.agirlik_merkezi.y_ekseni;

        // Yatay düzlemdeki mesafe (Hipotenüs)
        double mesafe_xy = sqrt(dx * dx + dy * dy);

        // Eğer çemberler değmiyorsa, silindirler de çarpışmaz.
        bool cember_cakisma = mesafe_xy < (s1.yaricap + s2.yaricap);

        // 2. ADIM: Yükseklik (Z ekseni) Kontrolü
        // Silindir merkezleri Z ekseninde nerede?
        // Bu mantıkta merkez noktasının silindirin tam ortasında olduğunu varsayıyoruz.
        bool yukseklik_cakisma = abs(s1.agirlik_merkezi.z_ekseni - s2.agirlik_merkezi.z_ekseni) <
            (s1.yukseklik / 2 + s2.yukseklik / 2);

        // Her iki koşul da sağlanıyorsa çarpışma vardır.
        return cember_cakisma && yukseklik_cakisma;

    }

    static bool kareDikdortgenCarpisma(Kare k, Dikdortgen d) {

        // Kareyi de bir dikdörtgen gibi düşünüyoruz
        bool cakisma_x = abs(k.agirlik_merkezi.x_ekseni - d.agirlik_merkezi.x_ekseni) < (k.kenar / 2 + d.uzun_kenar / 2);
        bool cakisma_y = abs(k.agirlik_merkezi.y_ekseni - d.agirlik_merkezi.y_ekseni) < (k.kenar / 2 + d.kisa_kenar / 2);
        return cakisma_x && cakisma_y;

    }

    // 1 dikdörtgen - 1 çember çarpışması
    static bool dikdortgenCemberCarpisma(Dikdortgen d, Cember c) {

        // Dikdörtgenin merkezine göre sınırları (yarı genişlik ve yarı yükseklik)
        double yarimGenislik = d.uzun_kenar / 2.0;
        double yarimYukseklik = d.kisa_kenar / 2.0;

        // Çemberin merkezi ile Dikdörtgenin merkezi arasındaki fark vektörü
        double farkX = c.agirlik_merkezi.x_ekseni - d.agirlik_merkezi.x_ekseni;
        double farkY = c.agirlik_merkezi.y_ekseni - d.agirlik_merkezi.y_ekseni;

        // Fark vektörünü dikdörtgenin boyutlarına hapsederek en yakın noktayı buluyoruz.
        double enYakinX = max(-yarimGenislik, min(farkX, yarimGenislik));
        double enYakinY = max(-yarimYukseklik, min(farkY, yarimYukseklik));

        // En yakın nokta ile çember merkezi arasındaki kalan mesafe
        double mesafeX = farkX - enYakinX;
        double mesafeY = farkY - enYakinY;

        // Pisagor teoremi (karekök almadan kareler üzerinden karşılaştırma)
        return (mesafeX * mesafeX + mesafeY * mesafeY) < (c.yaricap * c.yaricap);

    }

    //  kare - çember çarpışması
    static bool kareCemberCarpisma(Kare k, Cember c) {

        // Kare boyutları
        double yarimKenar = k.kenar / 2.0;

        // Merkezler arası fark
        double farkX = c.agirlik_merkezi.x_ekseni - k.agirlik_merkezi.x_ekseni;
        double farkY = c.agirlik_merkezi.y_ekseni - k.agirlik_merkezi.y_ekseni;

        // Sınırlama  işlemi
        double enYakinX = max(-yarimKenar, min(farkX, yarimKenar));
        double enYakinY = max(-yarimKenar, min(farkY, yarimKenar));

        // Mesafe hesaplama
        double mesafeX = farkX - enYakinX;
        double mesafeY = farkY - enYakinY;

        return (mesafeX * mesafeX + mesafeY * mesafeY) < (c.yaricap * c.yaricap);

    }

    // küre - silindir çarpışması
    static bool kureSilindirCarpisma(Kure k, Silindir s) {

        // Silindirin alt ve üst sınırlarını belirle
        double silindirAltZ = s.agirlik_merkezi.z_ekseni - (s.yukseklik / 2.0);
        double silindirUstZ = s.agirlik_merkezi.z_ekseni + (s.yukseklik / 2.0);

        // Eğer küre silindirin tepesindeyse, en yakın nokta üst kapaktır.
        // Eğer küre silindirin altındaysa, en yakın nokta alt kapaktır.
        // Ortadaysa, kürenin kendi Z değeridir.
        double enYakinZ = max(silindirAltZ, min(k.agirlik_merkezi.z_ekseni, silindirUstZ));

        // Küre merkezi ile Silindir merkezi arasındaki yatay farklar
        double farkX = k.agirlik_merkezi.x_ekseni - s.agirlik_merkezi.x_ekseni;
        double farkY = k.agirlik_merkezi.y_ekseni - s.agirlik_merkezi.y_ekseni;

        // Yatay mesafe (Pisagor)
        double mesafeXY = sqrt(farkX * farkX + farkY * farkY);

        double enYakinX, enYakinY;

        // Eğer küre merkezi, silindirin yarıçapı içindeyse (yani silindirin içindeyse veya üstündeyse)
        if (mesafeXY < s.yaricap) {

            // En yakın nokta, kürenin kendi X,Y koordinatlarıdır (İçeride olduğu için)
            enYakinX = k.agirlik_merkezi.x_ekseni;
            enYakinY = k.agirlik_merkezi.y_ekseni;

        }

        else {

            // Eğer küre dışarıdaysa, en yakın nokta silindirin dış kabuğudur (çemberin kenarı).
            // Benzer üçgen mantığıyla veya birim vektörle o noktayı buluyoruz:
            // (fark / mesafe) bize yönü verir, bunu yarıçapla çarparız.
            enYakinX = s.agirlik_merkezi.x_ekseni + (farkX / mesafeXY) * s.yaricap;
            enYakinY = s.agirlik_merkezi.y_ekseni + (farkY / mesafeXY) * s.yaricap;

        }

        // Bulduğumuz "En Yakın Nokta" (enYakinX, enYakinY, enYakinZ) ile 
        // Küre Merkezi arasındaki mesafeyi hesapla.

        double dx = k.agirlik_merkezi.x_ekseni - enYakinX;
        double dy = k.agirlik_merkezi.y_ekseni - enYakinY;
        double dz = k.agirlik_merkezi.z_ekseni - enYakinZ;

        // Mesafe kareleri toplamı
        double mesafeKare = (dx * dx) + (dy * dy) + (dz * dz);

        // Bu mesafe, kürenin yarıçapından küçükse (veya eşitse) çarpışma vardır.
        return mesafeKare < (k.yaricap * k.yaricap);

    }

};

//ÇIKTILAR İÇİN YARDIMCI FONKSİYONLAR

// Sonuçları ekrana yazdırmak için
void sonucYazdir(string testAdi, bool sonuc) {

    cout << testAdi << ": ";
    if (sonuc) cout << "ÇARPIŞMA VAR!" << endl;
    else cout << "Çarpışma Yok." << endl;

}

// Kare için bilgi yazdırma
void bilgiYazdir(string ad, Kare k) {

    // Polar hesaplama
    KoordinatDonustur::polar_2b_dizi polar = KoordinatDonustur::K2btoK2bpolar(k.agirlik_merkezi);
    double derece = polar.aci * 180.0 / 3.14159;

	//Ekrana yazdırma
    cout << ad << " -> ";
    cout << "x=" << k.agirlik_merkezi.x_ekseni << ", y=" << k.agirlik_merkezi.y_ekseni;
    cout << " | Kenar=" << k.kenar;
    cout << " | (Polar: r=" << polar.mesafe << ", açı=" << derece << " drc)" << endl;

}

// Dikdörtgen için bilgi yazdırma
void bilgiYazdir(string ad, Dikdortgen d) {

    // Polar hesaplama
    KoordinatDonustur::polar_2b_dizi polar = KoordinatDonustur::K2btoK2bpolar(d.agirlik_merkezi);
    double derece = polar.aci * 180.0 / 3.14159;

	//Ekrana yazdırma
    cout << ad << " -> ";
    cout << "x=" << d.agirlik_merkezi.x_ekseni << ", y=" << d.agirlik_merkezi.y_ekseni;
    cout << " | Uzun K.=" << d.uzun_kenar << ", Kısa K.=" << d.kisa_kenar;
    cout << " | (Polar: r=" << polar.mesafe << ", açı=" << derece << " drc)" << endl;

}

// Çember için bilgi yazdırma
void bilgiYazdir(string ad, Cember c) {

    // Polar hesaplama
    KoordinatDonustur::polar_2b_dizi polar = KoordinatDonustur::K2btoK2bpolar(c.agirlik_merkezi);
    double derece = polar.aci * 180.0 / 3.14159;

	//Ekrana yazdırma
    cout << ad << " -> ";
    cout << "x=" << c.agirlik_merkezi.x_ekseni << ", y=" << c.agirlik_merkezi.y_ekseni;
    cout << " | Yarıçap=" << c.yaricap;
    cout << " | (Polar: r=" << polar.mesafe << ", açı=" << derece << " drc)" << endl;

}

// Küre için bilgi yazdırma
void bilgiYazdir(string ad, Kure k) {

    // Hesaplama 
    KoordinatDonustur::silindirik_dizi silindirik = KoordinatDonustur::K3BtoK3bsilindir(k.agirlik_merkezi);
    double derece = silindirik.aci_xy * 180.0 / 3.14159;

	//Ekrana yazdırma
    cout << ad << " -> ";
    cout << "x=" << k.agirlik_merkezi.x_ekseni << ", y=" << k.agirlik_merkezi.y_ekseni << ", z=" << k.agirlik_merkezi.z_ekseni;
    cout << " | Yarıçap=" << k.yaricap;
    cout << " | (Silindirik: r=" << silindirik.mesafe << ", açı=" << derece << " drc, z=" << silindirik.z_yukseklik << ")" << endl;

}

// Silindir için bilgi yazdırma 
void bilgiYazdir(string ad, Silindir s) {

    // Hesaplama
    KoordinatDonustur::silindirik_dizi silindirik = KoordinatDonustur::K3BtoK3bsilindir(s.agirlik_merkezi);
    double derece = silindirik.aci_xy * 180.0 / 3.14159;

	//Ekrana yazdırma
    cout << ad << " -> ";
    cout << "x=" << s.agirlik_merkezi.x_ekseni << ", y=" << s.agirlik_merkezi.y_ekseni << ", z=" << s.agirlik_merkezi.z_ekseni;
    cout << " | Yarıçap=" << s.yaricap << ", Yükseklik=" << s.yukseklik;
    cout << " | (Silindirik: r=" << silindirik.mesafe << ", açı=" << derece << " drc, z=" << silindirik.z_yukseklik << ")" << endl;

}


//ÇARPIŞMALARIN MAİN FONKSİYONDA KONTROLÜ
int main() {

    // Rastgele sayı üretimi için çekirdek (zaman tabanlı)
    srand(time(0));

	// Türkçe karakter desteği
    setlocale(LC_ALL, "Turkish");

    // ANA MENÜ DÖNGÜSÜ
    while (true) {
        cout << "\n========================================" << endl;
        cout << "      ÇARPIŞMA TESTİ PROGRAMI" << endl;
        cout << "========================================" << endl;
        cout << "Ekrana istediğiniz menünün numarasını yazmanız yeterli.Başka numara yazmayın" << endl;
        cout << "Aşağıda çarpışmaları hazır veriler üzerinden ya da sizin girdiğiniz veriler üzerinden olmasını seçin:" << endl;
        cout << "1. Hazır Test Senaryolarını Çalıştır (Rastgele Değerlerle)" << endl;
        cout << "2. Yeni Test Girişi Yap (Kullanıcı Tanımlı)" << endl;
        cout << "3. Çıkış" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Seçiminiz: ";

        // Yanlış girilişin kontrol edilmesi için kullanılacak değişken
        int anaSecim;

        //Yanlış değerin girilip girilmediğinin kontrolü
        if (!(cin >> anaSecim)) 
        {
            
            // Sayı girilmezse hata kontrolü
            cout << "Hatalı giriş! Lütfen sayı giriniz." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;

        }

        // 3 yazılmışsa çalışacak kodlar
        if (anaSecim == 3) 
        {

			// Çıkış seçeneği
            cout << "Programdan çıkılıyor..." << endl;
            break; // Döngüden çık, programı bitir.

        }

        // 1 yazılmışsa çalışacak kodlar
        else if (anaSecim == 1) 
        {

			// HAZIR TEST SENARYOLARI (RASTGELE VERİLER)
            cout << "\n--- HAZIR ÖRNEK TESTLER BAŞLIYOR (RASTGELE VERİLER) ---\n" << endl;

            cout << "NOT: Hazır test verileri her çalıştırıldığında rastgele üretilir." << endl;
            cout << "     Boyutlar 1-20 arası, Konumlar -50 ile +50 arasıdır." << endl << endl;

            // NESNELERİN OLUŞTURULMASI (RASTGELE veriler)
            // Kareler (Kenar, X, Y)
            Kare kare1(RASTGELE(1, 20), RASTGELE(-50, 50), RASTGELE(-50, 50));
            Kare kare2(RASTGELE(1, 20), RASTGELE(-50, 50), RASTGELE(-50, 50));
            Kare kare3(RASTGELE(1, 20), RASTGELE(-50, 50), RASTGELE(-50, 50));
            Kare kare4(RASTGELE(1, 20), RASTGELE(-50, 50), RASTGELE(-50, 50));

            // Dikdörtgenler (Uzun, Kısa, X, Y)
            Dikdortgen dikdortgen1(RASTGELE(10, 30), RASTGELE(1, 10), RASTGELE(-50, 50), RASTGELE(-50, 50));
            Dikdortgen dikdortgen2(RASTGELE(10, 30), RASTGELE(1, 10), RASTGELE(-50, 50), RASTGELE(-50, 50));
            Dikdortgen dikdortgen3(RASTGELE(10, 30), RASTGELE(1, 10), RASTGELE(-50, 50), RASTGELE(-50, 50));

            // Çemberler (Yarıçap, X, Y)
            Cember cember1(RASTGELE(1, 15), RASTGELE(-50, 50), RASTGELE(-50, 50));
            Cember cember2(RASTGELE(1, 15), RASTGELE(-50, 50), RASTGELE(-50, 50));
            Cember cember3(RASTGELE(1, 15), RASTGELE(-50, 50), RASTGELE(-50, 50));
            Cember cember4(RASTGELE(1, 15), RASTGELE(-50, 50), RASTGELE(-50, 50));
            Cember cember5(RASTGELE(1, 15), RASTGELE(-50, 50), RASTGELE(-50, 50));

            // Küreler (Yarıçap, X, Y, Z)
            Kure kure1(RASTGELE(1, 15), RASTGELE(-50, 50), RASTGELE(-50, 50), RASTGELE(-50, 50));
            Kure kure2(RASTGELE(1, 15), RASTGELE(-50, 50), RASTGELE(-50, 50), RASTGELE(-50, 50));

            // Silindirler (Yarıçap, Yükseklik, X, Y, Z)
            Silindir silindir1(RASTGELE(1, 15), RASTGELE(5, 30), RASTGELE(-50, 50), RASTGELE(-50, 50), RASTGELE(-50, 50));
            Silindir silindir2(RASTGELE(1, 15), RASTGELE(5, 30), RASTGELE(-50, 50), RASTGELE(-50, 50), RASTGELE(-50, 50));
            Silindir silindir3(RASTGELE(1, 15), RASTGELE(5, 30), RASTGELE(-50, 50), RASTGELE(-50, 50), RASTGELE(-50, 50));

            // BİLGİLERİ YAZDIR
            cout << "[ÜRETİLEN RASTGELE ŞEKİL BİLGİLERİ]" << endl;
            bilgiYazdir("Kare 1", kare1);
            bilgiYazdir("Kare 2", kare2);
            bilgiYazdir("Kare 3", kare3);
            cout << "-------------------------" << endl;
            bilgiYazdir("Dikdörtgen 1", dikdortgen1);
            bilgiYazdir("Dikdörtgen 2", dikdortgen2);
            cout << "-------------------------" << endl;
            bilgiYazdir("Çember 1", cember1);
            bilgiYazdir("Çember 2", cember2);
            cout << "-------------------------" << endl;
            bilgiYazdir("Küre 1", kure1);
            bilgiYazdir("Küre 2", kure2);
            cout << "-------------------------" << endl;
            bilgiYazdir("Silindir 1", silindir1);
            bilgiYazdir("Silindir 2", silindir2);
            cout << endl;

            // TESTLERİ ÇALIŞTIR
            cout << "[ÇARPIŞMA TEST SONUÇLARI]" << endl;
            sonucYazdir("1. Kare 1 ve Kare 2 Testi", Carpisma::karelerCarpisma(kare1, kare2));
            sonucYazdir("2. Kare 1 ve Kare 3 Testi", Carpisma::karelerCarpisma(kare1, kare3));
            sonucYazdir("3. Dikdörtgen 1 ve Dikdörtgen 2 Testi", Carpisma::dikdortgenlerCarpisma(dikdortgen1, dikdortgen2));
            sonucYazdir("4. Çember 1 ve Çember 2 Testi", Carpisma::cemberlerCarpisma(cember1, cember2));
            sonucYazdir("5. Kare 4 ve Çember 3 Testi", Carpisma::kareCemberCarpisma(kare4, cember3));
            sonucYazdir("6. Dikdörtgen 3 ve Çember 4 Testi", Carpisma::dikdortgenCemberCarpisma(dikdortgen3, cember4));
            sonucYazdir("7. Dikdörtgen 3 ve Çember 5 Testi", Carpisma::dikdortgenCemberCarpisma(dikdortgen3, cember5));
            sonucYazdir("8. Küre 1 ve Küre 2 Testi", Carpisma::kurelerCarpisma(kure1, kure2));
            sonucYazdir("9. Silindir 1 ve Silindir 2 Testi", Carpisma::silindirlerCarpisma(silindir1, silindir2));
            sonucYazdir("10. Silindir 1 ve Silindir 3 Testi", Carpisma::silindirlerCarpisma(silindir1, silindir3));
            sonucYazdir("11. Küre 1 ve Silindir 1 Testi", Carpisma::kureSilindirCarpisma(kure1, silindir1));
            sonucYazdir("12. Küre 2 ve Silindir 1 Testi", Carpisma::kureSilindirCarpisma(kure2, silindir1));

			// BİTİRME MESAJI
            cout << "\n(Hazır testler tamamlandı.)" << endl;

        }

        // 2 yazılmışsa çalışacak kodlar
        else if (anaSecim == 2) {

            
            // KULLANICI TANIMLI TESTLER
            

            cout << "\n----------------------------------------------------------------" << endl;
            cout << "(!) VERİ GİRİŞİ HAKKINDA BİLGİLENDİRME:" << endl;
            cout << "1. Konum değerleri (X, Y, Z) negatif (-) veya pozitif (+) olabilir." << endl;
            cout << "2. Boyut değerleri (Kenar, Yarıçap, Yükseklik) DAİMA POZİTİF olmalıdır." << endl;
            cout << "   (Örneğin: Yarıçap -5 olamaz, program hatalı çalışabilir.)" << endl;
            cout << "----------------------------------------------------------------" << endl;
			cout << "Ekrana gelecek menülerden şekil türünü ve boyutunu seçip, istenen değerleri giriniz." << endl;
            cout << "İstediğiniz menünün numarasını yazın" << endl;
            cout << "Lütfen çalışmak istediğiniz boyutu seçin:" << endl;
            cout << "1. 2 Boyutlu (2D)" << endl;
            cout << "2. 3 Boyutlu (3D)" << endl;
            int boyutSecim;
            cout << "Seçiminiz (1-2): ";
            cin >> boyutSecim;

            // 1 yazılmışsa çalışacak kodlar
            if (boyutSecim == 1)
            {

                // ------------------ 2D MENÜSÜ ------------------
                cout << "\n--- 2D Cisim Seçimi ---" << endl;
                cout << "1. Kare - Kare" << endl;
                cout << "2. Dikdörtgen - Dikdörtgen" << endl;
                cout << "3. Çember - Çember" << endl;
                cout << "4. Kare - Çember" << endl;
                cout << "5. Dikdörtgen - Çember" << endl;
                int sekilSecim;
                cout << "Seçiminiz: ";
                cin >> sekilSecim;

                // 1 yazılmışsa çalışacak kodlar
                if (sekilSecim == 1) 
                {
                
                   // KARE - KARE
                    double k1_k, k1_x, k1_y;
                    double k2_k, k2_x, k2_y;

                    cout << "\n--- 1. Kare Bilgileri ---" << endl;
                    cout << "Kenar Uzunluğu: "; cin >> k1_k;
                    cout << "Merkez X: "; cin >> k1_x;
                    cout << "Merkez Y: "; cin >> k1_y;

                    cout << "\n--- 2. Kare Bilgileri ---" << endl;
                    cout << "Kenar Uzunluğu: "; cin >> k2_k;
                    cout << "Merkez X: "; cin >> k2_x;
                    cout << "Merkez Y: "; cin >> k2_y;

                    Kare kulK1(k1_k, k1_x, k1_y);
                    Kare kulK2(k2_k, k2_x, k2_y);
                    cout << endl;
                    sonucYazdir("Kullanıcı Kare-Kare Testi", Carpisma::karelerCarpisma(kulK1, kulK2));

                }

                // 2 yazılmışsa çalışacak kodlar
                else if (sekilSecim == 2) 
                {

                    // DIKDORTGEN - DIKDORTGEN
                    double d1_u, d1_k, d1_x, d1_y;
                    double d2_u, d2_k, d2_x, d2_y;

                    cout << "\n--- 1. Dikdörtgen Bilgileri ---" << endl;
                    cout << "Uzun Kenar: "; cin >> d1_u;
                    cout << "Kısa Kenar: "; cin >> d1_k;
                    cout << "Merkez X: "; cin >> d1_x;
                    cout << "Merkez Y: "; cin >> d1_y;

                    cout << "\n--- 2. Dikdörtgen Bilgileri ---" << endl;
                    cout << "Uzun Kenar: "; cin >> d2_u;
                    cout << "Kısa Kenar: "; cin >> d2_k;
                    cout << "Merkez X: "; cin >> d2_x;
                    cout << "Merkez Y: "; cin >> d2_y;

                    Dikdortgen kulD1(d1_u, d1_k, d1_x, d1_y);
                    Dikdortgen kulD2(d2_u, d2_k, d2_x, d2_y);
                    cout << endl;
                    sonucYazdir("Kullanıcı Dikdörtgen-Dikdörtgen Testi", Carpisma::dikdortgenlerCarpisma(kulD1, kulD2));

                }

                // 3 yazılmışsa çalışacak kodlar
                else if (sekilSecim == 3) 
                {

                    // CEMBER - CEMBER
                    double c1_r, c1_x, c1_y;
                    double c2_r, c2_x, c2_y;

                    cout << "\n--- 1. Çember Bilgileri ---" << endl;
                    cout << "Yarıçap: "; cin >> c1_r;
                    cout << "Merkez X: "; cin >> c1_x;
                    cout << "Merkez Y: "; cin >> c1_y;

                    cout << "\n--- 2. Çember Bilgileri ---" << endl;
                    cout << "Yarıçap: "; cin >> c2_r;
                    cout << "Merkez X: "; cin >> c2_x;
                    cout << "Merkez Y: "; cin >> c2_y;

                    Cember kulC1(c1_r, c1_x, c1_y);
                    Cember kulC2(c2_r, c2_x, c2_y);
                    cout << endl;
                    sonucYazdir("Kullanıcı Çember-Çember Testi", Carpisma::cemberlerCarpisma(kulC1, kulC2));

                }

                // 4 yazılmışsa çalışacak kodlar
                else if (sekilSecim == 4) 
                {

                    // KARE - CEMBER
                    double k_k, k_x, k_y;
                    double c_r, c_x, c_y;

                    cout << "\n--- Kare Bilgileri ---" << endl;
                    cout << "Kenar Uzunluğu: "; cin >> k_k;
                    cout << "Merkez X: "; cin >> k_x;
                    cout << "Merkez Y: "; cin >> k_y;

                    cout << "\n--- Çember Bilgileri ---" << endl;
                    cout << "Yarıçap: "; cin >> c_r;
                    cout << "Merkez X: "; cin >> c_x;
                    cout << "Merkez Y: "; cin >> c_y;

                    Kare kulK(k_k, k_x, k_y);
                    Cember kulC(c_r, c_x, c_y);
                    cout << endl;
                    sonucYazdir("Kullanıcı Kare-Çember Testi", Carpisma::kareCemberCarpisma(kulK, kulC));

                }

                // 5 yazılmışsa çalışacak kodlar
                else if (sekilSecim == 5)
                {

                    // DIKDORTGEN - CEMBER
                    double d_u, d_k, d_x, d_y;
                    double c_r, c_x, c_y;

                    cout << "\n--- Dikdörtgen Bilgileri ---" << endl;
                    cout << "Uzun Kenar: "; cin >> d_u;
                    cout << "Kısa Kenar: "; cin >> d_k;
                    cout << "Merkez X: "; cin >> d_x;
                    cout << "Merkez Y: "; cin >> d_y;

                    cout << "\n--- Çember Bilgileri ---" << endl;
                    cout << "Yarıçap: "; cin >> c_r;
                    cout << "Merkez X: "; cin >> c_x;
                    cout << "Merkez Y: "; cin >> c_y;

                    Dikdortgen kulD(d_u, d_k, d_x, d_y);
                    Cember kulC(c_r, c_x, c_y);
                    cout << endl;
                    sonucYazdir("Kullanıcı Dikdörtgen-Çember Testi", Carpisma::dikdortgenCemberCarpisma(kulD, kulC));

                }

                // farklı değer girilmişse çalışacak kodlar
                else 
                {
                    
					// GEÇERSİZ SEÇİM
                    cout << "Geçersiz seçim!" << endl;

                }

            }

            // Menüden 2 yazılmışsa çalışacak kodlar
            else if (boyutSecim == 2) 
            {

                // ------------------ 3D MENÜSÜ ------------------
                cout << "\n--- 3D Cisim Seçimi ---" << endl;
                cout << "1. Küre - Küre" << endl;
                cout << "2. Silindir - Silindir" << endl;
                cout << "3. Küre - Silindir" << endl;
                int sekilSecim;
                cout << "Seçiminiz: ";
                cin >> sekilSecim;

                // 1 yazılmışsa çalışacak kodlar
                if (sekilSecim == 1) 
                {
                    
                    // KURE - KURE
                    double k1_r, k1_x, k1_y, k1_z;
                    double k2_r, k2_x, k2_y, k2_z;

                    cout << "\n--- 1. Küre Bilgileri ---" << endl;
                    cout << "Yarıçap: "; cin >> k1_r;
                    cout << "Merkez X: "; cin >> k1_x;
                    cout << "Merkez Y: "; cin >> k1_y;
                    cout << "Merkez Z: "; cin >> k1_z;

                    cout << "\n--- 2. Küre Bilgileri ---" << endl;
                    cout << "Yarıçap: "; cin >> k2_r;
                    cout << "Merkez X: "; cin >> k2_x;
                    cout << "Merkez Y: "; cin >> k2_y;
                    cout << "Merkez Z: "; cin >> k2_z;

                    Kure kulKu1(k1_r, k1_x, k1_y, k1_z);
                    Kure kulKu2(k2_r, k2_x, k2_y, k2_z);
                    cout << endl;
                    sonucYazdir("Kullanıcı Küre-Küre Testi", Carpisma::kurelerCarpisma(kulKu1, kulKu2));

                }

                // 2 yazılmışsa çalışacak kodlar
                else if (sekilSecim == 2) 
                {
                    
                    // SILINDIR - SILINDIR
                    double s1_r, s1_h, s1_x, s1_y, s1_z;
                    double s2_r, s2_h, s2_x, s2_y, s2_z;

                    cout << "\n--- 1. Silindir Bilgileri ---" << endl;
                    cout << "Yarıçap: "; cin >> s1_r;
                    cout << "Yükseklik: "; cin >> s1_h;
                    cout << "Merkez X: "; cin >> s1_x;
                    cout << "Merkez Y: "; cin >> s1_y;
                    cout << "Merkez Z: "; cin >> s1_z;

                    cout << "\n--- 2. Silindir Bilgileri ---" << endl;
                    cout << "Yarıçap: "; cin >> s2_r;
                    cout << "Yükseklik: "; cin >> s2_h;
                    cout << "Merkez X: "; cin >> s2_x;
                    cout << "Merkez Y: "; cin >> s2_y;
                    cout << "Merkez Z: "; cin >> s2_z;

                    Silindir kulS1(s1_r, s1_h, s1_x, s1_y, s1_z);
                    Silindir kulS2(s2_r, s2_h, s2_x, s2_y, s2_z);
                    cout << endl;
                    sonucYazdir("Kullanıcı Silindir-Silindir Testi", Carpisma::silindirlerCarpisma(kulS1, kulS2));

                }

                // 3 yazılmışsa çalışacak kodlar
                else if (sekilSecim == 3) 
                {
                    
                    // KURE - SILINDIR
                    double k_r, k_x, k_y, k_z;
                    double s_r, s_h, s_x, s_y, s_z;

                    cout << "\n--- Küre Bilgileri ---" << endl;
                    cout << "Yarıçap: "; cin >> k_r;
                    cout << "Merkez X: "; cin >> k_x;
                    cout << "Merkez Y: "; cin >> k_y;
                    cout << "Merkez Z: "; cin >> k_z;

                    cout << "\n--- Silindir Bilgileri ---" << endl;
                    cout << "Yarıçap: "; cin >> s_r;
                    cout << "Yükseklik: "; cin >> s_h;
                    cout << "Merkez X: "; cin >> s_x;
                    cout << "Merkez Y: "; cin >> s_y;
                    cout << "Merkez Z: "; cin >> s_z;

                    Kure kulKu(k_r, k_x, k_y, k_z);
                    Silindir kulS(s_r, s_h, s_x, s_y, s_z);
                    cout << endl;
                    sonucYazdir("Kullanıcı Küre-Silindir Testi", Carpisma::kureSilindirCarpisma(kulKu, kulS));

                }

                // Farklı değer  yazılmışsa çalışacak kodlar
                else 
                {

					// GEÇERSİZ SEÇİM
                    cout << "Geçersiz seçim!" << endl;

                }

            }

            // Boyut seçimi ekranında farklı değer girilmişse çalışacak kodlar
            else 
            {
				// GEÇERSİZ SEÇİM
                cout << "Geçersiz seçim!" << endl;
            }

        }

        // İlk menüde farklı değer yazılmışsa çalışacak kodlar
        else 
        {

			// GEÇERSİZ SEÇİM
            cout << "Geçersiz seçim! Lütfen 1, 2 veya 3 giriniz." << endl;

        }

    }
    
	// Program bitiyor
    return 0;

}
