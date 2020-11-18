#include "io.hpp"

#include <iostream>

terminal::terminal(int w, int h)
{
    this->width = w;
    this->height = h;

    std::vector<char> row;

    for(int x = 0; x < width; x++)
    {
        row.push_back(' ');
    }

    for(int y = 0; y < height; y++)
    {
        buffer.push_back(row);
    }
}

void terminal::draw()
{
    for(int y = 0; y < buffer.size(); y++)
    {
        for(int x = 0; x < buffer.at(y).size(); x++)
        {
            std::cout<<buffer.at(y).at(x);
        }

        std::cout<<"\n";
    }
}

void terminal::clear()
{
    std::vector<char> row;

    for(int x = 0; x < width; x++)
    {
        row.push_back(' ');
    }

    for(int y = 0; y < height; y++)
    {
        buffer.at(y) = row;
    }
}

void terminal::set_buffer(std::vector<std::vector<char>> b)
{
    this->buffer = b;
}

void terminal::set_char(int x, int y, char c)
{
    buffer.at(y).at(x) = c;
}

int terminal::get_width()
{
    return this->width;
}

int terminal::get_height()
{
    return this->height;
}