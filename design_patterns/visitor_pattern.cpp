#include <iostream>
#include <string>

using namespace std;

class Visitor{
public:
    virtual string visit(const Excel& excel_file) = 0;
    virtual string visit(const PDF& excel_file) = 0;
};

class Extractor: public Visitor{
public:
    string visit(const Excel& excel_file){
        return "extract excel";
    }
    string visit(const PDF& pdf_file){
        return "extract pdf";
    }
};

class Compress: public Visitor{
    string visit(const Excel& excel_file){
        return "compress excel";
    }
    string visit(const PDF& pdf_file){
        return "compress pdf";
    }
};

class Document{
public:
    Document(string path):path_(path){
    }

    virtual string parse(Visitor&) = 0;
private:
    string path_;
};

class PDF: public Document{
public:
    PDF(string path):Document(path){
    }
    string parse(Visitor& exec){
        exec.visit(*this);
    }
};

class Excel: public Document{
public:
    Excel(string path):Document(path){
    }
    string parse(Visitor& exec){
        exec.visit(*this);
    }
};

int main(){
    Document* doc1 = new PDF("pdf_file");
    Document* doc2 = new Excel("excel_file");
    Visitor* v1 = new Compress{};
    Visitor* v2 = new Extractor{};
    doc1->parse(*v1);
    doc2->parse(*v1);
    doc1->parse(*v2);
    doc2->parse(*v2);
    return 0;
}