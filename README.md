# Janim

Janim is a Maths animation library inspired by Manim.

## Installation

Prerequisites: g++, texlive, texlive-latex-extra, texlive-luatex

```bash
sudo apt-get install build-essential texlive texlive-latex-extra texlive-luatex
```

To install Janim, follow these steps:

1. Clone the repository:
   ```
   git clone https://github.com/JanDalhuysen/janim.git
   ```
2. Navigate to the project directory:
   ```
   cd janim
   ```
3. Compile the project:
   ```
   g++ main.cpp -o main
   ```

## Usage

Here is an example of how to use the Janim library:

```cpp
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

    janim_set_page_height("108mm");
    janim_set_page_width("192mm");

    janim_set_main_font("CascadiaMono.ttf");

    janim_create_document();

    janim_text("Hallo World");

    janim_line("0mm", "0mm", "5mm", "5mm", "cyan");
    janim_line("0mm", "5mm", "5mm", "0mm", "cyan");

    janim_circle("10mm", "10mm", "10mm", "red", "60", "blue", "20");
    janim_circle("10mm", "10mm", "10mm", "green", "60", "yellow", "20");

    janim_square("10mm", "10mm", "10mm", "red", "60", "blue", "20");

    janim_rectangle("10mm", "10mm", "20mm", "10mm", "red", "60", "blue", "20");

    janim_end_document();
    janim_render();
}
```

![Example](document.png)
