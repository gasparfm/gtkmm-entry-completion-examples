gtkmm-entry-completion-examples
===============================

Gtk::EntryCompletion examples - Because I couldn't find working examples

That's it, I was making a little project and I couldn't find working examples on
this component in C++ for Gtk+3.0. A lot of them were in Python, a lot of them were 
for older versions and a lot of them didn't compile.

You're free to use this example.

## What you can find here
  - Example 1 : Easy way to have a working completion in your Gtk::Entry
  - Example 2 : Easy way to manage string-only completions for your Gtk::Entry objects

## Example 1 

```
   Shows the simplest completion example. Just create a simple GUI: a box, a label, a button
   and the entry component.
   Entry completion is filled up with european countries. I wanted to show a customizable way
   to do it
```

To compile this example, just do:

```
g++ -o main main.cpp mainwindow.cpp `pkg-config --libs --cflags gtkmm-3.0`
```

Of course you can put CompletionRecord class in any other place, but I used this way to be
more familiar with other Gtkmm examples.


You can use this code if you already have created a model (e.g. for a Gtk::TreeView) and you want
the user to autocomplete the Entry Fields with this data.

## Example 1 

```
   Just a simple EntryCompletion class (now EasyCompletion) which uses its own Model to store Glib::ustring
   objects. Only if you want to make a simple completion. It allows being populated with a STL vector which
   makes it easy sometimes.

   But EasyCompletion class may be extended to support another string input methods.
```

It's useful if you want to create several Entry components with completion and don't want to be creating
and maintaining models.

EasyCompletion class allows:
   - addString (Glib::ustring str, bool norepeat = true) : adds a string to the record, optionally checks it
     to not insert anything twice.
   - clearStrings () : clear all strings in the record
   - deleteString (Glib::ustring str) : search for str and deletes it (only once).
   - insertVector (std::vector<Glib::ustring> strVector, bool norepeat = true) : adds strings from a STL vector.
