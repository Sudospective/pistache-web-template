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
