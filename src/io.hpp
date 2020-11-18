#pragma once

#include <vector>

class terminal
{
    public:
    terminal(int,int);

    void draw();

    void clear();

    void set_buffer(std::vector<std::vector<char>>);
    void set_char(int x, int y, char c);

    int get_width();
    int get_height();
    private:
    int width;
    int height;
    std::vector<std::vector<char>> buffer;
};