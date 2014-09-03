/* @(#)mainwindow.h
 */

#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H 1
#include <gtkmm.h>

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
  Glib::RefPtr<Gtk::EntryCompletion> m_refEntryCompletion;
  Glib::RefPtr<Gtk::ListStore> m_refCompletionModel; 

  class CompletionRecord : public Gtk::TreeModel::ColumnRecord
    {
    public:
      CompletionRecord()
        {
          add(col_text);
        }
      Gtk::TreeModelColumn<Glib::ustring> col_text;
    };

  CompletionRecord m_completionRecord;

  void populateCompletion();

  /* Events */
  void on_button_quit();
};

#endif /* _MAINWINDOW_H */

