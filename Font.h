#ifndef FONT_H
#define FONT_H

#include <iostream>

#include "Rosalila/RosalilaGraphics/RosalilaGraphics.h"

using namespace std;

class Font
{
    public:
        int font_size=10;
        TTF_Font* font;
        SDL_Color textColor;
        string font_path;
        Font(string);

        void drawText(std::string text,int position_x,int position_y);
        void setSize(int size);
        void setColor(int,int,int);

        virtual ~Font();
    protected:
    private:
};

#endif // FONT_H
