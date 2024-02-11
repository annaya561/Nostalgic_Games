#include <bits/stdc++.h>
using namespace std;
/********************************** base class ***********************************/
class baseShape
{
protected:
    float height, length, breadth, vol;

public:
    void getData(float, float, float);
    virtual void volume() = 0;
    virtual void display() = 0;
};
void baseShape ::getData(float l, float br = 1, float h = 1)
{
    length = l;
    breadth = br;
    height = h;
}
/*************************************** pyramid ***********************************/
class Pyramid : public baseShape
{
private:
    string shape;

public:
    void volume();
    void display();
};

void Pyramid ::volume()
{
    string s;
    cout << "Enter type of pyramid.\n";
    cin >> s;
    shape = s;
    if (s == "triangular")
        vol = (float)1 / 6 * (length * height * breadth);
    else if (s == "square")
        vol = (float)1 / 3 * (length * height * breadth);
    else if (s == "rectangular")
        vol = (float)1 / 3 * (length * height * breadth);
    else if (s == "pentagonal")
        vol = (float)5 / 6 * (length * height * breadth);
    else if (s == "hexagonal")
        vol = length * height * breadth;
    else
    {
        cout << "No such pyramid exist.\n";
        vol = 0;
    }
}
void Pyramid::display()
{
    cout << "Volume of " << shape << " pyramid is " << vol <<
     endl;
}
/************************************** cuboid ***********************************/
class Cuboid : public baseShape
{
private:
public:
    void volume();
    void display();
};
void Cuboid::volume()
{
    vol = length * height * breadth;
}
void Cuboid::display()
{
    cout << "Volume of cuboid is " << vol << endl;
}

/*************************************** sphere ********************************/
class sphere : public baseShape
{
private:
public:
    void volume();
    void display();
};
void sphere::volume()
{
    vol = 4 / 3 * 3.14 * pow(length, 3);
}
void sphere::display()
{
    cout << "Volume of sphere is " << vol << endl;
}

/*************************************** main **********************************/
int main()
{
    
    baseShape *ptr;
    Cuboid cu;
    Pyramid p;
    sphere s;
    int Choice;
    cout << "1- Pyramid " << endl;
    cout << "2- Cuboid" << endl;
    cout << "3- Sphere" << endl;
    cout << "0- End the program" << endl;
    do
    {
        cout << "Enter your choice." << endl;
        cin >> Choice;
        switch (Choice)
        {
        case 1:
        {
            float a, b, c;
            cout << "Enter base lengths and height respectively.\n";
            cin >> a >> b >> c;
            p.getData(a, b, c);
            p.volume();
            p.display();
        }
        break;
        case 2:
        {
            float a, b, c;
            cout << "Enter length, breadth and height respectively.\n";
            cin >> a >> b >> c;
            cu.getData(a, b, c);
            cu.volume();
            cu.display();
        }
        break;
        case 3:
        {
            float r;
            cout << "Enter radius of sphere.\n";
            cin >> r;
            s.getData(r);
            s.volume();
            s.display();
        }
        break;
        default:
            cout << "Wrong input.\n";
            break;
        case 0:
            exit;
        }
    } while (Choice != 0);

    return 0;
}