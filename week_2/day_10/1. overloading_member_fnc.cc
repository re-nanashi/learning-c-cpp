#include <iostream>

//Rectangle class declaration
class Rectangle
{
public:
    //constructors
    Rectangle(int width, int height);
    ~Rectangle() {}

    //overloaded class function DrawShape
    void DrawShape();
    void DrawShape(int width, int height) const;

private:
    int its_width_;
    int its_height_;
};

//Constructor implementation
Rectangle::Rectangle(int width, int height)
{
    its_width_ = width;
    its_height_ = height;
}

//Overloaded DrawShape - no values
//Draws based on current class member values
void Rectangle::DrawShape()
{
    DrawShape(its_width_, its_height_);
}

void Rectangle::DrawShape(int width, int height) const
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

//Driver program to demonstrate overloaded functions
int main()
{
    //initialize a rectangle to 30, 5
    Rectangle the_rect(30, 5);
    std::cout << "DrawShape():" << std::endl;
    the_rect.DrawShape();
    std::cout << "\nDrawShape(40,2):" << std::endl;
    the_rect.DrawShape(40, 2);

    return 0;
}