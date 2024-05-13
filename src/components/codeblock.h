#ifndef CODEBLOCK_H_
#define CODEBLOCK_H_

#include <fstream>
#include <sstream>
#include <string>

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

/*
Copyright (C) 2024 Sudospective

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
