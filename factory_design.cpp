#include<iostream>
#include<memory>

class Data{
    public:
        virtual void sendData() = 0;
};

class Udp : public Data{
    public :
    void sendData(){
        std::cout<<"send data as udp\n";
    }
};

class Terminal : public Data{
    public :
    void sendData(){
        std::cout<<"send data on Terminal\n";
    }
};
/*
If new type of send Data method required, you can just add the class here and one if else condition in DataInterfc class
This is simple factory Design pattern, in which you can add new functionality without changing the entire codebase
*/

class DataInterfc{
    public:
    static DataInterfc* instance(){
        static DataInterfc di;
        return &di;
    }
    std::shared_ptr<Data> createData(const std::string type){
        if(type == "udp") return std::make_shared<Udp>();
        else if (type == "terminal") return std::make_shared<Terminal>();
        else return nullptr;
    }
};

int main(int argc , char**argv){
    //you can add check for the argv
    std::shared_ptr<Data> data = DataInterfc::instance()->createData(argv[1]);
    if(data == nullptr){
        std::cout<<"Give valid data\n";
        return 1;
    }
    data->sendData();
    return 0;
}