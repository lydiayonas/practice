import random 
while True:
    correctGuess = random.randint(1,10)
    attempt = 0
    while attempt<3:
        attempt= attempt + 1
        print(f"This is your {attempt} attempt!")        
        user_guess = int(input("Guess the number from 1 to 10: "))
        if user_guess==correctGuess:
            print("you guessed correct🎉")
            break
        elif user_guess>correctGuess:
            print("your guess is  higher:")
        elif user_guess<correctGuess:
            print("you guess is lower: ")
        else:
            print("wrong guess")
