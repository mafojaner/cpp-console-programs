# C++ console programs

*Four small command-line programs in C++: character classification, a convergent series, a menu-driven calculator and a compound interest calculator.*

**Type:** Coursework, first-year C++ (2025). Individual work.
**Focus:** Control flow, functions, input validation, bitwise operations, floating-point maths
**Built with:** C++, standard library only, no third-party dependencies

## Overview

Four separate programs, each solving one problem from the ground up with no libraries
beyond the standard one. They are small on purpose. The interesting part is not the size
of the programs but what happens when the person at the keyboard types something
unexpected, which is most of what the later two deal with.

They were written for a first-year programming course and the logic is unchanged from what
was submitted. What has changed: the files are named for what they do rather than for the
order they were set in, and dead commented-out code and two typos in the output text have
been removed.

## The programs

### Character classifier

`src/character-classifier.cpp`

Reads one character and reports what it is: uppercase letter, lowercase letter, digit,
whitespace or a special character. A straight walk through the `<cctype>` classification
functions, with the final branch stating the "none of the above" condition explicitly
rather than relying on a bare `else`.

### Convergent series

`src/series-sum.cpp`

Sums the series 1 / (1 + n²), printing each term and the running total, and stops once a
term falls to 0.01 or below. An unbounded `for` loop with the exit condition in the body,
which is the honest shape for "keep going until the terms stop mattering".

### Menu-driven calculator

`src/calculator.cpp`

Addition, subtraction, multiplication, division and modulus on two integers, plus a
digit-to-binary conversion. It keeps running until the user chooses to exit.

Two things it handles that the brief did not require:

- **Non-numeric input.** Typing a letter at the menu would normally put `cin` into a fail
  state and spin the loop forever. The program clears the flag, discards the rest of the
  line and asks again.
- **Division and modulus by zero**, which are caught before they are attempted rather than
  left to crash.

The binary conversion is done with a bit mask (`n & (1 << i)`) across four bits rather than
by repeated division, which is the reason it is capped at a single digit.

### Compound interest calculator

`src/compound-interest.cpp`

Takes a principal, an annual rate and a term in years, applies `A = P(1 + r)^t`, and offers
a year-by-year breakdown. Amounts are in rands.

Input is gathered through two small helper functions, `getValidatedDouble` and `getYesOrNo`,
each of which loops until it gets something usable. That keeps `main` readable: it reads as
the three inputs, the calculation, and the optional breakdown, with none of the retry logic
in the way.

## Building and running

No build system and no dependencies. Any C++ compiler will do:

```bash
g++ -std=c++17 -o calculator src/calculator.cpp
./calculator
```

On Windows with MSVC:

```bat
cl /EHsc /std:c++17 src\calculator.cpp
```

Each file has its own `main`, so compile them one at a time.

## Known issue

`series-sum.cpp` prints `n + 1` as the term number while calculating with `n`, so the
printed index is one ahead of the term it describes. The sum itself is correct. It is left
as it was written rather than quietly corrected, because the point of this repository is to
show the work as it stood.

## Skills demonstrated

- Control flow: conditionals, nested branching, `switch`, and loops with a computed exit.
- Breaking a program into functions with a single job each, and keeping `main` legible.
- Defensive input handling: recovering a stream from a fail state rather than letting it
  spin, and rejecting values that would break the maths before they reach it.
- Bitwise operations for base conversion.
- Formatting floating-point output for money with `<iomanip>`.
