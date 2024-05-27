#include <iostream>
#include <math.h>

using namespace std;

class Point {
private:
    int _x, _y;

public:
    Point(int x, int y)
        : _x(x), _y(y) {}

    int GetX() {
        return _x;
    }

    int GetY() {
        return _y;
    }

    void Info() {
        cout << "x: " << _x << ", y: " << _y << endl;
    }
};

class Line {
private:
    Point _pt1, _pt2;

public:
    Line(int pt1x, int pt1y, int pt2x, int pt2y)
        : _pt1(pt1x, pt1y), _pt2(pt2x, pt2y) {}

    Line(Point pt1, Point pt2)
        : _pt1(pt1), _pt2(pt2) {}

    float GetLength() {
        int xBase = _pt2.GetX() - _pt1.GetX();
        int height = _pt1.GetY() - _pt2.GetY();

        return sqrt(pow(xBase, 2) + pow(height, 2));
    }
};

// 삼각형 클래스 (정삼각형, 직삼각형)
// 사각형 클래스 (정사각형, 직각사각형)
// 원 클래스

// 각각의 도형클래스를 만들고 면적을 출력하세요..

class Triangle {
private:
    Point _topPt, _leftBottomPt, _rightBottomPt;

public:
    Triangle(Point topPt, Point leftBottomPt, Point rightBottomPt)
        :_topPt(topPt), _leftBottomPt(leftBottomPt), _rightBottomPt(rightBottomPt) {}

    Triangle(int leftBottomPtX, int leftBottomPtY, int topPtX, int topPtY, int rightBottomPtX, int rightBottomPtY)
        :_topPt(topPtX, topPtY), _leftBottomPt(leftBottomPtX, leftBottomPtY),
        _rightBottomPt(rightBottomPtX, rightBottomPtY) {}

    float GetArea() {
            int xBase = _rightBottomPt.GetX() - _leftBottomPt.GetX();
            int height = _leftBottomPt.GetY() - _topPt.GetY();

            return xBase * height / 2.0f;
    }

   
};

class Rectangle {
private: 
    Point _leftTopPt, _rightBottomPt;

public: 
    Rectangle(int leftTopPtX, int leftTopPtY, int rightBottomPtX, int rightBottomPtY)
        : _leftTopPt(leftTopPtX, leftTopPtY), _rightBottomPt(rightBottomPtX, rightBottomPtY) {}

    Rectangle(Point leftTopPt, Point rightBottomPt)
        : _leftTopPt(leftTopPt), _rightBottomPt(rightBottomPt) {}

    float GetArea() {
        int xBase = _rightBottomPt.GetX() - _leftTopPt.GetX();
        int height = _rightBottomPt.GetY() - _leftTopPt.GetY();

        return xBase * height;
    }
};

class Cycle {
private:
    Point _centerPt; // 중심점
    int _radius; // 반지름
    const float Pl = 3.14f;

public:
    Cycle(int centerPtX, int centerPtY, int radius)
        : _centerPt(centerPtX, centerPtY), _radius(radius) {}

    Cycle(Point centerPt, Point edgePt)
        : _centerPt(centerPt)
    {
        Line line(centerPt, edgePt);

        _radius = line.GetLength();
    }

    Cycle(int centerPtX, int centerPtY, int edgePtX, int edgePtY)
        : _centerPt(centerPtX, centerPtY) 
    {
        Line line(centerPtX, centerPtY, edgePtX, edgePtY);

        _radius = line.GetLength();
    }
    
    float GetArea() {
        return Pl * _radius * _radius;
    }
};


int main() {
    Line line(0, 0, 4, 4);
    cout << "line length = " << line.GetLength() << endl;

    Triangle tri(0, 4, 2, 2, 4, 4);
    cout << "tri area = " << tri.GetArea() << endl;

    Point leftTopPt(2, 2);
    Point rightBottomPt(4, 4);

    Rectangle rect(leftTopPt, rightBottomPt);
    cout << "Rectangle area = " << rect.GetArea() << endl;

    Cycle cycle(0, 0, 4, 4);
    cout << "cycle area = " << cycle.GetArea() << endl;

    return 0;
}