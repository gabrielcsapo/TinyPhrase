#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define BUTTON_LEFT D5
#define BUTTON_RIGHT D4
#define BUZZER_PIN D6

#define DEBOUNCE_BUTTON 100000
#define ROUND_INTERVAL 90 // This is the time in seconds a round should take

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

typedef struct { 
  uint8_t index;
  char* menuItemName;
  char options[881][55];
} MenuOption;

const MenuOption MenuOptions[] PROGMEM {
        {0, "around_the_world", {"africa","airline","airplane","airport","airport security","alaska","america","antarctica","arctic ocean","are we there yet?","arizona","aruba","asia","athens","atlantic ocean","australia","austria","ayers rock","backpacking","barbados","barcelona","beach ball","beach house","beijing","belgium","belt","bermuda","bicycle","big ben","binoculars","bird watching","boardwalk","boston","brazil","broadway","buckingham palace","bug spray","california","camera","camping","canada","candy","carlsbad caverns","china","colorado","colorado river","condo","coral reef","costa rica","cruise ship","customs","delaware","disneyland","easter island","egypt","egyptian pyramids","empire state building","england","europe","family reunion","fanny pack","fiji","first class","florida","four corners","france","galapagos islands","great wall of china","greece","guam","hang glider","hawaii","hiking","holiday","honeymoon","hong kong","honolulu","hotel","ireland","island","istanbul","italy","jamaica","japan","july","june","kayak","lake","las vegas","layover","lazy river","london","london bridge","los angeles","luggage","luxembourg","madagascar","maine","manhattan island","map","mediterranean sea","mexico","miami","money","money belt","mount everest","mount rushmore","mountain biking","movies","national park","nepal","new york city","new zealand","niagara falls","oregon","orlando","pacific ocean","packing","paris","party","passport","portugal","puerto rico","rainforest","relax","resort","river","river rafting","road trip","rome","sacramento","safari","san francisco","say 'cheese'","scenery","scotland","scottland","scuba diving","shopping","sightseeing","singapore","six flags","skiing","sleeping bag","snow cone","snowboarding","south africa","south dakota","spain","state of liberty","stonehenge","stroll","suitcase","summer","sunglasses","sunny weather","sunscreen","sunset","sunshine","suntan","surfboard","swimming pool","switzerland","sydney","texas","the amazon rainforest","the bahamas","the coliseum","the dead sea","the eiffel tower","the golden gate bridge","the grand canyon","the great barrier reef","the louvre","the mayan ruins","the mississippi river","the nile","the sphinx","the taj mahal","the thames","the white house","theme park","time off","tokyo","tour guide","tourist","trains","turkey","universal studios","vacation day","venice","vienna","washington d.c.","water park","yellowstone"}},
        {1, "entertainment", {"100 meters","101 dalmatians","12 angry men","1917","2001: a space odyssey","21 bridges","a bag of marbles","a beautiful day in the neighborhood","a bug's life","a clockwork orange","a dog's journey","a dog's purpose","a dog's way home","a fortunate man","a hard day's night","a nightmare on elm street","a private war","a series of unfortunate events","a star is born","a taxi driver","a twelve-year night","a wrinkle in time","ad astra","adventure time","aguirre: the wrath of god","air bud","airplane!","akira","aladdin","ali and nino","alibi.com","alice in wonderland","alice’s adventures in wonderland","alien","aliens","alita: battle angel","all about eve","all about my mother","all the money in the world","all the president's men","allied","almost famous","alpha","american animals","american crime story","american made","an american in paris","an officer and a spy","and your mother too","andhadhun","andy griffith","angels in the outfield","anna","anna karenina: vronsky's story","anne of green gables","annie","annie hall","annihilation","anthropoid","apocalypse now","apollo 13","aquaman","archer","arrested development","ash vs evil dead","at the end of the tunnel","at war","atomic blonde","avatar","avatar: the last airbender","avengers: endgame","avengers: infinity war","baahubali 2: the conclusion","babe","baby driver","back to the future","backstabbing for beginners","bad genius","bad samaritan","bad times at the el royale","badla","badlands","balloon","bambi","banshee","batman","battle for sevastopol","battlestar galactica","beauty and the beast","becoming astrid","being john malkovich","being there","beirut","belle and sebastian, friends for life","ben-hur","bet on revenge","better call saul","better luck tomorrow","bicycle thieves","big","big little lies","bill and ted's excellent adventure","billions","black hawk down","black orpheus","black panther","blackkklansman","blade of the immortal","blade runner","blade runner 2049","blazing saddles","bleed for this","blood father","blue’s clues","boardwalk empire","bohemian rhapsody","bojack horseman","bolt","boogie nights","borg vs. mcenroe","boy erased","boyka: undisputed","boys don't cry","boyz n the hood","brad's status","breaking bad","breathe","breathless","bridesmaids","bridget jones's diary","brimstone","broadcast news","brokeback mountain","brooklyn nine-nine","brother bear","brotherhood of blades 2","brown bear, brown bear, what do you see?","burn out","butch cassidy and the sundance kid","cabaret","californication","call me by your name","call of heroes","callilou","capernaum","captain america: civil war","captain fantastic","carbon","carol","cars","casablanca","casino royale","catch me if you can","charlie and the chocolate factory","charlotte's web","charlotte’s web","cheaper by the dozen","chicka chicka boom boom","child 44","children of men","chinatown","chitty chitty bang bang","chocolat","cinderella","citizen kane","city lights","city of god","clara","clergy","clerks","cloudy with a chance of meatballs","clueless","coco","cold pursuit","colette","collateral beauty","community","corduroy","crazy rich asians","creed","creed ii","crouching tiger, hidden dragon","cupcake wars","curb your enthusiasm","curious george","custody","dangal","daredevil","dark","dark waters","darkest hour","dawn of the dead","dazed and confused","dead poets society","deadpool","deadwood","deepwater horizon","den of thieves","denial","department q: a conspiracy of faith","dexter","diary of a wimpy kid","die hard","dirty grandpa","do the right thing","doctor strange","doctor who","doctor zhivago","dog day afternoon","don't look now","double indemnity","downton abbey","dracula","dragged across concrete","dragon ball z","drishyam","drive","drunken master ii","duck soup","dumbo","dunkirk","dying to survive","e.t.","e.t. the extra-terrestrial","easy rider","eddie the eagle","edward scissorhands","election","elle","enter the dragon","entourage","eternal sunshine of the spotless mind","everest","everybody knows","evil dead 2","extremely wicked, shockingly evil and vile","eye for an eye","fahrenheit 451","fancy nancy","fantastic beasts and where to find them","fantastic beasts: the crimes of grindelwald","far from the madding crowd","fargo","fast & furious","fast times at ridgemont high","fight club","finding nemo","firefly","first they killed my father","fish tank","fixer upper","flight crew","flight of the conchords","focus","forbidden planet","ford v ferrari","forrest gump","four weddings and a funeral","frankenstein","freaks and geeks","free state of jones","free willy","frida","friday night lights","friends","fringe","frozen","futurama","game night","game of thrones","gandhi","george of the jungle","get out","ghost in the shell","ghostbusters","gifted","girls trip","god of war","godzilla","going in style","gold","goldfinger","goodbye christopher robin","goodfellas","goodnight moon","grand illusion","gravity falls","grease","greater","green book","groundhog day","guardians of the galaxy","hacksaw ridge","hairspray","halloween","hands of stone","hannibal","harold and maude","harry potter and the prisoner of azkaban","heat","heathers","hedwig and the angry inch","held for ransom","hercules","hero","hidden figures","hidden man","high noon","high school musical","his girl friday","holes","home","home alone","homeland","honey boy","honey, i shrunk the kids","hostiles","hotel mumbai","house","house of cards","how i met your mother","how to be a latin lover","i am losing weight","i can only imagine","i'm a killer","i, tonya","ice","ice age","if beale street could talk","in the heart of the sea","in the heat of the night","in the mood for love","inception","indian in the cupboard","indiana jones","inferno","inglourious basterds","innocent","inside out","iron man","it happened one night","it's a wonderful life","it's always sunny in philadelphia","italian race","james and the giant peach","james bond","jason bourne","jasper jones","jaws","john wick","joker","joy","judy moody and the not bummer summer","jumanji","jungle","jurassic park","jurassic world","just mercy","justice league","justified","killing","king arthur: legend of the sword","king kong","king petar the first","kingsman: the golden circle","kitchen. the last battle","knives out","kong: skull island","l.a. confidential","la bamba","la la land","lady and the tramp","lady bird","land of mine","last knights","last week tonight with john oliver","lawrence of arabia","leap!","legend","lego movie","let the right one in","lethal weapon","life itself","like water for chocolate","lion","little giants","little house on the prairie","little shop of horrors","little women","live by night","logan","logan lucky","loki","lord of the flies","lost","lost in translation","louie","love & basketball","love at second sight","loveless","mad max: fury road","mad men","madagascar","malcolm x","marriage story","marshall","mary poppins","matilda","maudie","maze runner: the death cure","me before you","mean girls","metropolis","mickey mouse club","mighty joe young","milo and otis","mindhunter","miracles from heaven","miss sloane","missing link","mission: impossible","moana","modern family","modern times","molly's game","money monster","monsoon wedding","monsters, inc.","monty python and the holy grail","moonlight","mortal engines","mowgli: legend of the jungle","mr. church","mr. robot","mr. smith goes to washington","mulan","mulholland dr.","murder on the orient express","my fair lady","my left foot","my neighbor totoro","naked","napoleon dynamite","narcos","nashville","national lampoon's animal house","neerja","network","never look away","newsies","night at the museum","night of the living dead","no country for old men","north by northwest","notting hill","now you see me 2","nuovo cinema paradiso","ocean's eight","october","official secrets","old yeller","oldboy","on the waterfront","once upon a time... in hollywood","one flew over the cuckoo's nest","only yesterday","open city","operation finale","our kind of traitor","out stealing horses","outlander","outlaw king","oz","pad man","paddington","palm trees in the snow","pan's labyrinth","pandora's box","papillon","parasite","parks and recreation","passengers","pather panchali","paw patrol","pawn sacrifice","pele: birth of a legend","peppermint","perfect strangers","person of interest","pete's dragon","peter pan","peter rabbit","pink","pinocchio","pioneer woman cooking show","pirates of the caribbean","pirates of the carribean","pitch perfect","planet single","playtime","pocahontas","portrait of a lady on fire","pretty in pink","pride and prejudice","princess mononoke","prison break","project gutenberg","psycho","pulp fiction","queen of hearts","queen of katwe","race","rafiki","raging bull","raiders of the lost ark","rampage","rashomon","ratatouille","ready player one","rear window","rebel in the rye","red sparrow","remember the titans","remi, nobody's boy","repo man","requiem for a dream","retribution","return of the hero","rick and morty","robin hood","robinson caruso","robocop","rocketman","rocky","rogue one: a star wars story","roman holiday","roman j. israel, esq.","rome","room","rosemary's baby","salyut-7","sanju","sara's notebook","saving face","saving private ryan","say anything...","scarface","schindler's list","scream","scrubs","searching","secret superstar","see you up there","seinfeld","selma","sense8","sesame street","seven","seven samurai","shaft","shameless","shaun of the dead","sherlock","shoplifters","shot caller","shrek","sicario","sicario: day of the soldado","silicon valley","sing","singin' in the rain","six feet under","slumdog millionaire","smith family robinson","snow white and the seven dwarfs","snow white and the seven dwarves","snow white the incredibles sleeping beauty","snowden","solace","sold","soldier's lullaby","some like it hot","sons of anarchy","sorry to bother you","sound of music","south park","south wind","southpaw","spacewalk","spartacus","spectre","spider-man","spider-man: far from home","spider-man: homecoming","spider-man: into the spider-verse","spirited away","split","spotlight","stan & ollie","star trek: the next generation","star wars","star wars: episode iv -- a new hope","star wars: episode v -- the empire strikes back","stone soup","storm boy","straight outta compton","stranger things","stronger","stuart little","suits","sully","sunset blvd.","superbad","superman: the movie","supernatural","swiss family robinson","tangerine","tangled","tarzan","taxi driver","ted lasso","teenage mutant ninja turtles","terminator 2: judgment day","the 12th man","the 33","the 400 blows","the accountant","the admiral","the adventures of priscilla, queen of the desert","the adventures of robin hood","the african doctor","the age of adaline","the age of shadows","the americans","the angel","the apartment","the apparition","the art of racing in the rain","the balkan line","the best years of our lives","the bfg","the big lebowski","the big sick","the blackout","the book of henry","the boy who harnessed the wind","the boys","the brave little toaster","the brawler","the breakfast club","the bridge on the river kwai","the cabinet of dr. caligari","the candidate","the cat in the hat","the chessplayer","the climb","the collini case","the commuter","the conductor","the crown","the dark knight","the day the earth stood still","the duelist","the elephant man","the emoji movie","the emperor of paris","the emperor's new groove","the equalizer 2","the etruscan smile","the exorcist","the expanse","the extraordinary journey of the fakir","the farewell","the favourite","the fencer","the finest hours","the foreigner","the fortress","the founder","the fox and the hound","the french connection","the fundamentals of caring","the general","the gentlemen","the giving tree","the glass castle","the godfather","the good, the bad and the ugly","the grand budapest hotel","the grand tour","the grapes of wrath","the great battle","the great escape","the great wall","the greatest showman","the guernsey literary and potato peel pie society","the handmaid's tale","the handmaiden","the hate u give","the haunting of hill house","the highwaymen","the hunt","the icebreaker","the ideal palace","the importance of being earnest","the incredibles","the infiltrator","the informer","the insult","the intern","the invisible guest","the irishman","the iron giant","the jungle book","the kid","the king's choice","the lady eve","the land before time","the last king","the least of these: the graham staines story","the legend of korra","the legend of tarzan","the limehouse golem","the lion king","the lion, the witch, and the wardrobe","the little engine that could","the little mermaid","the lord of the rings","the lost city of z","the magnificent seven","the maltese falcon","the man who invented christmas","the man who knew infinity","the man with the iron heart","the manchurian candidate","the mandalorian","the martian","the marvelous mrs. maisel","the matrix","the mighty ducks","the miracle","the mountain between us","the mountain ii","the mule","the muppet christmas carol","the mustang","the naked gun","the newsroom","the nice guys","the night of the hunter","the nightmare before christmas","the office","the ottoman lieutenant","the outsider","the parent trap","the passion of joan of arc","the peanut butter falcon","the philadelphia story","the photographer of mauthausen","the piano","the pirates of somalia","the player","the princess and the frog","the princess bride","the princess diaries","the professor","the professor and the madman","the promise","the punisher","the queen's gambit","the red shoes","the rescuers","the resistance banker","the revenant","the rules of the game","the ruthless","the salesman","the sandlot","the santa clause","the sea inside","the searchers","the secret garden","the seventh seal","the shape of water","the shawshank redemption","the shield","the shining","the siege of jadotville","the silence of the lambs","the simpsons","the sixth sense","the snowy day","the sopranos","the sound of music","the sword in the stone","the tale of peter rabbit","the tale of the princess kaguya","the terminator","the thing","the third man","the throne","the tiger","the tip of the iceberg","the treasure of the sierra madre","the twilight zone","the umbrellas of cherbourg","the very hungry caterpillar","the wailing","the well","the west wing","the wife","the wild bunch","the wire","the witcher","the wizard of lies","the wizard of oz","the x-files","the young karl marx","the zookeeper's wife","their finest","thelma & louise","there will be blood","this is spinal tap","this is us","thomas the tank engine","thor: ragnarok","three billboards outside ebbing, missouri","three seconds","through the fire","thumbelina","titanic","to be or not to be","to kill a mockingbird","togo","tokyo story","tomb raider","tootsie","total recall","toy story","trainspotting","transit","trener","triple frontier","tron","true detective","twin peaks","uncut gems","unforgiven","unsolved mysteries","up","upgrade","uri: the surgical strike","venom","vertigo","victoria & abdul","volver","wakefield","wall-e","war for the planet of the apes","warcraft","wazir","wendy and lucy","west side story","westworld","what's love got to do with it","where the wild things are","white fang","widows","wild strawberries","willy wonka and the chocolate factory","wind river","wolf totem","wonder","wonder woman","x-men: apocalypse","you were never really here","your sister's sister","yuli","zero dark thirty","zootopia","zorro"}},
        {2, "famous_figures", {"abraham lincoln","adele","adolf hitler","agatha christie","ai weiwei","al pacino","albert einstein","albert enstein","alec baldwin","alex rodriguez","alexander graham bell","alexander the great","alfred hitchcock","alfred nobel","alice (in wonderland)","amanda bynes","amelia earhart","amy winehouse","anakin skywalker","andrew lloyd webber","andy griffith","andy warhol","angelina jolie","anne frank","archimedes","aretha franklin","ariana grande","aristotle","arnold schwarzenegger","arsenio hall","audrey hepburn","augustus","axl rose","babe ruth","bach","barack obama","barbara walters","barbie","barbra streisand","batman","baymax","beauty queen","beavis and butt-head","beethoven","ben affleck","ben franklin","benjamin franklin","betsy ross","betty ford","beyonce","big bird","bill clinton","bill cosby","bill gates","billy the kid","bob dylan","bob marley","bono","brad pitt","britney spears","bruce lee","bruce springsteen","bruce willis","buddy holly","bugs bunny","burt reynolds","buzz aldrin","buzz lightyear","c. s. lewis","calvin klein","cameron diaz","canelo alvarez","cap'n crunch","captain hook","carol burnett","carrie fisher","cartman","celine dion","charles darwin","charles dickens","charlie brown","charlie chaplin","che guevara","cher","chopin","chris rock","christian bale","christie brinkley","christopher columbus","cinderella","cindy crawford","clark gable","clark kent","claude monet","cleopatra","clifford the big red dog","clint eastwood","coco chanel","coldplay","colin powell","columbus","confucius","cookie monster","copernicus","cristiano ronaldo","dabo swinney","dakota fanning","dalai lama","daniel craig","danny glover","darth vader","david beckham","david bowie","david letterman","david livingstone","davy crockett","denzel washington","devin booker","diana ross","diana, princess of wales","dick clark","dick van dyke","diva","doctor","dolly parton","donald duck","donald trump","dora the explorer","doris day","dorothy hamill","dr. phil","dr. seuss","drew barrymore","dwayne johnson","dwight d. eisenhower","eddie murphy","edgar allen poe","edgar degas","edith piaf","edvard munch","eleanor roosevelt","eli whitney","elijah wood","elizabeth taylor","ellen degeneres","elmo","elon musk","elsa from frozen","elton john","elvis presley","eminem","ernest hemingway","ewan mcgregor","fancy nancy","farrah fawcett","fidel castro","firefighter","frank lloyd wright","frank sinatra","frankenstein","franklin d. roosevelt","fred flintstone","frederick douglass","frida kahlo","galileo","gandhi","garfield","garth brooks","genghis khan","george bush","george clooney","george lucas","george of the jungle","george orwell","george w. carver","george washington","georgia o'keeffe","gianni versace","gilligan","grace kelly","grogu","gwen stefani","hadrian","hair stylist","halle berry","hans christian andersen","harriet tubman","harrison ford","harry houdini","harry potter","helen keller","henri matisse","henry ford","herbert hoover","hillary clinton","homer","howard stern","hugh hefner","immanuel kant","inigo montoya","isaac newton","j.k. rowling","jack black","jack nicholson","jackie chan","jackie robinson","jackson pollock","jacqueline kennedy onassis","jake gyllenhaal","james bond","james brown","james cook","james dean","james earl jones","james madison","james taylor","jane austen","janet jackson","jason sudeikis","jay leno","jay-z","jeff bezos","jennifer lawrence","jennifer lopez","jerry garcia","jerry seinfeld","jesus","jim carrey","jim henson","jim morrison","jimi hendrix","jimmy stewart","joan of arc","jodie foster","joe biden","joe dimaggio","joe namath","johann sebastian bach","johannes gutenberg","johannes kepler","john adams","john belushi","john f. kennedy","john hancock","john kennedy, jr.","john lennon","john travolta","john wayne","john williams","johnny carson","johnny cash","johnny depp","jonathan taylor thomas","joseph stalin","judge judy","judy garland","julia roberts","julius ceasar","justin bieber","justin timberlake","kafka","kanye west","karl marx","kate middleton","kate winslet","katie couric","keanu reeves","kermit and miss piggy","kermit the frog","kevin bacon","kim jong il","kim kardashian","king arthur","king george","kurt cobain","lady gaga","lance armstrong","lenin","leo tolstoy","leonardo da vinci","leonardo dicaprio","lewis and clark","lewis carrol","liberace","lil nas x","lionel messi","lord byron","louis armstrong","lucille ball","luke skywalker","macaulay culkin","machine gun kelly","madonna","magic johnson","mahatma gandhi","malala yousafzai","malcolm x","mandy moore","mao","marco polo","margaret qualley","margaret thatcher","mariah carey","marie antoinette","marie curie","marilyn monroe","mario","mark twain","mark zuckerberg","marlon brando","martha stewart","martin luther","martin luther king, jr.","martin sheen","marvin gaye","mary poppins","mary tyler moore","mary-kate and ashley olsen","matthew broderick","megan fox","mel gibson","merlin","meryl streep","michael j. fox","michael jackson","michael jordan","michael k. williams","michael phelps","michael schumacher","michelangelo","micky mouse","mike myers","moby dick","mohammad ali","molly ringwald","monica lewinsky","mother teresa","mother theresa","mozart","mr. rogers","muhammad ali","music conductor","napoleon","napoleon bonaparte","nathaniel hawthorne","neil armstrong","neil diamond","nelson mandela","nero","nicole kidman","nikola tesla","nora lum","norm macdonald","norman rockwell","olivia newton-john","oprah winfrey","osama bin laden","oscar the grouch","oscar wilde","p. diddy","pablo picasso","pablo piccaso","pamela anderson","patrick henry","patrizia reggiani","paul mccartney","paul newman","pele","peppa pig","pete davidson","peter pan","peyton manning","pinocchio","plato","pocahontas","police officer","president","prince","princess diana","princess leia","pro wrestler","puneeth rajkumar","pythagoras","queen elizabeth","queen latifah","queen victoria","quentin tarantino","ralf rangnick","rami malek","raphael","rapunzel","rasputin","reese witherspoon","regis philbin","rembrandt","richard nixon","richard pryor","ricky martin","rihanna","robert de niro","robin hood","robin williams","rock hudson","rocky","romeo and juliet","ron howard","ronald reagan","ronald regan","rosa parks","roseanne barr","rosie o’donnell","rowan atkinson","rudy giuliani","russell crowe","ryan reynolds","sacajawea","sally field","sally ride","salvador dali","samuel adams","samuel l. jackson","samuel morse","sandro botticelli","santa claus","sarah jessica parker","scarlett johansson","scooby doo","sean connery","serena williams","shakespeare","shakira","shania twain","shaquille o'neal","shel silverstein","sherlock holmes","shia labeouf","sidharth shukla","sigmund freud","sigourney weaver","simu liu","sir arthur conan doyle","sitting bull","snow white","socrates","sonic the hedgehog","spider man","stephanie meyer","stephen hawking","stephen king","steve burns","steve jobs","steve martin","steven spielberg","stevie wonder","sting","superman","susan b. anthony","susan lucci","susan wojcicki","sylvester stallone","taylor swift","teacher","the beatles","the grinch","the incredible hulk","the rock","the simpsons","the sundance kid","the three stooges","the wright brothers","the zodiac killer","theodore roosevelt","thomas edison","thomas jefferson","thomas paine","tiger woods","tigger","tim tebow","timothee chalamet","tina turner","tolkien","tom brady","tom cruise","tom hanks","tony hawk","travis scott","tupac shakur","tutankhamen","twiggy","tyson fury","ulysses s. grant","van gogh","vasco da gama","victor hugo","vincent van gogh","vlad dracula","vladimir putin","waiter/server","waldo","walt disney","walter cronkite","wayne gretzky","weird al","weird al yankovick","whitney houston","whoopi goldberg","will ferrell","will smith","william shakespeare","william the conqueror","winnie the pooh","winona ryder","winston churchill","wolfgang amadeus mozart","wonder woman","woody allen","yoko ono","you","zac efron","zendaya"}},
        {3, "food", {"a la carte","alfredo sauce","all you can eat buffet","almond","almond extract","angel food cake","appetizer","apple","apple pie","apricot","artichoke","asparagus","avocado","baby carrots","bagel","baguette","bake","baked alaska","baked beans","baked potatoes","baking soda","balsamic vinegar","banana","banana bread","banana pudding","banana split","barley","basil","bavarian cream","beef","beef jerky","beet","bell pepper","birthday cake","biscuit","biscuits and gravy","black beans","black-eyed pea","blackberry","blanch","blender","blt","blueberry","boiled egg","bok choy","boston cream pie","bran muffins","bread","bread bowl","breakfast","broccoli","broil","broth","brownie","brussels sprouts","bubblegum","buffalo wings","bundt cake","bundt pan","burger king","cabbage","cake","canadian bacon","candy","cantaloupe","caramel","carrot","carrot cake","cashew","catfish","cauliflower","caviar","celery","cereal","cheddar cheese","cheese","cheeseburger","cheesecake","cherry","cherry pie","chicken","chicken fried steak","chicken pot pie","chicken salad sandwich","chicken soup","chickpea","chili pepper","chocolate cake","chocolate chip cookie","chocolate milk","chocolate shake","chow mien","cinnamon","cinnamon rolls","clams","clementine","coconut","colander","cookie","corn","corn flakes","corn on the cob","cornbread","corndog","cornmeal","cottage cheese","crab","crackers","cranberry","crepe","croutons","cucumber","cupcakes","curry","custard","cutting board","dairy","date","deep fry","deep-fry","deviled eggs","doughnuts","dredge","drive through","drive-through","dutch oven","egg","egg nog","egg salad","egg salad sandwich","egg timer","eggnog","eggplant","fig","flamb�","flatbread","flour","fork","fortune cookie","freeze","french fries","fried chicken","fried rice","frozen yogurt","fruit salad","fruit smoothie","fruitcake","frying pan","garbanzo bean","garlic","ginger","gingerbread","gingerbread man","gourd","granola","granola bar","grape","grapefruit","green bean","green bean casserole","green onion","grill","grilled cheese","grits","guacamole","ham","hamburger","honeydew","horseradish","hot dog","hot dogs","ice cream","ice cream cone","ice cream sundae","jalape�o","jam","jell-o","jelly","jellybeans","kale","key lime pie","kfc","kidney beans","kiwi","kool aid","kool-aid","kumquat","la carte","lamb","lasagna","leek","lemon","lemon zester","lentils","lettuce","lima bean","lime","liver","lobster","lollipop","low fat","low-fat","mac and cheese","macaroni and cheese","macaroon","marinade","marshmallow","mashed potatoes","mcdonalds","meat","meatballs","meatloaf","melt","milk","milk and cookies","milkshake","mozzarella cheese","muffin","muffin tin","mushroom","mustard","napkin","noodles","nutmeg","oatmeal","oatmeal raisin cookies","octopus","okra","olive","omelet","onion","onion rings","orange","orange chicken","oven mitt","paella","pancake","pancakes","papaya","parmesan cheese","parsnip","pasta","pea","peach","peanut","peanut butter","peanut butter and jelly sandwich","peanut butter cookies","pear","pecan","pepperoni pizza","pineapple","pineapple upside down cake","pinto beans","pistachio","pita","pizza","plum","poach","pomegranate","pop tart","popcorn","popcorn shrimp","popsicle","pork","potato","potato chip","potato chips","potato salad","potatoes au gratin","poultry","pretzel","produce","pudding","pumpkin","pumpkin pie","pumpkin seeds","radish","raisin","ranch dressing","raspberry","ratatouille","refried beans","rice","rolling pin","rolls","rye bread","s'mores","salad","salad dressing","salmon","salsa","salt","salt shaker","saltine crackers","sandwich","sardines","scone","scrambled eggs","sea salt","sesame seeds","shish kabob","shrimp","sifter","simmer","skim milk","sloppy joe","smoothie","snickerdoodle","soda","soft pretzel","souffl�","soup de jour","sourdough bread","soybean","spaghetti","spam","spatula","spinach","sponge cake","squash","strawberry","sugar cookie","sun dried tomatoes","sun-dried tomatoes","sunflower seeds","sushi","sweet potato","sweet potatoes","swiss cheese","taco","taco bell","tangerine","tater tots","tempura","toast","toaster","toaster oven","tofu","tomato","tomato soup","tortilla","tortilla chips","tuna","tuna salad","turkey","turkey bacon","turnip","twinkies","vanilla extract","vanilla wafer","veggie burger","venison","waffle cone","waffles","walnuts","water chestnut","watermelon","wedding cake","wheat bread","whisk","white bread","whole milk","wok","wooden spoon","yam","yogurt","zest","zucchini"}},
        {4, "holidays", {"'1776'","afraid","alexander hamilton","america","america the beautiful","american revolution","angel","anthem","apple cider","apple pie","autumn","baking","balloons","band","barbeque","baseball","bats","bells","benjamin franklin","betsy ross","black","blessings","block party","blue","bonfires","boo","boston","boston tea party","buddy the elf","candle","candlesticks","candy","candy cane","candy corn","carnival","celebration","chains","charity","chestnuts","chimney","chocolate","christmas break","christmas carol","christmas eve","christmas spirit","christmas tree","cinnamon","coffin","coleslaw","colonies","common sense","concerts","congress","connecticut","cookies","cooking","corn","corn maze","corn on the cob","cornucopia","costume","cranberry","cranberry sauce","creamed corn","creepy","crypt","dark","declaration of independence","decorations","delaware","democracy","doll","doorbell","dracula","dumplings","eagle","eating","eerie","eggnog","elves","england","fair","fall","family","family reunions","festival","firecracker","fireworks","flag","floats","food drives","football","football games","fortune teller","founding fathers","francis scott key","frankenstein","freedom","frightened","frosty the snowman","fun","games","george washington","georgia","ghost","ghost story","ghostbusters","ghoul","gifts","gingerbread house","goblin","god bless america","god bless the u.s.a.","going trick-or-treating","goody bag","grateful","gratitude","grave","graveyard","gravy","green bean casserole","gumdrops","gypsy","hamburgers","harvest","haunted house","hay ride","ho ho ho","holiday","horror","hot chocolate","hot dogs","ice cream","ice skating","icicle","igor","inalienable rights","independence","independence day","jack frost","jack-o-lantern","james madison","jingle bells","john adams","john hancock","july","justice","lantern","liberty","liberty and justice for all","life, liberty, and the pursuit of happiness","lights","little saint nick","lollipop","macy's day parade","mad scientist","manger","marshmallow","maryland","mashed potatoes","massachusetts","minutemen","mistletoe","mittens","monster","monster mash","music","my country 'tis of thee","national anthem","national holiday","native american","nativity","new england","new hampshire","new jersey","new york","nighttime","north carolina","orange","parade","parade floats","parades","parks","party","patrick henry","patriot","patriotism","pecan pie","pennsylvania","picnic","pie","pilgrims","plymouth","potato salad","praise","pride","pumpkin","pumpkin pie","pumpkin seeds","red","red, white, and blue","reindeer","rejoice","republicanism","resting","revolutionary war","rhode island","rolls","rudolph the red-nosed reindeer","s'mores","santa claus","santa's sleigh","santa's workshop","scarecrow","scarf","scary","scary movies","secret lab","setting the table","shepherds","shows","skeleton","sledding","sleigh ride","snow","snowball fight","snowflake","snowman","soda","soup","south carolina","sparklers","speeches","spells","spider","spider web","spooks","spooky","sports","squanto","squash","stable","star","star spangled banner","stars","stars and stripes","states","statue of liberty","stocking","streamers","stripes","stuffing","summer","survive the winter","sweet corn","sweet potatoes","sweets","table setting","tablecloth","taxes","thankful","thanks","thanksgiving dinner","the constitution","the grinch","the liberty bell","the little drummer boy","the north pole","the nutcracker","the pledge of allegiance","thirteen colonies","this land is your land","thomas jefferson","thomas paine","thursday","toys","travel","treaty of paris","trick or treat","turkey","turkey bowl","turkey pardoning","united","vampire","venison","virginia","wassail","watching tv","watermelon","werewolf","white","winter squash","wise men","witch","wrapping paper","yams","yankee doodle","you're a grand old flag","zombie"}},
        {5, "household", {"baby-sitter","bag","balloon","ballpoint pen","banana peel","band-aid","banister","baseboards","basket","bath","bathroom","bathroom scale","bathtub","batteries","bed","bedbug","bedroom","bedtime","bench","bib","bicycle","bike","blanket","bleach","block","blue jeans","book","books","boot","boots","bottle","bowtie","box","broom","brother","bubble","bucket","bunk bed","button","calendar","camera","candle","cardboard","cash","cd","ceiling","ceiling fan","cell phone","cell phone charger","chair","chest","chimney","cleaning spray","clock","coat","coin","computer","crayon","crayons","crib","crumb","curtains","desk","dinner","dog leash","doghouse","doll","dollar","door","door knob","doorbell","doorknob","doormat","doorway","dress","dress shirt","drill","driveway","drums","dryer sheets","duct tape","dust bunny","dustpan","dvds","electrical outlet","eraser","extension cord","fake flowers","flashlight","floor","flowers","front porch","garage","garbage","garden","garden hose","glass","glasses","globe","glue stick","grill","hair dryer","hairbrush","hairspray","hand lotion","hand soap","handle","headband","home movies","homework","hot water","hula hoop","ice","ink","internet","ipad","ipod","iron","ironing board","jar","jewelry","junk drawer","key","kitchen","kitchen knife set","kite","lace","ladder","lamp","laptop","laundry basket","laundry detergent","lawn mower","leak","letter opener","light switch","lipstick","living room","loose change","loveseat","lunchbox","magazine","magnets","mail","mailbox","markers","meal","mess","mini blinds","mirror","mitten","mold","money","napkin","necktie","newspaper","paint","pajamas","pantry","pants","paper","paperback","paperclip","pencil","penny","photograph","piano","picture","picture frame","pillow","pillowcase","plastic","pocket","pogo stick","porch swing","poster","printer","printer paper","purse","puzzle piece","quarter","quilt","rake","rattle","red wagon","refrigerator","ribbon","ring","robe","rocking chair","roof","rubber band","sandbox","sandpaper","sash","scarf","scissors","scuff mark","shampoo","shirt","shoe","shoes","shovel","shower","shower curtain","silverware","skateboard","skirt","snack","snowman","socks","sofa","speakers","spice rack","sponge","spoon","sprinkler","stain","stairs","stamp","stamps","stapler","stationery","stove","suitcase","sun block","sunday shoes","sunglasses","sweater","sweater vest","swimming pool","swing","t shirt","t-shirt","table","tape","telephone","television","tennis shoes","thread","tissue","toilet paper","toothbrush","toothpaste","towel","trash can","tv","umbrella","vase","vest","video camera","wallet","washing machine","watering can","weed","wheel","wick","windex","window","wreath","wristwatch","yardstick","yarn","yo-yo","zipper"}},
};

