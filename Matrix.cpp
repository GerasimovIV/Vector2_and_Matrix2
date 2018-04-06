#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Vector.cpp"
using namespace std;

class Matrix2
{
public:
    Matrix2();
	Matrix2(int x, int y, int z, int s);
    ~Matrix2();
    int getX();
    int getY();
	int getZ();
    int getS();
	void setX(int x);
    void setY(int y);
	void setZ(int x);
    void setS(int y);
    bool operator== (const Matrix2& v2);
    int x;
    int y;
	int z;
    int s;
    bool operator!= (const Matrix2& v2);
    Matrix2 operator+ (const Matrix2& v2);
    Matrix2 operator* (const int a);
	Matrix2 operator* (const Matrix2& v2);
	Matrix2 operator- (const Matrix2& v2);
    Vector2D operator* (const Vector2D& v);

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

Vector2D Matrix2::operator* (const Vector2D& v)
{
    Vector2D vec(this->x * v.x + this->y * v.y, this->z * v.x + this->s * v.y);
    return vec; 
}
int Matrix2::getX()
{
	return this->x;
}
int Matrix2::getY()
{
	return this->y;
}
int Matrix2::getZ()
{
	return this->z;
}
int Matrix2::getS()
{
	return this->s;
}
bool Matrix2::operator== (const Matrix2& v2)
{
	if((this->x == v2.x) && (this->y == v2.y) && (this->z == v2.z) && (this->s == v2.s))
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
	if((this->x != v2.x) || (this->y != v2.y) || (this->z != v2.z) || (this->s != v2.s))
	{
		return true;
	}
	else
	{
		return false;
	}
}
Matrix2 Matrix2::operator+ (const Matrix2& v2)
{
	Matrix2 Vec(this->x + v2.x, this->y + v2.y, this->z + v2.z, this->s + v2.s);
	return Vec;
}

Matrix2 Matrix2::operator- (const Matrix2& v2)
{
    Matrix2 Vec(this->x - v2.x, this->y - v2.y, this->z - v2.z, this->s - v2.s);
    return Vec;
}

Matrix2 Matrix2::operator* (const int a)
{
	Matrix2 Vec(this->x * a, this->y * a, this->z * a, this->s * a);
	return Vec;
}

Matrix2 Matrix2::operator* (const Matrix2& v2)
{
	Matrix2 Vec(this->x * v2.x + this->y * v2.z, this->x * v2.y + this->y * v2.s , this->z * v2.x + this->s * v2.z, this->z * v2.y + this->s * v2.s);
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

// Перегруженный оператор, вывод вектора в формате (1; 1)
std::ostream& operator<<(std::ostream& os, Matrix2& v)
{  
    os <<"|("<< v.x << "; " << v.y << ")" << endl;
	os <<" ("<< v.z << "; " << v.s << ")|";
    return os;  
} 
Matrix2 operator* (int a, const Matrix2& v)
{
        Matrix2 Vec(v.x * a, v.y * a, v.z * a, v.s * a);
        return Vec;
}

std::istream& operator>>(std::istream &is, Matrix2 &v)
{
	is >> v.x;
	is >> v.y;
	is >> v.z;
	is >> v.s;
	return is;
}


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
}

