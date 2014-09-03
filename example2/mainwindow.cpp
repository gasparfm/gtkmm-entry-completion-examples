#include "mainwindow.h"
#include <vector>

std::vector <Glib::ustring> strVec(const char* first, ...)
{
  va_list args;
  std::vector<Glib::ustring> ret;
  int n=0;
  char *value;

  ret.push_back(Glib::ustring(first));
  va_start(args, first);

  do
    {
      value = va_arg(args, char*);
      if (value==NULL)
        break;

      ret.push_back(Glib::ustring(value));
    } while (1);

  return ret;
}

MainWindow::MainWindow():m_vBox(Gtk::ORIENTATION_VERTICAL), m_quitButton("_Quit", true), m_label("Please, enter some text"), m_entry()
{
  // Configure the GUI
  this->add(m_vBox);

  m_vBox.pack_start(m_label, Gtk::PACK_EXPAND_WIDGET);
  m_vBox.pack_start(m_entry);
  m_vBox.pack_end(m_quitButton, Gtk::PACK_SHRINK);

  this->set_border_width(3);
  this->set_title("Entry Completion Example");
  this->set_default_size(200,200);

  // Configure the Completion
  m_refEntryCompletion = EasyCompletion::create(strVec("Spain", "Portugal", "France", "Italy", "United Kingdom", "Greece", "Ireland", "Finland", "Denmark", "Luxembourg",
						       "Netherlands", "Poland", "Romania", "Czech Republic", "Malta", "Lithuania", "Slovakia", "Slovenia", "Bulgaria",
						       "Croatia", "Cyprus", "Austria", "Belgium", "Austria", "Italy", "Portugal", "Belgium", "Austria",
						       NULL));

  m_entry.set_completion(m_refEntryCompletion);

  m_refEntryCompletion->set_minimum_key_length(1);

  // Configure signales
  m_quitButton.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_quit));

  // Let's start!
  this->show_all_children();
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_button_quit()
{
  this->hide();
}
