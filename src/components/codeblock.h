#ifndef CODEBLOCK_H_
#define CODEBLOCK_H_

#include <fstream>

#include "element.h"

class CodeBlock : public Element {
 public:
  CodeBlock() : Element("code") {
    SetStyle({
      {"display", "block"},
      {"background", "#404040"},
      {"width", "100\%"},
      {"border-radius", "8px"},
      {"padding", "8px"},
      {"margin-bottom", "16px"},
      {"white-space", "nowrap"},
      {"overflow-x", "auto"},
    });
  }
  CodeBlock(std::string path) : Element("code") {
    SetStyle({
      {"display", "block"},
      {"background", "#404040"},
      {"width", "100\%"},
      {"border-radius", "8px"},
      {"padding", "8px"},
      {"margin-bottom", "16px"},
      {"white-space", "nowrap"},
      {"overflow-x", "auto"},
    });
    std::ifstream file(path);
    std::ostringstream text;
    text << file.rdbuf();
    file.close();
    SetInnerHTML(text.str());
  }
};

#endif // CODEBLOCK_H_
