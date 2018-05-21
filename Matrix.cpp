#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Vector.cpp"


class Matrix2
{
public:
    Matrix2();
    Matrix2(int x, int y, int z, int s);
    ~Matrix2();
    int getX() const;
    int getY() const;
    int getZ() const;
    int getS() const;
    void setX(int x);
    void setY(int y);
    void setZ(int x);
    void setS(int y);
    bool operator== (const Matrix2& v2);
    int det();
    bool operator!= (const Matrix2& v2);
    Matrix2 operator+ (const Matrix2& v2);
    Matrix2 operator* (const int a);
    Matrix2 operator* (const Matrix2& v2);
    Matrix2 operator- (const Matrix2& v2);
    Vector2D operator* (const Vector2D& v);
private:
    int x;
    int y;
    int z;
    int s;

};
Matrix2::Matrix2(){}


Matrix2::Matrix2(int x, int y, int z, int s)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->s = s;
}
Matrix2::~Matrix2(){}

// Перегруженный оператор, вывод вектора в формате (1; 1)
std::ostream& operator<<(std::ostream& os, Matrix2 const &v2)
{
    os <<"|("<< v2.getX() << "; " << v2.getY() << ")" << endl;
    os <<" ("<< v2.getZ() << "; " << v2.getS() << ")|";
    return os;
}


Vector2D Matrix2::operator* (const Vector2D& v)
{
    Vector2D vec(this->x * v.getX() + this->y * v.getY(), this->z * v.getX() + this->s * v.getY());
    return vec;
}
int Matrix2::getX() const
{
        return this->x;
}
int Matrix2::getY() const
{
        return this->y;
}
int Matrix2::getZ() const
{
        return this->z;
}
int Matrix2::getS() const
{
        return this->s;
}
bool Matrix2::operator== (const Matrix2& v2)
{
        if((this->x == v2.getX()) && (this->y == v2.getY()) && (this->z == v2.getZ()) && (this->s == v2.getS()))
        {
                return true;
        }
        else
        {
                return false;
        }
}

bool Matrix2::operator!= (const Matrix2& v2)
{
    return !(this->operator ==(v2));
}
Matrix2 Matrix2::operator + (const Matrix2& v2)
{
        Matrix2 Vec(this->x + v2.getX(), this->y + v2.getY(), this->z + v2.getZ(), this->s + v2.getS());
        return Vec;
}

Matrix2 Matrix2::operator- (const Matrix2& v2)
{
    Matrix2 Vec(this->x - v2.getX(), this->y - v2.getY(), this->z - v2.getZ(), this->s - v2.getS());
    return Vec;
}





void Matrix2::setX(int x)
{
        this->x = x;
}

void Matrix2::setY(int y)
{
        this->y = y;
}

void Matrix2::setZ(int z)
{
        this->z = z;
}
void Matrix2::setS(int s)
{
        this->s = s;
}

Matrix2 Matrix2::operator* ( int a)
{
        Matrix2 Mat(this->getX() * a, this->getY() * a, this->getZ() * a, this->getS() * a);
        return Mat;
}

Matrix2 Matrix2::operator* (const Matrix2& v2)
{
        Matrix2 Vec(this->x * v2.getX() + this->y * v2.getZ(), this->x * v2.getY() + this->y * v2.getS() , this->z * v2.getX() + this->s * v2.getZ(), this->z * v2.getY() + this->s * v2.getS());
        return Vec;
}

Matrix2 operator* (int a, const Matrix2& m)
{
        Matrix2 m0 = m;
        Matrix2 Mat = m0.operator *(a);
        return Mat;
}

int Matrix2::det()
{
    return this->getX()*this->getS() - this->getY() * this->getZ();
}

std::istream& operator>>(std::istream &is, Matrix2 &v)
{
        int a,b,c,d;
        is >> a;
        is >> b;
        is >> c;
        is >> d;
        v.setX(a);
        v.setY(b);
        v.setZ(c);
        v.setS(d);
        return is;
}

/*
std::ostream& operator<<(std::ostream& os, Matrix2 v)
{
    os <<"|("<< v.getX() << "; " << v.getY() << ")" << endl;
        os <<" ("<< v.getZ() << "; " << v.getS() << ")|";
    return os;
}
*/


/*
int main()
{
        Matrix2 v1(1, 2, 3, 4);
    Matrix2 v2(3, 4, 5, 6);
    cout << v1 << endl;
    cout << v2 << endl;
    Matrix2 v3 = v1 + v2;
    cout << v3 << endl;
    cout << (v1 == v2) << endl;
    cout << (v1 != v2) << endl;
        Matrix2 s = v1 * v2;
        cout << s << endl;
        Matrix2 v5 = v1 * 5;
        Matrix2 v6 = v2 - v1;
        cout << v5 << endl;
        cout << v6 << endl;
    Vector2D v(1, 7);
    Vector2D v7 = v1 * v;
    cout << v7 << endl;
        return 0;
}*/

int main()
{
    Matrix2 m1(0, 1, 1, 2);
    Matrix2 m2(0, 1, 2, 2);

    std::cout << "=== Test matrix ===" << std::endl;

    std::cout << (m1 + m2) << std::endl;
    std::cout << (m1 - m2) << std::endl;
    std::cout << m1 * 5 << std::endl;
    std::cout << -5 * m2 << std::endl;
    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;
    std::cout << m1 * m2 << std::endl;
    std::cout << m1.det() << std::endl;

    std::cout << "=== Cross test vector and matrix ===" << std::endl;

    Vector2D v1 = {1, 1};
    std::cout << m1 * v1 << std::endl;

    if (m1 != m2)
    {
        std::cout << "YES" << std::endl;
    }

    return 0;
}
