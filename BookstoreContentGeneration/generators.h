#ifndef GENERATORS_H
#define GENERATORS_H

#include <QString>
#include <QStringList>
#include <stdlib.h>
#include <time.h>

//Массивы строк, из которых генерируются имена и названия
QStringList preposition = (QStringList()<<"Above"<<"After"<<"At"<<"Beyond"<<"For"<<"From"<<"In"<<"Into"<<"On"<<"Out of"<<"With"<<"Without"<<"Under");

QStringList noun = (QStringList()<<"Abbey"<<"Adventure"<<"Affair"<<"Africa"<<"Age"<<"Agoroman"<<"Alexander"<<"Alexander the Great"<<"Aladdin"<<"Aliens"<<
"Amulet"<<"Angelo"<<"Angel"<<"Apocalypse"<<"Aristotle"<<"Armageddon"<<"Ash"<<"Asylum"<<"Atlantis"<<"Avenger"<<"Awakening"<<
"Barsac"<<"Bat"<<"Beard"<<"Beast"<<"Beasts"<<"Big Bad Wolf"<<"Birds"<<"Birthday Present"<<"Bishop"<<"Bites"<<
"Blackwell"<<"Blade"<<"Blight"<<"Blog"<<"Blogger"<<"Blonde"<<"Blood"<<"Bloodline"<<"Body"<<"Book"<<"Bookkeeper"<<"Bones"<<
"Boudica"<<"Boy"<<"Brass"<<"Brain"<<"Bridge"<<"Bronze"<<"Books"<<"Brother"<<"Brothers"<<"Bullet"<<"Bus"<<"Butterfly"<<
"Cabin"<<"Caesar"<<"Call"<<"Cape"<<"Captain Hook"<<"Captain Nemo"<<"Carnival"<<"Case"<<"Casket"<<"Caverns"<<"Cell"<<"Cemetery"<<
"Chain"<<"Chance"<<"Chicago"<<"Childhood"<<"Child"<<"Children"<<"Cindarella"<<"Circle"<<"Circus"<<"City"<<"Claim"<<"Club"<<"Cloven Hoof"<<
"Coast"<<"Cold"<<"Comb"<<"Comet"<<"Compendium"<<"Constantine"<<"Corpse"<<"Cotswold"<<"Cove"<<
"Creek"<<"Crows"<<"Crown"<<"Cry"<<"Cthulhu"<<"Cup"<<"Cupid"<<"Curse"<<"Cylinder"<<"Crypt"<<
"Dance"<<"Dancers"<<"Dark"<<"Darkness"<<"Daughter"<<"Dawn"<<"Day"<<"Daylight"<<"Days"<<"Da Vinci"<<"Death"<<"Dead"<<"Deception"<<"Demon"<<
"Departed"<<"Desert"<<"Detective"<<"Devil"<<"Devils"<<"Discovery"<<"Doctor"<<"Doctor Jeckyll"<<"Dog"<<"Dome"<<"Doom"<<"Door"<<"Doors"<<
"Dracula"<<"Dragon"<<"Dragons"<<"Drapes"<<"Dream"<<"Dusk"<<"Dust"<<"Dweller"<<
"Earth"<<"Edge"<<"Effie"<<"Elysium"<<"Einstein"<<"Emperor"<<"Empire"<<"Eons"<<"Eternity"<<"Equation"<<"Escape"<<"Ether"<<
"Evolution"<<"Exile"<<"Express"<<"Evil"<<"Eye"<<
"Face"<<"Faerie"<<"Fangs"<<"Farm House"<<"Fear"<<"Feast"<<"Feet"<<"Fiend"<<"Fire"<<"Fish"<<
"Flame"<<"Floor"<<"Flower"<<"Fog"<<"Folk"<<"Force"<<"Fox"<<"Frankenstein"<<"Future"<<
"Gambit"<<"G arden"<<"Gentleman"<<"Ghost"<<"Ghostlands"<<"Ghoul"<<"Girl"<<"Gateway"<<"Glory"<<"Glass"<<
"Goblet"<<"Goblins"<<"Gods"<<"God"<<"Gold"<<"Grace"<<"Grave"<<"Graveyard"<<"Guard"<<"Guardian"<<"Guest"<<"Guns"<<"Gun"<<"Gunfighter"<<"Gurov"<<"Gunsmoke"<<
"Hall"<<"Hamlet"<<"Hand"<<"Hands"<<"Hare"<<"Hate"<<"Haunted"<<"Health"<<"Hearts"<<"Heaven"<<"Him"<<"Heist Job"<<"Hell"<<"Heroes"<<
"Hieroglyph"<<"Highway"<<"Hitler"<<"Hollywood"<<"Home"<<"Honor"<<"Horde"<<"Horror"<<"Houdini"<<"Hour"<<"Hours"<<"House"<<
"Huckleberry Finn"<<"Human"<<"Hyborian"<<
"Idol"<<"Inheritance"<<"Inferno"<<"Intention"<<"Imaginary"<<"Insects"<<"Inverness"<<"Island"<<
"Jars"<<"Jailer"<<"Jenny Everywhere"<<"Jewels"<<"Joan of Arc"<<"Journey"<<"Jungle"<<
"Kaldar"<<"Key"<<"Kitchen"<<"Killer"<<"King"<<"Kings"<<
"Labyrinth"<<"Lady MacBeth"<<"Lamia"<<"Law"<<"Legacy"<<"Letters"<<"Life"<<"Lightning"<<"Link"<<"Long John Silver"<<"Lord"<<"Lovecraft"<<
"Madness"<<"Madman"<<"Magic"<<"Man"<<"Manhattan"<<"Manor"<<"Manuscript"<<"March"<<"Marquis de Sade"<<"Mars"<<"Master"<<"Mask"<<"Mata Hari"<<
"Memory"<<"Men"<<"Mesa"<<"Metronome"<<"Mind"<<"Minutes"<<"Mirror"<<"Mistletoe"<<
"Modern"<<"Monster"<<"Monster-God"<<"Moon"<<"Moonlight"<<"Mountain"<<"Mozart"<<"Murder"<<"Music-Box"<<"Mystery"<<
"Nails"<<"Names"<<"Napoleon"<<"Neighbors"<<"Night"<<"Nightmare"<<"North"<<"Nothing"<<"Nowhere"<<
"Odin"<<"Opportunity"<<"Options"<<"Orchid"<<
"Pain"<<"Paladins"<<"Paradox"<<"Parlor"<<"Party"<<"Patch"<<"Path"<<"Patrol"<<"People"<<"Peter Pan"<<"Pets"<<"Phantom"<<"Pilgrim"<<"Piper"<<"Pirate"<<
"Place"<<"Plan"<<"Plant"<<"Player"<<"Power"<<"Prague"<<"Prey"<<"Priestess"<<"Protest"<<"Punch"<<
"Queen"<<"Quest"<<
"Rabbit"<<"Rat"<<"Rats"<<"Reaper"<<"Reckless"<<"Reply"<<"Return"<<"Revenge"<<"Revolt"<<"Revolution"<<"Riders"<<"Ring"<<"River"<<
"Room"<<"Rulers"<<"Rules"<<
"Salvage"<<"Satan"<<"Scientist"<<"Science"<<"Scream"<<"Sea"<<"Sealed"<<"Season"<<"Secret"<<
"Shadows"<<"Shadow"<<"Shakespeare"<<"Shambler"<<"Shell"<<"Sherlock Holmes"<<"She"<<
"Silence"<<"Sip"<<"Sky"<<"Skull"<<"Skunk"<<"Slab"<<"Sleep"<<"Sleepers"<<"Snake"<<
"Soldiers"<<"Song"<<"Sorcery"<<"Soul"<<"South"<<"Space"<<"Spawn"<<"Stars"<<"Steam"<<"Step"<<"Stranger"<<"Studio"<<"Study"<<
"Suicide"<<"Sun"<<"Survivors"<<"Sword"<<
"Tale"<<"Tartarus"<<"Terror"<<"Tesla"<<"They"<<"Thieves"<<"Thing"<<"Things"<<"Thule"<<"Thunder"<<"Ticket"<<"Tiger"<<"Time"<<
"Toad"<<"Tomb"<<"Tombstone"<<"Tommy"<<"Tower"<<"Trade"<<"Trail"<<"Train"<<"Treasures"<<"Trees"<<"Tree"<<"Tsan-Lo"<<
"Us"<<
"Valley"<<"Vampire"<<"Vengeance"<<"Voice"<<"Vials"<<
"Wall"<<"Watcher"<<"Waters"<<"War"<<"Wax"<<"We"<<"Web"<<"Weirds"<<"What Waits"<<"Will"<<"Wind"<<"Window"<<"Wings"<<"Witch"<<
"Wolfhound"<<"Wolves"<<"Woodcarver"<<"Wolf"<<"Woman"<<"Women"<<"Woods"<<"World"<<"Worm"<<"Wrath"<<"Wretched"<<"Wyatt"<<
"Zamboula"<<"Zombie");

QStringList adjective = (QStringList()<<"Accidental"<<"Accusing"<<"Amazing"<<"Atomic"<<"Automatic"<<"Aztec"<<
"Bangkok"<<"Bad"<<"Big"<<"Black"<<"Bloodstained"<<"Blue"<<"Broken"<<
"Clockwork"<<"Closing"<<"Cold"<<"Conquering"<<"Corrupt"<<"Cosmic"<<"Consuming"<<"Closed"<<"Clutching"<<"Copper"<<"Crystal"<<
"Damned"<<"Dancing"<<"Dark"<<"Daylight"<<"Dead"<<"Dead-Alive"<<"Dear"<<"Delicate"<<"Destroying"<<"Different"<<"Dimensional"<<
"Edible"<<"English"<<"Eternal"<<"Evening"<<
"Fae"<<"Fallen"<<"Final"<<"Flapping"<<"Forever"<<"Forty"<<"Frozen"<<
"Galvanic"<<"Golden"<<"Gothic"<<"Gray"<<"Great"<<"Green"<<"Grey"<<"Grim"<<"Grisly"<<
"Hairy"<<"Haunting"<<"Hideous"<<"Hidden"<<
"Imitation"<<"Invisible"<<"Iron"<<
"Last"<<"Lead"<<"Living"<<"Logical"<<"Lost"<<
"Mad"<<"Mechanical"<<"Midnight"<<"Missing"<<"Moonlit"<<"Muddy"<<"My"<<
"New"<<"Next"<<"Noble"<<"Nomadic"<<
"One"<<
"Perfect"<<"Poor"<<"Poisoned"<<"Priceless"<<
"Quantum"<<
"Radient"<<"Raw"<<"Red"<<
"Savage"<<"Scarlet"<<"Second"<<"Secret"<<"Seven"<<"Shattered"<<"Silent"<<"Silver"<<"Six"<<
"Souls"<<"Spare"<<"Special"<<"Strange"<<"Steam-Powered"<<"Steel"<<"Supreme"<<
"Third"<<"Tragic"<<"Twenty"<<"Two"<<
"Ultimate"<<"Undead"<<"Unknown"<<"Unrequited"<<"Urban"<<"Uncommon"<<"Unfaithful"<<"Unseen"<<
"Variable"<<"Vampiric"<<"Velvet"<<"Violet"<<
"Wayward"<<"Weaving"<<"Whispering"<<
"Yellow");

QStringList verb = (QStringList()<<"Be"<<
"Chain"<<"Chase"<<"Come"<<
"Die"<<"Drag"<<"Dream"<<
"Embrace"<<
"Fall"<<"Forget"<<"Fight"<<
"Go"<<
"Hang"<<"Hang"<<"Have"<<
"Kill"<<
"Laugh"<<"Lie"<<
"Murder"<<
"Own"<<
"Run"<<"Ride"<<
"Save"<<"See"<<"Speak"<<"Steal"<<
"Trick"<<
"Go");

QStringList verbed = (QStringList()<<"Borrowed"<<"Built"<<
"Came"<<"Chained"<<"Changed"<<"Chased"<<
"Died"<<"Dragged"<<
"Embraced"<<
"Fell"<<"Forgot"<<"Fought"<<
"Had"<<
"Hung"<<
"Killed"<<
"Laughed"<<"Lied"<<
"Murdered"<<
"Owned"<<
"Ran"<<"Rode"<<
"Saw"<<"Seduced"<<"Spoke"<<
"Tricked"<<
"Was"<<"Went");

QStringList verbs = (QStringList()<<"Comes"<<"Chains"<<"Changes"<<"Chases"<<
"Dies"<<"Drag"<<
"Embraces"<<
"Falls"<<"Forgets"<<"Fights"<<
"Goes"<<
"Hangs"<<
"Has"<<
"Is"<<
"Kills"<<
"Laughs"<<"Lies"<<
"Murders"<<
"Owns"<<
"Rides"<<"Runs"<<
"Screams"<<"Sees"<<"Speaks"<<
"Tricks"<<
"Weeps");

