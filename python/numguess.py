import random 
correctGuess = random.randint(1,10)
user_guess = int(input("Guess the number from 1 to 10: "))
if user_guess==correctGuess:
    print("you guessed correct🎉")
elif user_guess>correctGuess:
     print(f"your guess is a bit higher than the correct guess: {correctGuess}")
elif user_guess<correctGuess:
     print(f"you guess is lower than the correct guess: {correctGuess}")
else:
     print("wrong guess")
