PASSWORDS = {'email@edu': 'hittu@abc',
'blog': 'neha@123',
'luggage': 'Sonia_45'}
import sys, pyperclip
if len(sys.argv) < 2:
 print('Usage: python mclip.py [account] - copy account password')
 sys.exit()
account = sys.argv[1]
if account in PASSWORDS:
 pyperclip.copy(PASSWORDS[account])
 print('Password for ' + account + ' copied to clipboard.')
else:
 print('There is no account named ' + account)
