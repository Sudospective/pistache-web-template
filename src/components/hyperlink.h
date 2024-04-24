#ifndef HYPERLINK_H_
#define HYPERLINK_H_

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
