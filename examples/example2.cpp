// Janim Example 2: Automata Visualization
// This example demonstrates creating and visualizing finite automata

#include <iostream>
#include <string>
#include "janim.hpp"

using namespace std;

int main()
{
    cout << janim_version << endl;
    
    // Set up document for automata visualization
    janim_set_mode("Document");
    janim_set_page_color("white");
    janim_set_page_orientation("Landscape");
    janim_make_title("Janim Example 2", "Finite Automata Visualization", "John Doe");
    janim_set_page_height("216mm");
    janim_set_page_width("384mm");
    janim_set_main_font("CascadiaMono.ttf");
    
    // Create document
    janim_create_document();
    
    // Add title
    janim_text("\\Huge \\textcolor{blue}{Finite Automata}");
    janim_text("\\vspace{5mm}");
    
    // Example 1: Simple DFA that accepts strings ending with 'a'
    janim_text("\\textbf{Example 1: DFA for strings ending with 'a'}");
    janim_text("\\vspace{2mm}");
    
    Automaton dfa1;
    janim_parse_automaton(R"(
        [initial:q0]
        q0 -> q0 [label=b];
        q0 -> q1 [label=a];
        q1 -> q0 [label=b];
        q1 [final];
        q1 -> q1 [label=a];
    )", dfa1);
    
    janim_layout_automaton(dfa1, 20, 40); // Position at x=20, y=40
    janim_draw_automaton(dfa1);
    
    janim_text("\\vspace{30mm}"); // Add space between automata
    
    // Example 2: NFA that accepts strings with 'aa' or 'bb' as substring
    janim_text("\\textbf{Example 2: NFA for strings containing 'aa' or 'bb'}");
    janim_text("\\vspace{2mm}");
    
    Automaton nfa1;
    janim_parse_automaton(R"(
        [initial:q0]
        q0 -> q0 [label=a,b];
        q0 -> q1 [label=a];
        q0 -> q3 [label=b];
        q1 -> q2 [label=a];
        q2 [final];
        q2 -> q2 [label=a,b];
        q3 -> q4 [label=b];
        q4 [final];
        q4 -> q4 [label=a,b];
    )", nfa1);
    
    janim_layout_automaton(nfa1, 20, 100); // Position at x=20, y=100
    janim_draw_automaton(nfa1);
    
    // Add description
    janim_text("\\vspace{20mm}");
    janim_text("\\textcolor{black}{This document shows two finite automata examples:}");
    janim_text("\\begin{itemize}");
    janim_text("\\item A DFA that accepts all strings over {a,b} ending with 'a'");
    janim_text("\\item An NFA that accepts strings containing 'aa' or 'bb' as a substring");
    janim_text("\\end{itemize}");
    
    // Finalize document
    janim_end_document();
    janim_render();
    
    return 0;
}
