#ifndef PAGES_H_
#define PAGES_H_

#include <string>
#include <map>

#include <pistache/endpoint.h>
#include <pistache/router.h>

#include "pages/home.h"
#include "pages/about.h"
#include "pages/numbers.h"

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
