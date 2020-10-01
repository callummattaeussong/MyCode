def phrasebank(examples):

    import processes

    choice = int(input("Would you like to enter your own answer or allow a random answer from the answer bank?\nYou enter your own-1\nAnswer bank-2"))

    if examples == 1:

        noun = 1
        verb = 1
        adjective = 0
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("The %s won't dry if you keep on wanting to %s it"%(nouns[0],verbs[0]))

    elif examples == 2:

        noun = 1
        verb = 0
        adjective = 1
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("I like to assume that he is %s. Just because he owns a/an %s"%(adjectives[0],nouns[0]))

    elif examples == 3:

        noun = 1
        verb = 1
        adjective = 0
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("He is going to %s the %s"%(verbs[0],nouns[0]))

    elif examples == 4:

        noun = 1
        verb = 0
        adjective = 2
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("I tried mixing pancakes with %s and they turned out quite %s and %s"%(nouns[0],adjectives[0],adjectives[1]))

    elif examples == 5:

        noun = 2
        verb = 0
        adjective = 1
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("I can't wait until I find out how the %s beat the %s in a %s wrestling match"%(nouns[0],nouns[1],adjectives[0]))

    elif examples == 6:

        noun = 1
        verb = 0
        adjective = 1
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("Have you ever worn a/an %s? I'm quite %s to try one on"%(nouns[0],adjectives[0]))

    elif examples == 7:

        noun = 1
        verb = 0
        adjective = 1
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("Wow... that's a really %s way from my %s"%(adjectives[0],nouns[0]))

    elif examples == 8:

        noun = 1
        verb = 0
        adjective = 1
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("I swear! I saw the %s move all on it's own! It was really %s..."%(nouns[0],adjectives[0]))

    elif examples == 9:

        noun = 2
        verb = 0
        adjective = 0
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnouns,adverbs)

        print("I've really got to be a better %s in order the earn the respect i deserve from my %s"%(nouns[0],nouns[1]))

    elif examples == 10:

        noun = 0
        verb = 0
        adjective = 1
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("I'm sorry you were speaking too %s. I couldn't catch the words you were saying."%(adjectives[0]))

