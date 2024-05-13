#ifndef ABOUT_H_
#define ABOUT_H_

#include "../components.h"

class About : public StaticPage {
 public:
  About() : StaticPage("About") {
    Section section1("Who the heck are you?");
    Paragraph para1("content/about/section1.txt");

    Element box("div");
    box.SetStyle({
      {"display", "flex"},
      {"width", "100\%"},
      {"justify-content", "center"}
    });

    Hyperlink subo("https://sudospective.net", "Main Website", true);

    Section section2("What is this template for?");
    Paragraph para2("content/about/section2.txt");

    Section section3("How do I work with this thing?");

    Paragraph para3("content/about/section3.txt");

    CodeBlock code1("content/about/codeblock1.txt");

    Paragraph para4("content/about/section4.txt");

    CodeBlock code2;
    code2.SetInnerHTML("$ g++ src/main.cpp -o website -lpistache");

    Paragraph para5;
    para5.SetInnerHTML("Then run the executable using your preferred port:");

    CodeBlock code3;
    code3.SetInnerHTML("$ ./website 9080");
    
    box.AddChild(subo);

    section1.AddChild(para1);
    section1.AddChild(box);

    section2.AddChild(para2);

    section3.AddChild(para3);
    section3.AddChild(code1);
    section3.AddChild(para4);
    section3.AddChild(code2);
    section3.AddChild(para5);
    section3.AddChild(code3);

    AddChild(section1);
    AddChild(section2);
    AddChild(section3);
  }
};

#endif // ABOUT_H_

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
