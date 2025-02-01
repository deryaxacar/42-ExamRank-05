<div align="center">
  <h2>Sınav Çalışma Notları</h2>
</div>

- [Level 1 - cpp_module00](#cpp_module00)
- [cpp_module01](#cpp_module01)

<a name="cpp_module00"></a>
## Level 1 - cpp_module00

`Warlock sınıfı`, `Coplien` formunu takip ederek uygun kapsülleme ve nesne yönelimli prensiplere uygun şekilde tasarlanmıştır. Sınıf, `name` (isim) ve `title` (ünvan) için özel niteliklere sahiptir ve bu nitelikler için getter ve setter metodları sunar. Ayrıca, Warlock'un kendini tanıtması ve yapıcı/yıkıcı mesajlarını işlemesi için metodlar içerir.

**Nitelikler**
- `name`: Warlock'un ismini temsil eden özel bir string niteliği.
- `title`: Warlock'un ünvanını temsil eden özel bir string niteliği.

**Metodlar**
- `getName()`: Warlock'un ismini temsil eden sabit bir string referansı döndürür.
- `getTitle()`: Warlock'un ünvanını temsil eden sabit bir string referansı döndürür.
- `setTitle(const std::string&)`: Warlock'un ünvanını sağlanan string değeriyle ayarlar.
- `introduce() const`: Warlock'u tanıtan bir mesaj yazdırır. Bu mesaj, isim ve ünvanı içerir.

**Yapıcı ve Yıkıcı**
- `Warlock(const std::string&, const std::string&)`: Warlock'u bir isim ve ünvanla başlatan yapıcı metod. Oluşturulduğunda bir mesaj yazdırır.
- `~Warlock()`: Warlock yok edildiğinde bir mesaj yazdıran yıkıcı metod.

**Kısıtlamalar**
- `Warlock sınıfı` kopyalanamaz veya isim ve ünvan olmadan örneklenemez. Kopya yapıcı ve kopya atama operatörü silinerek bu kısıtlama uygulanmıştır.

### Warlock class yapısı:

---

```cpp
#pragma once

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Warlock {
    private:
        string _name;       // Warlock'un ismini tutan özel değişken
        string _title;      // Warlock'un ünvanını tutan özel değişken

    public:
        // Warlock'un ismini döndüren getter metodu (const referans olarak)
        const string& getName() const;

        // Warlock'un ünvanını döndüren getter metodu (const referans olarak)
        const string& getTitle() const;

        // Warlock'un ünvanını ayarlayan setter metodu
        void setTitle(const string& title);

        // Yapıcı metod: Warlock'u isim ve ünvan ile başlatır
        Warlock(const string& name, const string& title);

        // Yıkıcı metod: Warlock yok edildiğinde çağrılır
        ~Warlock();

        // Warlock'u tanıtan mesajı ekrana yazdıran metod
        void introduce() const;
};
```

---

### Açıklamalar:
- `#pragma once`: Bu, başlık dosyasının yalnızca bir kez dahil edilmesini sağlar ve çoklu dahil etme sorunlarını önler.
- `using std::string, using std::cout, using std::endl`: Bu ifadeler, `std::` önekini kullanmadan `string`, `cout` ve `endl` gibi standart kütüphane öğelerine erişim sağlar.
- `_name` ve `_title`: Warlock sınıfının özel nitelikleri. Bu değişkenler, sınıfın iç durumunu temsil eder.
- `getName()` ve `getTitle()`: Warlock'un ismini ve ünvanını döndüren getter metodları. `const` anahtar kelimesi, bu metodların sınıfın iç durumunu değiştirmeyeceğini garanti eder.
- `setTitle():` Warlock'un ünvanını ayarlayan setter metodu. Parametre olarak bir string alır.
- `Warlock(const string& name, const string& title)`: Yapıcı metod. Warlock'u isim ve ünvan ile başlatır.
- `~Warlock()`: Yıkıcı metod. Warlock yok edildiğinde çağrılır ve bir mesaj yazdırır.
- `introduce() const`: Warlock'u tanıtan bir mesajı ekrana yazdıran metod. const anahtar kelimesi, bu metodun sınıfın iç durumunu değiştirmeyeceğini garanti eder.

---

### Beklenen çıktı:

```ssh
~$ ./a.out | cat -e
Richard: This looks like another boring day.$
Richard: I am Richard, Mistress of Magma!$
Richard - Mistress of Magma$
Jack: This looks like another boring day.$
Jack: I am Jack, the Long!$
Jack: I am Jack, the Mighty!$
Jack: My job here is done!$
Richard: My job here is done!$
~$
```

---
