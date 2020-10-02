from random import randint
import source
example = 1
   
print("Welcome to the MAD LIBS GAME!")

types = int(input("Please enter the game mode you would like to choose:\nShort Story-1\nPhrase-2\n\n"))
flag = 0
while flag == 0:
    
    if types == 1:
        source.storybank(example)
        example = randint(1,6)
        flag = 1

    elif types ==2:
        source.phrasebank(example)
        randint(1,14)
        flag = 1
    else:
        print("The answer you have entered is invalid, please try again")