enum GameState {
  PAUSED,
  MAIN_MENU,
  START_ROUND,
  IN_A_ROUND,
  FINISH_ROUND,
};

GameState gameState = MAIN_MENU;

// State
long lastMenuOption=0;
long lastGameOption=0;
long timeSinceLastTick=0;
long lastPress=0;
long timeSinceGameStarted=0;
MenuOption selectedMenuOption;

const char* TypeOf(const bool&)   { static const char type[] = "bool";    return type; }
const char* TypeOf(const bool*)   { static const char type[] = "bool*";   return type; }
const char* TypeOf(const char&)   { static const char type[] = "char";    return type; }
const char* TypeOf(const char*)   { static const char type[] = "char*";   return type; }
const char* TypeOf(const double&) { static const char type[] = "double";  return type; }
const char* TypeOf(const double*) { static const char type[] = "double*"; return type; }
const char* TypeOf(const float&)  { static const char type[] = "float";   return type; }
const char* TypeOf(const float*)  { static const char type[] = "float*";  return type; }
const char* TypeOf(const int&)    { static const char type[] = "int";     return type; }
const char* TypeOf(const int*)    { static const char type[] = "int*";    return type; }
const char* TypeOf(const String&) { static const char type[] = "String";  return type; }
const char* TypeOf(const String*) { static const char type[] = "String*"; return type; }
//const char* const TypeOf(const char[5])    { static const char* type = "char[5]";    return type; }  // Decays to char* so generates compiler redefinition warning.
const char* const TypeOf(const char(*)[5]) { static const char* type = "char(*)[5]"; return type; }

