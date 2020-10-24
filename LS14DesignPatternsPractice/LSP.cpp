//
// Created by TJC on 10/24/2020.
//
#include <iostream>
class Rectangle
{
protected:
    int width, height;
public:
    Rectangle(int width, int height)
    : width(width), height(height)
    {

    }

    virtual int getWidth() const {
      return width;
    }

    virtual void setWidth(int width) {
      Rectangle::width = width;
    }

    virtual int getHeight() const {
      return height;
    }

    virtual void setHeight(int height) {
      Rectangle::height = height;
    }
    int Area() const { return width*height;}
};

class Square : public Rectangle
{
public:
    Square(int size) : Rectangle{size, size} {}

    void setWidth(int width) override {
      //Rectangle::setWidth(width);
      this->width = height = width;
    }

    void setHeight(int height) override {
      //Rectangle::setHeight(height);
      this->height = width = height;
    }
};//end Square()
void process(Rectangle& r)
{
  int w = r.getWidth();
 r.setHeight(10);
 std::cout << "expect area = " << (w*10) << ", got " << r.Area() << std::endl;
}

int main()
{
  Rectangle r {5,5};
  process(r);

  Square s {3};
  process(s);

  //getchar();
  return 0;
}