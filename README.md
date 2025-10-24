🔍📂 PyFind — A Tiny File Text Finder in Python

Meet PyFind, your lightning-fast, ultra-simple command-line text search tool ⚡🐍
Search any file for a keyword — instantly see where it appears, with line numbers and context! 💡

🚀 What It Does

Type one command — find all lines that contain your target text. 🔎

It’s that easy.
No dependencies. No setup. Just pure Python simplicity. ❤️

💡 Example Usage
python pyfind.py myfile.txt hello


Output:

Line 3 : hello world!
Line 15 : say hello to Python


🎯 Finds every line containing "hello" and prints it with its line number!

⚙️ How It Works

🧠 The program:
1️⃣ Opens the target file
2️⃣ Reads all lines
3️⃣ Loops through them, checking for the target string
4️⃣ Prints matching lines with their index (0-based by default)

That’s it. Beautifully minimal. ✨

🧩 Command Syntax
python pyfind.py <filename> <search_term>


Example:

python pyfind.py notes.txt TODO


Output:

Line 12 : # TODO: Refactor this function
Line 24 : TODO: Add logging

🧰 Features

✅ Blazing-fast for small to medium files ⚡
✅ Displays line numbers for quick reference
✅ Works with any plain-text file (.txt, .py, .md, etc.)
✅ No external modules — just Python standard library 🐍
✅ Perfect for quick debugging or searching through notes 💬

🧠 Possible Upgrades

💡 Add case-insensitive search (.lower())
💡 Support for regular expressions 🎯
💡 Color highlight the matched text 🎨
💡 Add line count summary at the end
💡 Add file globbing (search across multiple files)

🧩 Example in Action
$ python pyfind.py script.py def
Line 2 : def ftif(filename, target):
Line 5 : def another_function():


💥 Boom — instant insight into your code!

🛠️ Installation

No installation needed!
Just clone and run:

git clone https://github.com/yourusername/pyfind.git
cd pyfind
python pyfind.py yourfile.txt keyword

❤️ Why It’s Awesome

🧠 Great for learning file I/O in Python
🔧 Handy for quick file inspection or debugging
⚡ Minimal but useful — a true "one-liner powerhouse"
💻 A fun project that showcases Python’s elegance

👨‍💻 Author

Made with 🖤 and curiosity by [Your Name]
💬 “Sometimes, the simplest tools are the ones you use the most.”
