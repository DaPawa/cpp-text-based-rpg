#ifndef DIALOGUE
#define DIALOGUE
#include "interface.h"

//From other files
inline void clearScreen();
void displayMap(int level, playableCharacter* player, gameInterface ui);

//Playersay, MOVSay and sleep are just here to make the code look cleaner
inline void sleep(int duration){
    #ifndef NOSLEEP

    std::chrono::seconds wait(duration);
    std::this_thread::sleep_for(wait);

    #endif // NOSLEEP
}

inline void playerSay(playableCharacter *player, std::string msg){
    std::cout << player->getName() << ": " << msg << std::endl;
    sleep(2);
}

inline void playerSay(playableCharacter *player, std::string msg, int wait){
    std::cout << player->getName() << ": " << msg << std::endl;
    sleep(wait);
}

inline void MOVSay(std::string msg){
    std::cout << "Mysterious Ominous Voice: " << msg << std::endl;
    sleep(2);
}

inline void MOVSay(std::string msg, int wait){
    std::cout << "Mysterious Ominous Voice: " << msg << std::endl;
    sleep(wait);
}

inline void NPCSay(std::string npcName, std::string msg){
    std::cout << npcName << ": " << msg << std::endl;
    sleep(2);
}

inline void NPCSay(std::string npcName, std::string msg, int wait){
    std::cout << npcName << ": " << msg << std::endl;
    sleep(wait);
}

/*
All of these functions just make it so that there isn't a bunch of dialogue and stuff
covering the code which handles the logic. It's here where everything in between dialogue
also happens, just to simplify stuff and make it easier to tell where an error occurred (i.e.
if it happened during dialogue it's here, if it didn't it isn't)
*/

void beginning(gameInterface ui, playableCharacter *player){
    std::cout << "..." << std::endl;
    sleep(3);
    playerSay(player, "Where am I?");
    MOVSay("I'm a mysterious ominous voice, not a GPS!");
    MOVSay("Buuut... I'm a mysterious ominous voice with vision. You're currently in a training room, to prepare you for battle!",
           3);
    playerSay(player, "Battle? What do you mean battle!");
    MOVSay("Oh yeah, we were in a rush to kidnap you, forgot to explain! Basically, something something grand adventure something something dragon.",
           3);
    playerSay(player, "Kidnapping? Explains the chloroform bottle next to me. Also what dragon?");
    MOVSay("Let's not dwell on past events. Here's a living test dummy for you to fight with!\n");
    enemy dummy("Test Dummy", 10, 0, 0, 10, 1.5f, true);
    switch(ui.startAttack(player, dummy)){
    case 0:
        MOVSay("Well... let's pretend that didn't happen!");
        player->setLives(2);
        clearScreen();
        beginning(ui, player);
        break;
    case 1:
        MOVSay("Congratulations! You won! Time for the dragon!");
        break;
    case 2:
        MOVSay("Wow what a brave warrior, running away like that. Try running from the dragon. See where that gets you.");
        playerSay(player, "I presume away from the dragon. Wait");
        break;
    default:
        MOVSay("You find yourself in a strange place...");
        beginning(ui, player);
    }
    playerSay(player, "What the hell is going on with this dragon thing?");
    MOVSay("Don't you worry about that! We'll cross that bridge when we get there.");
    playerSay(player, "For God's sake! First there's a dragon now there's a bridge?");
    MOVSay("God, someone isn't happy! Just wait till we get to the clowns");
    playerSay(player, "THERE ARE CLOWNS TOO!?");
    MOVSay("Oh, yeah, they're epic! Lemme show you one!");
    enemy clown("clown", 10000, 500, 100, 10000, 100, true);
    switch(ui.startAttack(player, clown)){
    case 0:
        MOVSay("HA! DID YOU SEE YOUR DEAD FACE JUST THEN?");
        playerSay(player, "How the hell am I still here? I thought I died");
        MOVSay("Oh, yeah I forgot to say, you only have 2 lives.");
        playerSay(player, "Wait, so I've only got 1 life left?");
        MOVSay("That does make sense.");
        playerSay(player, "Bloody hell.");
        MOVSay("You're acting like I killed someone!");
        playerSay(player, "I wonder why...");
        MOVSay("Anyways, I'll let you into the training room now!");
        break;

    case 1:
        MOVSay("Did you just... sorry... what...");
        playerSay(player, "That clown sure did put up a fight!");
        MOVSay("Yeah...");
        playerSay(player, "Something up?");
        MOVSay("Let's just go to the training room");

    case 2:
        MOVSay("Fine, if you're gonna run, I'll take the life from you myself!");
        playerSay(player, "What, you're gonna kill me?");
        MOVSay("Yeah! Clown didn't so I will!");
        player->setLives(player->getLives() - 1);
        playerSay(player, "OW! How am I not dead!");
        MOVSay("You're not dead because you get 2 lives!");
        playerSay(player, "So now I have one?");
        MOVSay("Yep!");
        playerSay(player, "Just great...");
        MOVSay("I'm glad you're happy! Let's move onto the training room now!");
    }
    displayMap(__BEGINNINGLEVEL, player, ui);
}

