#Define a function.
def isPalindrome(string):
    if (string[0] == string[-1]):
        print("The string is a palindrome.")
    else:
        print("The string is not a palindrome.")
#Enter input string.
string = input ("Enter string: ")
isPalindrome(string)
