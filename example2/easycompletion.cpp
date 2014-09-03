#include "easycompletion.h"

EasyCompletion::EasyCompletion()
{
  this->init();
}

EasyCompletion::~EasyCompletion()
{
}

void EasyCompletion::addString(Glib :: ustring str, bool norepeat)
{
  if ( (!norepeat) || (!this->_stringExists(str)) ) 
    {
      Gtk::TreeModel::Row row =*(m_refCompletionModel->append());
      row[m_completionRecord.col_text] = str;
    }
}

Glib::RefPtr < EasyCompletion > EasyCompletion::create()
{
  return Glib::RefPtr<EasyCompletion> ( new EasyCompletion() );
}

void EasyCompletion::clearStrings()
{
  m_refCompletionModel->clear();
}

void EasyCompletion::deleteString(Glib :: ustring str)
{
  m_refCompletionModel->foreach_iter(sigc::bind<const Glib::ustring& >(sigc::mem_fun( *this, &EasyCompletion::_deleteString), str));
}

bool EasyCompletion::_deleteString(const Gtk :: TreeModel :: iterator & iter, const Glib :: ustring & str)
{
  if (Gtk::TreeModel::Row(*iter)[m_completionRecord.col_text] == str)
    {
      m_refCompletionModel->erase(iter);
      return true;
    }
  return false;
}

bool EasyCompletion::_stringExists(const Glib :: ustring & str)
{
  for (Gtk::TreeModel::iterator iter = m_refCompletionModel->children().begin(); iter!=m_refCompletionModel->children().end(); ++iter)
    {
      if (Gtk::TreeModel::Row(*iter)[m_completionRecord.col_text] == str)
	  return true;
    }
  return false;
}

EasyCompletion::EasyCompletion(std :: vector < Glib :: ustring > strVector, bool norepeat)
{
  this->init();
  this->insertVector(strVector, norepeat);
}

Glib::RefPtr < EasyCompletion > EasyCompletion::create(std :: vector < Glib :: ustring > strVector, bool norepeat)
{
  return Glib::RefPtr<EasyCompletion> ( new EasyCompletion(strVector) );
}

void EasyCompletion::init()
{
  m_refCompletionModel = Gtk::ListStore::create(m_completionRecord);

  this->set_model(m_refCompletionModel);
  this->set_text_column (m_completionRecord.col_text);
}

void EasyCompletion::insertVector(std :: vector < Glib :: ustring > strVector, bool norepeat)
{
  for (std::vector<Glib::ustring>::iterator i=strVector.begin(); i!=strVector.end(); ++i)
    this->addString(*i, norepeat);
}