void theEmptyRoom(gameInterface ui, playableCharacter *player){
    clearScreen();
    MOVSay("Congrats on killing all those dummies!");
    playerSay(player, "What happened to the door?");
    MOVSay("What door?");
    playerSay(player, "The door I got here through");
    MOVSay("You didn't get here through a door");
    playerSay(player, "Then what was that?");
    MOVSay("What was what?");
    playerSay(player, "The thing I came through?");
    MOVSay("What did you come through?");
    playerSay(player, "I came through a door!");
    MOVSay("No you didn't");
    playerSay(player, "Then what did I come through?");
    MOVSay("I have no idea!");
    playerSay(player, "Then how do you know it wasn't a door?");
    MOVSay("I have no idea!");
    playerSay(player, "How'd I end up in this situation!");
    MOVSay("We both established that we have no idea");
    playerSay(player, "...");
    MOVSay("Oh also, there are these holes in the wall that close when you go through.");
    playerSay(player, "THAT'S WHAT A DOOR IS!");
    MOVSay("No, a door is a mysterious 4 letter word.");
    playerSay(player, "ANYWAYS. Where am I?");
    MOVSay("In an empty room");
    playerSay(player, "I can see that...");
    playerSay(player, "I mean, what do I do here?");
    MOVSay("Apparently, there's a living wall here");
    playerSay(player, "Thank god, you finally said something useful.");
    MOVSay("Yay! Onwards we go then!");
}

void enterTheRealWorld(gameInterface ui, playableCharacter *player){
    clearScreen();
    MOVSay("Welcome to the outside world, and congrats on making it out of training!");
    playerSay(player, "But I was literally in the real world before you kidnapped me.");
    MOVSay("Nah, this is the *real* real world!");
    playerSay(player, "That's why the building I just left is labelled \"Simulation Training Room\"");
    MOVSay("What do you mean?");
    playerSay(player, "Where did... You know what, I don't care, just tell me what to do next");
    MOVSay("Well, you stand in a small town. There is a health building which will refill your HP");
    playerSay(player, "Yeah... that's oddly convenient... just like real life...");
    MOVSay("Exactly! Now let's go!");
}

void banditAttack(gameInterface ui, playableCharacter *player){
    clearScreen();
    MOVSay("Where are you going?");
    playerSay(player, "There was only 1 place to go");
    MOVSay("Yeah... Fair enough");
    playerSay(player, "So anyways, where does this road lead?");
    MOVSay("To a bunch of bandits out to kill you");
    playerSay(player, "To... what...");
    MOVSay("Yeah, they want you dead");
    playerSay(player, "Why?");
    MOVSay("Here, take a MAXIMUM healing potion! You'll need it.");
    player->inventory.maxHeal++;
    player->inventory.healingPotions++;
    playerSay(player, "I asked why...");
    MOVSay("Oh, sorry, I didn't hear! The last vict... associate of ours pissed them off a lot");
    playerSay(player, "Could you have not told me before?");
    MOVSay("Nope!");
    playerSay(player, "Why not?");
    MOVSay("Didn't wanna");
    playerSay(player, "What.");
    MOVSay("Anyways, ahead of the bandits, you'll find your way to a town");
    MOVSay("Over there you can buy stuff with the money you earn from killing bandits");
    playerSay(player, "What can I buy there?");
    MOVSay("Health potions, other potions, other stuff, etc");
    playerSay(player, "-_-");
    MOVSay("What's wrong?");
    playerSay(player, "Could you get any more broad?");
    MOVSay("Nope!");
    playerSay(player, "Just lea...", 1);
    MOVSay("BANDIT!");
    enemy bandit("Bandit", 70, 5, 20, 65, 4,  true);
    ui.startAttack(player, bandit);
}

