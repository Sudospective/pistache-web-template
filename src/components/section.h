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
