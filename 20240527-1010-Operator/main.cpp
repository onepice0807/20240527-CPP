#include <iostream>
#include <string>

using namespace std;

// Ŭ�������� ���踦 �δ� ���
// ���, ����
// Arm, Robot�� ��ӵǰ� �����

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
        : Arm("ĳ���")
    {
    }
};

class BombArm : public Arm {
public:
    BombArm()
        : Arm("��ź��")
    {
    }
};

class LazerArm : public Arm {
public:
    LazerArm()
        : Arm("��������")
    {
    }
};

class GunArm : public Arm {
public:
    GunArm()
        : Arm("��ź��")
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
        cout << "������: ";
        _leftArm.Info();
        cout << endl;
        cout << "��������: ";
        _rightArm.Info();
        cout << endl;
        cout << endl;
    }
};

class CannonArmRobot : public Robot {
public:
    CannonArmRobot(CannonArm& leftArm, CannonArm& rightArm)
        : Robot("ĳ��Ϸκ�", leftArm, rightArm)
    {}
};

class BombArmRobot : public Robot {
public:
    BombArmRobot(BombArm& leftArm, BombArm& rightArm)
        : Robot("��ź�Ϸκ�", leftArm, rightArm)
    {}
};

class LazerArmRobot : public Robot {
public:
    LazerArmRobot(LazerArm& leftArm, LazerArm& rightArm)
        : Robot("�������Ϸκ�", leftArm, rightArm)
    {}
};

class GunArmRobot : public Robot {
public:
    GunArmRobot(GunArm& leftArm, GunArm& rightArm)
        : Robot("��ź�Ϸκ�", leftArm, rightArm)
    {}
};


int main() {
    CannonArm cannonArm;
    BombArm bombArm;
    LazerArm lazerArm;
    GunArm gunArm;

    CannonArmRobot cannonArmRobot(cannonArm, cannonArm);
    BombArmRobot bombArmRobot(bombArm, bombArm);
    LazerArmRobot lazerArmRobot(lazerArm, lazerArm);
    GunArmRobot gunArmRobot(gunArm, gunArm);

    cannonArmRobot.Info();
    bombArmRobot.Info();
    lazerArmRobot.Info();
    gunArmRobot.Info();


    return 0;
}