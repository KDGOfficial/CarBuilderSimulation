#include <iostream>
#include <string>
using namespace std;

// Класс продукта - Автомобиль
class Car {
public:
    string body;
    int enginePower;
    int wheelSize;
    string transmission;

    void show() {
        cout << "Автомобиль:\n";
        cout << "Корпус: " << body << endl;
        cout << "Мощность двигателя: " << enginePower << " л.с.\n";
        cout << "Размер колес: R" << wheelSize << endl;
        cout << "Коробка передач: " << transmission << endl;
        cout << "-------------------\n";
    }
};

// Абстрактный строитель
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

// Конкретные строители для разных моделей
class DaewooLanosBuilder : public CarBuilder {
public:
    void buildBody() override { car->body = "Седан"; }
    void buildEngine() override { car->enginePower = 98; }
    void buildWheels() override { car->wheelSize = 13; }
    void buildTransmission() override { car->transmission = "5 Manual"; }
};

class FordProbeBuilder : public CarBuilder {
public:
    void buildBody() override { car->body = "Купе"; }
    void buildEngine() override { car->enginePower = 160; }
    void buildWheels() override { car->wheelSize = 14; }
    void buildTransmission() override { car->transmission = "4 Auto"; }
};

class UAZPatriotBuilder : public CarBuilder {
public:
    void buildBody() override { car->body = "Универсал"; }
    void buildEngine() override { car->enginePower = 120; }
    void buildWheels() override { car->wheelSize = 16; }
    void buildTransmission() override { car->transmission = "4 Manual"; }
};

class HyundaiGetzBuilder : public CarBuilder {
public:
    void buildBody() override { car->body = "Хетчбэк"; }
    void buildEngine() override { car->enginePower = 66; }
    void buildWheels() override { car->wheelSize = 13; }
    void buildTransmission() override { car->transmission = "4 Auto"; }
};

// Класс Director (Магазин)
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
    setlocale(LC_ALL, "Russian"); // Для вывода русского текста

    Shop shop;

    // Создание строителей
    DaewooLanosBuilder lanosBuilder;
    FordProbeBuilder probeBuilder;
    UAZPatriotBuilder patriotBuilder;
    HyundaiGetzBuilder getzBuilder;

    // Сборка автомобилей
    cout << "Сборка автомобилей:\n\n";

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

    // Освобождение памяти
    delete lanos;
    delete probe;
    delete patriot;
    delete getz;

    return 0;
}