def storybank(examples):

    import processes

    choice = int(input("Would you like to enter your own answer or allow a random answer from the answer bank?\nYou enter your own-1\nAnswer bank-2"))

    if examples == 1:

        noun = 7
        verb = 1
        adjective = 3
        pluralnoun = 2
        adverb = 2

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("""Driving a car can be fun if you follow this %s advice: When approaching a %s on the right,
        always blow your %s. Before making a/an %s turn, always stick your %s out of the window %s. Every 2000 miles,
        have your %s inspected and your %s checked.When approaching a school, watch out for %s %s. Above all, drive carefully.
        The %s you save may be your own! If everyone decides to %s together in order to solve this %s %s, we would be able to
        many more %s on a daily basis!"""%(adjectives[0],nouns[0],nouns[1],adjectives[1],nouns[2], adverbs[0],nouns[3],nouns[4],adjectives[2],pluralnouns[0],nouns[5],verbs[0],nouns[6],adverbs[1],pluralnouns[1]))

    elif examples == 2:

        noun = 9
        verb = 0
        adjective = 1
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("""Ireland is a beautiful green island lying directly west of place.
        In 250 B.C., Ireland was inhabited by short, dark %ss whowere later called \"Picts\" They intermarried
        with %s Vikings and with Celts who were %ss from Northern Europe. In 1846, a blight ruined the %s crop
        in Ireland, and over a million Irishmen migrated to the United States. Many of their descendants have become very
        important American %ss. The Irish are noted for their poetry and songs. Some of these Irish songs are: \"When Irish
        %ss are Smiling\" \"Did Your %s come from Ireland?,\" and \"McNamara's %s\"Thousands of American tourists go to
        Ireland every year to visit its capital, place, and buy Irish linen %ss and see the beautiful %ss and lakes."""%(nouns[0],adjectives[0],nouns[1],nouns[2],nouns[3],nouns[4],nouns[5],nouns[6],nouns[7],nouns[8]))

    elif examples == 3:

        noun = 3
        verb = 6
        adjective = 2
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("""Once there was a boy named %s. He would always %s his mom before going to school.
He really loved his parents a lot. He would often %s because he would miss them so much.
He would often have problems in school because he would be %s and long to %s them. He would
seek for %s from other people in order to %s his needs. He was longing for the time to return home.
When the time finally came, he %s in the house and %s! He was so %s to see his old folks.
They joined together and ate a nice %s.He dreaded the day the would have to leave his home and %s his
parents once again. Would he be able to take such %s? He will find out soon."""%(nouns[0],verbs[0],verbs[1],adjectives[0],verbs[2],nouns[1],verbs[3],verbs[4],verbs[5],adjectives[1],nouns[2],verbs[6],nouns[3]))

    elif examples == 4:

        noun = 9
        verb = 6
        adjective = 4
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("""Today we will be making %ss. Firstly, to prepare to %s our %s, we need to %s our %s very firmly.
After that we need to %s the %s in a pot and %s it very vigorously! Alas, when the %s feels %s
and %s, we should leave it in the %s for a couple of hours. After that, it should be ready to %s to your guests.
The ideal %s of the %s should be quite %s! Your guests will certainly be excited to %s all the effort you have
put into this %s. What a %s recipe!"""%(nouns[0],verbs[0],nouns[1],verbs[1],nouns[2],verbs[2],nouns[3],verbs[3],nouns[4],
                                                                   adjectives[0],adjectives[1],nouns[5],verbs[4],nouns[6],nouns[7],adjectives[2],verbs[5],nouns[8],adjectives[3]))

    elif examples == 5:

        noun = 9
        verb = 7
        adjective = 8
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("""Today was the big %s between %s and %s! Thousands of %s are pouring into
the %s to %s the %adjective1s %s! The crowds would %s and %s as the two %s %ss clashed!
The commentator began to %s as the match continued on. The atmosphere, thick with %s was %s with
%s as the fight reached its climax! Never has there been a more %s battle in the history of %s! Annie,
watching the %s fight followed as her the crowd around her began to %s. She felt very uncomfortable and %s.
Breathing became %s for her and she began to feel %s. Suddenly she blacked out and awoke to %s.
What a strange event."""%(verbs[0],nouns[0],nouns[1],nouns[2],nouns[3],verbs[1],adjectives[0],verbs[2],verbs[3],verbs[4],adjectives[1],nouns[4],verbs[5],nouns[5]
                          ,adjectives[2],nouns[6],adjectives[3],nouns[7],adjectives[4],verbs[6],adjectives[5],adjectives[6],adjectives[7],nouns[8]))

    elif examples == 6:

        noun = 1
        verb = 0
        adjective = 1
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("""I have known Linda.for 20 years and %adverb1s recommend him/her for the position of assistant %noun1s.in your
%adjective1s.company. I can't %verb1s.enough about this person's %adjective2s.character and ability to get along with his/her fellow
%pluralnoun1s. As for educational background, Linda is a college %noun2s, is capable of speaking several foreign
%pluralnoun2s, and has an IQ of 12. You will find Linda.to be a %adjective3s.worker who is not only
as smart as a %noun3s, but who doesn't know the meaning of the word %verb2s. Unfortunately, this is one of many words
this person doesn't know the meaning of"""%(nouns[0],adjectives[0]))

    elif examples == 7:

        noun = 1
        verb = 0
        adjective = 1
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("Wow... that's a really %s way from my %s"%(adjectives[0],nouns[0]))

    elif examples == 8:

        noun = 1
        verb = 0
        adjective = 1
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("I swear! I saw the %s move all on it's own! It was really %s..."%(nouns[0],adjectives[0]))

    elif examples == 9:

        noun = 2
        verb = 0
        adjective = 0
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("I've really got to be a better %s in order the earn the respect i deserve from my %s"%(nouns[0],nouns[1]))

    elif examples == 10:

        noun = 0
        verb = 0
        adjective = 1
        pluralnoun = 0
        adverb = 0

        if choice ==1:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answer(noun,verb,adjective,pluralnoun,adverb)
        if choice ==2:
            nouns,verbs,adjectives,pluralnouns,adverbs=processes.answerbank(noun,verb,adjective,pluralnoun,adverb)

        print("I'm sorry you were speaking too %s. I couldn't catch the words you were saying."%(adjectives[0]))
