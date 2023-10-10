
#include "iostream"
#include "sstream"
#include "string"
#include "vector"

using namespace std;

class Article {
protected:
    string name;
    string barcode;
    double price;
    double quantity;
public:
    Article(string n, string b, double p) {
        this->name = n;
        this->barcode = b;
        this->price = p;
        this->quantity = 1;
    }

    bool hasSameCode(Article *a) {
        if (this->barcode == a->barcode) {
            return true;
        } else {
            return false;
        }
    }

    double getTotalPrice() const {
        return this->price * quantity;
    }

    virtual string toString() const {
        stringstream articleData;
        articleData << name << " " << to_string(quantity) << " " << to_string(this->getTotalPrice()) << " €";
        return articleData.str();
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        this->name = name;
    }

    const string &getBarcode() const {
        return barcode;
    }

    void setBarcode(const string &barcode) {
        this->barcode = barcode;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        this->price = price;
    }

    double getQuantity() const {
        return quantity;
    }

    void setQuantity(double quantity) {
        this->quantity = quantity;
    }

};

class WeighableArticle : public Article {
public:
    WeighableArticle(string n, string b, double p, double q) : Article(n, b, p) {
        this->quantity = q;
    }

    string toString() const override {
        stringstream weighableArticleData;
        weighableArticleData << name << " " << to_string(quantity);
        weighableArticleData << " kg " << to_string(this->getTotalPrice()) << " €" << endl;
        return weighableArticleData.str();
    }

};

class Invoice {
private:
    string seller;
    int id;
    static int countId;
    vector<Article *> articles;
public:
    Invoice(string seller) {
        this->seller = seller;
        this->id = countId;
        countId++;
    }

    void addArticle(Article *a) {

                articles.push_back(a);


            }



    void print() const{
        double recieptPrice;
        cout << this->seller << " Racun st. " << this->id << endl;
        for (int i = 0; i < articles.size(); i++) {
            cout<< articles[i]->toString() << endl;
            recieptPrice += articles[i]->getTotalPrice();
        }
        cout << "Skupaj " << recieptPrice << " € " << endl;
    }

};

int Invoice::countId = 1;


int main() {

    Article* article1 = new Article("Cips","ab13c",1.0);

    article1->setQuantity(2);
    article1->setPrice(1.22);

    Article* article2 = new Article("Pepsi","bc349",1.12);
    Article* article3 = new Article("Cokolada","bc349",2.15);

    Invoice invoice1("Hofer d.o.o.");
    invoice1.addArticle(article1);
    invoice1.addArticle(article2);
    invoice1.addArticle(article3);

    Article* article4 = new Article("mleko", "ffjwp", 1.78);
    WeighableArticle* article5 = new WeighableArticle("kivi", "ffjwp", 1.78, 2.64);
    WeighableArticle* article6 = new WeighableArticle("banane", "ffjwp", 1.78, 2.64);

    Invoice invoice2("Tus d.o.o.");

    invoice2.addArticle(article4);
    invoice2.addArticle(article5);
    invoice2.addArticle(article6);

    invoice1.print();
    invoice2.print();


    delete article1;
    delete article2;
    delete article3;
    delete article4;
    delete article5;
    delete article6;
    return 0;
}