QStringList verbing = (QStringList()<<"Coming"<<"Chaining"<<"Changing"<<"Chasing"<<"Crossing"<<
"Dragging"<<"Dying"<<
"Embracing"<<
"Falling"<<"Forgetting"<<"Fighting"<<
"Going"<<
"Hanging"<<
"Having"<<
"Killing"<<
"Laughing"<<"Lying"<<
"Murdering"<<
"Owning"<<
"Riding"<<"Running"<<"Rising"<<
"Seeing"<<"Speaking"<<
"Tricking");

QStringList auxverb = (QStringList()<<"Could"<<"Could Not"<<"Must"<<"Must Not"<<"Shall"<<"Shall Not"<<"Should"<<"Should Not"<<"That"<<"That Never"<<"Would"<<"Would Not");

QStringList abbreviation = (QStringList()<<"PLC"<<"Ltd"<<"Inc"<<"Corp."<<"LLC"<<"LDC"<<"IC"<<"& Co"<<"LP");

QStringList name = (QStringList()<<"Aaron"<<"Abdul"<<"Abdullah"<<"Abe"<<"Abel"<<"Abraham"<<"Abram"<<"Abriel"<<"Ace"<<"Adam"<<
"Albie"<<"Alden"<<"Aldo"<<"Aldric"<<"Alec"<<"Alejandro"<<"Alen"<<"Alesandro"<<"Alex"<<"Alexander"<<
"Alexis"<<"Alfie"<<"Alfonso"<<"Alfred"<<"Alfredo"<<"Ali"<<"Alistair"<<"Allan"<<"Allen"<<"Alonzo"<<
"Aloysius"<<"Alphonso"<<"Alton"<<"Alvin"<<"Amari"<<"Amir"<<"Amit"<<"Amos"<<"Anand"<<"Anderson"<<
"Andre"<<"Andreas"<<"Andres"<<"Andrew"<<"Andy"<<"Angel"<<"Angelo"<<"Angus"<<"Ansel"<<"Anson"<<
"Anthony"<<"Anton"<<"Antonio"<<"Antony"<<"Apollo"<<"Aran"<<"Archer"<<"Archie"<<"Ari"<<"Arjun"<<
"Avery"<<"Axel"<<"Ayaan"<<"Ayden"<<"Bailey"<<"Barack"<<"Barclay"<<"Barnaby"<<"Barney"<<"Barrett"<<
"Barron"<<"Barry"<<"Bart"<<"Bartholomew"<<"Basil"<<"Bastian"<<"Baxter"<<"Bay"<<"Baylor"<<"Bear"<<
"Beau"<<"Beck"<<"Beckett"<<"Bellamy"<<"Ben"<<"Benedict"<<"Benjamin"<<"Benji"<<"Benjy"<<"Bennett"<<
"Bennie"<<"Benny"<<"Benson"<<"Bentley"<<"Bently"<<"Bernard"<<"Bernardo"<<"Bernie"<<"Bert"<<"Bertie"<<
"Brandon"<<"Brantley"<<"Braxton"<<"Brayan"<<"Brayden"<<"Braydon"<<"Braylon"<<"Brendan"<<"Brenden"<<"Brendon"<<
"Brennan"<<"Brent"<<"Brentley"<<"Brenton"<<"Bret"<<"Brett"<<"Brevin"<<"Brevyn"<<"Brian"<<"Brice"<<
"Carl"<<"Carlisle"<<"Carlos"<<"Carlton"<<"Carsen"<<"Carson"<<"Carter"<<"Cary"<<"Casey"<<"Cash"<<
"Cason"<<"Casper"<<"Cassius"<<"Castiel"<<"Castor"<<"Cathal"<<"Cato"<<"Cavan"<<"Cayden"<<"Caydon"<<
"Cecil"<<"Cedric"<<"Cesar"<<"Chad"<<"Chance"<<"Chandler"<<"Channing"<<"Charles"<<"Charley"<<"Charlie"<<
"Christopher"<<"Chuck"<<"Cian"<<"Ciaran"<<"Cillian"<<"Clancy"<<"Clarence"<<"Clark"<<"Claude"<<"Clay"<<
"Clayton"<<"Clement"<<"Cliff"<<"Clifford"<<"Clifton"<<"Clint"<<"Clinton"<<"Clive"<<"Clyde"<<"Coby"<<
"Cody"<<"Cohen"<<"Colby"<<"Cole"<<"Colin"<<"Collin"<<"Colm"<<"Colt"<<"Colton"<<"Conan"<<
"Cory"<<"Craig"<<"Cristian"<<"Cristobal"<<"Crosby"<<"Cruz"<<"Cullen"<<"Curt"<<"Curtis"<<"Cuthbert"<<
"Cyril"<<"Cyrus"<<"Dacey"<<"Daire"<<"Dakota"<<"Dale"<<"Dallas"<<"Dalton"<<"Damian"<<"Damien"<<
"Darren"<<"Darrin"<<"Darryl"<<"Darryn"<<"Darwin"<<"Daryl"<<"Dash"<<"Dashawn"<<"Dave"<<"David"<<
"Davin"<<"Davion"<<"Davis"<<"Dawson"<<"Dax"<<"Daxter"<<"Daxton"<<"Dayton"<<"Deacon"<<"Dean"<<
"Deandre"<<"Declan"<<"Deepak"<<"Delbert"<<"Demetrius"<<"Denis"<<"Dennis"<<"Denver"<<"Denzel"<<"Deon"<<
"Derek"<<"Dermot"<<"Derrick"<<"Deshaun"<<"Deshawn"<<"Desmond"<<"Dev"<<"Devin"<<"Devlin"<<"Devon"<<
"Dewayne"<<"Dewey"<<"Dexter"<<"Diarmuid"<<"Dick"<<"Dicky"<<"Diego"<<"Dilan"<<"Dillon"<<"Dimitri"<<
"Dinesh"<<"Dino"<<"Dion"<<"Dirk"<<"Django"<<"Dmitri"<<"Dominic"<<"Dominick"<<"Don"<<"Donald"<<
"Donnie"<<"Donovan"<<"Dorian"<<"Doug"<<"Douglas"<<"Doyle"<<"Drake"<<"Drew"<<"Duane"<<"Duke"<<
"Duncan"<<"Dustin"<<"Dwayne"<<"Dwight"<<"Dylan"<<"Eamon"<<"Earl"<<"Earnest"<<"Eason"<<"Easton"<<
"Ed"<<"Eddie"<<"Eddy"<<"Eden"<<"Edgar"<<"Edison"<<"Edmund"<<"Edouard"<<"Edric"<<"Edsel"<<
"Eduardo"<<"Edward"<<"Edwardo"<<"Edwin"<<"Efrain"<<"Efren"<<"Egan"<<"Egon"<<"Eli"<<"Elias"<<
"Elijah"<<"Eliot"<<"Elisha"<<"Ellington"<<"Elliot"<<"Elliott"<<"Ellis"<<"Elmer"<<"Elmo"<<"Elton"<<
"Elvis"<<"Elwyn"<<"Emanuel"<<"Emerson"<<"Emery"<<"Emet"<<"Emil"<<"Emiliano"<<"Emilio"<<"Emmanuel"<<
"Ewan"<<"Ezekiel"<<"Ezio"<<"Ezra"<<"Fabian"<<"Fabio"<<"Faisal"<<"Farley"<<"Febian"<<"Felipe"<<
"Felix"<<"Fergus"<<"Fernand"<<"Fernando"<<"Fidel"<<"Finbar"<<"Finlay"<<"Finley"<<"Finn"<<"Finnian"<<
"Finnigan"<<"Fionn"<<"Fletcher"<<"Floyd"<<"Flynn"<<"Ford"<<"Forest"<<"Forrest"<<"Foster"<<"Fox"<<
"Francesco"<<"Francis"<<"Francisco"<<"Frank"<<"Frankie"<<"Franklin"<<"Franklyn"<<"Fraser"<<"Fred"<<"Freddie"<<
"Freddy"<<"Frederick"<<"Fredrick"<<"Fritz"<<"Gabe"<<"Gabriel"<<"Gael"<<"Gaelan"<<"Gage"<<"Gale"<<
"Galen"<<"Gannon"<<"Gareth"<<"Garman"<<"Garrett"<<"Garrison"<<"Garry"<<"Garth"<<"Gary"<<"Gaston"<<
"Gavin"<<"Gene"<<"Geoff"<<"Geoffrey"<<"George"<<"Geraint"<<"Gerald"<<"Gerard"<<"Gerardo"<<"Germain"<<
"Gerry"<<"Gian"<<"Gibson"<<"Gideon"<<"Gil"<<"Gilbert"<<"Gilberto"<<"Giles"<<"Gino"<<"Giorgio"<<
"Giovanni"<<"Glen"<<"Glenn"<<"Glyndwr"<<"Godfrey"<<"Godric"<<"Godwin"<<"Gonzalo"<<"Gordon"<<"Grady"<<
"Graeme"<<"Graham"<<"Grant"<<"Grayson"<<"Greg"<<"Gregg"<<"Gregor"<<"Gregory"<<"Grey"<<"Greyson"<<
"Griffin"<<"Guillermo"<<"Gunnar"<<"Gunner"<<"Gus"<<"Gustav"<<"Gustavo"<<"Guy"<<"Haden"<<"Haiden"<<
"Hal"<<"Hamish"<<"Han"<<"Hank"<<"Hans"<<"Harlan"<<"Harley"<<"Harold"<<"Harris"<<"Harrison"<<
"Harry"<<"Harvey"<<"Hassan"<<"Hayden"<<"Hayes"<<"Heath"<<"Hector"<<"Hendrik"<<"Hendrix"<<"Henley"<<
"Henri"<<"Henry"<<"Herbert"<<"Herman"<<"Heston"<<"Hilary"<<"Holden"<<"Homer"<<"Horace"<<"Horatio"<<
"Howard"<<"Hubert"<<"Hudson"<<"Hugh"<<"Hugo"<<"Humberto"<<"Humphrey"<<"Hunter"<<"Huw"<<"Hywel"<<
"Imran"<<"Indiana"<<"Inigo"<<"Ira"<<"Irvin"<<"Irving"<<"Irwin"<<"Isaac"<<"Isaiah"<<"Isiah"<<
"Isidore"<<"Ismael"<<"Israel"<<"Issac"<<"Ivan"<<"Ivor"<<"Jace"<<"Jack"<<"Jackie"<<"Jackson"<<
"Jared"<<"Jarod"<<"Jarrett"<<"Jarrod"<<"Jarvis"<<"Jase"<<"Jason"<<"Jasper"<<"Javier"<<"Javon"<<
"Jax"<<"Jaxon"<<"Jaxson"<<"Jay"<<"Jayce"<<"Jayden"<<"Jaydon"<<"Jaylen"<<"Jaylin"<<"Jaylon"<<
"Jayson"<<"Jeb"<<"Jebediah"<<"Jed"<<"Jediah"<<"Jedidiah"<<"Jeff"<<"Jefferson"<<"Jeffery"<<"Jeffrey"<<
"Jeffry"<<"Jensen"<<"Jenson"<<"Jerald"<<"Jeremiah"<<"Jeremy"<<"Jericho"<<"Jermaine"<<"Jerome"<<"Jerry"<<
"Jesse"<<"Jessie"<<"Jesus"<<"Jet"<<"Jethro"<<"Jett"<<"Jim"<<"Jimmie"<<"Jimmy"<<"Joachim"<<
"Joaquin"<<"Jody"<<"Joe"<<"Joel"<<"Joey"<<"Johan"<<"John"<<"Johnathan"<<"Johnathon"<<"Johnnie"<<
"Kenny"<<"Kent"<<"Kenton"<<"Kerry"<<"Kevin"<<"Khalid"<<"Khalil"<<"Kian"<<"Kiefer"<<"Kieran"<<
"Kieron"<<"Killian"<<"Kim"<<"Kingsley"<<"Kingston"<<"Kip"<<"Kiran"<<"Kirby"<<"Kirk"<<"Kit"<<
"Klaus"<<"Klay"<<"Knox"<<"Kobe"<<"Koby"<<"Kody"<<"Kolby"<<"Kris"<<"Krish"<<"Kristian"<<
"Kristoff"<<"Kristopher"<<"Kurt"<<"Kurtis"<<"Kye"<<"Kylar"<<"Kyle"<<"Kylen"<<"Kyler"<<"Kyran"<<
"Kyrin"<<"Kyron"<<"Lacey"<<"Lachlan"<<"Lake"<<"Lamar"<<"Lamont"<<"Lance"<<"Landen"<<"Landon"<<
"Landyn"<<"Lane"<<"Langdon"<<"Langston"<<"Larry"<<"Lars"<<"Laurence"<<"Laurie"<<"Lawrence"<<"Lawson"<<
"Layne"<<"Layton"<<"Leaf"<<"Leandro"<<"Lebron"<<"Lee"<<"Leigh"<<"Leighton"<<"Leland"<<"Lennie"<<
"Lennon"<<"Lennox"<<"Lenny"<<"Leo"<<"Leon"<<"Leonard"<<"Leonardo"<<"Leonel"<<"Leopold"<<"Leroy"<<
"Les"<<"Leslie"<<"Lester"<<"Leuan"<<"Lev"<<"Leven"<<"Levi"<<"Lewis"<<"Lex"<<"Liam"<<
"Lief"<<"Lincoln"<<"Link"<<"Linus"<<"Lionel"<<"Lisandro"<<"Lloyd"<<"Lochlan"<<"Logan"<<"Loki"<<
"Mario"<<"Marion"<<"Mark"<<"Marley"<<"Marlon"<<"Marquis"<<"Marshall"<<"Martin"<<"Marty"<<"Martyn"<<
"Marvin"<<"Mason"<<"Massimo"<<"Mat"<<"Mateo"<<"Mathew"<<"Matt"<<"Matthew"<<"Matthias"<<"Maurice"<<
"Mauricio"<<"Maverick"<<"Max"<<"Maxim"<<"Maximilian"<<"Maximus"<<"Maxwell"<<"Mehdi"<<"Mehtab"<<"Mekhi"<<
"Mel"<<"Melvin"<<"Merick"<<"Mervyn"<<"Micah"<<"Michael"<<"Micheal"<<"Mick"<<"Mickey"<<"Miguel"<<
"Mike"<<"Mikey"<<"Milan"<<"Miles"<<"Miller"<<"Milo"<<"Milton"<<"Misha"<<"Mitch"<<"Mitchell"<<
"Mitt"<<"Moe"<<"Mohamed"<<"Mohammad"<<"Mohammed"<<"Moises"<<"Monte"<<"Monty"<<"Mordecai"<<"Morgan"<<
"Morris"<<"Moses"<<"Muhammad"<<"Murphy"<<"Murray"<<"Myles"<<"Myron"<<"Nash"<<"Nasir"<<"Nate"<<
"Nath"<<"Nathan"<<"Nathanael"<<"Nathaniel"<<"Neal"<<"Ned"<<"Nehemiah"<<"Neil"<<"Nelson"<<"Nesbit"<<
"Nestor"<<"Neville"<<"Nevin"<<"Niall"<<"Nicholas"<<"Nick"<<"Nickolas"<<"Nicky"<<"Nico"<<"Nicolas"<<
"Nigel"<<"Niklaus"<<"Nikolai"<<"Nikolas"<<"Nile"<<"Nils"<<"Noah"<<"Noe"<<"Noel"<<"Nolan"<<
"Norbert"<<"Norman"<<"Oakes"<<"Oakley"<<"Octavio"<<"Oisin"<<"Olaf"<<"Oli"<<"Oliver"<<"Ollie"<<
"Olly"<<"Omar"<<"Oran"<<"Orion"<<"Orlando"<<"Orson"<<"Oscar"<<"Osvaldo"<<"Oswald"<<"Otis"<<
"Otto"<<"Owen"<<"Ozzie"<<"Ozzy"<<"Pablo"<<"Paco"<<"Paddy"<<"Padraig"<<"Palmer"<<"Paolo"<<
"Parker"<<"Pascal"<<"Pat"<<"Patrick"<<"Paul"<<"Paxton"<<"Payton"<<"Pearce"<<"Pedro"<<"Percy"<<
"Perry"<<"Petar"<<"Pete"<<"Peter"<<"Peyton"<<"Phebian"<<"Phil"<<"Philip"<<"Philippe"<<"Phillip"<<
"Phineas"<<"Phoenix"<<"Pierce"<<"Piers"<<"Pip"<<"Porter"<<"Poul"<<"Prakash"<<"Preston"<<"Prince"<<
"Princeton"<<"Quentin"<<"Quincy"<<"Quinlan"<<"Quinn"<<"Quinton"<<"Quintrell"<<"Rafael"<<"Rafferty"<<"Raheem"<<
"Rahul"<<"Raiden"<<"Raj"<<"Rajesh"<<"Ralph"<<"Ram"<<"Rameel"<<"Ramon"<<"Ramsey"<<"Randal"<<
"Randall"<<"Randolph"<<"Randy"<<"Raoul"<<"Raphael"<<"Rashad"<<"Rashan"<<"Rashid"<<"Raul"<<"Ravi"<<
"Ray"<<"Raylan"<<"Raymond"<<"Reece"<<"Reed"<<"Reef"<<"Reese"<<"Reggie"<<"Reginald"<<"Rehan"<<
"Rob"<<"Robbie"<<"Robby"<<"Robert"<<"Roberto"<<"Robin"<<"Rocco"<<"Rock"<<"Rocky"<<"Rod"<<
"Roderick"<<"Rodger"<<"Rodney"<<"Rodolfo"<<"Rodrigo"<<"Rogelio"<<"Roger"<<"Rohan"<<"Roland"<<"Rolando"<<
"Roman"<<"Romeo"<<"Ron"<<"Ronald"<<"Ronan"<<"Ronnie"<<"Ronny"<<"Roosevelt"<<"Rory"<<"Roscoe"<<
"Ross"<<"Rowan"<<"Roy"<<"Royce"<<"Ruairi"<<"Ruben"<<"Rubin"<<"Rudolph"<<"Rudy"<<"Rufus"<<
"Rupert"<<"Russ"<<"Russell"<<"Rusty"<<"Ryan"<<"Ryder"<<"Ryker"<<"Rylan"<<"Ryland"<<"Ryley"<<
"Sacha"<<"Said"<<"Salvador"<<"Salvatore"<<"Sam"<<"Samir"<<"Sammy"<<"Samson"<<"Samuel"<<"Sandeep"<<
"Seamus"<<"Sean"<<"Seb"<<"Sebastian"<<"Sebastien"<<"Sebestian"<<"Sergio"<<"Seth"<<"Shadrach"<<"Shane"<<
"Shannon"<<"Shaun"<<"Shawn"<<"Shay"<<"Shayne"<<"Shea"<<"Sheldon"<<"Shelton"<<"Sherlock"<<"Sherman"<<
"Shiloh"<<"Sid"<<"Sidney"<<"Silas"<<"Simeon"<<"Simon"<<"Sky"<<"Skylar"<<"Skyler"<<"Slade"<<
"Sol"<<"Solomon"<<"Sonny"<<"Soren"<<"Spencer"<<"Spike"<<"Stacey"<<"Stacy"<<"Stan"<<"Stanley"<<
"Stefan"<<"Stephan"<<"Stephen"<<"Sterling"<<"Steve"<<"Steven"<<"Stevie"<<"Stewart"<<"Stone"<<"Storm"<<
"Stuart"<<"Sufyan"<<"Sullivan"<<"Sven"<<"Sylvester"<<"Tadhg"<<"Talon"<<"Tam"<<"Tanner"<<"Tariq"<<
"Tarquin"<<"Tate"<<"Taylor"<<"Ted"<<"Teddy"<<"Teo"<<"Terence"<<"Terrance"<<"Terrell"<<"Terrence"<<
"Toby"<<"Tod"<<"Todd"<<"Tom"<<"Tomas"<<"Tommie"<<"Tommy"<<"Tony"<<"Torin"<<"Toryn"<<
"Trace"<<"Tracey"<<"Tracy"<<"Travis"<<"Tray"<<"Tremaine"<<"Trent"<<"Trenton"<<"Trevon"<<"Trevor"<<
"Trey"<<"Tristan"<<"Tristen"<<"Triston"<<"Troy"<<"Truman"<<"Tucker"<<"Ty"<<"Tyler"<<"Tyrese"<<
"Tyrone"<<"Tyson"<<"Ulysses"<<"Umar"<<"Uriah"<<"Uriel"<<"Usama"<<"Valentin"<<"Valentine"<<"Valentino"<<
"Van"<<"Vance"<<"Vasco"<<"Vaughn"<<"Vernon"<<"Victor"<<"Vidal"<<"Vihan"<<"Vijay"<<"Vikram"<<
"Wilbur"<<"Wiley"<<"Wilfred"<<"Wilhelm"<<"Will"<<"Willam"<<"Willard"<<"Willem"<<"William"<<"Willie"<<
"Willis"<<"Wilson"<<"Winston"<<"Wolfgang"<<"Woody"<<"Wyatt"<<"Xander"<<"Xavier"<<"Xerxes"<<"Yahir"<<
"Yardley"<<"Yehudi"<<"Yestin"<<"York"<<"Yuri"<<"Yusuf"<<"Yves"<<"Zac"<<"Zach"<<"Zachariah"<<
"Zachary"<<"Zachery"<<"Zack"<<"Zackary"<<"Zackery"<<"Zaiden"<<"Zain"<<"Zaine"<<"Zak"<<"Zander"<<
"Zane"<<"Zayden"<<"Zayn"<<"Zayne"<<"Zeb"<<"Zebulon"<<"Zed"<<"Zeke"<<"Zeph"<<"Ziggy"<<
"Zion"<<"Zoltan"<<"Zuriel"<<"Zylen"<<"Aaliyah"<<"Aarushi"<<"Abagail"<<"Abbey"<<"Abbi"<<"Abbie"<<"Abby"<<"Abi"<<"Abia"<<"Abigail"<<
"Abrianna"<<"Abrielle"<<"Aby"<<"Acacia"<<"Ada"<<"Adalia"<<"Adalyn"<<"Addie"<<"Addison"<<"Adelaide"<<
"Adele"<<"Adelene"<<"Adelia"<<"Adelina"<<"Adeline"<<"Adreanna"<<"Adriana"<<"Adrianna"<<"Adrianne"<<"Adrienne"<<
"Aerona"<<"Agatha"<<"Aggie"<<"Agnes"<<"Aida"<<"Aileen"<<"Ailsa"<<"Aimee"<<"Aine"<<"Ainsleigh"<<
"Alize"<<"Alka"<<"Allie"<<"Allison"<<"Ally"<<"Allyson"<<"Alma"<<"Alondra"<<"Alycia"<<"Alyshialynn"<<
"Alyson"<<"Alyssa"<<"Alyssia"<<"Amalia"<<"Amanda"<<"Amani"<<"Amara"<<"Amari"<<"Amaris"<<"Amaya"<<
"Amber"<<"Amberly"<<"Amelia"<<"Amelie"<<"America"<<"Amethyst"<<"Amie"<<"Amina"<<"Amirah"<<"Amity"<<
"Amy"<<"Amya"<<"Ana"<<"Anabel"<<"Anabelle"<<"Anahi"<<"Anais"<<"Anamaria"<<"Ananya"<<"Anastasia"<<
"Andie"<<"Andrea"<<"Andromeda"<<"Angel"<<"Angela"<<"Angelia"<<"Angelica"<<"Angelina"<<"Angeline"<<"Angelique"<<
"Angie"<<"Anika"<<"Anisa"<<"Anita"<<"Aniya"<<"Aniyah"<<"Anjali"<<"Ann"<<"Anna"<<"Annabel"<<
"Annabella"<<"Annabelle"<<"Annabeth"<<"Annalisa"<<"Annalise"<<"Anne"<<"Anneke"<<"Annemarie"<<"Annette"<<"Annie"<<
"Ava"<<"Avalon"<<"Avery"<<"Avril"<<"Aya"<<"Ayana"<<"Ayanna"<<"Ayesha"<<"Ayisha"<<"Ayla"<<
"Azalea"<<"Azaria"<<"Azariah"<<"Bailey"<<"Barbara"<<"Barbie"<<"Bay"<<"Baylee"<<"Bea"<<"Beatrice"<<
"Beatrix"<<"Becca"<<"Beccy"<<"Becky"<<"Belinda"<<"Bella"<<"Bellatrix"<<"Belle"<<"Benita"<<"Bernadette"<<
"Bernice"<<"Bertha"<<"Beryl"<<"Bess"<<"Beth"<<"Bethan"<<"Bethanie"<<"Bethany"<<"Betsy"<<"Bettina"<<
"Betty"<<"Beverly"<<"Beyonce"<<"Bianca"<<"Billie"<<"Blair"<<"Blaire"<<"Blake"<<"Blakely"<<"Blanche"<<
"Blaze"<<"Blessing"<<"Bliss"<<"Bloom"<<"Blossom"<<"Blythe"<<"Bobbi"<<"Bobbie"<<"Bobby"<<"Bonita"<<
"Bonnie"<<"Bonquesha"<<"Braelyn"<<"Brandi"<<"Brandy"<<"Braylee"<<"Brea"<<"Breanna"<<"Bree"<<"Breeze"<<
"Brenda"<<"Brenna"<<"Bria"<<"Briana"<<"Brianna"<<"Brianne"<<"Briar"<<"Bridget"<<"Bridgette"<<"Bridie"<<
"Carlie"<<"Carly"<<"Carlynn"<<"Carmel"<<"Carmela"<<"Carmen"<<"Carol"<<"Carole"<<"Carolina"<<"Caroline"<<
"Carolyn"<<"Carrie"<<"Carter"<<"Carys"<<"Casey"<<"Cassandra"<<"Cassia"<<"Cassidy"<<"Cassie"<<"Cat"<<
"Chenai"<<"Chenille"<<"Cher"<<"Cheri"<<"Cherie"<<"Cherry"<<"Cheryl"<<"Cheyanne"<<"Cheyenne"<<"Chiara"<<
"Chloe"<<"Chris"<<"Chrissy"<<"Christa"<<"Christabel"<<"Christal"<<"Christen"<<"Christi"<<"Christiana"<<"Christie"<<
"Christina"<<"Christine"<<"Christy"<<"Chrystal"<<"Ciara"<<"Cici"<<"Ciel"<<"Cierra"<<"Cindy"<<"Claire"<<
"Clara"<<"Clarabelle"<<"Clare"<<"Clarice"<<"Claris"<<"Clarissa"<<"Clarisse"<<"Clarity"<<"Clary"<<"Claudette"<<
"Claudia"<<"Claudine"<<"Clea"<<"Clementine"<<"Cleo"<<"Cleopatra"<<"Clodagh"<<"Clotilde"<<"Clover"<<"Coco"<<
"Colette"<<"Colleen"<<"Connie"<<"Constance"<<"Cora"<<"Coral"<<"Coralie"<<"Coraline"<<"Cordelia"<<"Cori"<<
"Corina"<<"Corinne"<<"Cornelia"<<"Corra"<<"Cosette"<<"Courtney"<<"Cressida"<<"Cristal"<<"Cristina"<<"Crystal"<<
"Delilah"<<"Della"<<"Delores"<<"Delphine"<<"Demetria"<<"Demi"<<"Dena"<<"Denise"<<"Denny"<<"Desiree"<<
"Destinee"<<"Destiny"<<"Diamond"<<"Diana"<<"Diane"<<"Dianna"<<"Dianne"<<"Dido"<<"Dina"<<"Dionne"<<
"Dior"<<"Dixie"<<"Dolly"<<"Dolores"<<"Dominique"<<"Donna"<<"Dora"<<"Doreen"<<"Doris"<<"Dorothy"<<
"Dot"<<"Drew"<<"Dulce"<<"Dusty"<<"Eabha"<<"Ebony"<<"Echo"<<"Eden"<<"Edie"<<"Edith"<<
"Edna"<<"Edwina"<<"Effie"<<"Eileen"<<"Eilidh"<<"Eimear"<<"Elaina"<<"Elaine"<<"Elana"<<"Eleanor"<<
"Electra"<<"Elektra"<<"Elen"<<"Elena"<<"Eliana"<<"Elin"<<"Elina"<<"Elinor"<<"Elisa"<<"Elisabeth"<<
"Elise"<<"Eliza"<<"Elizabeth"<<"Ella"<<"Elle"<<"Ellen"<<"Ellery"<<"Ellie"<<"Ellis"<<"Elly"<<
"Elodie"<<"Eloise"<<"Elora"<<"Elsa"<<"Elsie"<<"Elspeth"<<"Elva"<<"Elvira"<<"Elysia"<<"Elyza"<<
"Emanuela"<<"Ember"<<"Emelda"<<"Emely"<<"Emer"<<"Emerald"<<"Emerson"<<"Emilee"<<"Emilia"<<"Emilie"<<
"Emily"<<"Emma"<<"Emmalee"<<"Emmaline"<<"Emmalyn"<<"Emmanuelle"<<"Emmeline"<<"Emmie"<<"Emmy"<<"Enid"<<
"Enya"<<"Erica"<<"Erika"<<"Erin"<<"Eris"<<"Ernestine"<<"Eryn"<<"Esmay"<<"Esme"<<"Esmeralda"<<
"Esparanza"<<"Esperanza"<<"Estee"<<"Estelle"<<"Ester"<<"Esther"<<"Estrella"<<"Ethel"<<"Eugenie"<<"Eunice"<<
"Eva"<<"Evangelina"<<"Evangeline"<<"Eve"<<"Evelin"<<"Evelyn"<<"Everly"<<"Evie"<<"Evita"<<"Fabrizia"<<
"Faith"<<"Fallon"<<"Fanny"<<"Farah"<<"Farrah"<<"Fatima"<<"Fawn"<<"Fay"<<"Faye"<<"Felicia"<<
"Felicity"<<"Fern"<<"Fernanda"<<"Ffion"<<"Fifi"<<"Fiona"<<"Fleur"<<"Flick"<<"Flo"<<"Flora"<<
"Florence"<<"Fran"<<"Frances"<<"Francesca"<<"Francine"<<"Frankie"<<"Freda"<<"Freya"<<"Frida"<<"Gabby"<<
"Gabriela"<<"Gabriella"<<"Gabrielle"<<"Gail"<<"Garnet"<<"Gayle"<<"Gaynor"<<"Geena"<<"Gemma"<<"Gena"<<
"Genesis"<<"Genevieve"<<"Georgette"<<"Georgia"<<"Georgie"<<"Georgina"<<"Geraldine"<<"Gert"<<"Gertrude"<<"Gia"<<
"Gianna"<<"Gigi"<<"Gillian"<<"Gina"<<"Ginger"<<"Ginny"<<"Giovanna"<<"Gisela"<<"Giselle"<<"Gisselle"<<
"Gladys"<<"Glenda"<<"Glenys"<<"Gloria"<<"Glynis"<<"Golda"<<"Goldie"<<"Grace"<<"Gracelyn"<<"Gracie"<<
"Heather"<<"Heaven"<<"Heidi"<<"Helen"<<"Helena"<<"Helene"<<"Helga"<<"Helina"<<"Henrietta"<<"Hepsiba"<<
"Hera"<<"Hermione"<<"Hester"<<"Hetty"<<"Hilary"<<"Hilda"<<"Hillary"<<"Hollie"<<"Holly"<<"Honesty"<<
"Honey"<<"Honor"<<"Honour"<<"Hope"<<"Hyacinth"<<"Ianthe"<<"Ida"<<"Ila"<<"Ilene"<<"Iliana"<<
"Ilona"<<"Ilse"<<"Imani"<<"Imelda"<<"Imogen"<<"India"<<"Indie"<<"Indigo"<<"Indira"<<"Ines"<<
"Ingrid"<<"Iona"<<"Ira"<<"Irene"<<"Irina"<<"Iris"<<"Irma"<<"Isa"<<"Isabel"<<"Isabell"<<
"Isabella"<<"Isabelle"<<"Isadora"<<"Isha"<<"Isis"<<"Isla"<<"Isobel"<<"Isolde"<<"Itzel"<<"Ivana"<<
"Ivy"<<"Iyanna"<<"Izabella"<<"Izidora"<<"Izzie"<<"Izzy"<<"Jacinda"<<"Jacinta"<<"Jackie"<<"Jacqueline"<<
"Jacquelyn"<<"Jada"<<"Jade"<<"Jaden"<<"Jadyn"<<"Jaelynn"<<"Jaida"<<"Jaime"<<"Jamie"<<"Jamiya"<<
"Jan"<<"Jana"<<"Jancis"<<"Jane"<<"Janelle"<<"Janessa"<<"Janet"<<"Janette"<<"Jania"<<"Janice"<<
"Janie"<<"Janine"<<"Janis"<<"Janiya"<<"January"<<"Jaqueline"<<"Jasmin"<<"Jasmine"<<"Jaya"<<"Jayda"<<
"Jayden"<<"Jayla"<<"Jaylene"<<"Jaylinn"<<"Jaylynn"<<"Jayne"<<"Jazlyn"<<"Jazmin"<<"Jazmine"<<"Jazz"<<
"Jean"<<"Jeanette"<<"Jeanine"<<"Jeanne"<<"Jeannette"<<"Jeannie"<<"Jeannine"<<"Jemima"<<"Jemma"<<"Jen"<<
"Jo"<<"Joan"<<"Joann"<<"Joanna"<<"Joanne"<<"Jocelyn"<<"Jodi"<<"Jodie"<<"Jody"<<"Joelle"<<
"Johanna"<<"Joleen"<<"Jolene"<<"Jolie"<<"Joni"<<"Jordan"<<"Jordana"<<"Jordyn"<<"Jorja"<<"Joselyn"<<
"Josephine"<<"Josie"<<"Journey"<<"Joy"<<"Joyce"<<"Juanita"<<"Jude"<<"Judith"<<"Judy"<<"Jules"<<
"Julia"<<"Juliana"<<"Julianna"<<"Julianne"<<"Julie"<<"Julienne"<<"Juliet"<<"Juliette"<<"Julissa"<<"July"<<
"Karla"<<"Karlee"<<"Karly"<<"Karolina"<<"Karyn"<<"Kasey"<<"Kassandra"<<"Kassidy"<<"Kassie"<<"Kat"<<
"Katara"<<"Katarina"<<"Kate"<<"Katelyn"<<"Katelynn"<<"Katerina"<<"Katharine"<<"Katherine"<<"Kathleen"<<"Kathryn"<<
"Kathy"<<"Katia"<<"Katie"<<"Katlyn"<<"Katniss"<<"Katrina"<<"Katy"<<"Katya"<<"Kay"<<"Kaya"<<
"Kaye"<<"Kayla"<<"Kaylee"<<"Kayleigh"<<"Kayley"<<"Kaylie"<<"Kaylin"<<"Keara"<<"Keeley"<<"Keely"<<
"Keira"<<"Keisha"<<"Kelis"<<"Kelley"<<"Kelli"<<"Kellie"<<"Kelly"<<"Kelsey"<<"Kelsie"<<"Kendall"<<
"Kendra"<<"Kenna"<<"Kennedy"<<"Kenzie"<<"Kera"<<"Keri"<<"Kerian"<<"Kerri"<<"Kerry"<<"Kia"<<
"Kiana"<<"Kiara"<<"Kiera"<<"Kierra"<<"Kiersten"<<"Kiki"<<"Kiley"<<"Kim"<<"Kimberlee"<<"Kimberley"<<
"Kimberly"<<"Kimbriella"<<"Kimmy"<<"Kinley"<<"Kinsey"<<"Kinsley"<<"Kira"<<"Kirsten"<<"Kirstin"<<"Kirsty"<<
"Kitty"<<"Kizzy"<<"Kloe"<<"Kora"<<"Kori"<<"Kourtney"<<"Kris"<<"Krista"<<"Kristen"<<"Kristi"<<
"Kristie"<<"Kristin"<<"Kristina"<<"Kristine"<<"Kristy"<<"Krystal"<<"Kyla"<<"Kylee"<<"Kyleigh"<<"Kylie"<<
"Kyra"<<"Lacey"<<"Lacie"<<"Lacy"<<"Ladonna"<<"Laila"<<"Lainey"<<"Lakyn"<<"Lala"<<"Lana"<<
"Laney"<<"Lara"<<"Larissa"<<"Latoya"<<"Laura"<<"Laurel"<<"Lauren"<<"Laurie"<<"Lauryn"<<"Lavana"<<
"Lavender"<<"Lavinia"<<"Layla"<<"Lea"<<"Leah"<<"Leandra"<<"Leann"<<"Leanna"<<"Leanne"<<"Lee"<<
"Lexie"<<"Lexis"<<"Leyla"<<"Lia"<<"Liana"<<"Lianne"<<"Libbie"<<"Libby"<<"Liberty"<<"Lidia"<<
"Liesl"<<"Lila"<<"Lilac"<<"Lilah"<<"Lili"<<"Lilian"<<"Liliana"<<"Lilita"<<"Lilith"<<"Lillia"<<
"Lillian"<<"Lillie"<<"Lilly"<<"Lily"<<"Lina"<<"Linda"<<"Lindsay"<<"Lindsey"<<"Lindy"<<"Lisa"<<
"Lisette"<<"Liv"<<"Livia"<<"Livvy"<<"Liz"<<"Liza"<<"Lizbeth"<<"Lizette"<<"Lizzie"<<"Lizzy"<<
"Logan"<<"Lois"<<"Lola"<<"Lolita"<<"London"<<"Lora"<<"Loran"<<"Lorelei"<<"Loren"<<"Lorena"<<
"Loretta"<<"Lori"<<"Lorie"<<"Lorna"<<"Lorraine"<<"Lorri"<<"Lorrie"<<"Lottie"<<"Lotus"<<"Lou"<<
"Louella"<<"Louisa"<<"Louise"<<"Luann"<<"Lucia"<<"Luciana"<<"Lucie"<<"Lucille"<<"Lucinda"<<"Lucky"<<
"Lucy"<<"Luisa"<<"Lulu"<<"Luna"<<"Lupita"<<"Luz"<<"Lydia"<<"Lyla"<<"Lynda"<<"Lyndsey"<<
"Mackenzie"<<"Macy"<<"Madalyn"<<"Maddie"<<"Maddison"<<"Maddy"<<"Madeleine"<<"Madeline"<<"Madelyn"<<"Madison"<<
"Madisyn"<<"Madonna"<<"Madyson"<<"Mae"<<"Maeve"<<"Magda"<<"Magdalena"<<"Magdalene"<<"Maggie"<<"Maia"<<
"Maire"<<"Mairead"<<"Maisie"<<"Maisy"<<"Maja"<<"Makayla"<<"Makenna"<<"Makenzie"<<"Malia"<<"Malina"<<
"Margret"<<"Maria"<<"Mariah"<<"Mariam"<<"Marian"<<"Mariana"<<"Marianna"<<"Marianne"<<"Maribel"<<"Marie"<<
"Mariela"<<"Mariella"<<"Marilyn"<<"Marina"<<"Marion"<<"Marisa"<<"Marisol"<<"Marissa"<<"Maritza"<<"Marjorie"<<
"Marla"<<"Marlee"<<"Marlena"<<"Marlene"<<"Marley"<<"Marnie"<<"Marsha"<<"Martha"<<"Martina"<<"Mary"<<
"Miranda"<<"Miriam"<<"Mirielle"<<"Missie"<<"Misty"<<"Mitzi"<<"Moira"<<"Mollie"<<"Molly"<<"Mona"<<
"Monica"<<"Monika"<<"Monique"<<"Montana"<<"Montserrat"<<"Morgan"<<"Morgana"<<"Moya"<<"Muriel"<<"Mya"<<
"Myfanwy"<<"Myla"<<"Myra"<<"Myrna"<<"Myrtle"<<"Nadene"<<"Nadia"<<"Nadine"<<"Naja"<<"Nala"<<
"Nana"<<"Nancy"<<"Nanette"<<"Naomi"<<"Natalia"<<"Natalie"<<"Natasha"<<"Naya"<<"Nayeli"<<"Nell"<<
"Nellie"<<"Nelly"<<"Nena"<<"Nerissa"<<"Nessa"<<"Nevaeh"<<"Neve"<<"Nia"<<"Niamh"<<"Nichola"<<
"Nichole"<<"Nicki"<<"Nicky"<<"Nicola"<<"Nicole"<<"Nicolette"<<"Nieve"<<"Niki"<<"Nikita"<<"Nikki"<<
"Nila"<<"Nina"<<"Nishka"<<"Noelle"<<"Noemi"<<"Nola"<<"Nora"<<"Norah"<<"Noreen"<<"Norma"<<
"Nova"<<"Nyla"<<"Oasis"<<"Ocean"<<"Octavia"<<"Odalis"<<"Odalys"<<"Odele"<<"Odelia"<<"Odette"<<
"Olga"<<"Olive"<<"Olivia"<<"Oona"<<"Oonagh"<<"Opal"<<"Ophelia"<<"Oprah"<<"Oriana"<<"Orianna"<<
"Orla"<<"Orlaith"<<"Page"<<"Paige"<<"Paisley"<<"Paloma"<<"Pam"<<"Pamela"<<"Pandora"<<"Pansy"<<
"Paola"<<"Paris"<<"Patience"<<"Patrice"<<"Patricia"<<"Patsy"<<"Patti"<<"Patty"<<"Paula"<<"Paulette"<<
"Paulina"<<"Pauline"<<"Payton"<<"Peace"<<"Pearl"<<"Peggy"<<"Penelope"<<"Penny"<<"Perla"<<"Perrie"<<
"Persephone"<<"Petra"<<"Petunia"<<"Peyton"<<"Phillipa"<<"Philomena"<<"Phoebe"<<"Phoenix"<<"Phyllis"<<"Piper"<<
"Pippa"<<"Pixie"<<"Polly"<<"Pollyanna"<<"Poppy"<<"Portia"<<"Precious"<<"Presley"<<"Preslie"<<"Primrose"<<
"Renata"<<"Rene"<<"Renee"<<"Renesmee"<<"Reyna"<<"Rhea"<<"Rhian"<<"Rhianna"<<"Rhiannon"<<"Rhoda"<<
"Rhona"<<"Rhonda"<<"Ria"<<"Rianna"<<"Ricki"<<"Rihanna"<<"Rikki"<<"Riley"<<"Rita"<<"River"<<
"Rosella"<<"Rosemarie"<<"Rosemary"<<"Rosetta"<<"Rosie"<<"Rosy"<<"Rowan"<<"Rowena"<<"Roxana"<<"Roxanne"<<
"Roxie"<<"Roxy"<<"Rozlynn"<<"Ruby"<<"Rue"<<"Ruth"<<"Ruthie"<<"Ryanne"<<"Rydel"<<"Rylee"<<
"Ryleigh"<<"Rylie"<<"Sabina"<<"Sabine"<<"Sable"<<"Sabrina"<<"Sade"<<"Sadhbh"<<"Sadie"<<"Saffron"<<
"Safire"<<"Safiya"<<"Sage"<<"Sahara"<<"Saige"<<"Saira"<<"Sally"<<"Salma"<<"Salome"<<"Sam"<<
"Samantha"<<"Samara"<<"Samia"<<"Samira"<<"Sammie"<<"Sammy"<<"Sandra"<<"Sandy"<<"Sania"<<"Saoirse"<<
"Sapphire"<<"Sara"<<"Sarah"<<"Sarina"<<"Sariya"<<"Sascha"<<"Sasha"<<"Saskia"<<"Savanna"<<"Savannah"<<
"Scarlet"<<"Scarlett"<<"Sebastianne"<<"Selah"<<"Selena"<<"Selene"<<"Selina"<<"Selma"<<"Senuri"<<"September"<<
"Seren"<<"Serena"<<"Serenity"<<"Shakira"<<"Shana"<<"Shania"<<"Shannon"<<"Shari"<<"Sharon"<<"Shary"<<
"Sloane"<<"Snow"<<"Sofia"<<"Sofie"<<"Sondra"<<"Sonia"<<"Sonja"<<"Sonya"<<"Sophia"<<"Sophie"<<
"Sophy"<<"Sorrel"<<"Spring"<<"Stacey"<<"Staci"<<"Stacie"<<"Stacy"<<"Star"<<"Starla"<<"Stefanie"<<
"Stella"<<"Steph"<<"Stephanie"<<"Sue"<<"Sugar"<<"Suki"<<"Summer"<<"Susan"<<"Susanna"<<"Susannah"<<
"Susanne"<<"Susie"<<"Sutton"<<"Suzanna"<<"Suzanne"<<"Suzette"<<"Suzie"<<"Suzy"<<"Sybil"<<"Sydney"<<
"Sylvia"<<"Sylvie"<<"Tabatha"<<"Tabitha"<<"Tagan"<<"Tahlia"<<"Tala"<<"Talia"<<"Talitha"<<"Taliyah"<<
"Tallulah"<<"Tamara"<<"Tamera"<<"Tami"<<"Tamia"<<"Tamika"<<"Tammi"<<"Tammie"<<"Tammy"<<"Tamra"<<
"Tamsin"<<"Tania"<<"Tanika"<<"Tanisha"<<"Tanya"<<"Tara"<<"Taryn"<<"Tasha"<<"Tasmin"<<"Tatiana"<<
"Tiffany"<<"Tilly"<<"Tina"<<"Tisha"<<"Toni"<<"Tonia"<<"Tonya"<<"Tori"<<"Tracey"<<"Traci"<<
"Tracie"<<"Tracy"<<"Tricia"<<"Trina"<<"Trinity"<<"Trish"<<"Trisha"<<"Trista"<<"Trixie"<<"Trixy"<<
"Trudy"<<"Tula"<<"Tulip"<<"Tyra"<<"Ulrica"<<"Uma"<<"Una"<<"Ursula"<<"Valentina"<<"Valeria"<<
"Vicki"<<"Vickie"<<"Vicky"<<"Victoria"<<"Vienna"<<"Viola"<<"Violet"<<"Violetta"<<"Virginia"<<"Vivian"<<
"Viviana"<<"Vivien"<<"Vivienne"<<"Wallis"<<"Wanda"<<"Waverley"<<"Wendi"<<"Wendy"<<"Whitney"<<"Wilhelmina"<<
"Willa"<<"Willow"<<"Wilma"<<"Winnie"<<"Winnifred"<<"Winona"<<"Winter"<<"Xandra"<<"Xanthe"<<"Xaviera"<<
"Xena"<<"Xia"<<"Ximena"<<"Xochil"<<"Xochitl"<<"Yasmin"<<"Yasmine"<<"Yazmin"<<"Yelena"<<"Yesenia"<<
"Yolanda"<<"Ysabel"<<"Yulissa"<<"Yvaine"<<"Yvette"<<"Yvonne"<<"Zada"<<"Zaheera"<<"Zahra"<<"Zaira"<<
"Zendaya"<<"Zia"<<"Zina"<<"Ziva"<<"Zoe"<<"Zoey"<<"Zola"<<"Zora"<<"Zoya"<<"Zula"<<
"Zuri"<<"Zyana");

