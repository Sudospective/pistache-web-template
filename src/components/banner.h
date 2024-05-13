#ifndef BANNER_H_
#define BANNER_H_

#include <string>
#include <map>

#include "element.h"

class Banner : public Element {
 public:
  Banner(std::string titleText = "Hello, World!") : Element("div") {
    SetStyle({
      {"background", "#8000FF"},
      {"padding", "32px"},
      {"margin-bottom", "32px"},
      {"width", "100%"},
    });
    Element title("h1");
    title.SetInnerHTML(titleText);
    title.SetStyle({
      {"text-align", "center"},
      {"padding", "0"},
      {"margin", "0"},
    });
    AddChild(title);

    // Banner links go here
    LinkMap links = {
      {"/", "Home"},
      {"/about", "About"},
    };

    CreateLinks(links);
  }

 private:
  typedef std::map<std::string, std::string> LinkMap;
  void CreateLinks(LinkMap links) {
    Element box("div");
    box.SetStyle({
      {"display", "flex"},
      {"justify-content", "center"},
      {"margin-top", "16px"},
      {"margin-bottom", "0"},
      {"padding", "0"},
    });
    for (const auto& [url, name] : links) {
      Element link("a");
      link.SetProperty("href", url);
      link.SetStyle({
        {"display", "block"},
        {"color", "white"},
        {"padding", "8px 16px 0"},
        {"margin", "0 8px"},
        {"text-decoration", "none"},
      });
      link.SetInnerHTML(name);
      box.AddChild(link);
    }
    AddChild(box);
  }
};

#endif // BANNER_H_

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
