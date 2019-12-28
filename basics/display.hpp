/*
On utilisera GTKmm pour l'affichage
https://www.gtkmm.org/en/

g++ display.cpp -o test.x `pkg-config gtkmm-3.0 --cflags --libs`
*/

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/drawingarea.h>

// On définit la classe de la fenêtre qui hérite de celle de Gtk

class HelloWorld : public Gtk::Window
{

public:
  HelloWorld(); // constructeur
  virtual ~HelloWorld(); // destructeur

protected:
  //Signal handlers:
  void on_button_clicked();

  //Member widgets:
  Gtk::Button m_button;
};

class MyArea : public Gtk::DrawingArea
{
public:
  MyArea();
  virtual ~MyArea();

protected:
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
};