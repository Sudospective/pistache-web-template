#ifndef PARAGRAPH_H_
#define PARAGRAPH_H_

#include <fstream>
#include <string>

#include "element.h"

class Paragraph : public Element {
 public:
  Paragraph() : Element("p") {};
  Paragraph(std::string path) : Element("p") {
    std::ifstream file(path);
    std::ostringstream text;
    text << file.rdbuf();
    file.close();
    SetInnerHTML(text.str());
  }
};

#endif // PARAGRAPH_H_
