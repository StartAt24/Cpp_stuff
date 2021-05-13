#include <iostream>
#include <string>

using namespace std;

class Extractor{
public:
    string extractor2txt(const Excel& excel_file){
        return "excel";
    }
    string extractor2txt(const PDF& pdf_file){
        return "pdf";
    }
};

class Document{
public:
    Document(string path):path_(path){
    }

    virtual string parse(Extractor&) = 0;
private:
    string path_;
};

class PDF: public Document{
public:
    PDF(string path):Document(path){
    }
    string parse(Extractor& exec){
        exec.extractor2txt(*this);
    }
};

class Excel: public Document{
public:
    Excel(string path):Document(path){
    }
    string parse(Extractor& exec){
        exec.extractor2txt(*this);
    }
};

int main(){
    Document* doc1 = new PDF("pdf_file");
    Document* doc2 = new Excel("excel_file");
    Extractor exc{};
    doc1->parse(exc);
    doc2->parse(exc);
    return 0;
}