// Janim Version 0.0.1 (g++ 13.2.0)

// Jan Maths animation library, inspired by Manim

// Jan Dalhuysen

#include <iostream>
#include <string>

#include "janim.hpp"

using namespace std;

int main()
{
    // Janim version
    cout << janim_version << endl;

    janim_set_mode("Document");
    janim_set_page_color("black");
    janim_set_page_orientation("Landscape");

    janim_set_page_height("200mm");
    janim_set_page_width("200mm");

    janim_create_document();

    janim_text("Hello, world!");
    janim_text("Hallo world");

    janim_end_document();
    janim_render();
}
