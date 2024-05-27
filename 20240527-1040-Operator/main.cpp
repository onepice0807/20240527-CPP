#include <iostream>
#include <string>

using namespace std;

// 클래스간에 관계를 맺는 방법
// 상속, 포함
// Arm, Robot에 상속되게 만들었던 것을 Robot의 자식을 없에고 Robot 활용하기

class Arm {
private:
    string _name;

public:
    Arm(string name)
        : _name(name)
    {
    }

    void Info() {
        cout << _name;
    }
};

class CannonArm : public Arm {
public:
    CannonArm()
        : Arm("캐논암")
    {
    }
};

class BombArm : public Arm {
public:
    BombArm()
        : Arm("폭탄암")
    {
    }
};

class LazerArm : public Arm {
public:
    LazerArm()
        : Arm("레이저암")
    {
    }
};

class GunArm : public Arm {
public:
    GunArm()
        : Arm("총탄암")
    {
    }
};

class Robot {
private:
    string _name;
    Arm& _leftArm;
    Arm& _rightArm;

public:
    Robot(string name, Arm& leftArm, Arm& rightArm)
        : _name(name), _leftArm(leftArm), _rightArm(rightArm) {}

    void Info() {
        cout << _name << endl;
        cout << "왼쪽팔: ";
        _leftArm.Info();
        cout << endl;
        cout << "오른쪽팔: ";
        _rightArm.Info();
        cout << endl;
        cout << endl;
    }
};

int main() {
    CannonArm cannonArm;
    BombArm bombArm;
    LazerArm lazerArm;
    GunArm gunArm;

    Robot cannonArmRobot("캐논암로봇", cannonArm, cannonArm);
    Robot bombArmRobot("폭탄암로봇", bombArm, bombArm);
    Robot lazerArmRobot("레이저암로봇", lazerArm, lazerArm);
    Robot gunArmRobot("총탄암로봇", gunArm, gunArm);
    Robot IcannonArmRgunArmRobot("왼쪽캐논암오른쪽총탄암로봇", cannonArm, gunArm);

    cannonArmRobot.Info();
    bombArmRobot.Info();
    lazerArmRobot.Info();
    gunArmRobot.Info();
    IcannonArmRgunArmRobot.Info();

    return 0;
}