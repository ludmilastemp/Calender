#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

void monthes(int i, int j, std::string x, sf::Font& font, sf::RenderWindow& window) {
    sf::Text text;
    text.setFont(font);
    text.setString(x);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(i * 250 + 50, j * 200 + 75);
    window.draw(text);
}

void weeks(int i, int j, int k, std::string x, sf::Font& font, sf::RenderWindow& window) {
    sf::Text text;
    text.setFont(font);
    text.setString(x);
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(i * 250 + 20, j * 200 + 95 + k * 20);
    window.draw(text);
}

void dates(int i, int j, int week, int date, int p, sf::Font& font, sf::RenderWindow& window) {
    std::string s = std::to_string(date);
    sf::Text text;
    text.setFont(font);
    text.setString(s);
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(i * 250 + 50 + p * 30, j * 200 + 75 + week * 20);
    window.draw(text);
}

void years(sf::String yearstr, sf::Font& font, sf::RenderWindow& window) {
    sf::Text text; // хрень, которую можно нарисовать
    text.setFont(font); // теперь у нас есть шрифт
    text.setString(yearstr); // передали текст 
    text.setCharacterSize(50); // размер буковок
    text.setFillColor(sf::Color::Red); // цвет буковок
    text.setStyle(sf::Text::Bold | sf::Text::Underlined); // хрень закончилась
    text.setPosition(430, 0); // перемещаем надпись
    window.draw(text);
}

void DrowButton(sf::RenderWindow& window)
{
    sf::ConvexShape left_button(3);
    left_button.setPoint(0, sf::Vector2f(418, 20));
    left_button.setPoint(1, sf::Vector2f(418, 50));
    left_button.setPoint(2, sf::Vector2f(388, 35));
    left_button.setFillColor(sf::Color::Red);
    sf::ConvexShape right_button(3);
    right_button.setPoint(0, sf::Vector2f(560, 20));
    right_button.setPoint(1, sf::Vector2f(560, 50));
    right_button.setPoint(2, sf::Vector2f(590, 35));
    right_button.setFillColor(sf::Color::Red);
    window.draw(left_button);
    window.draw(right_button);
}

void Holiday(int year, sf::String yearstr, sf::Font& font, sf::RenderWindow& window) {
    int nweek;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        nweek = (year - 1 + (year - 1) / 4 - (year - 1) / 400 * 3 + 5) % 7 + 1;
        if (nweek == 6 || nweek == 7) {
            sf::Text text;
            text.setFont(font);
            text.setString("14");
            text.setCharacterSize(20);
            text.setFillColor(sf::Color::Red);
            text.setPosition(0 * 250 + 50 + 1 * 30, 2 * 200 + 75 + nweek * 20);
            window.draw(text);
        }
        else {
            sf::Text text;
            text.setFont(font);
            text.setString("14");
            text.setCharacterSize(20);
            text.setFillColor(sf::Color::Red);
            text.setPosition(0 * 250 + 50 + 2 * 30, 2 * 200 + 75 + nweek * 20);
            window.draw(text);
        }
    }
    else {
        nweek = (year - 1 + (year - 1) / 4 - (year - 1) / 400 * 3 + 3) % 7 + 1;
        if (nweek == 6 || nweek == 7) {
            sf::Text text;
            text.setFont(font);
            text.setString("13");
            text.setCharacterSize(20);
            text.setFillColor(sf::Color::Red);
            text.setStyle(sf::Text::Bold);
            text.setPosition(0 * 250 + 50 + 1 * 30, 2 * 200 + 75 + nweek * 20);
            window.draw(text);
        }
        else {
            sf::Text text;
            text.setFont(font);
            text.setString("13");
            text.setCharacterSize(20);
            text.setFillColor(sf::Color::Red);
            text.setStyle(sf::Text::Bold);
            text.setPosition(0 * 250 + 50 + 2 * 30, 2 * 200 + 75 + nweek * 20);
            window.draw(text);
        }
    }

}

void DrowCalander(int year, sf::String yearstr, sf::Font& font, sf::RenderWindow& window) {
    years(yearstr, font, window);
    std::string month[4][3] = { {"January", "May", "September"}, {"February", "June", "October"}, {"March", "July", "November"}, { "April", "August", "December"} };
    std::string week[7] = { "m", "t", "w", "t", "f", "s", "s" };
    int a;
    if (year > 0 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
        a = 29;
    }
    else if (year < 0 && (((year + 1) % 4 == 0 && (year + 1) % 100 != 0) || (year + 1 % 400 == 0))) {
        a = 29;
    }
    else {
        a = 28;
    }
    int date[4][3] = { {31, 31, 30}, {a, 30, 31}, {31, 31, 30}, {30, 31, 31} };
    int nweek = (year - 1 + (year - 1) / 4 - (year - 1) / 400 * 3) % 7 + 1;
    if (year < 0) {
        year = abs(year);
        nweek = 7 - ((year + (year - 1) / 4 - (year - 1) / 400 * 3) % 7);
    }
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 4; i++) {
            monthes(i, j, month[i][j], font, window);
            for (int k = 0; k < 7; k++) {
                weeks(i, j, k, week[k], font, window);
            }
            int p = 0;
            for (int k = 1; k <= date[i][j]; k++) {
                dates(i, j, nweek, k, p, font, window);
                nweek++;
                if (nweek == 8) {
                    nweek -= 7;
                    p++;
                }
            }
        }
    }
    window.display();
}

void Event(sf::RenderWindow& window, sf::Image& img) {
    sf::Font font;
    if (!font.loadFromFile("D:/Proga/Calender/Raleway-Regular.ttf"))
    {
        // error...
    }
    sf::String yearstr;
    int year = 1;
    int kyear = 0;
    sf::Texture texture;
    texture.loadFromImage(img);
    sf::Sprite sprite;
    sprite.setTexture(texture, true);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {
                year = 0;
                int j = 1;
                std::string s = yearstr.toAnsiString();
                for (int i = s.length() - 1; i >= 0; i--) {
                    if (s[i] == '-') year = -year;
                    else {
                        year += (int)(s[i] - '0') * j;
                        j *= 10;
                    }
                }
            }
            else if (event.key.code == sf::Keyboard::Backspace) {
                kyear -= 1;
                yearstr.erase(kyear);
            }
            else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128)
                {
                    yearstr += event.text.unicode;
                    kyear += 1;
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Right) {
                    if (event.mouseButton.x - 458 > -2 * event.mouseButton.y &&
                        event.mouseButton.x - 318 > 2 * event.mouseButton.y &&
                        event.mouseButton.x < 418) {
                        if (year == 1) year = year - 2;
                        else year = year - 1;
                    }
                    else if (event.mouseButton.x - 660 < -2 * event.mouseButton.y &&
                        event.mouseButton.x - 520 < 2 * event.mouseButton.y &&
                        event.mouseButton.x > 560) {
                        if (year == -1) year = year + 2;
                        else year = year + 1;
                    }
                    yearstr.erase(kyear);
                    yearstr = std::to_string(year);
                    years(yearstr, font, window);
                }
            }
        }
        window.clear();
        window.draw(sprite);
        DrowButton(window);
        Holiday(year, yearstr, font, window);
        DrowCalander(year, yearstr, font, window);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 700), "SFML works!");
    sf::Image img; //—оздает картинку ¬жууууууууух
    img.create(1000, 700, sf::Color::White);
    Event(window, img);
    return 0;
}