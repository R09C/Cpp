#include <iostream>
#include <numbers>

using namespace std;

class Shape {
public:
  virtual ~Shape() = default;
  virtual double area() const = 0;
};

class Circle : public Shape {
  double radius;

public:
  explicit Circle(double r) : radius(r) {}

  double area() const override {
    return numbers::pi * radius * radius;
  }
};

class Rectangle : public Shape {
  double width, height;

public:
  Rectangle(double w, double h) : width(w), height(h) {}

  double area() const override {
    return width * height;
  }
};

class Square : public Shape {
  double side;

public:
  explicit Square(double s) : side(s) {}

  double area() const override {
    return side * side;
  }
};

void print_area(const Shape& shape){
  cout << shape.area() << '\n';
}

int main(){
  Circle circle(2);
  Rectangle rect(3, 5);
  Square square(4);

  const Shape* shapes[] = {&circle, &rect, &square};
  for (const auto* shape : shapes) {
    print_area(*shape);
  }
  return 0;
}