QStringList surname = (QStringList()<<"Abell"<<"Ackworth"<<"Adams"<<"Addicock"<<"Alban"<<"Aldebourne"<<"Alfray"<<"Alicock"<<"Allard"<<"Allen"<<
"Allington"<<"Amberden"<<"Amcotts"<<"Amondsham"<<"Andrews"<<"Annesley"<<"Ansty"<<"Archer"<<"Ardall"<<"Ardern"<<
"Argentein"<<"Arnold"<<"Arthur"<<"Asger"<<"Ashby"<<"Ashcombe"<<"Ashenhurst"<<"Ashton"<<"Askew"<<"Asplin"<<
"Astley"<<"Atherton"<<"Atkinson"<<"Atlee"<<"Attilburgh"<<"Aubrey"<<"Audeley"<<"Audlington"<<"Ayde"<<"Ayleward"<<
"Barstaple"<<"Bartelot"<<"Barton"<<"Basset"<<"Bathurst"<<"Battersby"<<"Battle"<<"Baynton"<<"Beauchamp"<<"Beaumont"<<
"Beaurepaire"<<"Beckingham"<<"Bedell"<<"Bedgberry"<<"Bedingfeld"<<"Beer"<<"Beeton"<<"Bell"<<"Bend"<<"Bennet"<<
"Bishopson"<<"Bishoptree"<<"Blacknall"<<"Blackwell"<<"Bladewell"<<"Blakeley"<<"Blennerhayset"<<"Blexham"<<"Blodwell"<<
"Bloom"<<"Blount"<<"Blundell"<<"Boddenham"<<"Bohan"<<"Boote"<<"Boothe"<<"Borrell"<<"Borrow"<<"Bosby"<<"Bost"<<"Bostock"<<
"Boston"<<"Bothy"<<"Botteler"<<"Boulder"<<"Bourne"<<"Boville"<<"Bowcer"<<"Bowett"<<"Bownell"<<"Bowyar"<<"Bradbridge"<<
"Brownflet"<<"Browning"<<"Brudenell"<<"Bryan"<<"Buckingham"<<"Bulkeley"<<"Bulstrode"<<"Burgess"<<"Burgh"<<"Burghill"<<
"Caley"<<"Callthorpe"<<"Campden"<<"Canon"<<"Cantilupe"<<"Carbonall"<<"Cardiff"<<"Carew"<<"Carlyle"<<"Carter"<<"Cassy"<<
"Castell"<<"Castletown"<<"Catesby"<<"Cavell"<<"Caxton"<<"Cely"<<"Chamberlain"<<"Champneys"<<"Chanceller"<<"Chandler"<<
"Chapman"<<"Charles"<<"Chase"<<"Chatwyn"<<"Chauncey"<<"Cheddar"<<"Chelsey"<<"Chernock"<<"Chester"<<"Chetwood"<<
"Cheverell"<<"Cheyne"<<"Chichester"<<"Child"<<"Chilton"<<"Chowne"<<"Chudderley"<<"Church"<<"Churmond"<<"Clark"<<
"Clavell"<<"Claybrook"<<"Clement"<<"Clerk"<<"Clifford"<<"Clifton"<<"Clitherow"<<"Clopton"<<"Cobb"<<"Cobham"<<"Cobley"<<
"Cockayne"<<"Cod"<<"Coddington"<<"Coffin"<<"Coggshall"<<"Colby"<<"Cole"<<"Colkins"<<"Collard"<<"Colmer"<<"Colt"<<
"Colthurst"<<"Complin"<<"Compton"<<"Conquest"<<"Cooke"<<"Coorthopp"<<"Coppinger"<<"Corbett"<<"Corby"<<"Cossington"<<
"Cosworth"<<"Cotton"<<"Courtenay"<<"Covert"<<"Cowill"<<"Cox"<<"Crane"<<"Cranford"<<"Crawley"<<"Cressy"<<"Crickett"<<
"Cripps"<<"Crisp"<<"Cristemas"<<"Crocker"<<"Crugg"<<"Cuddon"<<"Culpepper"<<"Cunningham"<<"Curtis"<<"Curzon"<<"Dagworth"<<
"Dale"<<"Dalingridge"<<"Damsell"<<"Danett"<<"Danvers"<<"Darcy"<<"Darley"<<"Daubernon"<<"Daunce"<<"Dauncey"<<"Daundelyon"<<
"Davy"<<"Dawne"<<"Day"<<"Deacons"<<"Dean"<<"Deering"<<"Delabere"<<"Delamere"<<"Delly"<<"Dencourt"<<"Dennis"<<"Denton"<<
"Dericott"<<"Derington"<<"Desford"<<"Digby"<<"Dimmock"<<"Dinley"<<"Dixton"<<"Doddle"<<"Dogmersfield"<<"Donnett"<<"Doreward"<<
"Dormer"<<"Dove"<<"Dow"<<"Downer"<<"Draper"<<"Draw"<<"Drayton"<<"Dryden"<<"Dryland"<<"Dunch"<<"Duncombe"<<"Dunham"<<
"Estbury"<<"Eston"<<"Etchingham"<<"Etton"<<"Everard"<<"Everdon"<<"Evingar"<<"Eyer"<<"Eyston"<<"Fabian"<<"Faldo"<<"Fane"<<
"Flexney"<<"Flower"<<"Fodd"<<"Fogg"<<"Foliot"<<"Foljambe"<<"Follon"<<"Follywolle"<<"Folsham"<<"Fonteyn"<<"Ford"<<"Forder"<<
"Fortescue"<<"Fortey"<<"Fowler"<<"Fox"<<"Francey"<<"Franklin"<<"Fraunces"<<"Freen"<<"Freer"<<"Freville"<<"Frewell"<<"Frilende"<<
"Frilleck"<<"Frith"<<"Froggenhall"<<"Fromond"<<"Froste"<<"Frowseloure"<<"Frye"<<"Fulburne"<<"Fulmer"<<"Furnace"<<"Gage"<<
"Gerard"<<"Gerville"<<"Geste"<<"Gibbs"<<"Gifford"<<"Gilbert"<<"Gill"<<"Ginter"<<"Gisborne"<<"Gittens"<<"Glennon"<<"Glover"<<
"Gobberd"<<"Goddam"<<"Godfrey"<<"Gold"<<"Golding"<<"Goldwell"<<"Gomershall"<<"Gomfrey"<<"Gonson"<<"Good"<<"Goodenouth"<<"Gooder"<<
"Goodwin"<<"Goring"<<"Gorney"<<"Gorst"<<"Gosebourne"<<"Grafton"<<"Gray"<<"Greene"<<"Greenway"<<"Grenefeld"<<"Greville"<<"Grey"<<
"Grimbald"<<"Grobbam"<<"Grofhurst"<<"Groston"<<"Grove"<<"Guildford"<<"Hackman"<<"Haddock"<<"Haddon"<<"Hadresham"<<"Hakebourne"<<
"Hale"<<"Hall"<<"Halley"<<"Hambard"<<"Hammer"<<"Hammond"<<"Hampden"<<"Hancock"<<"Hansart"<<"Harbird"<<"Harbottle"<<"Harcourt"<<
"Hardy"<<"Harewell"<<"Hargreve"<<"Harlakinden"<<"Harleston"<<"Harley"<<"Harpeden"<<"Harper"<<"Harris"<<"Harte"<<"Harvard"<<
"Harwood"<<"Hasard"<<"Hatch"<<"Hatcliff"<<"Hautreeve"<<"Hawkins"<<"Hawksworth"<<"Hawtrey"<<"Haye"<<"Hayes"<<"Hayton"<<"Helm"<<
"Henshawe"<<"Herleston"<<"Heron"<<"Hertcomb"<<"Hervey"<<"Heydon"<<"Heywood"<<"Heyworth"<<"Higden"<<"Highgate"<<"Hilderley"<<
"Hill"<<"Hinson"<<"Hitchcock"<<"Hoare"<<"Hobart"<<"Hodgson"<<"Holbrook"<<"Holcott"<<"Holland"<<"Holsey"<<"Holt"<<"Holton"<<
"Hopton"<<"Horman"<<"Hornebolt"<<"Hornley"<<"Horsey"<<"Horthall"<<"Horton"<<"Hosteler"<<"Hotham"<<"Howard"<<"Huddleston"<<
"Hugeford"<<"Hughes"<<"Hungate"<<"Hurst"<<"Hussey"<<"Hutchinson"<<"Hyde"<<"Inwood"<<"Isley"<<"Jackmann"<<"Jackson"<<"James"<<
"Janner"<<"Jarman"<<"Jay"<<"Jendring"<<"Jenney"<<"Johnson"<<"Jordan"<<"Joslin"<<"Joulon"<<"Jowchet"<<"Keckilpenny"<<"Kellett"<<
"Kelly"<<"Kemp"<<"Kent"<<"Keriell"<<"Kesteven"<<"Key"<<"Kidwelly"<<"Killigrew"<<"Killingworth"<<"Kinge"<<"Kirkeby"<<"Kitson"<<
"Knighton"<<"Knivetton"<<"Knody"<<"Knoyll"<<"Knyvett"<<"Kottow"<<"la Barre"<<"la Hale"<<"la Penne"<<"Lacy"<<"Lambert"<<
"Lloyd"<<"Lockton"<<"Loddington"<<"Lond"<<"London"<<"Long"<<"Longton"<<"Lovell"<<"Loveney"<<"Lowth"<<"Lucy"<<"Ludsthorp"<<"Luke"<<
"Mayne"<<"Maynwaring"<<"Mead"<<"Medeley"<<"Merden"<<"Mereworth"<<"Merstun"<<"Merton"<<"Metcalf"<<"Michelgrove"<<"Middleton"<<"Mill"<<
"Millet"<<"Millis"<<"Milner"<<"Milsent"<<"Moland"<<"Molins"<<"Molyngton"<<"Monde"<<"Montacute"<<"Montagu"<<"Moore"<<"More"<<
"Morecott"<<"Morley"<<"Morris"<<"Mortimer"<<"Moryet"<<"Motesfont"<<"Mowfurth"<<"Mugg"<<"Mullens"<<"Muston"<<"Narbridge"<<"Nash"<<
"Neale"<<"Nevinson"<<"Newdegate"<<"Newman"<<"Noke"<<"Norbury"<<"Norden"<<"Norris"<<"North"<<"Northwood"<<"Norton"<<"Norwich"<<
"Norwood"<<"Notfeld"<<"Nottingham"<<"Nysell"<<"Obson"<<"Oke"<<"Oken"<<"Olingworth"<<"Oliver"<<"Osborne"<<"Osillbury"<<"Osteler"<<
"Outlawe"<<"Oxenbrigg"<<"Page"<<"Pagg"<<"Palmer"<<"Panshawe"<<"Papley"<<"Parker"<<"Parrett"<<"Parris"<<"Parsons"<<"Paston"<<"Payne"<<
"Peacock"<<"Peck"<<"Peckham"<<"Peel"<<"Pelletoot"<<"Peltie"<<"Pemberton"<<"Penhallick"<<"Pennebrygg"<<"Perchehay"<<"Perris"<<
"Philips"<<"Polton"<<"Porter"<<"Portington"<<"Potter"<<"Powlett"<<"Pownder"<<"Pratt"<<"Pray"<<"Prelate"<<"Prophet"<<"Prowd"<<
"Purles"<<"Pursglove"<<"Quintin"<<"Radley"<<"Rampston"<<"Ramsey"<<"Ratcliff"<<"Raudell"<<"Rawlin"<<"Rawson"<<"Raynsford"<<"Redman"<<
"Reed"<<"Reeve"<<"Reynes"<<"Richeman"<<"Rickhill"<<"Rickworth"<<"Ringer"<<"Rippringham"<<"Risley"<<"Robbins"<<"Roberts"<<"Robertson"<<
"Robinson"<<"Rochester"<<"Rochforth"<<"Roland"<<"Rolleston"<<"Rondel"<<"Ront"<<"Roper"<<"Rous"<<"Rowdon"<<"Rowe"<<"Rowlett"<<
"Rowley"<<"Rudhall"<<"Rufford"<<"Ruggenall"<<"Ruggwain"<<"Rusch"<<"Russell"<<"Ryall"<<"Sacheverell"<<"Sackville"<<"Sadler"<<
"Saintaubin"<<"Saintjohn"<<"Salford"<<"Salman"<<"Salter"<<"Saltonstall"<<"Sampson"<<"Samuell"<<"Sanburne"<<"Sandys"<<
"Saunders"<<"Saunterton"<<"Savill"<<"Sayer"<<"Saynsberry"<<"Scarcliff"<<"Scobahull"<<"Scolfield"<<"Scott"<<"Scroggs"<<"Scrope"<<
"Sedley"<<"Selwyn"<<"Serche"<<"Sever"<<"Seymour"<<"Seys"<<"Sharman"<<"Shawe"<<"Sheffield"<<"Sheraton"<<"Sherbourne"<<"Sherman"<<
"Silvester"<<"Simeon"<<"Simmons"<<"Sinclair"<<"Skern"<<"Skipwith"<<"Sleaford"<<"Slyfield"<<"Smith"<<"Snayth"<<"Snell"<<"Snelling"<<
"Sotton"<<"Sparrow"<<"Spebbington"<<"Speir"<<"Spelman"<<"Spencer"<<"Spettell"<<"Spicer"<<"Sprottle"<<"Sprunt"<<"Stacy"<<"Stanbury"<<
"Strader"<<"Strangewayes"<<"Street"<<"Strelley"<<"Stubb"<<"Styles"<<"Sulyard"<<"Sumner"<<"Swan"<<"Sweetecok"<<"Swetenham"<<"Switt"<<
"Tabard"<<"Tame"<<"Taylor"<<"Tedcastle"<<"Thomas"<<"Thornburgh"<<"Thorne"<<"Thornton"<<"Thorpe"<<"Throckmorton"<<"Thursby"<<"Tibbord"<<
"Tilghman"<<"Tindall"<<"Tiploft"<<"Topsfield"<<"Torrington"<<"Totthill"<<"Town"<<"Tregonwell"<<"Trenowyth"<<"Trevett"<<"Trumpington"<<
"Tubney"<<"Turner"<<"Twarby"<<"Tweedy"<<"Tyrell"<<"Ufford"<<"Underhill"<<"Unton"<<"Upton"<<"Urswick"<<"Vaughan"<<"Vawdrey"<<"Veldon"<<
"Verney"<<"Vernon"<<"Vinter"<<"Wade"<<"Wadham"<<"Wake"<<"Waldegrave"<<"Waldeley"<<"Walden"<<"Walford"<<"Walker"<<"Wallace"<<"Walrond"<<
"Walsch"<<"Waltham"<<"Walton"<<"Wantell"<<"Warbulton"<<"Warde"<<"Wardyworth"<<"Warner"<<"Warren"<<"Wayte"<<"Webb"<<"Weeks"<<"Welbeck"<<
"Welby"<<"Wellins"<<"Wenman"<<"Wensley"<<"West"<<"Westbrook"<<"Westlake"<<"Weston"<<"Wetherden"<<"Wexcombe"<<"White"<<"Whitewood"<<
"Williams"<<"Willis"<<"Willmer"<<"Wilmot"<<"Wilson"<<"Windham"<<"Wingfield"<<"Winkle"<<"Winston"<<"Winstringham"<<"Winter"<<"Wiseman"<<
"Wood"<<"Wyatt"<<"Wyghtham"<<"Wylde"<<"Wymer"<<"Wyville"<<"Yate"<<"Yaxley"<<"Yelverton"<<"Yornold"<<"Young");

