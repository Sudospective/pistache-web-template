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

#ifndef CAT_H_
#define CAT_H_

#include "../components.h"

class Cat : public DynamicPage {
 public:
  Cat(const Request& req) : DynamicPage("Meow meow:") {
    std::string msg = req.splatAt(0).as<std::string>();
    msg = std::regex_replace(msg, std::regex("\%20"), " ");
    msg = std::regex_replace(msg, std::regex("<"), "&lt;");
    msg = std::regex_replace(msg, std::regex(">"), "&gt;");

    Section section1;

    Element para1("p");
    para1.SetInnerHTML(msg + " nya~");

    section1.AddChild(para1);
    AddChild(section1);
  }
  Code GetCode() {
    return Code::Ok;
  }
};

#endif // CAT_H_
