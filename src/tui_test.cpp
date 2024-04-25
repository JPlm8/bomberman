#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <list>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    int fotograma = 0;
    string reset;
    int posX = 0;
    int posY = 6;

    while (true)
    {
        fotograma++;

        Element personaje = spinner(17, fotograma);
        Decorator colorFondo = bgcolor(Color::DarkBlue);
        Decorator colorTexto = color(Color::White);
        Element dibujo = border({hbox(personaje) | colorFondo | colorTexto});

        Dimensions Alto = Dimension::Fixed(10);
        Dimensions Ancho = Dimension::Full();

        Screen pantalla = Screen::Create(Ancho, Alto);
        Render(pantalla, dibujo);
        list<string> textos;
        textos.push_back("Primera linea");
        textos.push_back("Segunda linea");
        textos.push_back("Tercera linea");
        int l = 0;
        for (auto &&texto : textos)
        {
            int i = 0;
            for (auto &&letra : textos)
            {
                pantalla.PixelAt(posX + i, posY + l).character = letra;
                i++;
            }
            l++;
        }
        posX++;

        pantalla.Print();
        reset = pantalla.ResetPosition();
        cout << reset;

        this_thread::sleep_for(0.1s);
    }

    return 0;
}