QStringList rusNoun = (QStringList()<<"Астрономия"<<"Аллегория"<<"Аллюзия"<<"Анатомия"<<"Амфибия"<<"Акция"<<"Акация"<<"Антрессоль"<<"Агония"<<"Академия"<<"Аудитория"<<"Антология"<<
"Буря"<<"Боль"<<"Бакалея"<<"Булавка"<<"Булава"<<"Бельгия"<<"Борода"<<"Белка"<<"Буква"<<
"Вера"<<"Вина"<<"Воля"<<"Вода"<<"Влага"<<"Венгрия"<<"Весна"<<"Вилка"<<"Ворона"<<"Война"<<"Волна"<<
"Гиря"<<"Гроза"<<"Граната"<<"Гора"<<"Гиена"<<"Глупость"<<"Грусть"<<
"Дама"<<"Доля"<<"Дата"<<"Доска"<<"Драгоценность"<<"Деревня"<<"Длина"<<
"Ерунда"<<
"Жизнь"<<"Жажда"<<"Жара"<<"Жадность"<<"Жалость"<<"Жена"<<
"Заря"<<"Зима"<<"Земля"<<"Зоология"<<"Змея"<<"Защита"<<
"Игра"<<"Игла"<<"Икра"<<"Ирригация"<<"Иллюминация"<<"Иллюзия"<<"Импликация"<<"История"<<
"Кара"<<"Краткость"<<"Котлета"<<"Кухня"<<"Курица"<<"Капля"<<"Красота"<<"Красавица"<<"Комната"<<"Карта"<<
"Лодка"<<"Ложка"<<"Люстра"<<"Ладонь"<<"Лиса"<<
"Милость"<<"Милосердие"<<"Малодушие"<<"Мать"<<"Молодость"<<"Мудрость"<<"Мышь"<<"Метель"<<"Мечта"<<
"Настойчивость"<<"Невозмутимость"<<"Находчивость"<<"Надежда"<<"Неукротимость"<<"Неуязвимость"<<"Необходимость"<<"Нужда"<<"Нога"<<"Новость"<<"Неделя"<<
"Опасность"<<"Осторожность"<<"Она"<<"Оливка"<<"Оплата"<<"Остановка"<<"Охота"<<
"Печаль"<<"Путаница"<<"Помощь"<<"Помощница"<<"Погода"<<"Пудра"<<"Пурга"<<"Панама"<<"Пирамида"<<"Плата"<<"Палата"<<"Пустыня"<<"Покупка"<<"Продажа"<<"Поддержка"<<"Передача"<<"Песнь"<<
"Радость"<<"Регенерация"<<"Революция"<<"Россия"<<
"Старость"<<"Столовая"<<"Сфера"<<"Скромность"<<"Стена"<<"Ссуда"<<"Синица"<<"Стрела"<<"Стрелка"<<
"Тоска"<<"Тарелка"<<"Тундра"<<"Тайга"<<"Тайна"<<
"Уязвимость"<<"Улитка"<<"Услада"<<"Утечка"<<"Унижение"<<
"Фаза"<<"Фигура"<<"Форма"<<
"Хартия"<<
"Ценность"<<"Цена"<<"Целеустремленность"<<"Цель"<<
"Чума"<<"Чаша"<<
"Щука"<<"Ширма"<<
"Эпидемия"<<"Эволюция"<<"Энциклопедия"<<
"Юрта"<<"Яхта");

