#include <iostream>
#include <vector>
using namespace std;

class Hayvan {
public:
    Hayvan(const string& isim): name(isim) {}
    virtual void makeSound() const = 0;
    virtual string getType() const = 0;
    virtual ~Hayvan() = default;

    string getName() const { return name; }

private:
    string name;
};

// Türetilmiş Sınıflar ; Köpek, kedi, kuş
class Köpek : public Hayvan {
public:
    Köpek(const string& isim) : Hayvan(isim){}
    void makeSound() const override{
        cout << "Hav hav" << endl;
    }
    string getType() const override { return "Dog"; }
};

class Kedi : public Hayvan{
public:
    Kedi(const string& isim): Hayvan(isim){}
    void makeSound() const override {
        cout << "Miyav miyav" << endl;
    }
    string getType() const override { return "Miyav"; }
};
class Kuş : public Hayvan{
public:
    Kuş(const string& isim): Hayvan(isim){}
    void makeSound() const override {
        cout << "Cik cik" << endl;
    }
    string getType() const override { return "Cik cik"; }
};

int main()
{
    vector<Hayvan*> kayitlar;

    // Polymorphism kullanarak farklı hayvan türlerini ekliyoruz
    kayitlar.push_back(new Köpek("Karabas"));
    kayitlar.push_back(new Kedi("Kartopu"));
    kayitlar.push_back(new Kuş("Mavis"));

    // Kayıtları listeleyen bir döngü
    for (const auto& record : kayitlar) {
        cout << "Isim: " << record->getName()   << "\n"
            << "Tur: " << record->getType()    << "\n"
            << "Ses: "                         << "\n";
        record->makeSound();
    }

    // Belleği temizle
    for (const auto& record : kayitlar) {
        delete record;
    }
}