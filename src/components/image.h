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

#ifndef IMAGE_H_
#define IMAGE_H_

#include "element.h"

class Image : public Element {
 public:
  Image(std::string src, std::string alt = "") : Element("img") {
    SetStyle({
      {"justify-self", "center"},
      {"max-width", "100\%"},
      {"margin-bottom", "16px"},
    });

    SetProperty("src", src);
    SetProperty("alt", alt);
  }
};

#endif // IMAGE_H_
