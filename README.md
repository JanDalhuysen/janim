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

    janim_set_page_height("200mm");
    janim_set_page_width("200mm");

    janim_create_document();

    janim_text("Hello, world!");
    janim_text("Hallo world");

    janim_end_document();
    janim_render();
}
```
