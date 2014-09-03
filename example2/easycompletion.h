/* @(#)easycompletion.h
 */

#ifndef _EASYCOMPLETION_H
#define _EASYCOMPLETION_H 1

#include <gtkmm.h>
#include <vector>

class EasyCompletion : public Gtk::EntryCompletion
{
 public:
  EasyCompletion();
  EasyCompletion(std::vector<Glib::ustring> strVector, bool norepeat = true);

  virtual ~EasyCompletion();

  void addString(Glib::ustring str, bool norepeat=true);
  void clearStrings();
  void deleteString (Glib::ustring str);
  void insertVector(std::vector<Glib::ustring> strVector, bool norepeat = true);

  static Glib::RefPtr<EasyCompletion> create();
  static Glib::RefPtr<EasyCompletion> create(std::vector<Glib::ustring> strVector, bool norepeat = true);
 protected:
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
  bool _deleteString (const Gtk::TreeModel::iterator &iter, const Glib::ustring &str);
  bool _stringExists (const Glib::ustring &str);
  void init();
};

#endif /* _EASYCOMPLETION_H */

