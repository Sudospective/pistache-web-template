#ifndef STATIC_PAGE_H_
#define STATIC_PAGE_H_

#include <string>

#include "banner.h"
#include "element.h"

class StaticPage : public Element {
 public:
  StaticPage(std::string title = "") : Element("body") {
    SetStyle({
      {"overflow-x", "hidden"},
      {"color", "white"},
      {"background", "#202020"},
      {"padding", "0"},
      {"margin", "0"},
      {"display", "flex"},
      {"flex-direction", "column"},
      {"align-items", "center"}
    });

    Banner banner("Pistache Web Template");
    AddChild(banner);

    if (!title.empty()) {
      Element header("h2");
      header.SetInnerHTML(title);
      AddChild(header);
    }
  }
};

#endif // STATIC_PAGE_H_

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