QStringList rusActNoun = (QStringList()<<"Арест"<<
"Бросок"<<"Бег"<<
"Возрождение"<<"Восстановление"<<
"Достижение"<<
"Захват"<<"Завоевание"<<"Закрытие"<<"Замена"<<
"Изменение"<<"Идентификация"<<"Исчезновение"<<
"Крушение"<<"Копирование"<<
"Минимизация"<<"Маневр"<<
"Наращивание"<<"Наслаждение"<<
"Обман"<<"Обгон"<<"Открытие"<<"Обучение"<<"Откровение"<<
"Предложение"<<"Приостановка"<<"Преследование"<<"Перевод"<<"Переживания"<<"Падение"<<"Полет"<<"Побег"<<"Прослушивание"<<"Поимка"<<"Переименование"<<"Прием"<<
"Рождение"<<"Развитие"<<
"Старение"<<"Страдания"<<"Стремление"<<
"Уничтожение"<<"Установка");

QStringList rusNounGen = (QStringList()<<"Амфибии"<<"Академии"<<"Аудитории"<<
"Бури"<<"Боли"<<"Бороды"<<"Богов"<<"Буквы"<<"Биржи"<<
"Веры"<<"Воды"<<"Весны"<<"Ворона"<<"Войны"<<"Волны"<<
"Грозы"<<"Горы"<<"Глупости"<<"Грусти"<<"Города"<<"Гречи"<<
"Дамы"<<"Даты"<<"Детей"<<"Денег"<<"Дровосека"<<
"Еды"<<"Егеря"<<
"Жизни"<<"Жажды"<<"Жары"<<"Жадности"<<"Жены"<<
"Зари"<<"Зимы"<<"Земли"<<"Защиты"<<"Золота"<<
"Игры"<<"Иллюзий"<<"Истории"<<
"Кухни"<<"Красоты"<<"Красавицы"<<"Комнаты"<<"Карты"<<"Кошек"<<
"Ладони"<<"Лисы"<<"Людей"<<"Лет"<<"Ледников"<<
"Милости"<<"Милосердия"<<"Молодости"<<"Мудрости"<<"Мыши"<<"Мечты"<<"Мужчин"<<"Молодежи"<<"Москвы"<<"Мира"<<
"Надежды"<<"Нужды"<<"Ноги"<<"Новости"<<"Недели"<<
"Опасности"<<"Осторожности"<<"Оливки"<<"Оплаты"<<"Остановки"<<"Охоты"<<"Окна"<<"Оружия"<<"Океанов"<<
"Печали"<<"Путаницы"<<"Помощи"<<"Помощницы"<<"Погоды"<<"Пирамид"<<"Пустыни"<<"Продажи"<<"Поддержки"<<"Прощаний"<<"Песни"<<"Причин"<<"Последствий"<<
"Радости"<<"Революции"<<
"Старости"<<"Сферы"<<"Скромности"<<"Стены"<<"Стрелы"<<"Секретов"<<"Собак"<<"Солдата"<<
"Тоски"<<"Тайги"<<"Тайны"<<
"Уязвимости"<<"Улитки"<<"Утечки"<<"Унижения"<<
"Фотона"<<"Фонтана"<<"Фонарей"<<
"Хартии"<<
"Ценностей"<<"Цены"<<"Цели"<<
"Чумы"<<"Чувств"<<
"Шума"<<"Шахтеров"<<
"Эпидемии"<<"Эволюции"<<
"Яхты");

