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

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <string>
#include <vector>
#include <map>

class Element {
 public:
  Element() {
    elemType = "div";
    id = "";
    className = "";
    innerHTML = "";
  }
  Element(std::string elem) {
    elemType = elem;
    id = "";
    className = "";
    innerHTML = "";
  }

  void SetId(std::string newId) {
    id = newId;
  }
  std::string GetId() const {
    return id;
  }

  void SetClass(std::string newClass) {
    className = newClass;
  }
  std::string GetClass() const {
    return className;
  }

  void SetInnerHTML(std::string newInner) {
    if (elemType == "code") {
      // we need to make sure leading spaces render correctly in code...
      newInner = std::regex_replace(newInner, std::regex(" "), "&nbsp;");
      // ...and angle brackets.
      newInner = std::regex_replace(newInner, std::regex("<"), "&lt;");
      newInner = std::regex_replace(newInner, std::regex(">"), "&gt;");
    }
    // replace newlines
    newInner = std::regex_replace(newInner, std::regex("\n"), "<br>");
    // replace tabs
    newInner = std::regex_replace(newInner, std::regex("\t"), "&emsp;");

    innerHTML = newInner;
  }
  std::string GetInnerHTML() const {
    return innerHTML;
  }

  void SetStyle(std::unordered_map<std::string, std::string> stylemap) {
    for (const auto& [key, val] : stylemap) {
      AddToStyle(key, val);
    }
  }
  void AddToStyle(std::string category, std::string value) {
    if (style.find(category) != style.end())
      style[category] = value;
    else
      style.emplace(category, value);
  }
  void RemoveFromStyle(std::string category) {
    style.erase(category);
  }

  void SetProperty(std::string name, std::string value) {
    if (props.find(name) != props.end())
      props[name] = value;
    else
      props.emplace(name, value);
  }
  void ClearProperty(std::string name) {
    props.erase(name);
  }

  void AddChild(Element& child) {
    children.push_back(child);
  }
  
  std::string Render() {
    std::string p = "";
    for (const auto& [key, val] : props) {
      p += " " + key + "=\"" + val + "\"";
    }

    std::string s = "";
    for (const auto& [key, val] : style) {
      s += key + ":" + val + ";";
    }

    std::string c = "";
    for (Element& elem : children) {
      c += elem.Render();
    }

    return (
      "<" + elemType
      + " id=\"" + id + "\""
      + " class=\"" + className + "\""
      + p
      + " style=\"" + s + "\""
      + ">"
      + innerHTML
      + c
      + "</" + elemType + ">"
    );
  }

 private:
  std::string elemType;
  std::string id;
  std::string className;
  std::string innerHTML;
  std::unordered_map<std::string, std::string> style;
  std::unordered_map<std::string, std::string> props;
  std::vector<Element> children;
};

#endif // ELEMENT_H_
