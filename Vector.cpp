

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

class Vector2D
{
public:
    Vector2D();
    Vector2D(int x, int y);
    ~Vector2D();
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    bool operator== (const Vector2D& v2);
    bool operator!= (const Vector2D& v2);
    Vector2D operator+ (const Vector2D& v2);
    Vector2D operator* (const int a);
    int operator* (const Vector2D& v2);
    Vector2D operator- (const Vector2D& v2);
private:
    int x;
    int y;
};
Vector2D::Vector2D(){}


Vector2D::Vector2D(int x, int y)
{
    this->x = x;
    this->y = y;
}
Vector2D::~Vector2D(){}


int Vector2D::getX() const
{
        return this->x;
}
int Vector2D::getY() const
{
        return this->y;
}
bool Vector2D::operator== (const Vector2D& v2)
{
        if((this->x == v2.getX()) && (this->y == v2.getY()))
        {
                return true;
        }
        else
        {
                return false;
        }
}


bool Vector2D::operator!= (const Vector2D& v2)
{
        return !(this->operator ==(v2));
}
Vector2D Vector2D::operator+ (const Vector2D& v2)
{
        Vector2D Vec(this->x + v2.getX(), this->y + v2.getY());
        return Vec;
}

Vector2D Vector2D::operator- (const Vector2D& v2)
{
    Vector2D Vec(this->x - v2.getX(), this->y - v2.getY());
    return Vec;
}

Vector2D Vector2D::operator* (const int a)
{
        Vector2D Vec(this->x * a, this->y * a);
        return Vec;
}

int Vector2D::operator* (const Vector2D& v2)
{
        return this->x * v2.getX() + this->y * v2.getY();
}

void Vector2D::setX(int x)
{
        this->x = x;
}

void Vector2D::setY(int y)
{
        this->y = y;
}

// Перегруженный оператор, вывод вектора в формате (1; 1)
std::ostream& operator<<(std::ostream& os,const Vector2D& v)
{
    os <<"|("<< v.getX() << "; " << v.getY() << ")|";
    return os;
}
Vector2D operator* (int a, const Vector2D& v)
{
        Vector2D Vec(v.getX() * a, v.getY() * a);
        return Vec;
}

std::istream& operator>>(std::istream &is, Vector2D &v)
{
        int a,b;
        is >> b;
        is >> a;
        v.setX(a);
        v.setY(b);
        return is;
}
/*

int main()
{
    Vector2D v1(1, 2);
    Vector2D v2(3, 4);
    Vector2D v3 = v1 + v2;
    cout << v3 << endl;
    cout << (v1 == v2) << endl;
    cout << (v1 != v2) << endl;
    int s = v1 * v2;
    cout << s << endl;
    Vector2D v5 = v1 * 5;
    Vector2D v6 = v2 - v1;
    cout << v5 << endl;
    cout << v6 << endl;
    Vector2D v7 = {1,2};
    cout << v7 << endl;
    cout << v7 + v6 << endl;


        return 0;
}


*/
