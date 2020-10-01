def answer(noun,verb,adjective,pluralnoun,adverb):
    nouns = []
    verbs = []
    adjectives = []
    pluralnouns = []
    adverbs = []
    for x in range (0,noun):
        temp = str(input("Please enter a noun"))
        nouns.append(temp)

        file = open("answerbanknoun.txt","a")

        file.write("\n%s"%(temp))

        file.close()

    for x in range (0,verb):
        temp = str(input("Please enter a verb"))
        verbs.append(temp)

        file = open("answerbankverb.txt","a")

        file.write("\n%s"%(temp))

        file.close()
    
    for x in range (0,adjective):
        temp = str(input("Please enter a adjective"))
        adjectives.append(temp)

        file = open("answerbankadjective.txt","a")

        file.write("\n%s"%(temp))

        file.close()

    for x in range (0,pluralnoun):
        temp = str(input("Please enter a plural noun"))
        pluralnouns.append(temp)

        file = open("answerbankpluralnoun.txt","a")

        file.write("\n%s"%(temp))

        file.close()

    for x in range (0,adverb):
        temp = str(input("Please enter an adverb"))
        adverbs.append(temp)

        file = open("answerbankadverb.txt","a")

        file.write("\n%s"%(temp))

        file.close()

    

    return nouns,verbs,adjectives,pluralnouns,adverbs

def answerbank(noun,verb,adjective,pluralnoun,adverb):
    from random import randint
    
    nouns = []
    verbs = []
    adjectives = []
    pluralnouns = []
    adverbs = []
    for x in range (0,noun):
        file = open("answerbanknoun.txt","r")
        counter=0
        for y in file:
            file.readline()
            counter+=1
        randword = randint(0,counter)
        file.close()
        file = open("answerbanknoun.txt","r")
        count=1
        while(count <=randword):
            file.readline()
            count+=1
        tempword=""
        for y in file.readline():
            if y == '\n':
                break
            else:
                tempword+=y
        nouns.append(tempword)
        file.close()
            

    for x in range (0,verb):
        file = open("answerbankverb.txt","r")
        counter=0
        for y in file:
            file.readline()
            counter+=1
        randword = randint(0,counter)
        file.close()
        file = open("answerbankverb.txt","r")
        count=1
        while(count <=randword):
            file.readline()
            count+=1
        tempword=""
        for y in file.readline():
            if y == '\n':
                break
            else:
                tempword+=y
        verbs.append(tempword)
        file.close()
    
    for x in range (0,adjective):
        file = open("answerbankadjective.txt","r")
        counter=0
        for y in file:
            file.readline()
            counter+=1
        randword = randint(0,counter)
        file.close()
        file = open("answerbankadjective.txt","r")
        count=1
        while(count <=randword):
            file.readline()
            count+=1
        tempword=""
        for y in file.readline():
            if y == '\n':
                break
            else:
                tempword+=y
        adjectives.append(tempword)
        file.close()

    for x in range (0,pluralnoun):
        file = open("answerbankpluralnoun.txt","r")
        counter=0
        for y in file:
            file.readline()
            counter+=1
        randword = randint(0,counter)
        file.close()
        file = open("answerbankpluralnoun.txt","r")
        count=1
        while(count <=randword):
            file.readline()
            count+=1
        tempword=""
        for y in file.readline():
            if y == '\n':
                break
            else:
                tempword+=y
        pluralnouns.append(tempword)
        file.close()

    for x in range (0,adverb):
        file = open("answerbankadverb.txt","r")
        counter=0
        for y in file:
            file.readline()
            counter+=1
        randword = randint(0,counter)
        file.close()
        file = open("answerbankadverb.txt","r")
        count=1
        while(count <=randword):
            file.readline()
            count+=1
        tempword=""
        for y in file.readline():
            if y == '\n':
                break
            else:
                tempword+=y
        adverbs.append(tempword)
        file.close()

    return nouns,verbs,adjectives,pluralnouns,adverbs
