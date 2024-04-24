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
