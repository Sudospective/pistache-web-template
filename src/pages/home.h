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

#ifndef HOME_H_
#define HOME_H_

#include "../components.h"

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

    FlexBox box;

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
