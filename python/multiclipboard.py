# mcb.py - Saves and loads pieces of text to the clipboard. 
import shelve, pyperclip, sys 
s = shelve.open('mcb') 
if len(sys.argv) == 3 and sys.argv[1].lower() == 'save': 
    s[sys.argv[2]] = pyperclip.paste() 
elif len(sys.argv) == 2: 
    if sys.argv[1].lower() == 'list': 
        pyperclip.copy(str(list(s.keys()))) 
    elif sys.argv[1] in s: 
        pyperclip.copy(s[sys.argv[1]]) 
s.close()