void cityOfTown(gameInterface ui, playableCharacter *player){
    clearScreen();
    playerSay(player, "Damn, they almost got us");
    MOVSay("What almost got what?");
    playerSay(player, "Nevermind. Wait... How're we here already?");
    MOVSay("How are we where already?");
    playerSay(player, "You're pretty dim for an omnipotent omnipresent being");
    MOVSay("Yeah, we don't emit light. Not within the visible spectrum at least");
    playerSay(player, "Wait... What kind of light do you emit then?");
    MOVSay("Who said I emit light?");
    playerSay(player, "You just did");
    __CLEARSCREENPROMPTLESS();
    MOVSay("Hello! We were just talking! We're finally here in the town! We're in the city of town!");
    playerSay(player, "But... We were...", 1);
    MOVSay("We were just fighting bandits!");
    playerSay(player, "Okay, whatever, so what can I do here?");
    MOVSay("You can recover health, you can buy items, you can just generally prepare for later on");
    playerSay(player, "What's happening later on?");
    MOVSay("DRAGON!");
    playerSay(player, "Oh. Yeah.");
}

void theBabyDragon(gameInterface ui, playableCharacter *player){
    clearScreen();
    MOVSay("You know, we've already been to 2 towns and there's hardly been any action");
    playerSay(player, "Hardly any action? We just fought a bunch of bandits after I got kidnapped!");
    MOVSay("And killed by a clown");
    playerSay(player, "Exactly! What do you mean hardly any action!");
    MOVSay("Sorry, what I meant to say is that there are hardly any dragons");
    playerSay(player, "Oh, yeah you did talk about the dragons before. If I can go kill them now am I done here?");
    MOVSay("You're not ready");
    playerSay(player, "Then why are you complaining?");
    MOVSay("I didn't specify which dragon I was talking about");
    playerSay(player, "Oh... oh no... where are we headed?");
    MOVSay("To the nest of a baby dragon. You will go in, kill the baby dragon, and escape");
    playerSay(player, "What am I escaping from?");
    MOVSay("The big dragon which will almost certainly kill you if you're not careful!");
    playerSay(player, "That's uh, great");
    MOVSay("Yeah. When you've killed the baby fall through the middle of the nest, where I will find you");
    playerSay(player, "Wait you're an actual thing, and not just a disembodied voice?");
    MOVSay("Indeed");
    playerSay(player, "Wow");
    MOVSay("Anyways, we are here!");
}

void theGrandEscape(gameInterface ui, playableCharacter *player){
    __CLEARSCREENPROMPTLESS();
    MOVSay("Congrats! You escaped!");
    playerSay(player, "And what was the point of that?");
    MOVSay("I was bored, wanted to see what would happen");
    playerSay(player, "What if I died?");
    MOVSay("Like the rest of them?");
    playerSay(player, "What? Okay nevermind, where are you taking me now?");
    MOVSay("Taking you? You have to escape this place first");
    playerSay(player, "And how do I do that?");
    MOVSay("You just leave");
    playerSay(player, "Wait, it's that easy?");
    MOVSay("Nope, you dropped all your money on the way down");
    player->inventory.money = 0;
    playerSay(player, "Dammit, but apart from that can I just leave?");
    MOVSay("Well, uh, yeah, I guess");
    playerSay(player, "Great, I guess");
    MOVSay("Oh, there's also a sea of dragon eggs to get rid of");
}

