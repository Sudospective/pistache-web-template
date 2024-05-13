#ifndef PARAGRAPH_H_
#define PARAGRAPH_H_

#include <fstream>
#include <sstream>
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