QStringList rusAdjective = (QStringList()<<"Беззаботная"<<"Баснословная"<<"Богатая"<<"Бедная"<<"Большая"<<"Белая"<<
"Водная"<<"Веселая"<<"Вводная"<<"Вечерняя"<<"Вторая"<<
"Годная"<<"Грядущая"<<"Грозная"<<"Готовая"<<"Говорящая"<<"Гордая"<<"Гиблая"<<"Громкая"<<
"Добрая"<<"Доходная"<<"Дорогая"<<"Детская"<<"Другая"<<"Долгая"<<
"Живая"<<"Жуткая"<<"Жалобная"<<"Жесткая"<<"Жестокая"<<
"Знойная"<<"Злая"<<"Заманчивая"<<"Завидная"<<"Золотая"<<
"Игрушечная"<<"Интересная"<<
"Красочная"<<"Красивая"<<
"Ленивая"<<"Легкая"<<"Лучшая"<<"Любовная"<<"Летучая"<<
"Многозначная"<<"Морская"<<"Мощная"<<"Медленная"<<"Могучая"<<"Милая"<<"Моя"<<
"Несгибаемая"<<"Невидимая"<<"Ненавистная"<<"Незаметная"<<"Ночная"<<"Нудная"<<"Необходимая"<<"Ненужная"<<
"Отличная"<<"Отвратительная"<<"Оригинальная"<<"Обычная"<<
"Первая"<<"Потрясающая"<<"Подлая"<<
"Радостная"<<"Резкая"<<"Ручная"<<"Родная"<<"Редкая"<<"Резвая"<<
"Своя"<<"Скучная"<<"Сонливая"<<"Серая"<<
"Твоя"<<"Теневая"<<
"Умная"<<"Уличающая"<<
"Филигранная"<<"Фальшивая"<<
"Хорошая"<<"Худшая"<<
"Ценная"<<"Цельная"<<"Целесообразная"<<
"Шутливая"<<"Шаловливая"<<"Шумная"<<
"Этнографическая"<<"Юная"<<"Юркая"<<"Явная"<<"Яростная");