void tickingSound() {
  tone(BUZZER_PIN, 1000, 5);
}

void setup() {
  Serial.begin(115200);

  Wire.begin(D1, D2);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);

  pinMode(BUTTON_LEFT,INPUT_PULLUP);
  pinMode(BUTTON_RIGHT,INPUT_PULLUP);
  pinMode(BUZZER_PIN,OUTPUT);

  printCenteredText("Welcome!");  

  display.display();
}

uint8_t getButton(){
  uint8_t ret=0;
  for(;;){
    if(digitalRead(BUTTON_LEFT)==LOW){
      ret=BUTTON_LEFT;
    }else if(digitalRead(BUTTON_RIGHT)==LOW){
      ret=BUTTON_RIGHT;
    }
    if(ret!=0){
      if(micros()-lastPress>DEBOUNCE_BUTTON){
        lastPress=micros();
        return ret;
      }else{
        lastPress=micros();
        ret=0;
      }
    }
    delay(10);
  }
}

void printCenteredText(char* text) {
  int16_t x1;
  int16_t y1;
  uint16_t width;
  uint16_t height;

  display.getTextBounds(text, 0, 0, &x1, &y1, &width, &height);

  // display on horizontal and vertical center
  display.clearDisplay(); // clear display
  display.setCursor((SCREEN_WIDTH - width) / 2, (SCREEN_HEIGHT - height) / 2);
  display.println(text); // text to display
  display.display();
}

