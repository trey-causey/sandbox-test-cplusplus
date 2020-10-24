//
// Created by TJC on 10/24/2020.
//
#include <string>
#include <vector>
#include <iostream>
enum class Color {Red, Green, Blue};
enum class Size {Small, Medium, Large};

struct Product
{
    std::string name;
    Color color;
    Size size;
};

struct ProductFilter
{
    typedef std::vector<Product *> Items;
    static Items by_color(Items items, Color color)
    {
      Items results;
      for(auto& i : items)
        if(i->color == color)
          results.push_back(i);
      return results;
    }
    static Items by_size(Items items, Size size)
    {
      Items results;
      for(auto& i : items)
        if(i->size == size)
          results.push_back(i);
      return results;
    }
};
template<typename T> struct ISpecification
{
    virtual bool is_satisfied(T* item) = 0;
};
template<typename T> struct IFilter
{
    virtual std::vector<T*> filter(std::vector<T*> items, ISpecification<T>& spec) = 0;
};

struct BetterFilter : IFilter<Product>
{
    typedef std::vector<Product*> Items;
    std::vector<Product*> filter(std::vector<Product*> items, ISpecification<Product>& spec) override
    {
      Items result;
      for (auto& p : items)
        if(spec.is_satisfied(p))
          result.push_back(p);
      return result;
    }
};

struct ColorSpecification : ISpecification<Product>
{
    Color color;
    explicit ColorSpecification(const Color color)
    : color{color}
    {

    }

    bool is_satisfied(Product* item) override {
      return item->color == color;
    }
};

/*
int main() {
  Product apple{"Apple", Color::Green, Size::Small};
  Product tree{"Tree", Color::Green, Size::Large};
  Product house{"House", Color::Blue, Size:: Medium};

  std::vector<Product*> all{ &apple, &tree, &house};
  BetterFilter bf;
  ColorSpecification green(Color::Green);

  auto green_things = bf.filter(all, green);
  for (auto& x : green_things)
    std::cout << x->name << " is green" << std::endl;
  getchar();
  return 0;
}*/
