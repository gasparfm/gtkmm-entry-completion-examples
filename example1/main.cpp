#include <gtkmm.h>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  MainWindow w;

  return app->run(w);
}

