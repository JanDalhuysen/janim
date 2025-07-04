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
    janim_set_page_color("white");
    janim_set_page_orientation("Portrait");

    // Create a title page
    janim_make_title("Janim Document", "A Mathematical Animation Example", "John Doe", "2025-07-04");

    janim_set_page_height("432mm");
    janim_set_page_width("768mm");

    janim_set_main_font("CascadiaMono.ttf");

    janim_create_document();

    janim_text("Hallo World");

    janim_line("0mm", "0mm", "5mm", "5mm", "cyan");
    janim_line("0mm", "5mm", "5mm", "0mm", "cyan");

    janim_circle("10mm", "10mm", "10mm", "red", "60", "blue", "20");
    janim_circle("10mm", "10mm", "10mm", "green", "60", "yellow", "20");

    janim_square("10mm", "10mm", "10mm", "red", "60", "blue", "20");

    janim_rectangle("10mm", "10mm", "20mm", "10mm", "red", "60", "blue", "20");

    // Draw a triangle
    janim_triangle("15mm", "15mm", "10mm", "orange", "70", "yellow", "30");

    // Draw an oval
    janim_oval("25mm", "25mm", "15mm", "8mm", "purple", "70", "pink", "30");

    // Example automaton
    Automaton automaton;
    janim_parse_automaton(R"(
        [initial:q0]
        q0 -> q1 [label=a];
        q1 -> q2 [label=b];
        q2 [final];
        q2 -> q1 [label=c];
    )",
                          automaton);
    janim_layout_automaton(automaton);
    janim_draw_automaton(automaton);

    janim_end_document();
    janim_render();
}
