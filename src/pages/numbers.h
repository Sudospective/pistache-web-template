#ifndef NUMBERS_H_
#define NUMBERS_H_

#include "../components.h"

class Numbers : public DynamicPage {
 public:
  Numbers(const Request& req) : DynamicPage("Numbers") {
    int num = req.param(":num").as<int>();

    Section section1("Your Number");

    Element numElem("p");
    numElem.SetInnerHTML(std::to_string(num));

    Element box("div");
    box.SetStyle({
      {"display", "flex"},
      {"width", "100\%"},
      {"justify-content", "center"}
    });
    
    Hyperlink number("/numbers/" + std::to_string(rand()), "New Number");
    box.AddChild(number);

    section1.AddChild(numElem);
    section1.AddChild(box);
    AddChild(section1);
  }
  Code GetCode() {
    return Code::Ok;
  }
};

#endif // NUMBERS_H_

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
