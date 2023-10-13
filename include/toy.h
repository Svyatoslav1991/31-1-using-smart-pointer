#pragma once
#include <string>

class Toy 
{
public:
    Toy(std::string name = "ball") noexcept;
    ~Toy();
    Toy(const Toy& other) noexcept;
    Toy& operator==(const Toy& other) noexcept;
    Toy(Toy&& other) noexcept;
    Toy& operator=(Toy&& other) noexcept;

    std::string getName() const noexcept;
    
private:
    std::string m_name;
};