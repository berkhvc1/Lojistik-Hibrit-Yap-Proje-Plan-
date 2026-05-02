# Lojistik Yönetim Sistemi (Hibrit Veri Yapıları)

Bu proje, Kırklareli Üniversitesi Yazılım Mühendisliği bölümü Veri Yapıları ve Algoritmalar dersi kapsamında C dili kullanılarak geliştirilmiş bir final projesidir. Sistem, kargo paketlerinin indekslenmesi ve şehirler arası lojistik rotalarının oluşturulması için **Hash Tablosu (Hash Table)** ve **Graf (Graph)** veri yapılarının hibrit bir modelde kullanılmasını sağlar.

## 👨‍💻 Geliştirici Bilgileri
* **Ad Soyad:** Bekir Berk Kahveci
* **Üniversite:** Kırklareli Üniversitesi - Yazılım Mühendisliği

## ⚙️ Teknik Özellikler ve Algoritmalar
Proje, öğrenci numarasının son iki hanesi (**11**) kuralına göre özel olarak yapılandırılmıştır:

1. **Paket Yönetimi (Hash Tablosu):**
   * **Hash Fonksiyonu:** Tip B (Katlama / Folding Metodu) kullanılarak Paket ID'leri parçalanıp indekslenmiştir.
   * **Çakışma Yönetimi:** Açık Adresleme (Linear Probing) stratejisi uygulanmıştır. Çakışan veriler dizideki bir sonraki uygun boş slota (O(1) veya O(n) karmaşıklığında) yerleştirilir.

2. **Rota Planlaması (Graf Yapısı):**
   * Şehirler arası bağlantılar Bağlı Liste (Adjacency List) mantığıyla dinamik olarak (malloc ile) yönetilmektedir.
   * **Gezinme Algoritması:** Şehirler arası rotanın listelenmesinde Derinlik Öncelikli Arama (**DFS** - Depth First Search) kullanılmıştır.

3. **Dinamik Bellek Yönetimi:**
   * C dilinin doğası gereği çalışma zamanında (runtime) Heap bölgesinde ayrılan tüm düğümler (Nodes), program sonlandırılırken free() fonksiyonu ile sisteme iade edilerek "Memory Leak" (Bellek Sızıntısı) engellenmiştir.

## 📁 Proje Dosya Yapısı
* main.c : Kullanıcı arayüzü (Menü) ve sistemin ana kontrolcüsü.
* hash.c / hash.h : Paket ekleme, Hash Tip B algoritması ve doğrusal arama (Linear Probing) işlevleri.
* graph.c / graph.h : Şehir düğümlerinin oluşturulması, bağlantıların (Edge) kurulması, DFS gezinmesi ve belleğin temizlenmesi (Free).

## 🚀 Kurulum ve Çalıştırma

Projeyi bilgisayarınızda derlemek ve çalıştırmak için sisteminizde GCC derleyicisinin (MinGW vb.) kurulu olması gerekmektedir.

Terminal veya komut satırını açıp dosyaların bulunduğu dizine gidin ve aşağıdaki komutları sırasıyla çalıştırın:

1. Derleme:
gcc main.c hash.c graph.c -o lojistik

2. Çalıştırma:
./lojistik

(Not: Windows kullanıyorsanız ./lojistik yerine lojistik.exe yazarak çalıştırabilirsiniz.)
