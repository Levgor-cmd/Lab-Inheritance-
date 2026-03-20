// created by Lev | var.4

#include <iostream>

class Rectangle
{
protected:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) { }

    virtual ~Rectangle()
    {
        std::cout << "Rectangle destroyed" << std::endl;
    }

    virtual double area()
    {
        return length * width;
    }

    virtual void print()
    {
        std::cout << "This is rectangle " << length << " x " << width << std::endl;
        std::cout << "Its area is " << area() << std::endl;
    }
};

class RectangularParallelepiped : public Rectangle
{
protected:
    double height;

public:
    RectangularParallelepiped(double l, double w, double h) : Rectangle(l, w), height(h) { }

    ~RectangularParallelepiped()
    {
        std::cout << "Rectangular parallelepiped destroyed" << std::endl;
    }

    double area() override
    {
        return Rectangle::area() * height;
    }

    void print() override
    {
        Rectangle::print();
        std::cout << "Height is " << height << std::endl;
        std::cout << "Volume is " << area() << std::endl;
    }
};

int main()
{
    std::cout << "DYNAMIC POLYMORPHISM" << std::endl;

    Rectangle* ptr = new Rectangle(9, 7);
    ptr->print();
    delete ptr;

    std::cout << std::endl;

    ptr = new RectangularParallelepiped(3, 4, 5);
    ptr->print();
    delete ptr;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "STATIC POLYMORPHISM" << std::endl;

    Rectangle rect(9, 7);
    rect.print();

    std::cout << std::endl;

    RectangularParallelepiped rectP(3, 4, 5);
    rectP.print();

    return 0;
}
