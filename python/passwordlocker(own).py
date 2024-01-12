PASSWORDS={'yogeshwar2004':'1234@abc',
'9945216211':'5678@def',
'yogeshwar.22cse@cambridge.edu.in':'9012@ghi'}

import pyperclip,sys
if len(sys.argv)<2:
    print('Usage:python mclip[account]-copy account password')
    sys.exit()
account=sys.argv[1]

if account in PASSWORDS:
    pyperclip.copy(PASSWORDS[account])
    print('Password for '+account+' copied for clipboard')
else:
    print('there is no account named '+account)
