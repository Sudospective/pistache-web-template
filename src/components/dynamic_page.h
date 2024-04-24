#ifndef DYNAMIC_PAGE_H_
#define DYNAMIC_PAGE_H_

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
