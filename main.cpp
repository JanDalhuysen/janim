// Janim Version 0.0.1 (g++ 13.2.0)

// Jan Maths animation library, inspired by Manim
// This program demonstrates the use of the Janim library for creating mathematical animations
// Jan Dalhuysen

#include <iostream>
#include <string>

#include "janim.hpp"

using namespace std;

int main()
{
    // Display the current version of Janim
    cout << janim_version << endl;

    // Set the document mode and basic page properties
    janim_set_mode("Document");                    // Set the output mode to document
    janim_set_page_color("white");                 // Set the background color to white
    janim_set_page_orientation("Portrait");        // Set page orientation to portrait

    // Create a title page with document metadata
    janim_make_title("Janim Document", "A Mathematical Animation Example", "John Doe", "2025-07-04");

    // Set the document dimensions
    janim_set_page_height("432mm");                // Set page height
    janim_set_page_width("768mm");                 // Set page width

    // Set the main font for the document
    janim_set_main_font("CascadiaMono.ttf");

    // Initialize the document creation process
    janim_create_document();

    // Add text to the document
    janim_text("Hallo World");

    // Draw two diagonal lines forming an 'X' pattern
    janim_line("0mm", "0mm", "5mm", "5mm", "cyan");    // Diagonal line from top-left to bottom-right
    janim_line("0mm", "5mm", "5mm", "0mm", "cyan");    // Diagonal line from bottom-left to top-right

    // Draw overlapping circles with different colors
    janim_circle("10mm", "10mm", "10mm", "red", "60", "blue", "20");     // Red circle with blue fill
    janim_circle("10mm", "10mm", "10mm", "green", "60", "yellow", "20"); // Green circle with yellow fill

    // Draw a square with red outline and blue fill
    janim_square("10mm", "10mm", "10mm", "red", "60", "blue", "20");

    // Draw a rectangle with red outline and blue fill
    janim_rectangle("10mm", "10mm", "20mm", "10mm", "red", "60", "blue", "20");

    // Draw a triangle with orange outline and yellow fill
    janim_triangle("15mm", "15mm", "10mm", "orange", "70", "yellow", "30");

    // Draw an oval with purple outline and pink fill
    janim_oval("25mm", "25mm", "15mm", "8mm", "purple", "70", "pink", "30");

    // Create and draw a finite automaton
    Automaton automaton;
    janim_parse_automaton(R"(
        [initial:q0]           // Define q0 as the initial state
        q0 -> q1 [label=a];    // Transition from q0 to q1 with label 'a'
        q1 -> q2 [label=b];    // Transition from q1 to q2 with label 'b'
        q2 [final];            // Define q2 as a final/accepting state
        q2 -> q1 [label=c];    // Transition from q2 to q1 with label 'c'
    )",
                          automaton);
    janim_layout_automaton(automaton);    // Automatically position the automaton states
    janim_draw_automaton(automaton);      // Render the automaton on the document

    // Finalize the document
    janim_end_document();                 // Mark the end of document content
    janim_render();                       // Generate the final output
}
