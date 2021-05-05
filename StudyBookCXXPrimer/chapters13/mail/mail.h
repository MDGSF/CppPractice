#ifndef CHAPTERS13_MAIL_H
#define CHAPTERS13_MAIL_H

#include <algorithm>
#include <fstream>  // ifstream
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>  // unique_ptr, shared_ptr, weak_ptr
#include <set>
#include <sstream>  // istringstream
#include <string>
#include <utility>
#include <vector>

class Folder;
class Message {
  friend class Folder;
  friend void swap(Message& lhs, Message& rhs);

 public:
  explicit Message(const std::string& str = "");
  ~Message();

  Message(const Message& m);
  Message& operator=(const Message& rhs);

  void save(Folder& f);
  void remove(Folder& f);

 private:
  void add_to_folders(const Message& m);
  void remove_from_folders();

  std::string contents;
  std::set<Folder*> folders;
};

class Folder {
 public:
  void addMsg(Message* m);
  void remMsg(Message* m);

 private:
  std::set<Message*> messages;
};

void swap(Message& lhs, Message& rhs);

#endif
