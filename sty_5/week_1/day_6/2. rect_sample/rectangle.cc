#include "rectangle.h"

Rectangle::Rectangle(int top, int left, int bottom, int right)
{
    its_top_ = top;
    its_left_ = left;
    its_bottom_ = bottom;
    its_right_ = right;

    its_upper_left_.SetX(left);
    its_upper_right_.SetY(top);

    its_upper_right_.SetX(right);
    its_upper_right_.SetY(top);

    its_lower_left_.SetX(left);
    its_lower_left_.SetY(bottom);

    its_lower_right_.SetX(right);
    its_lower_right_.SetY(bottom);
}

int Rectangle::GetArea() const
{
    int width = its_right_ - its_left_;
    int height = its_top_ - its_bottom_;

    return (width * height);
}

int main()
{
    Rectangle MyRectangle(100, 20, 50, 80);

    int area = MyRectangle.GetArea();

    std::cout << "Area: " << area << "\n";
    std::cout << "Upper Left X Coordinate: ";
    std::cout << MyRectangle.GetUpperLeft().GetX()
              << std::endl;
    return 0;
}