void theMeetUp(gameInterface ui, playableCharacter *player){
    __CLEARSCREENPROMPTLESS();
    MOVSay("We're going to meet up with one of my close friends");
    playerSay(player, "So you aren't gonna comment on the thing that just happened?");
    MOVSay("Thing that what happened?");
    playerSay(player, "You know, the whole baby dragon thing");
    MOVSay("Oh yeah, that thing. What about it?");
    playerSay(player, "Okay, never mind. Who are we meeting");
    MOVSay("A close friend of mine");
    playerSay(player, "Anything significant about this person?");
    MOVSay("Nope, not really");
    playerSay(player, "Why are we meeting your friend?");
    MOVSay("I'm lonely");
    playerSay(player, "But... You're a disembodied voice, do you even have feelings?");
    MOVSay("Yeah, I do");
    playerSay(player, "But can't you just go meet your friend on your own");
    MOVSay("I can");
    playerSay(player, "So why drag me along?");
    MOVSay("Because I can");
    playerSay(player, "...");
    MOVSay("Anyways we're here");
    playerSay(player, "We didn't move");
    MOVSay("Minor details, anyways, here's _kotak");
    NPCSay("_kotak", "Hi!");
    playerSay(player, "Where the hell did you come from?");
    NPCSay("_kotak", "Earth");
    MOVSay("I think you meant uhh...");
    MOVSay("You're still on earth. Right _kotak?");
    NPCSay("_kotak", "Oh, yeah, of course");
    playerSay(player, "So you're not a disembodied voice like Mysterious Ominous Voice?");
    NPCSay("_kotak", "You didn't tell him your name?");
    MOVSay("What name?");
    NPCSay("_kotak", "Oh, of course");
    playerSay(player, "I'm very confused, who even are you?");
    MOVSay("_kotak is very epic and is the only person to have killed *the dragon*");
    playerSay(player, "Wait, the dragon is dead?");
    MOVSay("Yeah, but it respawns like every 10 minutes");
    playerSay(player, "What's the point of me killing it then?");
    MOVSay("It's entertaining for me and _kotak to watch");
    NPCSay("_kotak", "Yeah");
    playerSay(player, "Okay anyways, where even are we?");
    NPCSay("_kotak", "You're here to kill a bunch of things whilst I watch");
    playerSay(player, "Why?");
    NPCSay("_kotak", "So I can determine if you're a true dragon slayer");
    playerSay(player, "But... why don't you kill the dragon again?");
    NPCSay("_kotak", "Because I already have");
    playerSay(player, "So you're best suited for it");
    NPCSay("_kotak", "No, I'm best suited to watching someone else suffer to kill *the dragon*");
    MOVSay("Sorry to interrupt, but here is the bridge I was talking about!");
    playerSay(player, "What bri... Oh yeah...");
    MOVSay("See, I told you it'll be here!");
    playerSay(player, "Wait, am I not supposed to prove I can kill the dragon first?");
    NPCSay("_kotak", "Oh, yeah I'll bring the enemies");
    playerSay(player, "What?");
    MOVSay("Have fun!");
    NPCSay("_kotak", "I'll watch from a distance!");
    MOVSay("Also take this max heal potion, you might need it!");
    player->inventory.maxHeal += 1;
}

void theRealBattlePreparation(gameInterface ui, playableCharacter *player){
    __CLEARSCREENPROMPTLESS();
    NPCSay("_kotak", "Good job, now we can go into a real battle!");
    playerSay(player, "Wait, a real battle? What do you mean?");
    MOVSay("We're going to get you healed up and stuff");
    NPCSay("_kotak", "And then we're going to throw you into a pit of very angry enemies");
    MOVSay("And we'll hope you don't die");
    playerSay(player, "What happens if I do die?");
    MOVSay("Well, we'll have to replace you with one of the 20,000,000 other people we have kidnapped");
    playerSay(player, "I'm just not gonna question that");
    NPCSay("_kotak", "Like a true to-be dragon slayer!");
}

void theRealBattle(gameInterface ui, playableCharacter *player){
    __CLEARSCREENPROMPTLESS();
    NPCSay("_kotak", "Here's the real battle now!");
    MOVSay("Yeah, the pit of very angry enemies!");
    NPCSay("_kotak", "Hope you don't die!");
    playerSay(player, "Why are you all ending your sentences with exclamation marks?");
    MOVSay("To emphasise our excitement!");
    playerSay(player, "Excitement for my death?");
    NPCSay("_kotak", "Yeah!");
}

void theMugHouse(gameInterface ui, playableCharacter *player){
    __CLEARSCREENPROMPTLESS()
    NPCSay("_kotak", "Well done, you survived!");
    playerSay(player, "Thanks, I guess?");
    MOVSay("Let's celebrate by looking at _kotak's bakugan collection");
    playerSay(player, "Her what?");
    NPCSay("_kotak", "My bakugan collection");
    playerSay(player, "Why do you have a bakugan collection?");
    NPCSay("_kotak", "Are you disrespecting bakugan?");
    MOVSay("That's deserving of some punishment");
    playerSay(player, "Oh, sorry, I didn't mean to disrespect your bakugan");
    NPCSay("_kotak", "It's fine I guess");
    playerSay(player, "Wait... that looks like a mug");
    NPCSay("_kotak", "That's because it is");
    playerSay(player, "Don't worry, I won't disrespect your housing choices too");
    NPCSay("_kotak", "You're learning!");
}
//Note to self: add __CLEARSCREENPROMPTLESS() to beginning of stuff

#endif // DIALOGUE
