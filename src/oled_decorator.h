#ifndef OLED_DECORATOR_H
#define OLED_DECORATOR_H

#include <Adafruit_SSD1306.h>

class OledDecorator {
public:
    OledDecorator(Adafruit_SSD1306& display);
    void render();

    enum Style {
        STYLE_4ROWS,
        STYLE_2ROWS     
    };
    void setStyle(Style style);
    void setRow1(String text);
    void setRow2(String text);
    void setRow3(String text);
    void setRow4(String text);
    void clearRows();

private:
    Adafruit_SSD1306& display;    
    String row1, row2, row3, row4;
    Style _style = STYLE_4ROWS;
    void render4rows();
    void render2rows();
};

#endif // OLED_DECORATOR_H