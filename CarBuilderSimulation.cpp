#include <iostream>
#include <string>
using namespace std;

// ����� �������� - ����������
class Car {
public:
    string body;
    int enginePower;
    int wheelSize;
    string transmission;

    void show() {
        cout << "����������:\n";
        cout << "������: " << body << endl;
        cout << "�������� ���������: " << enginePower << " �.�.\n";
        cout << "������ �����: R" << wheelSize << endl;
        cout << "������� �������: " << transmission << endl;
        cout << "-------------------\n";
    }
};

// ����������� ���������
class CarBuilder {
protected:
    Car* car;
public:
    CarBuilder() : car(nullptr) {}
    virtual ~CarBuilder() { delete car; }

    void createNewCar() {
        car = new Car();
    }

    Car* getCar() {
        return car;
    }

    virtual void buildBody() = 0;
    virtual void buildEngine() = 0;
    virtual void buildWheels() = 0;
    virtual void buildTransmission() = 0;
};

// ���������� ��������� ��� ������ �������
class DaewooLanosBuilder : public CarBuilder {
public:
    void buildBody() override { car->body = "�����"; }
    void buildEngine() override { car->enginePower = 98; }
    void buildWheels() override { car->wheelSize = 13; }
    void buildTransmission() override { car->transmission = "5 Manual"; }
};

class FordProbeBuilder : public CarBuilder {
public:
    void buildBody() override { car->body = "����"; }
    void buildEngine() override { car->enginePower = 160; }
    void buildWheels() override { car->wheelSize = 14; }
    void buildTransmission() override { car->transmission = "4 Auto"; }
};

class UAZPatriotBuilder : public CarBuilder {
public:
    void buildBody() override { car->body = "���������"; }
    void buildEngine() override { car->enginePower = 120; }
    void buildWheels() override { car->wheelSize = 16; }
    void buildTransmission() override { car->transmission = "4 Manual"; }
};

class HyundaiGetzBuilder : public CarBuilder {
public:
    void buildBody() override { car->body = "�������"; }
    void buildEngine() override { car->enginePower = 66; }
    void buildWheels() override { car->wheelSize = 13; }
    void buildTransmission() override { car->transmission = "4 Auto"; }
};

// ����� Director (�������)
class Shop {
public:
    Car* constructCar(CarBuilder& builder) {
        builder.createNewCar();
        builder.buildBody();
        builder.buildEngine();
        builder.buildWheels();
        builder.buildTransmission();
        return builder.getCar();
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); // ��� ������ �������� ������

    Shop shop;

    // �������� ����������
    DaewooLanosBuilder lanosBuilder;
    FordProbeBuilder probeBuilder;
    UAZPatriotBuilder patriotBuilder;
    HyundaiGetzBuilder getzBuilder;

    // ������ �����������
    cout << "������ �����������:\n\n";

    Car* lanos = shop.constructCar(lanosBuilder);
    cout << "Daewoo Lanos:\n";
    lanos->show();

    Car* probe = shop.constructCar(probeBuilder);
    cout << "Ford Probe:\n";
    probe->show();

    Car* patriot = shop.constructCar(patriotBuilder);
    cout << "UAZ Patriot:\n";
    patriot->show();

    Car* getz = shop.constructCar(getzBuilder);
    cout << "Hyundai Getz:\n";
    getz->show();

    // ������������ ������
    delete lanos;
    delete probe;
    delete patriot;
    delete getz;

    return 0;
}