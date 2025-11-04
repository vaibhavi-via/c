# Student Management CLI (school.c)

Short description
- Menu-driven C program to manage student records (first/last name, roll, CGPA, 5 course IDs).
- Stores up to 50 students in a static array.

Build (Windows)
- Using GCC (MinGW/WSL):
    gcc school.c -o school.exe

Run
- In PowerShell or CMD:
    .\school.exe

Usage
- Choose an option from the menu and follow prompts.
- Each record contains: first name, last name, roll number, CGPA, and 5 course IDs.

  
  Data model
- struct sinfo {
    char fname[50];
    char lname[50];
    int roll;
    float cgpa;
    int cid[10];
  }
- Global array st[] holds records; program uses up to 50 entries.

Known issues & suggestions
- Unsafe input: uses scanf without width limits — risk of buffer overflow. Use fgets + parsing or scanf width specifiers (e.g., "%49s").
- Inconsistent sizes: cid[10] but only 5 used; st allocated 55 but limited to 50. Replace magic numbers with constants (MAX_STUDENTS, COURSE_COUNT).
- No validation or duplicate-roll checks — add input validation and prevent duplicate rolls.
- No persistence — add save/load to preserve records across runs.

Suggested commit message
- "Add school.c — CLI student management; add README and .gitignore; note: input validation and persistence recommended"