void round() {
  while(gameState == IN_A_ROUND) {
    int currentTime = millis();
    // we break up the total ROUND_INTERVAL time into 3 segments with distinct delay times.
    int timeSinceGameStartedSeconds = (currentTime - timeSinceGameStarted) / 1000;
    int timeToTick = 0;

    if(timeSinceGameStartedSeconds < (ROUND_INTERVAL / 3)) {
      timeToTick = 1000;
    } else if(timeSinceGameStartedSeconds > (ROUND_INTERVAL / 3) && timeSinceGameStartedSeconds < (ROUND_INTERVAL / 2)) {
      timeToTick = 500;
    } else {
      timeToTick = 250;
    }

    // We want to make sure that we are not exceeding the round interval limit in seconds
    if(timeSinceGameStartedSeconds >= ROUND_INTERVAL) {
      Serial.println("finishing the round");
      gameState = FINISH_ROUND;
    }
  
    memcpy_P(&selectedMenuOption, &MenuOptions[lastMenuOption], sizeof(selectedMenuOption));

    int totalGameOptions = sizeof(selectedMenuOption.options) / sizeof(selectedMenuOption.options[0]);
    Serial.print("Total Game Options: ");
    Serial.println(totalGameOptions);
    Serial.println(lastGameOption);

    Serial.println(selectedMenuOption.options[lastGameOption]);

    printCenteredText(selectedMenuOption.options[lastGameOption]);

    // TODO: dirty checks for button presses, this should be abstracted to a non-blocking getButton
    // TODO: we need to be able to check for multiple button presses at the same time
    uint8_t ret=0;
    for(int i = 0; i <= 5; i++){
      if(digitalRead(BUTTON_RIGHT)==LOW){
        ret=BUTTON_RIGHT;      
      }
      if(ret!=0){
        if(micros()-lastPress>DEBOUNCE_BUTTON){
          if((lastGameOption + 1) > totalGameOptions) {
            lastGameOption = 0;
          } else {
            lastGameOption += + 1;
          }

          lastPress=micros();
        }else{
          lastPress=micros();
          ret=0;
        }
      }
      delay(10);
    }

    if(currentTime - timeSinceLastTick >= timeToTick) {
      tickingSound();
      timeSinceLastTick = currentTime;
    }
  }
}

