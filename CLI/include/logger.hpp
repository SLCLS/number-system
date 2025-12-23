#ifndef LOGGER_HPP
#define LOGGER_HPP

// Colored output for errors and logs.

#include <streambuf>
#include <iostream>

struct RedBuf : std::streambuf
{
    std::streambuf* dest;
    bool colored = false;

    RedBuf(std::streambuf* d) : dest(d) {}

    int overflow(int c) override
    {
        if (!colored)
        {
            dest->sputn("\033[31m", 5); // Start red
            colored = true;
        }
        if (c == '\n')
        {
            dest->sputn("\033[0m", 4); // Reset color
            colored = false;
        }
        return dest->sputc(c);
    }
};

RedBuf redbuf_cerr(std::cerr.rdbuf());
RedBuf redbuf_clog(std::clog.rdbuf());

#endif