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

#ifndef PAGES_H_
#define PAGES_H_

#include <string>
#include <map>

#include <pistache/endpoint.h>
#include <pistache/router.h>

#include "pages/home.h"
#include "pages/about.h"
#include "pages/numbers.h"
#include "pages/cat.h"

using Pistache::Http::Code;
using Pistache::Http::ResponseWriter;
using Pistache::Rest::Request;
using Pistache::Rest::Router;

class Pages {
 public:
  static void CreateRoutes(Router& router) {
    // Page routes go here
    RouteMap routes = {
      {"/", Pages::GetStaticPage<Home>},
      {"/about", Pages::GetStaticPage<About>},
      {"/numbers/:num", Pages::GetDynamicPage<Numbers>},
      {"/cat/*", Pages::GetDynamicPage<Cat>},
    };

    Pages::SetupRoutes(router, routes);
  }

 private:
  typedef std::unordered_map<std::string, void (*const)(const Request&, ResponseWriter)> RouteMap;
  static void SetupRoutes(Router& router, RouteMap routes) {
    // Loop through routes and bind each URL to its function
    for (const auto& [url, func] : routes) {
      Pistache::Rest::Routes::Get(
        router,
        url,
        Pistache::Rest::Routes::bind(func)
      );
    }
  }
  template <typename StaticPageType>
  static void GetStaticPage(const Request&, ResponseWriter res) {
    StaticPageType page;
    res.send(Code::Ok, page.Render());
  }
  template <typename DynamicPageType>
  static void GetDynamicPage(const Request& req, ResponseWriter res) {
    DynamicPageType page(req);
    res.send(page.GetCode(), page.Render());
  }
};

#endif // PAGES_H
