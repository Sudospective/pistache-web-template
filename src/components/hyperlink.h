#ifndef HYPERLINK_H_
#define HYPERLINK_H_

#include <string>

#include "element.h"

class Hyperlink : public Element {
 public:
  Hyperlink(std::string href, std::string name = "", bool newTab = false) : Element("div") {
    if (name.empty())
      name = href;
    
    SetStyle({
      {"color", "white"},
      {"width", "auto"},
      {"margin-right", "8px"},
      {"background", "#404040"}
    });

    Element link("a");
    link.SetProperty("href", href);
    if (newTab)
      link.SetProperty("target", "_blank");
    link.SetStyle({
      {"display", "block"},
      {"color", "white"},
      {"padding", "16px"},
      {"text-decoration", "none"}
    });
    link.SetInnerHTML(name);
    AddChild(link);
  }
};

#endif // HYPERLINK_H_

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
