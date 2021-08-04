#include <iostream>

using namespace std;

class Rectangle
{
public:
    Rectangle();
    ~Rectangle() {}
    void SetLength(int length) { its_length_ = length; }
    int GetLength() const { return its_length_; }
    void SetWidth(int width) { its_width_ = width; }
    int GetWidth() const { return its_width_; }

private:
    int its_width_;
    int its_length_;
};

Rectangle::Rectangle()
{
    its_width_ = 5;
    its_length_ = 10;
}

int main()
{
    Rectangle *p_rect = new Rectangle;             //can be relocated + changed
    const Rectangle *p_const_rect = new Rectangle; //can be relocated but not changed
    Rectangle *const p_const_ptr = new Rectangle;  //can change but not relocated

    cout << "p_rect width: " << p_rect->GetWidth() << " feet" << endl;
    cout << "p_const_rect " << p_const_rect->GetWidth() << " feet" << endl;
    cout << "p_const_ptr " << p_const_ptr->GetWidth() << " feet" << endl;

    p_rect->SetWidth(10);
    // p_const_rect->SetWidth(10);   error: can be relocated but not changed
    p_const_ptr->SetWidth(10);

    cout << "p_rect width: " << p_rect->GetWidth() << " feet" << endl;
    cout << "p_const_rect " << p_const_rect->GetWidth() << " feet" << endl;
    cout << "p_const_ptr " << p_const_ptr->GetWidth() << " feet" << endl;

    return 0;
}