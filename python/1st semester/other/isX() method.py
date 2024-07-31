while True:
    print('enter the age')
    age=input()
    if age.isdecimal():
        break
    print('Please enter a number for your age')

while True:
    print('Select a new password(letter and number only)')
    password=input()
    if password.isalnum():
        break
    print('password can only letters and numbers')