QStringList rusPreposition = (QStringList()<<"У"<<"Без"<<"Близ"<<"Возле"<<"Для"<<"Из"<<"В Целях"<<"Не Без"<<"Около"<<"От"<<"Поблизости"<<"После"<<"Против"<<"Ради"<<"С Точки Зрения");

QStringList rusMaleName = (QStringList()<<"Александр"<<"Алексей"<<"Альберт"<<"Анатолий"<<"Андрей"<<"Антон"<<"Аркадий"<<"Арсений"<<"Артём"<<
"Богдан"<<"Борис"<<"Вадим"<<"Валентин"<<"Валерий"<<"Валерьян"<<"Василий"<<"Виктор"<<"Виталий"<<
"Владимир"<<"Владислав"<<"Владлен"<<"Всеволод"<<"Вячеслав"<<"Геннадий"<<"Георгий"<<"Германн"<<"Глеб"<<
"Григорий"<<"Даниил"<<"Денис"<<"Дмитрий"<<"Евгений"<<"Егор"<<"Еремей"<<"Ефим"<<"Иван"<<"Игнатий"<<
"Игорь"<<"Илья"<<"Ким"<<"Кондрат"<<"Константин"<<"Лаврентий"<<"Леонид"<<"Лука"<<"Лукьян"<<"Макар"<<
"Максим"<<"Мартын"<<"Матвей"<<"Михаил"<<"Мстислав"<<"Никита"<<"Николай"<<"Олег"<<"Павел"<<"Пётр"<<
"Роман"<<"Ростислав"<<"Руслан"<<"Святослав"<<"Семён"<<"Сергей"<<"Станислав"<<"Степан"<<"Фёдор"<<
"Федот"<<"Фома"<<"Эдуард"<<"Юрий"<<"Яков");

QStringList rusFemaleName = (QStringList()<<"Агата"<<"Александра"<<"Алина"<<"Алла"<<"Анастасия"<<"Ангелина"<<"Анжела"<<"Анжелика"<<"Анна"<<
"Антонина"<<"Валентина"<<"Валерия"<<"Варвара"<<"Василиса"<<"Вера"<<"Вероника"<<"Виктория"<<"Галина"<<
"Дарья"<<"Евгения"<<"Екатерина"<<"Елена"<<"Елизавета"<<"Жанна"<<"Зинаида"<<"Зоя"<<"Ирина"<<"Ия"<<
"Кира"<<"Ксения"<<"Лариса"<<"Лидия"<<"Любовь"<<"Людмила"<<"Майя"<<"Маргарита"<<"Марина"<<"Мария"<<
"Надежда"<<"Наталья"<<"Нина"<<"Нинель"<<"Нонна"<<"Оксана"<<"Ольга"<<"Полина"<<"Прасковья"<<"Раиса"<<
"Регина"<<"Светлана"<<"София"<<"Таисия"<<"Тамара"<<"Татьяна"<<"Ульяна"<<"Фаина"<<"Элеонора"<<"Юлия");

QStringList rusSurname = (QStringList()<<"Иванов"<<"Васильев"<<"Петров"<<"Смирнов"<<"Михайлов"<<"Фёдоров"<<"Соколов"<<"Яковлев"<<"Попов"<<"Андреев"<<
"Алексеев"<<"Александров"<<"Лебедев"<<"Григорьев"<<"Степанов"<<"Семёнов"<<"Павлов"<<"Богданов"<<"Николаев"<<
"Дмитриев"<<"Егоров"<<"Волков"<<"Кузнецов"<<"Никитин"<<"Соловьёв"<<"Тимофеев"<<"Орлов"<<"Афанасьев"<<"Филиппов"<<
"Сергеев"<<"Захаров"<<"Матвеев"<<"Виноградов"<<"Кузьмин"<<"Максимов"<<"Козлов"<<"Ильин"<<"Герасимов"<<"Марков"<<
"Новиков"<<"Морозов"<<"Романов"<<"Осипов"<<"Макаров"<<"Зайцев"<<"Беляев"<<"Гаврилов"<<"Антонов"<<"Ефимов"<<
"Леонтьев"<<"Давыдов"<<"Гусев"<<"Данилов"<<"Киселёв"<<"Сорокин"<<"Тихомиров"<<"Крылов"<<"Никифоров"<<
"Кондратьев"<<"Кудрявцев"<<"Борисов"<<"Жуков"<<"Воробьёв"<<"Щербаков"<<"Поляков"<<"Савельев"<<"Трофимов"<<
"Чистяков"<<"Баранов"<<"Сидоров"<<"Соболев"<<"Карпов"<<"Белов"<<"Титов"<<"Львов"<<"Фролов"<<"Игнатьев"<<
"Комаров"<<"Прокофьев"<<"Быков"<<"Абрамов"<<"Голубев"<<"Пономарёв"<<"Покровский"<<"Мартынов"<<"Кириллов"<<
"Миронов"<<"Фомин"<<"Власов"<<"Федотов"<<"Назаров"<<"Ушаков"<<"Денисов"<<"Константинов"<<"Воронин"<<"Наумов");

