#include <iostream>
#include <string>

using namespace std;

// 클래스간에 관계를 맺는 방법
// 상속, 포함
// Arm, Robot에 상속되게 만들었던 것을 Robot의 자식을 없에고 Robot 활용하기
// Robot 클래스에서 Arm&을 Arm* 포인터타입으로 변경

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
    Arm* _pLeftArm;
    Arm* _pRightArm;

public:
    Robot(string name, Arm* pLeftArm, Arm* pRightArm)
        : _name(name), _pLeftArm(pLeftArm), _pRightArm(pRightArm) {}

    void ChangeLeftArm(Arm* pLeftArm) {
        _pLeftArm = pLeftArm;
    }

    void ChangeRightArm(Arm* pRightArm) {
        _pRightArm = pRightArm;
    }

    void Info() {
        cout << _name << endl;
        cout << "왼쪽팔: ";
        _pLeftArm->Info();
        cout << endl;
        cout << "오른쪽팔: ";
        _pRightArm->Info();
        cout << endl;
        cout << endl;
    }
};

int main() {
    CannonArm cannonArm;
    BombArm bombArm;
    LazerArm lazerArm;
    GunArm gunArm;

    Robot cannonArmRobot("캐논암로봇", &cannonArm, &cannonArm);
    Robot bombArmRobot("폭탄암로봇", &bombArm, &bombArm);
    Robot lazerArmRobot("레이저암로봇", &lazerArm, &lazerArm);
    Robot gunArmRobot("총탄암로봇", &gunArm, &gunArm);
    Robot IcannonArmRgunArmRobot("왼쪽캐논암오른쪽총탄암로봇", &cannonArm, &gunArm);

    cannonArmRobot.Info();
    bombArmRobot.Info();
    lazerArmRobot.Info();
    gunArmRobot.Info();
    IcannonArmRgunArmRobot.Info();

    IcannonArmRgunArmRobot.ChangeLeftArm(&bombArm);

    IcannonArmRgunArmRobot.Info();

    return 0;
}