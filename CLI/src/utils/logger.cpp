#include "common.hpp"

int RedBuf::overflow(int c)
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

RedBuf redbuf_cerr(std::cerr.rdbuf());
RedBuf redbuf_clog(std::clog.rdbuf());