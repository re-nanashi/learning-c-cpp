#include <iostream>

class Point
{
public:
    void SetX(int x) { its_x_ = x; }
    void SetY(int y) { its_y_ = y; }
    int GetX() const { return its_x_; }
    int GetY() const { return its_y_; }

private:
    int its_x_;
    int its_y_;
};

class Rectangle
{
public:
    Rectangle(int top, int left, int bottom, int right);
    ~Rectangle() {}

    int GetTop() const { return its_top_; }
    int GetLeft() const { return its_left_; }
    int GetBottom() const { return its_bottom_; }
    int GetRight() const { return its_right_; }

    Point GetUpperLeft() const { return its_upper_left_; }
    Point GetLowerLeft() const { return its_lower_left_; }
    Point GetUpperRight() const { return its_upper_right_; }
    Point GetLowerRight() const { return its_lower_right_; }

    void SetUpperLeft(Point Location) { its_upper_left_ = Location; }
    void SetLowerLeft(Point Location) { its_lower_left_ = Location; }
    void SetUpperRight(Point Location) { its_upper_right_ = Location; }
    void SetLowerRight(Point Location) { its_lower_right_ = Location; }

    void SetTop(int top) { its_top_ = top; }
    void SetLeft(int left) { its_left_ = left; }
    void SetBottom(int bottom) { its_bottom_ = bottom; }
    void SetRight(int right) { its_right_ = right; }

    int GetArea() const;

private:
    Point its_upper_left_;
    Point its_upper_right_;
    Point its_lower_left_;
    Point its_lower_right_;
    int its_top_;
    int its_left_;
    int its_bottom_;
    int its_right_;
};