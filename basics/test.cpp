#include <iostream>

#include "display.hpp"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    HelloWorld helloworld;
    Gtk::Window win;
    MyArea area;
    win.add(area);
    area.show();

    //Shows the window and returns when it is closed.
    return app->run(win);
}

/*
#include <curses.h>

int main () {
    // char ch;
    // char* yo;
    // yo = new char [5];
    std::string yo;
    char test[5] = {'^', '[', '[', 'D', '\0'};

    while (1) {
        // ch = getchar();
        // std::cout << "La valeur de la touche :" << ch << "\n" << std::endl;
        std::cin >> yo;
        std::cout << test << std::endl;

        if (yo.compare(test) == 0) {
            std::cout << "c le ba" << std::endl;
        }
    }
    return 0;
}
*/