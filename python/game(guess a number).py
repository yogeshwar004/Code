#this is a guess the number game
import random
secretnumber=random.randint(1,20)
print("I am thinking a number between 1 to 20......")

#ask a player to guess the number(6times)
for guesstaken in range(1,7):
    print("Take a guess...")
    guess=int(input())

    if guess<secretnumber:
        print('Your guess is too low....')
    elif guess>secretnumber:
        print('Your guess is too high....')
    else:
        break

if guess==secretnumber:
    print("Good job:you guessed my number in",guesstaken,"guesses.....")
else:
    print("Nope,the number I was thinking was",secretnumber)
