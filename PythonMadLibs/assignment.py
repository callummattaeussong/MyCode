from random import randint
import source
   
print("Welcome to the MAD LIBS GAME!")

types = int(input("Please enter the game mode you would like to choose:\nShort Story-1\nPhrase-2\n\n"))
flag = 0
while flag == 0:
    
    if types == 1:
        example = randint(1,6)
        source.storybank(example)
        
        flag = 1

    elif types ==2:
        randint(1,14)
        source.phrasebank(example)
        
        flag = 1
    else:
        print("The answer you have entered is invalid, please try again")


