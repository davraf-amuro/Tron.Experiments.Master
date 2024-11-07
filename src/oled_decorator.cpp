#include "oled_decorator.h"

OledDecorator::OledDecorator(Adafruit_SSD1306& display)
    : display(display), row1(""), row2(""), row3(""), row4("") {
}

void OledDecorator::setStyle(Style style) {
    _style = style;
}

void OledDecorator::setRow1(String text) {
    row1 = text;
}

void OledDecorator::setRow2(String text) {
    row2 = text;
}

void OledDecorator::setRow3(String text) {
    row3 = text;
}

void OledDecorator::setRow4(String text) {
    row4 = text;
}

void OledDecorator::clearRows() {
    row1 = "";
    row2 = "";
    row3 = "";
    row4 = "";
}

void OledDecorator::render() {
    display.clearDisplay();   
    display.setTextColor(SSD1306_WHITE);

    switch (_style)
    {
    case Style::STYLE_4ROWS:
        render4rows();
        break;
    case Style::STYLE_2ROWS:
        render2rows();
        break;
    default:
        break;
    }

    display.display();
}

void OledDecorator::render4rows() {
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println(row1);
    display.setCursor(0, 8);
    display.println(row2);
    display.setCursor(0, 16);
    display.println(row3);
    display.setCursor(0, 24);
    display.println(row4);
}

void OledDecorator::render2rows() {
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.println(row1);
    display.setCursor(0, 16);
    display.println(row2);
}