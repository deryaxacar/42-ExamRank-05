<div align="center">
  <h2>Sınav Çalışma Notları</h2>
</div>

- [Level 0 - cpp_module00](#cpp_module00)
- [Level 1 - cpp_module01](#cpp_module01)
- [Level 2 - cpp_module02](#cpp_module02)

---

**Açıklama:** sınavda klasör isimlerini `cpp_module_00` `cpp_module_01` `cpp_module_02`
şeklinde pushlayın. simülatörden çalışırken `cpp_module00` şeklinde `grademe` yapmanız gerekiyor, push yapmanıza gerek yoktur. 

---

<a name="cpp_module00"></a>
## Level 0 - cpp_module00

`Warlock sınıfı`, `Coplien` formunu takip ederek uygun kapsülleme ve nesne yönelimli prensiplere uygun şekilde tasarlanmıştır. Sınıf, `name` (isim) ve `title` (ünvan) için özel niteliklere sahiptir ve bu nitelikler için getter ve setter metodları sunar. Ayrıca, Warlock'un kendini tanıtması ve yapıcı/yıkıcı mesajlarını işlemesi için metodlar içerir.



- **Nitelikler**
  - `name`: Warlock'un ismini temsil eden özel bir string niteliği.

  - `title`: Warlock'un ünvanını temsil eden özel bir string niteliği.

- **Metodlar**
  - `getName()`: Warlock'un ismini temsil eden sabit bir string referansı döndürür.

  - `getTitle()`: Warlock'un ünvanını temsil eden sabit bir string referansı döndürür.

  - `setTitle(const std::string&)`: Warlock'un ünvanını sağlanan string değeriyle ayarlar.

  - `introduce() const`: Warlock'u tanıtan bir mesaj yazdırır. Bu mesaj, isim ve ünvanı içerir.

- **Yapıcı ve Yıkıcı**
  - `Warlock(const std::string&, const std::string&)`: Warlock'u bir isim ve ünvanla başlatan yapıcı metod. Oluşturulduğunda bir mesaj yazdırır.

  - `~Warlock()`: Warlock yok edildiğinde bir mesaj yazdıran yıkıcı metod.

- **Kısıtlamalar**
  - `Warlock sınıfı` kopyalanamaz veya isim ve ünvan olmadan örneklenemez. Kopya yapıcı ve kopya atama operatörü silinerek bu kısıtlama uygulanmıştır.

- **Örnek Class Yapısı**

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
        const string& getName() const; // Warlock'un ismini döndüren getter metodu (const referans olarak)
        const string& getTitle() const; // Warlock'un ünvanını döndüren getter metodu (const referans olarak)
        void setTitle(const string& title); // Warlock'un ünvanını ayarlayan setter metodu

        Warlock(const string& name, const string& title); // Yapıcı metod: Warlock'u isim ve ünvan ile başlatır
        ~Warlock(); // Yıkıcı metod: Warlock yok edildiğinde çağrılır

        void introduce() const; // Warlock'u tanıtan mesajı ekrana yazdıran metod
};
```

---

- **Açıklamalar:**
  - `#pragma once`: Bu, başlık dosyasının yalnızca bir kez dahil edilmesini sağlar ve çoklu dahil etme sorunlarını önler.

  - `using std::string, using std::cout, using std::endl`: Bu ifadeler, `std::` önekini kullanmadan `string`, `cout` ve `endl` gibi standart kütüphane öğelerine erişim sağlar.

  - `_name` ve `_title`: Warlock sınıfının özel nitelikleri. Bu değişkenler, sınıfın iç durumunu temsil eder.

  - `getName()` ve `getTitle()`: Warlock'un ismini ve ünvanını döndüren getter metodları. `const` anahtar kelimesi, bu metodların sınıfın iç durumunu değiştirmeyeceğini garanti eder.

  - `setTitle():` Warlock'un ünvanını ayarlayan setter metodu. Parametre olarak bir string alır.

  - `Warlock(const string& name, const string& title)`: Yapıcı metod. Warlock'u isim ve ünvan ile başlatır.

  - `~Warlock()`: Yıkıcı metod. Warlock yok edildiğinde çağrılır ve bir mesaj yazdırır.

  - `introduce() const`: Warlock'u tanıtan bir mesajı ekrana yazdıran metod. const anahtar kelimesi, bu metodun sınıfın iç durumunu değiştirmeyeceğini garanti eder.

- **00 Beklenen çıktı:**

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

<a name="cpp_module01"></a>
## Level 1 - cpp_module01

`Warlock` sınıfı ile soyut sınıflar olan `ASpell` ve `ATarget`'i ve bunların somut uygulamaları olan Fwoosh ve Dummy sınıflarını uygulamaya odaklanır. Amaç, bir Warlock'un büyüleri öğrenebileceği, unutabileceği ve hedeflere büyü fırlatabileceği bir sistem oluşturmaktır.

- **Dosyalar**

  - `Warlock.hpp` ve `Warlock.cpp`: `Warlock` sınıfının tanımı ve uygulaması.

  - `ASpell.hpp` ve `ASpell.cpp`: `ASpell` sınıfının tanımı ve uygulaması.

  - `ATarget.hpp` ve `ATarget.cpp`: `ATarget` sınıfının tanımı ve uygulaması.

  - `Fwoosh.hpp ve Fwoosh.cpp`: `Fwoosh` sınıfının tanımı ve uygulaması.

  - `Dummy.hpp` ve `Dummy.cpp`: `Dummy` sınıfının tanımı ve uygulaması.

- **Açıklamalar**

  - `Coplien Formu`: Sınıflar, `varsayılan yapıcı`, `kopya yapıcı`, `atama operatörü` ve `yıkıcı` metodları içermelidir.

  - `Soyut Sınıflar`: `ASpell` ve `ATarget` sınıfları, saf sanal metodlar (`clone()`) içermelidir.

  - `Büyü Yönetimi`: `Warlock`, öğrendiği büyüleri bir container'da saklamalı ve bu büyüleri hedeflere fırlatabilmelidir.

---

**1 - Warlock Sınıfı**

`Warlock` sınıfı, bir isim ve ünvan ile temsil edilen büyücüyü ifade eder. Büyüleri öğrenebilir, unutabilir ve hedeflere büyü fırlatabilir.

- **Nitelikler:**

  - `name`: Warlock'un ismini temsil eden bir string.

  - `title`: Warlock'un ünvanını temsil eden bir string.

  - `SpellBook`: Warlock'un bildiği büyüleri saklamak için bir container.

- **Metodlar:**

  - `getName()`: Warlock'un ismini döndürür.

  - `getTitle()`: Warlock'un ünvanını döndürür.

  - `setTitle(const std::string&)`: Warlock'un ünvanını ayarlar.

  - `introduce()`: Warlock'u tanıtan bir mesaj yazdırır.

  - `learnSpell(ASpell*)`: Warlock'a yeni bir büyü öğretir.
    - ```cpp
          // Warlock sınıfının learnSpell metodu, bir büyüyü (ASpell) öğrenmek için kullanılır.
          // Bu metod, büyünün Warlock'un büyü kitabına (_SpellBook) eklenmesini sağlar.
          void Warlock::learnSpell(ASpell* spell) {
          // Büyünün ismi (_SpellBook içinde) aranır.
          // find() metodu, büyünün ismiyle eşleşen bir öğe bulursa iterator döndürür.
          // Bulamazsa _SpellBook.end() döndürür.
            map<string, ASpell*>::iterator it = _SpellBook.find(spell->getName());
    
            // Eğer büyü kitabında bu isimde bir büyü yoksa (it == _SpellBook.end()),
            // büyü kitabına yeni bir büyü eklenir.
            if (it == _SpellBook.end()) {
              // Büyünün bir kopyası oluşturulur (clone() metodu kullanılarak),
              // ve bu kopya _SpellBook'a eklenir.
              _SpellBook[spell->getName()] = spell->clone();
            }
          }
      ```

  - `forgetSpell(const std::string&)`: Warlock'un bir büyüyü unutmasını sağlar.
    - ```cpp
        void Warlock::forgetSpell(const string& spellName) {
          // Büyü kitabında belirtilen büyünün olup olmadığını kontrol et
          map<string, ASpell*>::iterator it = _SpellBook.find(spellName);
          
          // Eğer büyü bulunursa, bellekteki büyüyü serbest bırak ve haritadan kaldır
          if( it != _SpellBook.end()){
              delete it->second; // Büyü nesnesini sil
              _SpellBook.erase(spellName); // Büyüyü büyü kitabından çıkar
          }
        }
      ```

  - `launchSpell(const std::string&, ATarget&)`: Belirli bir büyüyü hedefe fırlatır.
    - ```cpp
      void Warlock::launchSpell(const string& spellName, const ATarget& target) {
          // Büyü kitabında belirtilen büyünün olup olmadığını kontrol et
          map<string, ASpell*>::iterator it = _SpellBook.find(spellName);
          
          // Eğer büyü bulunursa, hedefe fırlat
          if( it != _SpellBook.end()){
              it->second->launch(target); // Büyüyü başlat
          }
      }
      ```

- **Örnek Class Yapısı**

```cpp
class Warlock {
    private:
        string _name;       // Büyücünün adı
        string _title;      // Büyücünün unvanı
        SpellBook _Spell;   // Büyücünün büyü kitabı

    public:
        const string& getName() const; // Büyücünün adını döndürür
        const string& getTitle() const; // Büyücünün unvanını döndürür
        void setTitle(const string& title); // Büyücünün unvanını ayarlar

        Warlock(const string& name, const string& title); // Kurucu fonksiyon: Büyücüyü adı ve unvanı ile oluşturur
        ~Warlock(); // Yıkıcı fonksiyon: Büyücü nesnesi yok edildiğinde çağrılır

        void introduce() const; // Büyücüyü tanıtan bir mesaj yazdırır
        void learnSpell(ASpell* spell); // Büyücüye yeni bir büyü öğretir
        void forgetSpell(const string& spellName); // Büyücünün belirli bir büyüyü unutmasını sağlar

        // Büyücünün belirli bir büyüyü hedefe fırlatmasını sağlar
        void launchSpell(const string& spellName, const ATarget& target);
};
```

---

**2 - ASpell Sınıfı (Soyut Sınıf)**

`ASpell`, büyülerin temel özelliklerini tanımlayan soyut bir sınıftır.

- **Nitelikler:**

  - `name`: Büyünün ismi.

  - `effects`: Büyünün etkileri.

- **Metodlar:**

  - `getName()`: Büyünün ismini döndürür.

  - `getEffects()`: Büyünün etkilerini döndürür.

  - `clone()`: Büyünün bir kopyasını döndüren saf sanal metod.

  - `launch(const ATarget&)`: Büyüyü belirli bir hedefe fırlatır.
 
- **Örnek Class Yapısı**

```cpp
class ASpell {
    protected:
        string _name;    // Büyünün adı
        string _effects; // Büyünün etkileri

    public:
        const string& getName() const; // Büyünün adını döndürür
        const string& getEffects() const; // Büyünün etkilerini döndürür

        // Büyünün bir kopyasını oluşturur
        virtual ASpell* clone() const = 0; // (saf sanal fonksiyon, türetilen sınıflar tarafından uygulanmalıdır)

        ASpell(const string& name, const string& effects); // Kurucu fonksiyon: Büyüyü adı ve etkileri ile oluşturur
        virtual ~ASpell(); // Yıkıcı fonksiyon: Büyü nesnesi yok edildiğinde çağrılır

        void launch(const ATarget& target) const; // Büyüyü belirli bir hedefe uygular
};
```

---

**3 - ATarget Sınıfı (Soyut Sınıf)**

`ATarget`, büyülerin hedef alabileceği nesneleri temsil eden soyut bir sınıftır.

- **Nitelikler:**

  - `type`: Hedefin türü.

- **Metodlar:**
  - `getType()`: Hedefin türünü döndürür.

  - `clone()`: Hedefin bir kopyasını döndüren saf sanal metod.

  - `getHitBySpell(const ASpell&)`: Büyünün hedefi vurduğunda gerçekleşen etkiyi tanımlar.
 
- **Örnek Class Yapısı**

```cpp
class ATarget {
    protected:
        string _type; // Hedefin türünü tutar (örneğin: "Human", "Dummy", "Stone")

    public:
        const string& getType() const; // Hedefin türünü döndürür

        // Hedefin bir kopyasını oluşturur
        virtual ATarget* clone() const = 0; // (saf sanal fonksiyon, türetilen sınıflar tarafından uygulanmalıdır)

        ATarget(const string& type); // Kurucu fonksiyon: Hedefi belirli bir tür ile oluşturur
        virtual ~ATarget(); // Yıkıcı fonksiyon: Hedef nesnesi yok edildiğinde çağrılır

        void getHitBySpell(const ASpell& spell) const; // Hedefin bir büyü tarafından vurulduğunda çağrılır
};
```

---

**4 - Fwoosh Sınıfı (ASpell'den Türetilmiş)**

`Fwoosh`, `ASpell` sınıfından türetilen somut bir büyü sınıfıdır.

- **Özellikler:**

  - Varsayılan yapıcı ( `Fwoosh() : ATarget("Fwoosh", "fwooshed")` ), büyünün ismini "Fwoosh" ve etkisini "fwooshed" olarak ayarlar.

  - `clone()` metodu, yeni bir `Fwoosh` nesnesi (`return new Fwoosh();`) döndürür.

- **Örnek Class Yapısı**

```cpp
class Fwoosh : public ASpell {
    public:
        ASpell* clone() const; // ASpell sınıfının saf sanal fonksiyonunu uygular: Büyünün bir kopyasını oluşturur

        Fwoosh(); // Kurucu fonksiyon: Fwoosh büyüsünü oluşturur ve temel özelliklerini ayarlar
        ~Fwoosh(); // Yıkıcı fonksiyon: Fwoosh büyüsü yok edildiğinde çağrılır
};
```

---

**5 - Dummy Sınıfı (ATarget'den Türetilmiş)**

`Dummy`, `ATarget` sınıfından türetilen somut bir hedef sınıfıdır.

- **Özellikler:**

  - `Varsayılan yapıcı`, hedefin türünü `"Target Practice Dummy"` olarak ayarlar.

  - `clone()` metodu, yeni bir `Dummy` nesnesi döndürür.
 
- **Örnek Class Yapısı**

```cpp
class Dummy : public ATarget {
    public:
        // clone() metodu, Dummy nesnesinin bir kopyasını oluşturur ve döndürür.
        // Bu metod, ATarget sınıfındaki saf sanal metodu uygular.
        ATarget* clone() const;

        // Varsayılan yapıcı metod.
        // Hedefin türünü "Target Practice Dummy" olarak ayarlar.
        Dummy();

        // Yıkıcı metod.
        // Dummy nesnesi yok edildiğinde çağrılır.
        ~Dummy();
};
```

---

**01 Beklenen Çıktı**

```ssh
~$ ./a.out | cat -e
Richard: This looks like another boring day.$
Richard: I am Richard, the Titled!$
Target Practice Dummy has been fwooshed!$
Richard: My job here is done!$
```

---

<a name="cpp_module02"></a>
## Level 2 - cpp_module02

`Warlock` sınıfına yeni özellikler eklenir ve `SpellBook` ile `TargetGenerator` sınıfları tanıtılır. Ayrıca, yeni büyüler (`Fireball`, `Polymorph`) ve yeni bir hedef (`BrickWall`) eklenir. Bu modül, büyülerin ve hedeflerin dinamik olarak yönetilmesini sağlar.

---

- **Yeni Özellikler:**
  
  - **Fireball:** `"Fireball"` adında bir büyü. **Etkisi:** `"burnt to a crisp"`.
  
  - **Polymorph:** `"Polymorph"` adında bir büyü. **Etkisi:** `"turned into a critter"`.
 
- **Yeni Hedef:**

  - **BrickWall:** `"Inconspicuous Red-brick Wall"` adında bir hedef.

- **SpellBook Sınıfı:**

  - Büyüleri yönetir. Büyüleri öğrenme, unutma ve oluşturma işlevlerini sağlar.

  - Kopyalanamaz ve kopya yapıcısı yasaklanmıştır.

- **TargetGenerator Sınıfı:**

  - Hedef türlerini yönetir. Hedef türlerini öğrenme, unutma ve oluşturma işlevlerini sağlar.

  - Kopyalanamaz ve kopya yapıcısı yasaklanmıştır.

---

**1 - SpellBook Sınıfı**

`SpellBook`, `Warlock` sınıfının büyülerini yönetir. Büyüleri öğrenme, unutma ve oluşturma işlevlerini sağlar.

- **Metodlar:**

  - `void learnSpell(ASpell* spell)`: Büyüyü öğrenir ve SpellBook'a ekler.
    - ```cpp
          // Warlock sınıfının learnSpell metodu, bir büyüyü (ASpell) öğrenmek için kullanılır.
          // Bu metod, büyünün Warlock'un büyü kitabına (_SpellBook) eklenmesini sağlar.
          void Warlock::learnSpell(ASpell* spell) {
          // Büyünün ismi (_SpellBook içinde) aranır.
          // find() metodu, büyünün ismiyle eşleşen bir öğe bulursa iterator döndürür.
          // Bulamazsa _SpellBook.end() döndürür.
            map<string, ASpell*>::iterator it = _SpellBook.find(spell->getName());
    
            // Eğer büyü kitabında bu isimde bir büyü yoksa (it == _SpellBook.end()),
            // büyü kitabına yeni bir büyü eklenir.
            if (it == _SpellBook.end()) {
              // Büyünün bir kopyası oluşturulur (clone() metodu kullanılarak),
              // ve bu kopya _SpellBook'a eklenir.
              _SpellBook[spell->getName()] = spell->clone();
            }
          }
      ```

  - `void forgetSpell(const string& spellName)`: Büyüyü unutur ve SpellBook'tan çıkarır.
    - ```cpp
        void Warlock::forgetSpell(const string& spellName) {
          // Büyü kitabında belirtilen büyünün olup olmadığını kontrol et
          map<string, ASpell*>::iterator it = _SpellBook.find(spellName);
          
          // Eğer büyü bulunursa, bellekteki büyüyü serbest bırak ve haritadan kaldır
          if( it != _SpellBook.end()){
              delete it->second; // Büyü nesnesini sil
              _SpellBook.erase(spellName); // Büyüyü büyü kitabından çıkar
          }
        }
      ```
      
  - `ASpell* createSpell(const std::string&)`: Büyüyü oluşturur ve döndürür.

    - ```cpp
      ASpell* SpellBook::createSpell(string const &spellName) {
          // Verilen büyü adını içeren bir büyü olup olmadığını kontrol etmek için haritayı arar
          map<string, ASpell*>::iterator it = _SpellBook.find(spellName);
      
          // Eğer büyü bulunursa, onun bir kopyasını döndür
          if (it != _SpellBook.end()) {
              return it->second->clone();
          }
          
          // Eğer büyü bulunamazsa, nullptr döndür
          return nullptr;
      }
      ```

- **Örnek Class Yapısı**

```cpp
class SpellBook {
    private:
        map<string, ASpell*> _SpellBook; // Büyüleri saklamak için bir map
    public:
        SpellBook(); // Varsayılan yapıcı
        ~SpellBook(); // Yıkıcı

        void learnSpell(ASpell* spell); // Büyü öğrenme
        void forgetSpell(const string& spellName); // Büyü unutma
        ASpell* createSpell(const string& spellName); // Büyü oluşturma
};
```

---

**2 - TargetGenerator Sınıfı**

`TargetGenerator`, Warlock sınıfının hedef türlerini yönetir. Hedef türlerini öğrenme, unutma ve oluşturma işlevlerini sağlar.

- **Metodlar:**

  - `void learnTargetType(ATarget* target)`: Hedef türünü öğrenir.
    - ```cpp
      void TargetGenerator::learnTargetType(ATarget* target) {
          // Hedefin türünün daha önce öğrenilip öğrenilmediğini kontrol et
          map<string, ATarget*>::iterator it = _TargetG.find(target->getType());
      
          // Eğer hedef türü haritada yoksa, haritaya ekle
          if (it == _TargetG.end()) {
              _TargetG[target->getType()] = target;
          }
      }
      ```

  - `void forgetTargetType(const string& targetName)`: Hedef türünü unutur.
    - ```cpp
      void TargetGenerator::forgetTargetType(string const &targetName) {
          // Verilen hedef adının haritada olup olmadığını kontrol et
          map<string, ATarget*>::iterator it = _TargetG.find(targetName);
      
          // Eğer hedef bulunursa, haritadan kaldır
          if (it != _TargetG.end()) {
              _TargetG.erase(targetName);
          }
      }
      ```

  - `ATarget* createTarget(const string& targetName)`: Hedef türünü oluşturur ve döndürür.
    - ```cpp
      ATarget* TargetGenerator::createTarget(string const &targetName) {
          // Verilen hedef adının haritada olup olmadığını kontrol et
          map<string, ATarget*>::iterator it = _TargetG.find(targetName);
      
          // Eğer hedef bulunursa, onun bir kopyasını döndür
          if (it != _TargetG.end()) {
              return it->second->clone();
          }
      
          // Eğer hedef bulunamazsa, nullptr döndür
          return nullptr;
      }
      ```

- **Örnek Class Yapısı**

```cpp
class TargetGenerator {
    private:
        map<string, ATarget*> _TargetBook; // Hedef türlerini saklamak için bir map
    public:
        TargetGenerator(); // Varsayılan yapıcı
        ~TargetGenerator(); // Yıkıcı

        void learnTargetType(ATarget* target); // Hedef türünü öğrenme
        void forgetTargetType(const string& targetName); // Hedef türünü unutma
        ATarget* createTarget(const string& targetName); // Hedef türünü oluşturma
};
```

---

**3 - Yeni Büyüler ve Hedefler**

---

- **Fireball Sınıfı:**

  - **Büyü adı:** `"Fireball"`.

  - **Etkisi:** `"burnt to a crisp"`.

  - **Class Yapısı:**
    - ```cpp
      class Fireball : public ASpell {
          public:
              Fireball(); // Varsayılan yapıcı
              ~Fireball(); // Yıkıcı
      
              ASpell* clone() const; // Büyünün bir kopyasını oluşturur
      };
      ```

  ---

  - **Polymorph Sınıfı:**

    - **Büyü adı:** `"Polymorph"`.

    - **Etkisi:** `"turned into a critter"`.
    
    - **Class Yapısı:**
      - ```cpp
        class Polymorph : public ASpell {
            public:
                Polymorph(); // Varsayılan yapıcı
                ~Polymorph(); // Yıkıcı
        
                ASpell* clone() const; // Büyünün bir kopyasını oluşturur
        };
        ``` 

---

- **BrickWall Sınıfı:**

  - **Hedef türü:** `"Inconspicuous Red-brick Wall"`.

  - **Class Yapısı**
    - ```cpp
      class BrickWall : public ATarget {
          public:
              BrickWall(); // Varsayılan yapıcı
              ~BrickWall(); // Yıkıcı
      
              ATarget* clone() const; // Hedefin bir kopyasını oluşturur
      };
      ```

---

**Warlock Sınıfına Eklenen Özellikler**

`Warlock` sınıfı, `SpellBook` ve `TargetGenerator` sınıflarını kullanarak büyüleri ve hedefleri yönetir.

  - **Metodlar:**

    - `void learnSpell(ASpell* spell):` Büyüyü öğrenir ve SpellBook'a ekler.
      - ```cpp
        void Warlock::learnSpell(ASpell* spell) {
            _Spell.learnSpell(spell);
        }
        ```

    - `void forgetSpell(const string& spellName):` Büyüyü unutur ve SpellBook'tan çıkarır.
      - ```cpp
        void Warlock::forgetSpell(const string& spellName) {
            _Spell.forgetSpell(spellName);
        }
        ```

    - `void launchSpell(const string& spellName, const ATarget& target)`: Büyüyü hedefe fırlatır.
      - ```cpp
        ASpell *tmp = _Spell.createSpell(spellName);
    
        if (tmp != nullptr) {
            tmp->launch(target);
            delete tmp;
        }
        ```

- **Örnek Class Yapısı**

  - ```cpp
        class Warlock {
        private:
            string _name;
            string _title;
            SpellBook _SpellBook; // Büyü kitabı
            TargetGenerator _TargetGenerator; // Hedef üreteci
    
        public:
            Warlock(const string& name, const string& title); // Yapıcı
            ~Warlock(); // Yıkıcı
    
            const string& getName() const;
            const string& getTitle() const;
            void setTitle(const string& title);
    
            void introduce() const;
            void learnSpell(ASpell* spell); // Büyü öğrenme
            void forgetSpell(const string& spellName); // Büyü unutma
            void launchSpell(const string& spellName, ATarget& target); // Büyü fırlatma
    };
    ```

---

**02 Beklenen Çıktı**

```ssh
~$ ./a.out | cat -e
Richard: This looks like another boring day.$
Richard: I am Richard, Hello, I'm Richard the Warlock!!$
Inconspicuous Red-brick Wall has been turned into a critter!$
Inconspicuous Red-brick Wall has been burnt to a crisp!$
Richard: My job here is done!$
~$
```

---

Bu README dosyası Derya ACAR tarafından hazırlanmıştır.