// We want to check what state we are in
void game() {
  switch(gameState) {
    case MAIN_MENU: {
      Serial.println("MAIN_MENU");

      int totalMenuOptions = sizeof(MenuOptions) / sizeof(MenuOptions[0]);

      MenuOption selectedMenuOption = MenuOptions[lastMenuOption];

      printCenteredText(selectedMenuOption.menuItemName);

      switch(getButton()) {
        case BUTTON_RIGHT:
          // We are starting the game
          gameState = START_ROUND;
        break;
        case BUTTON_LEFT:
          // We are cycling through menu options
          Serial.println(lastMenuOption, totalMenuOptions);
          if(lastMenuOption + 1 == totalMenuOptions) {
            lastMenuOption = 0;
          } else {
            lastMenuOption += 1;
          }
          MenuOption selectedMenuOptionNested = MenuOptions[lastMenuOption];

          printCenteredText(selectedMenuOptionNested.menuItemName);
          tickingSound();
        break;
      }
    }break;
    case START_ROUND:
      Serial.println("START_ROUND");

      printCenteredText("Starting");

      // Resetting the game constants
      timeSinceGameStarted = millis();
      lastGameOption = 0;

      gameState = IN_A_ROUND;

      round();
      break;
    case FINISH_ROUND:
      Serial.println("FINISH_ROUND");

      printCenteredText("If you are holding the device your team loses!");

      delay(2000);

      gameState = MAIN_MENU;
      break;
  }

  display.display();
}

void loop() {
  switch(gameState) {
    case IN_A_ROUND:
      break;
    case PAUSED:
      Serial.println("PAUSED");
      break;
    default:
      game();
      break;
  }
}