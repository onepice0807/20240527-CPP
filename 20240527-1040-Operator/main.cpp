#include <iostream>
#include <string>

using namespace std;

// Ŭ�������� ���踦 �δ� ���
// ���, ����
// Arm, Robot�� ��ӵǰ� ������� ���� Robot�� �ڽ��� ������ Robot Ȱ���ϱ�

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

int main() {
    CannonArm cannonArm;
    BombArm bombArm;
    LazerArm lazerArm;
    GunArm gunArm;

    Robot cannonArmRobot("ĳ��Ϸκ�", cannonArm, cannonArm);
    Robot bombArmRobot("��ź�Ϸκ�", bombArm, bombArm);
    Robot lazerArmRobot("�������Ϸκ�", lazerArm, lazerArm);
    Robot gunArmRobot("��ź�Ϸκ�", gunArm, gunArm);
    Robot IcannonArmRgunArmRobot("����ĳ��Ͽ�������ź�Ϸκ�", cannonArm, gunArm);

    cannonArmRobot.Info();
    bombArmRobot.Info();
    lazerArmRobot.Info();
    gunArmRobot.Info();
    IcannonArmRgunArmRobot.Info();

    return 0;
}