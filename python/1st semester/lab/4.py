number=input('Enter the Multi-Digit Number:')
frequency={}
for char in number:
    if char.isdigit():
        if char in frequency:
            frequency[char]+=1
        else:
            frequency[char]=1
print('Frequency of each digit:')
for digit,frequencies in sorted(frequency.items()):
    print(f'Digit {digit}:Frequency {frequencies}')