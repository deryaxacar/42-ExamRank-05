<div align="center">
  <h2>Exam Rank 5 Study Notes</h2>
</div>

- [Level 0 - cpp_module00](#cpp_module00)
- [Level 1 - cpp_module01](#cpp_module01)
- [Level 2 - cpp_module02](#cpp_module02)

---

Note: For the exam, push folder names as cpp_module_00, cpp_module_01, cpp_module_02, etc. However, when working in the simulator, you should use grademe with folder names like cpp_module00. There is no need to push in the simulator.

---

<a name="cpp_module00"></a>
## Level 0 - cpp_module00

The `Warlock class` is designed following the `Coplien` form and adheres to proper encapsulation and object-oriented principles. The class contains private attributes for `name` and `title`, and provides getter and setter methods for these attributes. Additionally, it includes methods for the Warlock to introduce itself and handle constructor/destructor messages.

- **Attributes**
  - `name`: A private string attribute representing the Warlock's name.

  - `title`: A private string attribute representing the Warlock's title.

- **Methods**
  - `getName()`: Returns a constant reference to the Warlock's name.

  - `getTitle()`: Returns a constant reference to the Warlock's title.

  - `setTitle(const std::string&)`: Sets the Warlock's title to the provided string value.

  - `introduce() const`: Prints a message introducing the Warlock, including their name and title.

- **Constructor and Destructor**
  - `Warlock(const std::string&, const std::string&)`: Constructor that initializes the Warlock with a name and title. Prints a message upon creation.

  - `~Warlock()`: Destructor that prints a message when the Warlock is destroyed.

- **Constraints**
  - The `Warlock` class cannot be copied or instantiated without a name and title. This restriction is enforced by deleting the copy constructor and copy assignment operator.

- **Example Class Structure**

```cpp
#pragma once

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Warlock {
    private:
        string _name;       // Private variable storing the Warlock's name
        string _title;      // Private variable storing the Warlock's title

    public:
        const string& getName() const;  // Getter method returning the Warlock's name (as const reference)
        const string& getTitle() const; // Getter method returning the Warlock's title (as const reference)
        void setTitle(const string& title); // Setter method to set the Warlock's title

        Warlock(const string& name, const string& title); // Constructor: initializes Warlock with name and title
        ~Warlock(); // Destructor: called when Warlock is destroyed

        void introduce() const; // Method that prints a message introducing the Warlock
};
```

---

- **Explanations:**
  - `#pragma once`: Ensures the header file is included only once, preventing multiple inclusion issues.

  - `using std::string, using std::cout, using std::endl`: These statements allow access to standard library components like `string`, `cout`, and `endl` without the `std::` prefix.

  - `_name` and `_title`: Private attributes of the Warlock class. These variables represent the internal state of the class.

  - `getName()` and `getTitle()`: Getter methods that return the Warlock's name and title. The `const` keyword ensures that these methods do not modify the object's state.

  - `setTitle()`: Setter method to update the Warlock's title. Takes a string as a parameter.

  - `Warlock(const string& name, const string& title)`: Constructor method that initializes the Warlock with a name and title.

  - `~Warlock()`: Destructor method, called when the Warlock object is destroyed. It prints a message.

  - `introduce() const`: Method that prints a message introducing the Warlock. The `const` keyword guarantees that the method does not modify the internal state of the object.

- **00 Expected Output:**

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

The focus is on implementing the `Warlock` class along with the abstract classes `ASpell` and `ATarget`, and their concrete implementations: `Fwoosh` and `Dummy`. The goal is to build a system where a Warlock can learn, forget, and cast spells on targets.

- **Files**

  - `Warlock.hpp` and `Warlock.cpp`: Definition and implementation of the `Warlock` class.

  - `ASpell.hpp` and `ASpell.cpp`: Definition and implementation of the `ASpell` abstract class.

  - `ATarget.hpp` and `ATarget.cpp`: Definition and implementation of the `ATarget` abstract class.

  - `Fwoosh.hpp` and `Fwoosh.cpp`: Definition and implementation of the `Fwoosh` spell class.

  - `Dummy.hpp` and `Dummy.cpp`: Definition and implementation of the `Dummy` target class.

- **Notes**

  - **Coplien Form**: Classes must include a default constructor, copy constructor, assignment operator, and destructor.

  - **Abstract Classes**: `ASpell` and `ATarget` must contain pure virtual methods such as `clone()`.

  - **Spell Management**: `Warlock` should store learned spells in a container and be able to cast them on targets.

---

**1 - Warlock Class**

The `Warlock` class represents a wizard characterized by a name and title. It can learn spells, forget them, and cast them on targets.

- **Attributes:**

  - `name`: A string representing the Warlock's name.

  - `title`: A string representing the Warlock's title.

  - `SpellBook`: A container to store the spells known by the Warlock.

- **Methods:**

  - `getName()`: Returns the Warlock's name.

  - `getTitle()`: Returns the Warlock's title.

  - `setTitle(const std::string&)`: Sets the Warlock's title.

  - `introduce()`: Prints a message introducing the Warlock.

  - `learnSpell(ASpell*)`: Teaches a new spell to the Warlock.
    - ```cpp
          // The `learnSpell` method of the Warlock class is used to teach the Warlock a new spell (ASpell).
          // This method adds the spell to the Warlock's spell book (`_SpellBook`).
          
          void Warlock::learnSpell(ASpell* spell) {
              // Searches for the spell name in the _SpellBook.
              // The `find()` method returns an iterator to the spell if found;
              // otherwise, it returns `_SpellBook.end()`.
          
              map<string, ASpell*>::iterator it = _SpellBook.find(spell->getName());
          
              // If the spell with the same name is not already in the spell book (it == _SpellBook.end()),
              // the new spell is added to the spell book.
              if (it == _SpellBook.end()) {
                  // A clone of the spell is created using the `clone()` method,
                  // and this clone is stored in the _SpellBook.
                  _SpellBook[spell->getName()] = spell->clone();
              }
          }
      ```

  - `forgetSpell(const std::string&)`: Allows the Warlock to forget a spell.
    - ```cpp
      void Warlock::forgetSpell(const string& spellName) {
        // Check if the specified spell exists in the spell book
        map<string, ASpell*>::iterator it = _SpellBook.find(spellName);
        
        // If the spell is found, release its memory and remove it from the map
        if (it != _SpellBook.end()) {
            delete it->second;            // Delete the spell object
            _SpellBook.erase(spellName);  // Remove the spell from the spell book
        }
      }
      ```

  - `launchSpell(const std::string&, ATarget&)`: Casts a specific spell on the given target.
    - ```cpp
      void Warlock::launchSpell(const string& spellName, const ATarget& target) {
          // Check if the specified spell exists in the spell book
          map<string, ASpell*>::iterator it = _SpellBook.find(spellName);
          
          // If the spell is found, cast it on the target
          if (it != _SpellBook.end()) {
              it->second->launch(target); // Launch the spell
          }
      }
      ```

- **Example Class Structure**

```cpp
class Warlock {
    private:
        string _name;       // The name of the wizard
        string _title;      // The title of the wizard
        SpellBook _Spell;   // The wizard's spell book

    public:
        const string& getName() const;       // Returns the wizard's name
        const string& getTitle() const;      // Returns the wizard's title
        void setTitle(const string& title);  // Sets the wizard's title

        Warlock(const string& name, const string& title); // Constructor: initializes the wizard with a name and title
        ~Warlock(); // Destructor: called when the wizard object is destroyed

        void introduce() const;                      // Prints a message introducing the wizard
        void learnSpell(ASpell* spell);              // Teaches a new spell to the wizard
        void forgetSpell(const string& spellName);   // Makes the wizard forget a specific spell

        // Allows the wizard to cast a specific spell on a target
        void launchSpell(const string& spellName, const ATarget& target);
};
```

---

**2 - ASpell Class (Abstract Class)**

`ASpell` is an abstract class that defines the core properties and behaviors of a spell.

- **Attributes:**

  - `name`: The name of the spell.

  - `effects`: The effects of the spell.

- **Methods:**

  - `getName()`: Returns the name of the spell.

  - `getEffects()`: Returns the effects of the spell.

  - `clone()`: A pure virtual method that returns a copy of the spell.

  - `launch(const ATarget&)`: Casts the spell on a specific target.

- **Example Class Structure**

```cpp
class ASpell {
    protected:
        string _name;    // The name of the spell
        string _effects; // The effects of the spell

    public:
        const string& getName() const;    // Returns the name of the spell
        const string& getEffects() const; // Returns the effects of the spell

        // Creates a copy of the spell
        virtual ASpell* clone() const = 0; // Pure virtual function to be implemented by derived classes

        ASpell(const string& name, const string& effects); // Constructor: initializes the spell with name and effects
        virtual ~ASpell(); // Virtual destructor: called when the spell object is destroyed

        void launch(const ATarget& target) const; // Applies the spell to a specific target
};
```

---

**3 - ATarget Class (Abstract Class)**

`ATarget` is an abstract class that represents objects that can be targeted by spells.

- **Attributes:**

  - `type`: The type of the target.

- **Methods:**

  - `getType()`: Returns the type of the target.

  - `clone()`: A pure virtual method that returns a copy of the target.

  - `getHitBySpell(const ASpell&)`: Defines the effect when a spell hits the target.

- **Example Class Structure**

```cpp
class ATarget {
    protected:
        string _type; // Stores the type of the target (e.g., "Human", "Dummy", "Stone")

    public:
        const string& getType() const; // Returns the type of the target

        // Creates a copy of the target
        virtual ATarget* clone() const = 0; // Pure virtual function to be implemented by derived classes

        ATarget(const string& type); // Constructor: initializes the target with a specific type
        virtual ~ATarget(); // Virtual destructor: called when the target object is destroyed

        void getHitBySpell(const ASpell& spell) const; // Called when the target is hit by a spell
};

```

---

**4 - Fwoosh Class (Derived from ASpell)**

`Fwoosh` is a concrete spell class derived from the `ASpell` abstract class.

- **Properties:**

  - The default constructor (`Fwoosh() : ASpell("Fwoosh", "fwooshed")`) sets the spell's name to "Fwoosh" and its effect to "fwooshed".

  - The `clone()` method returns a new instance of `Fwoosh` (`return new Fwoosh();`).

- **Example Class Structure**

```cpp
class Fwoosh : public ASpell {
    public:
        ASpell* clone() const; // Implements the pure virtual function from ASpell: creates a copy of the spell

        Fwoosh();  // Constructor: Initializes the Fwoosh spell and sets its core properties
        ~Fwoosh(); // Destructor: Called when the Fwoosh spell is destroyed
};
```

---

**5 - Dummy Class (Derived from ATarget)**

`Dummy` is a concrete target class derived from the `ATarget` abstract class.

- **Properties:**

  - The **default constructor** sets the target's type to `"Target Practice Dummy"`.

  - The `clone()` method returns a new instance of `Dummy`.

 
- **Example Class Structure**

```cpp
class Dummy : public ATarget {
    public:
        // The clone() method creates and returns a copy of the Dummy object.
        // Implements the pure virtual method from the ATarget class.
        ATarget* clone() const;

        // Default constructor.
        // Sets the target's type to "Target Practice Dummy".
        Dummy();

        // Destructor.
        // Called when the Dummy object is destroyed.
        ~Dummy();
};
```

---

**01 Expected Output**

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

New features are added to the `Warlock` class, and the `SpellBook` and `TargetGenerator` classes are introduced. Additionally, new spells (`Fireball`, `Polymorph`) and a new target (`BrickWall`) are added. This module enables dynamic management of spells and targets.

---

- **New Features:**

  - **Fireball:** A spell named `"Fireball"`.  
    **Effect:** `"burnt to a crisp"`.

  - **Polymorph:** A spell named `"Polymorph"`.  
    **Effect:** `"turned into a critter"`.

- **New Target:**

  - **BrickWall:** A target named `"Inconspicuous Red-brick Wall"`.

- **SpellBook Class:**

  - Manages spells. Provides functionality to learn, forget, and create spells.
  - Cannot be copied; copy constructor is disabled.

- **TargetGenerator Class:**

  - Manages target types. Provides functionality to learn, forget, and create targets.
  - Cannot be copied; copy constructor is disabled.

---

**1 - SpellBook Class**

`SpellBook` manages the spells for the `Warlock` class. It provides functionality to learn, forget, and create spells.

- **Methods:**


  - `void learnSpell(ASpell* spell)`: Learns the spell and adds it to the SpellBook.
    - ```cpp
      // The learnSpell method of the Warlock class is used to teach a new spell (ASpell).
      // This method adds the spell to the Warlock's spell book (_SpellBook).
      void Warlock::learnSpell(ASpell* spell) {
          // Search for the spell name in _SpellBook.
          // If found, find() returns an iterator; otherwise, it returns _SpellBook.end().
          map<string, ASpell*>::iterator it = _SpellBook.find(spell->getName());
  
          // If the spell is not already in the book (it == _SpellBook.end()),
          // add a new copy of the spell to the book.
          if (it == _SpellBook.end()) {
              // Create a clone of the spell using clone() and add it to _SpellBook.
              _SpellBook[spell->getName()] = spell->clone();
          }
      }
      ```

  - `void forgetSpell(const string& spellName)`: Forgets the spell and removes it from the SpellBook.
    - ```cpp
      void Warlock::forgetSpell(const string& spellName) {
          // Check if the specified spell exists in the spell book
          map<string, ASpell*>::iterator it = _SpellBook.find(spellName);
  
          // If the spell is found, free its memory and remove it from the map
          if (it != _SpellBook.end()) {
              delete it->second;             // Delete the spell object
              _SpellBook.erase(spellName);   // Remove the spell from the spell book
          }
      }
      ```
      
  - `ASpell* createSpell(const std::string&)`: Creates and returns a copy of the specified spell.
  
    - ```cpp
      ASpell* SpellBook::createSpell(const string& spellName) {
          // Search the map to check if a spell with the given name exists
          map<string, ASpell*>::iterator it = _SpellBook.find(spellName);
  
          // If the spell is found, return a clone of it
          if (it != _SpellBook.end()) {
              return it->second->clone();
          }
  
          // If the spell is not found, return nullptr
          return nullptr;
      }
      ```

- **Example Class Structure**

```cpp
class SpellBook {
    private:
        map<string, ASpell*> _SpellBook; // A map to store spells

    public:
        SpellBook();  // Default constructor
        ~SpellBook(); // Destructor

        void learnSpell(ASpell* spell);                  // Learn a new spell
        void forgetSpell(const string& spellName);       // Forget an existing spell
        ASpell* createSpell(const string& spellName);    // Create and return a copy of a spell
};
```

---

**2 - TargetGenerator Class**

`TargetGenerator` manages the target types for the Warlock class. It provides functionality to learn, forget, and create target instances.

- **Methods:**

  - `void learnTargetType(ATarget* target)`: Learns a new target type.
    - ```cpp
      void TargetGenerator::learnTargetType(ATarget* target) {
          // Check if the target type has already been learned
          map<string, ATarget*>::iterator it = _TargetG.find(target->getType());
  
          // If the target type is not in the map, add it
          if (it == _TargetG.end()) {
              _TargetG[target->getType()] = target;
          }
      }
      ```

  - `void forgetTargetType(const string& targetName)`: Forgets a target type.
    - ```cpp
      void TargetGenerator::forgetTargetType(const string& targetName) {
          // Check if the target type exists in the map
          map<string, ATarget*>::iterator it = _TargetG.find(targetName);
  
          // If found, remove it from the map
          if (it != _TargetG.end()) {
              _TargetG.erase(targetName);
          }
      }
      ```

  - `ATarget* createTarget(const string& targetName)`: Creates and returns an instance of the specified target type.
    - ```cpp
      ATarget* TargetGenerator::createTarget(const string& targetName) {
          // Check if the target type exists in the map
          map<string, ATarget*>::iterator it = _TargetG.find(targetName);
  
          // If found, return a clone of the target
          if (it != _TargetG.end()) {
              return it->second->clone();
          }
  
          // If not found, return nullptr
          return nullptr;
      }
      ```

- **Example Class Structure**

```cpp
class TargetGenerator {
    private:
        map<string, ATarget*> _TargetBook; // A map to store target types

    public:
        TargetGenerator();  // Default constructor
        ~TargetGenerator(); // Destructor

        void learnTargetType(ATarget* target);               // Learn a new target type
        void forgetTargetType(const string& targetName);     // Forget an existing target type
        ATarget* createTarget(const string& targetName);     // Create and return an instance of a target type
};
```

---

**3 - New Spells and Targets**

- **Fireball Class:**

  - **Spell Name:** `"Fireball"`

  - **Effect:** `"burnt to a crisp"`

  - **Class Structure:**
    -
    ```cpp
      class Fireball : public ASpell {
          public:
              Fireball();           // Default constructor
              ~Fireball();          // Destructor

              ASpell* clone() const; // Creates a copy of the spell
      };
    ```

  ---

- **Polymorph Class:**

  - **Spell Name:** `"Polymorph"`

  - **Effect:** `"turned into a critter"`

  - **Class Structure:**
    -
    ```cpp
      class Polymorph : public ASpell {
          public:
              Polymorph();           // Default constructor
              ~Polymorph();          // Destructor

              ASpell* clone() const; // Creates a copy of the spell
      };
    ```


---

- **BrickWall Class:**

  - **Target Type:** `"Inconspicuous Red-brick Wall"`

  - **Class Structure:**
    -
    ```cpp
      class BrickWall : public ATarget {
          public:
              BrickWall();           // Default constructor
              ~BrickWall();          // Destructor

              ATarget* clone() const; // Creates a copy of the target
      };
    ```

---

**Additional Features in the Warlock Class**

The `Warlock` class now uses the `SpellBook` and `TargetGenerator` classes to manage spells and targets.

- **Methods:**

  - `void learnSpell(ASpell* spell)`: Learns a spell and adds it to the SpellBook.
    -
    ```cpp
      void Warlock::learnSpell(ASpell* spell) {
          _Spell.learnSpell(spell);
      }
      ```

  - `void forgetSpell(const string& spellName)`: Forgets a spell and removes it from the SpellBook.
    -
    ```cpp
      void Warlock::forgetSpell(const string& spellName) {
          _Spell.forgetSpell(spellName);
      }
      ```

  - `void launchSpell(const string& spellName, const ATarget& target)`: Casts the spell on a target.
    -
    ```cpp
      ASpell* tmp = _Spell.createSpell(spellName);

      if (tmp != nullptr) {
          tmp->launch(target);
          delete tmp;
      }
      ```

- **Example Class Structure**

  -
  ```cpp
    class Warlock {
    private:
        string _name;
        string _title;
        SpellBook _SpellBook;          // Spell book
        TargetGenerator _TargetGenerator; // Target generator

    public:
        Warlock(const string& name, const string& title); // Constructor
        ~Warlock(); // Destructor

        const string& getName() const;
        const string& getTitle() const;
        void setTitle(const string& title);

        void introduce() const;
        void learnSpell(ASpell* spell);                   // Learn a spell
        void forgetSpell(const string& spellName);        // Forget a spell
        void launchSpell(const string& spellName, ATarget& target); // Cast a spell
    };
    ```

---

**02 Expected Output**

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

<p align="center">2025 This project was created by Derya ACAR.</p>
