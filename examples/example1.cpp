// Janim Example 1: Basic Document and Shapes
// This example demonstrates creating a document with basic geometric shapes

#include <iostream>
#include <string>
#include "janim.hpp"

using namespace std;

int main()
{
    cout << janim_version << endl;
    
    // Set up document properties
    janim_set_mode("Document");
    janim_set_page_color("black");
    janim_set_page_orientation("Landscape");
    janim_make_title("Janim Example 1", "Basic Shapes and Layout", "John Doe");
    janim_set_page_height("216mm");
    janim_set_page_width("384mm");
    janim_set_main_font("CascadiaMono.ttf");
    
    // Create document
    janim_create_document();
    
    // Add title text
    janim_text("\\Huge \\textcolor{cyan}{Basic Shapes}");
    janim_text("\\vspace{5mm}"); // Add some vertical space
    
    // Draw a grid of shapes
    // Circles
    janim_circle("20mm", "40mm", "15mm", "red");
    janim_circle("60mm", "40mm", "15mm", "green");
    janim_circle("100mm", "40mm", "15mm", "blue");
    
    // Squares
    janim_square("20mm", "80mm", "20mm", "magenta");
    janim_square("60mm", "80mm", "20mm", "yellow");
    janim_square("100mm", "80mm", "20mm", "cyan");
    
    // Triangles
    janim_triangle("30mm", "120mm", "20mm", "orange");
    janim_triangle("70mm", "120mm", "20mm", "purple");
    janim_triangle("110mm", "120mm", "20mm", "pink");
    
    // Lines connecting shapes
    janim_line("35mm", "55mm", "45mm", "70mm", "white", "thick");
    janim_line("75mm", "55mm", "85mm", "70mm", "white", "thick");
    janim_line("115mm", "55mm", "125mm", "70mm", "white", "thick");
    
    // Add descriptive text
    janim_text("\\vspace{20mm}");
    janim_text("\\textcolor{white}{This document demonstrates basic geometric shapes in Janim:}");
    janim_text("\\begin{itemize}");
    janim_text("\\item \\textcolor{red}{Red}, \\textcolor{green}{green}, and \\textcolor{blue}{blue} circles");
    janim_text("\\item \\textcolor{magenta}{Magenta}, \\textcolor{yellow}{yellow}, and \\textcolor{cyan}{cyan} squares");
    janim_text("\\item \\textcolor{orange}{Orange}, \\textcolor{purple}{purple}, and \\textcolor{pink}{pink} triangles");
    janim_text("\\end{itemize}");
    
    // Finalize document
    janim_end_document();
    janim_render();
    
    return 0;
}
