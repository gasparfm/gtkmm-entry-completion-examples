#include "mainwindow.h"

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
  m_refEntryCompletion = Gtk::EntryCompletion::create();
  m_refCompletionModel = Gtk::ListStore::create(m_completionRecord);

  m_refEntryCompletion->set_model(m_refCompletionModel);
  m_entry.set_completion(m_refEntryCompletion);
  m_refEntryCompletion->set_text_column (m_completionRecord.col_text);
  m_refEntryCompletion->set_minimum_key_length(1);
  m_refEntryCompletion->set_popup_completion(true);

  this->populateCompletion();

  // Configure signales
  m_quitButton.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_quit));

  // Let's start!
  this->show_all_children();
}

MainWindow::~MainWindow()
{
}

void MainWindow::populateCompletion()
{
  Gtk::TreeModel::Row row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Spain";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Portugal";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "France";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Germany";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Italy";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "United Kingdom";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Greece";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Ireland";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Finland";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Denmark";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Luxembourg";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Netherlands";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Poland";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Romania";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Czech Republic";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Malta";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Lithuania";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Slovakia";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Slovenia";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Bulgaria";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Croatia";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Cyprus";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Austria";

  row =*(m_refCompletionModel->append());
  row[m_completionRecord.col_text] = "Belgium";
}

void MainWindow::on_button_quit()
{
  this->hide();
}
