#ifndef NUMBERS_H_
#define NUMBERS_H_

#include "../components/codeblock.h"
#include "../components/dynamic_page.h"
#include "../components/element.h"
#include "../components/hyperlink.h"
#include "../components/section.h"

class Numbers : public DynamicPage {
 public:
  Numbers(const Request& req) : DynamicPage("Numbers") {
    int num = req.param(":num").as<int>();

    Section section1("Your Number");

    Element numElem("p");
    numElem.SetInnerHTML(std::to_string(num));

    Element box("div");
    box.SetStyle({
      {"display", "flex"},
      {"width", "100\%"},
      {"justify-content", "center"}
    });
    
    Hyperlink number("/numbers/" + std::to_string(rand()), "New Number");
    box.AddChild(number);

    section1.AddChild(numElem);
    section1.AddChild(box);
    AddChild(section1);
  }
  Code GetCode() {
    return Code::Ok;
  }
};

#endif // NUMBERS_H_
