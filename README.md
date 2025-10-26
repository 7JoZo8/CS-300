# CS-300
Josef Zoucha CS 300 Module 8 Journal

1. What was the problem you were solving in the projects for this course?
2. How did you approach the problem? Consider why data structures are important to understand.
3. How did you overcome any roadblocks you encountered while going through the activities or project?
4. How has your work on this project expanded your approach to designing software and developing programs?
5. How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?


The main objective of these projects was to design and implement an advising assistance program for the ABCU Computer Science department. The goal was to develop a system that could load course information from a file, store it efficiently, and allow users to view all courses in alphanumeric order or retrieve details about a specific course and its prerequisites. This required understanding how to represent course data effectively and selecting a data structure that optimized both performance and usability.

I began by creating pseudocode to outline how the program would load, parse, and store course data using three data structures: a vector, a hash table, and a binary search tree. After analyzing runtime performance and memory efficiency, I determined that the hash table offered the best balance of speed and simplicity. Understanding data structures was essential because they directly impact how quickly and effectively information can be stored and accessed. The hash table provided constant-time lookups for courses while still allowing for sorted output through the use of a vector.

One of the biggest challenges I faced was handling file input reliably. I initially encountered issues when reading filenames that caused an infinite menu loop. I resolved this by using getline() in combination with cin.ignore() to handle spaces and newline characters correctly. I also implemented validation and error messages to make the program more user-friendly and easier to debug. Testing the program with different input scenarios ensured it could handle missing files, formatting errors, and invalid course numbers gracefully.

This project reinforced the importance of planning before coding. Writing pseudocode first helped me visualize the program’s structure, divide it into manageable components, and identify efficient algorithms before implementation. It also demonstrated how choosing the right data structure simplifies development; using a hash table made searching and retrieving data much easier than scanning through a list. I learned to evaluate trade-offs early and design for scalability and efficiency from the start.

Throughout the project, I emphasized writing clean, organized, and maintainable code. I used meaningful variable names, inline comments, and separate functions such as LoadDataStructure, PrintCourseList, and PrintCourse to keep the program modular and easy to understand. These practices make the code adaptable to future changes, such as adding new features or interfaces. Overall, this project helped me appreciate that writing maintainable and readable code isn’t just about following conventions — it’s about designing software that can be easily understood, tested, and improved by others.
