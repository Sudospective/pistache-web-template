#ifndef SECTION_H_
#define SECTION_H_

#include <string>

#include "element.h"

class Section : public Element {
 public:
  Section() : Element("div") {
    SetStyle({
      {"margin", "0"},
      {"margin-bottom", "16px"},
      {"width", "70%"},
      {"max-width", "720px"},
    });
  }
  Section(std::string title) {
    SetStyle({
      {"margin", "0"},
      {"margin-bottom", "16px"},
      {"width", "70%"},
      {"max-width", "720px"},
    });
    Element header("h3");
    header.SetInnerHTML(title);
    AddChild(header);
  }
};

#endif // SECTION_H_
