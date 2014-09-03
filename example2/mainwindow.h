/* @(#)mainwindow.h
 */

#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H 1
#include <gtkmm.h>
#include "easycompletion.h"

class MainWindow : public Gtk::Window
{
 public:
  MainWindow();
  virtual ~MainWindow();

 protected:
  Gtk::Box m_vBox;
  Gtk::Label m_label;
  Gtk::Entry m_entry;
  Gtk::Button m_quitButton;
  Glib::RefPtr<EasyCompletion> m_refEntryCompletion;

  /* Events */
  void on_button_quit();
};

#endif /* _MAINWINDOW_H */

