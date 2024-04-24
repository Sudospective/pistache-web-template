#ifndef HOME_H_
#define HOME_H_

#include "../components/banner.h"
#include "../components/codeblock.h"
#include "../components/element.h"
#include "../components/hyperlink.h"
#include "../components/image.h"
#include "../components/paragraph.h"
#include "../components/section.h"
#include "../components/static_page.h"

class Home : public StaticPage {
 public:
  Home() : StaticPage("Welcome!") {
    Section section("Wait, what is this?");

    Paragraph para1("content/home/section1.txt");
    CodeBlock code("content/home/codeblock1.txt");

    Paragraph para2;
    para2.SetInnerHTML("And a sample image:");
    Image img(
      "https://sudospective.net/content/images/2022/12/banner.png",
      "Sudospective banner"
    );

    Element box("div");
    box.SetStyle({
      {"display", "flex"},
      {"width", "100\%"},
      {"justify-content", "center"}
    });

    Hyperlink subo("https://sudospective.net", "Main Website", true);
    Hyperlink onedev("https://git.sudospective.net", "SuboGit", true);
    Hyperlink numbers("/numbers/" + std::to_string(rand()), "Numbers Page");

    box.AddChild(subo);
    box.AddChild(onedev);
    box.AddChild(numbers);

    section.AddChild(para1);
    section.AddChild(code);
    section.AddChild(para2);
    section.AddChild(img);
    section.AddChild(box);

    AddChild(section);
  }
};

#endif // HOME_H_
