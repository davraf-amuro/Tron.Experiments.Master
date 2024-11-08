#include "oled_decorator.h"

OledDecorator::OledDecorator(Adafruit_SSD1306& display)
    : display(display), row1(""), row2(""), row3(""), row4("") {
}

void OledDecorator::setStyle(Style style) {
    _style = style;
}

void OledDecorator::setRow1(String text) { setRow1(text, false); }
void OledDecorator::setRow2(String text) { setRow2(text, false); }
void OledDecorator::setRow3(String text) { setRow3(text, false); }
void OledDecorator::setRow4(String text) { setRow4(text, false); }

void OledDecorator::setRow1(String text, bool renderNow) {
    row1 = text;
    if (renderNow) { render(); }
}

void OledDecorator::setRow2(String text, bool renderNow) {
    row2 = text;
    if (renderNow) { render(); }
}

void OledDecorator::setRow3(String text, bool renderNow) {
    row3 = text;
    if (renderNow) { render(); }
}

void OledDecorator::setRow4(String text, bool renderNow) {
    row4 = text;
    if (renderNow) { render(); }
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
    // case Style::STYLE_3ROWS:
    //     render3rows();
    //     break;
    case Style::STYLE_1ROWS:
        render1rows();
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
    display.setTextSize(1,2);
    display.setCursor(0, 0);
    display.println(row1);
    display.setCursor(0, 17);
    display.println(row2);
}

void OledDecorator::render3rows() {
    display.setTextSize(1,2);
    display.setCursor(0, 0);
    display.println(row1);
    display.setCursor(0, 10);
    display.println(row2);
    display.setCursor(0, 20);
    display.println(row4);
}

void OledDecorator::render1rows() {
    display.setTextSize(1,4);
    display.setCursor(0, 0);
    display.println(row1);
}