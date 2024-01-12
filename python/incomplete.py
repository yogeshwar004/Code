import shelve,pyperclip,sys
s=shelve.open('mcb')
if len(sys.argv)==3 and sys.argv[1].lower=='save':
    s[sys.argv[2]]=pyperclip.paste()
elif len(sys.argv)==2:
    if sys.argv[1].lower()=='list':
        

