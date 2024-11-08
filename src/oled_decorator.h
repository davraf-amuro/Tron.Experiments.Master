#ifndef OLED_DECORATOR_H
#define OLED_DECORATOR_H

#include <Adafruit_SSD1306.h>

class OledDecorator {
public:
    OledDecorator(Adafruit_SSD1306& display);
    void render();

    enum Style {
        STYLE_1ROWS,
        STYLE_2ROWS,
        // STYLE_3ROWS,
        STYLE_4ROWS     
    };
    void setStyle(Style style);
    void setRow1(String text);
    void setRow1(String text, bool renerNow);
    void setRow2(String text);
    void setRow2(String text, bool renerNow);
    void setRow3(String text);
    void setRow3(String text, bool renerNow);
    void setRow4(String text);
    void setRow4(String text, bool renerNow);
    void clearRows();

private:
    Adafruit_SSD1306& display;    
    String row1, row2, row3, row4;
    Style _style = STYLE_4ROWS;
    void render4rows();
    void render3rows();
    void render2rows();
    void render1rows();
};

#endif // OLED_DECORATOR_H