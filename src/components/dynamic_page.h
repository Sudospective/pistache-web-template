#ifndef DYNAMIC_PAGE_H_
#define DYNAMIC_PAGE_H_

#include <string>

#include <pistache/router.h>

#include "static_page.h"

using Pistache::Rest::Request;
using Pistache::Http::Code;

class DynamicPage : public StaticPage {
 public:
  DynamicPage(std::string title = "")
    : StaticPage(title) {}
  virtual Code GetCode() = 0;
};

#endif // DYNAMIC_PAGE_H_

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
