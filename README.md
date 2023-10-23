# Simple Search Engine
# This simple search engine is used to search for queries, auto-completion of the queries and finding matching results.
# The system is capable of correcting the spelling errors as well.

# Data structures :

- For implementation trie data structure is used.
- Arrays are used to store the web documents.

# Scope :
1) Trie Based Searches in Commercial Search Engines.

2) Auto-complete functionality is used widely over the internet and mobile apps. A lot of websites and apps try to complete your input as soon as you start typing. All the descendants of a node have a common prefix of the string associated with that node.

3) An orthographic corrector that can check that every word that you type is in a dictionary.

4) You can also use a Trie for suggested corrections of the words that are present in the text but not in the dictionary.

5) Extremely fast pattern matching.

6) Spell checking

7) Storing/Querying XML documents

# Modules :
1) Data Files: All the data files present in the project to search from.

2) Prefix Search: Add support for searching for prefixes. For example, a search for “auto…” should find all data files containing starting with “auto”.

3) Exact Search: Add support for searching for exact search query. For example, a search for “automatic” should find all data files with “automatic”.

4) Auto-completion: Given the prefix of an search string suggest possible endings automatically. (Particularly relevant when combined with a GUI).
******If Possible(Crawler, Spelling Suggestion, GUI)******

# How to run the project :
- The Project contains Makefile.
- Type "make" on terminal.
- Make will create the executable file name program
- Type "./program" on terminal and run it.

# References :
- https://www.researchgate.net/publication/281684909_TRIE_DATA_STRUCTURE
- https://www.javatpoint.com/trie-data-structure
- https://www.youtube.com/watch?v=0k79LqIaHyQ


# Authors and contributors:
- https://github.com/DineshbMahale
- https://github.com/NupurChavan