//Функции создания рандомных чисел, которые будут использоваться в генераторах
void randomize()
{
    srand(time(NULL));
}

int random(int n)
{
    return rand()%n;
}

//Функции, генерирующие имена и названия
QString generateEnglishTitle()
{
    int x = 1+random(45);
    int n1 = random(noun.size());
    int n2 = random(noun.size());
    int a1 = random(adjective.size());
    int a2 = random(adjective.size());
    int vpa = random(verbed.size());
    int vpr = random(verbs.size());
    int p = random(preposition.size());
    int av = random(auxverb.size());
    int v = random(verb.size());
    int ving = random(verbing.size());
    switch (x)
    {
    case 1:
        return (adjective[a1] + " " + noun[n1]);
    case 2:
        return ("The " + adjective[a1] + " " + noun[n1]);
    case 3:
        return (noun[n1] + " of " + noun[n2]);
    case 4:
        return ("The " + noun[n1] + "''s " + noun[n2]);
    case 5:
        return ("The " + noun[n1] + " of the " + noun[n2]);
    case 6:
        return ("The " + noun[n1] + " of " + adjective[a1] + " " + noun [n2]);
    case 7:
        return ("The " + noun[n1] + " and the " + noun[n2]);
    case 8:
        return (preposition[p] + " the " + noun[n1]);
    case 9:
        return ("The " + noun[n1] + " " + preposition[p]);
    case 10:
        return (adjective[a1] + " " + noun[n1] + " of " + noun[n2]);
    case 11:
        return ("The " + noun[n1] + " the " + noun[n2] + " " + verbed[vpa]);
    case 12:
        return ("The " + noun[n1] + " " + preposition[p] + " the " + noun[n2]);
    case 13:
        return ("The " + noun[n1] + " of the " + adjective[a1] + " " + adjective[a2] + " " + noun[n2]);
    case 14:
        return ("The " + noun[n1] + " " + preposition[p] + " the " + adjective[a1] + " " + noun[n2]);
    case 15:
        return ("The " + noun[n1] + " that " + verbed[vpa] + " the " + noun[n2]);
    case 16:
        return ("The " + noun[n1] + " of the " + adjective[a1] + " " + noun[n2]);
    case 17:
        return (noun[n1] + " in " + adjective[a1] + " " + noun[n2]);
    case 18:
        return ("The " + noun[n1] + " that " + auxverb[av] + " " + verb[v] + " " + noun[n2]);
    case 19:
        return (preposition[p] + " the " + adjective[a1] + " " + noun[n1]);
    case 20:
        return (noun[n1] + " " + verbs[vpr] + " " + noun[n2]);
    case 21:
        return (preposition[p] + " a " + noun[n1] + " with a " + noun[n2]);
    case 22:
        return ("The " + adjective[a1] + " " + adjective[a2] + " " + noun[n1]);
    case 23:
        return (noun[n1] + " " + verbed[vpa] + " the " + noun[n2]);
    case 24:
        return (preposition[p] + " the " + noun[n1] + " of the " + adjective[a1] + " " + noun[n2]);
    case 25:
        return ("The " + noun[n1] + " that " + auxverb[av] + " " + verb[v]);
    case 26:
        return ("The " + adjective[a1] + " " + adjective[a2] + " " + noun[n1]);
    case 27:
        return ("A " + adjective[a1] + " " + noun[n1] + " " + preposition[p] + " " + noun[n2]);
    case 28:
        return (verbing[ving] + " the " + noun[n1]);
    case 29:
        return (noun[n1] + " " + verbed[vpa]);
    case 30:
        return (adjective[a1] + " " + noun[n1] + " " + preposition[p] + " " + adjective[a2] + " " + noun[n2]);
    case 31:
        return (adjective[a1] + " " + noun[n1] + ", " + adjective[a1] + " " + noun[n2]);
    case 32:
        return (noun[n1] + ", " + verb[v]);
    case 33:
        return (verbed[vpa] + " " + noun[n1]);
    case 34:
        return (verbed[vpa] + " to " + verb[v]);
    case 35:
        return (verb[v] + " " + noun[n1]);
    case 36:
        return (noun[n1] + "''s " + noun[n2]);
    case 37:
        return (noun[n1] + " and " + noun[n2]);
    case 38:
        return (noun[n1] + " is " + adjective[a1]);
    case 39:
        return (noun[n1] + " " + noun[n2]);
    case 40:
        return ("The " + noun[n1] + " " + noun[n2]);
    case 41:
        return (noun[n1] + noun[n2]);
    case 42:
        return ("A " + noun[n1] + " of " + noun[n2]);
    case 43:
        return (noun[n1] + " " + preposition[p] + " " + adjective[a1] + " " + noun[n2]);
    case 44:
        return (verbed[vpa] + " by " + noun[n1]);
    default:
        return (noun[n1] + " in the " + noun[n2]);
    }
}

QString generateRussianTitle()
{
    int x = random(10);
    int an = random(rusActNoun.size());
    int ng = random(rusNounGen.size());
    int n1 = random(rusNoun.size());
    int n2 = random(rusNoun.size());
    int a = random(rusAdjective.size());
    int p = random(rusPreposition.size());
    switch(x)
    {
    case 0:
        return (rusActNoun[an] + " " + rusNounGen[ng]);
    case 1:
        return (rusNoun[n1] + " " + rusNounGen[ng]);
    case 2:
        return (rusNoun[n1] + " " + rusPreposition[p] + " " + rusNounGen[ng]);
    case 3:
        return (rusNoun[n1] + " и " + rusNoun[n2]);
    case 4:
        return (rusPreposition[p] + " " + rusNounGen[ng]);
    case 5:
        return (rusAdjective[a] + " " + rusNoun[n1]);
    case 6:
        return (rusAdjective[a] + " " + rusNoun[n1] + " " + rusPreposition[p] + " " + rusNounGen[ng]);
    case 7:
        return (rusNoun[n1]);
    case 8:
        return (rusAdjective[a] + " " + rusNoun[n1] + ": " + rusActNoun[an]);
    default:
        return (rusNoun[n1] + " и " + rusAdjective[a] + " " + rusNoun[n2]);
    }
}

QString generateGermanTitle()
{
    QString result = generateEnglishTitle();
    result.replace("a", "ä");
    result.replace("A", "Ä");
    result.replace("o", "ö");
    result.replace("O", "Ö");
    result.replace("u", "ü");
    result.replace("U", "Ü");
    result.replace("ss", "ß");
    return result;
}

QString generateFrenchTitle()
{
    QString result = generateEnglishTitle();
    result.replace("a", "á");
    result.replace("A", "Á");
    result.replace("o", "ó");
    result.replace("O", "Ó");
    result.replace("e", "é");
    result.replace("E", "É");
    result.replace("c", "ç");
    return result;
}

QString generateSpanishTitle()
{
    QString result = generateEnglishTitle();
    result.replace("a", "á");
    result.replace("A", "Á");
    result.replace("o", "ó");
    result.replace("O", "Ó");
    result.replace("i", "í");
    result.replace("I", "Í");
    result.replace("n", "ñ");
    result.replace("N", "Ñ");
    return result;
}

QString generateEnglishName()
{
    int n = random(name.size());
    int s = random(surname.size());
    return (name[n] + " " + surname[s]);
}

QString generateRussianName()
{
    int g = random(2);
    int s = random(rusSurname.size());
    if (g)
    {
        int n = random(rusMaleName.size());
        return (rusMaleName[n] + " " + rusSurname[s]);
    }
    else
    {
        int n = random(rusFemaleName.size());
        return (rusFemaleName[n] + " " + rusSurname[s] + "а");
    }
}

QString generateGermanName()
{
    QString result = generateEnglishName();
    result.replace("a", "ä");
    result.replace("A", "Ä");
    result.replace("o", "ö");
    result.replace("O", "Ö");
    result.replace("u", "ü");
    result.replace("U", "Ü");
    result.replace("ss", "ß");
    return result;
}

QString generateFrenchName()
{
    QString result = generateEnglishName();
    result.replace("a", "á");
    result.replace("A", "Á");
    result.replace("o", "ó");
    result.replace("O", "Ó");
    result.replace("e", "é");
    result.replace("E", "É");
    result.replace("c", "ç");
    return result;
}

QString generateSpanishName()
{
    QString result = generateEnglishName();
    result.replace("a", "á");
    result.replace("A", "Á");
    result.replace("o", "ó");
    result.replace("O", "Ó");
    result.replace("i", "í");
    result.replace("I", "Í");
    result.replace("n", "ñ");
    result.replace("N", "Ñ");
    return result;
}

QString generatePublisherName()
{
    int x = random(3);
    int n = random(noun.size());
    int ad = random(adjective.size());
    int ving = random(verbing.size());
    int ab = random(abbreviation.size());
    switch (x)
    {
    case 0:
        return (noun[n] + " " + abbreviation[ab]);
    case 1:
        return (adjective[ad] + " " + noun[n] + " " + abbreviation[ab]);
    default:
        return (verbing[ving] + " " + noun[n] + " " + abbreviation[ab]);
    }
}

QString generateLogin(QString& name)
{
    QString result = name.toLower();
    result.replace(" ", "_");
    result.replace("á", "a");
    result.replace("ó", "o");
    result.replace("é", "e");
    result.replace("í", "i");
    result.replace("ä", "ae");
    result.replace("ö", "oe");
    result.replace("ü", "ue");
    result.replace("ß", "ss");
    result.replace("ç", "c");
    result.replace("ñ", "n");
    result.replace("а", "a");
    result.replace("б", "b");
    result.replace("в", "v");
    result.replace("г", "g");
    result.replace("д", "d");
    result.replace("е", "e");
    result.replace("ё", "ye");
    result.replace("ж", "zh");
    result.replace("з", "z");
    result.replace("и", "i");
    result.replace("й", "y");
    result.replace("к", "k");
    result.replace("л", "l");
    result.replace("м", "m");
    result.replace("н", "n");
    result.replace("о", "o");
    result.replace("п", "p");
    result.replace("р", "r");
    result.replace("с", "s");
    result.replace("т", "t");
    result.replace("у", "u");
    result.replace("ф", "f");
    result.replace("х", "kh");
    result.replace("ц", "ts");
    result.replace("ч", "ch");
    result.replace("ш", "sh");
    result.replace("щ", "shch");
    result.replace("ь", "");
    result.replace("ы", "y");
    result.replace("ъ", "");
    result.replace("э", "e");
    result.replace("ю", "yu");
    result.replace("я", "ya");
    return result;
}

QString generateEmail(QString& name)
{
    QString result = generateLogin(name);
    int x = random(5);
    switch(x)
    {
    case 0:
        return (result + "@gmail.com");
    case 1:
        return (result + "@yahoo.com");
    case 2:
        return (result + "@outlook.com");
    case 3:
        return (result + "@mail.com");
    default:
        return (result + "@inbox.com");
    }
}

QString generateISBN(unsigned int& n)
{
    return ("978" + QString::number(n+100000000) + "0");
}

QString generateDescription()
{
    return "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.";
}

QString generateDate()
{
    int day;
    int month = random(12);
    switch (month)
    {
        case 0: day=random(31); break;
        case 1: day=random(28); break;
        case 2: day=random(31); break;
        case 3: day=random(30); break;
        case 4: day=random(31); break;
        case 5: day=random(30); break;
        case 6: day=random(31); break;
        case 7: day=random(31); break;
        case 8: day=random(30); break;
        case 9: day=random(31); break;
        case 10: day=random(30); break;
        case 11: day=random(31);
    }
    return ("201" + QString::number(random(5)) + "-" + QString::number(month+1) + "-" + QString::number(day+1) + " " + QString::number(random(24)) + ":" + QString::number(random(24)) + ":" + QString::number(random(24)));
}

#endif // GENERATORS_H
