# SuperHeroesGame
 

Жоро и неговите приятели са големи фенове на супергероите и комиксите. Той иска да създаде собствена игра със супергерои, в която различни играчи могат да закупуват супергерои, да нападат  супергероите на други потребители или да поставят своите супергерои в защитен режим. Всеки играч има право на максимум 3 хода за всяко влизане в играта. Резултатите се смятат спрямо средствата (парите), които един играч притежава.
Потребители

Жоро решава, че ще са му нужни два вида потребители:
Администратори, които ще имат права да добавят нови играчи, да изтриват профилите на играчи и да добавят карти на пазара.
Играчи, които ще играят играта.
И двата вида потребители се характеризират чрез две имена, имейл, потребителско име и парола, но играчите притежават и баланс от виртуални средства (пари), с които разполагат по време на играта.

Потребителски функционалности:
Администраторите
За удобство направете ръчно един администратор, който да съществува от началото.
Всеки администратор трябва да може да добавя нови администратори и играчи в системата.
Всеки администратор трябва да може да изтрива профили на играчи.
Всеки администратор трябва да има права да вижда цялата информацията за всеки потребител и неговия прогрес (без администраторите, един администратор може да вижда само имената и имейла на друг администратор) .
Всеки администратор трябва да може да добавя нови супергерои към “пазара”. В случай, че на “пазара” няма никакви супергерои, администраторът още с влизането си трябва да добави поне 3 супергероя. Администраторът трябва да може да вижда всички супергерои, които са били продадени и да може да избере един от тях за добавяне, ако не желае да добавя нов.
Играчите:

Всеки играч трябва да може да изтрива профила си.
Всеки играч трябва да може да вижда списък от всички играчи, в който са записани само техните потребителски имена, с колко пари разполагат и какви супергерои имат (без тяхната сила).
Всеки играч трябва да може да вижда моментното класиране
Всеки играч трябва да може да вижда пазара от супергерои (който е общ за всички играчи) и при желание да закупи някой супергерой. След закупуването супергероят трябва да изчезне от пазара. Не е позволено дублиране на един и същ супергерой, както като собственост на един играч така и като дублиране между различни играчи.
Всеки играч трябва да може да нападне избран от него супергерой на даден потребител.
Всеки играч трябва да може да променя позицията на героите си от атакуваща в дефанзивна и обратното.
Всеки играч трябва да може да излезе от системата, което се счита за край на неговия ход.

Системни ограничения и функционалности:

Супергероите трябва да се състоят от: две имена, супергеройски псевдоним, вид сила (огън, вода или земя), сила (в точки положително число), цена при закупуване и режим, в който е поставен (ако е закупен).
Когато играч атакува друг играч, трябва или да избере чий супергерой да нападне, или да се избере един на случаен принцип.
->Как се определя дали едно нападение е успешно:
Ако играч нападне друг играч, който няма никакви супергерои, то парите на нападнатия играч намаляват с броя на атакуващите точки, които е имал нападащия супергерой (в случай, че нападнатият играч разполага с по-малка сума пари от силата на нападащия супергерой, то неговият баланс става равен на 0$), а нападащият играч печели х на брой пари. 

Ако играч нападне супергерой на друг играч, първо се сравняват техният тип сили. Всеки един тип сила побеждава друг, както следва:       Огън->Земя->Вода->Огън. Ако нападащият играч е с доминиращ тип сила, то точките на супергероя му в тази битка биват удвоени и се прилагат правилата за сравняване на сила, изброени по-долу. В случай, че нападащият играч е с доминирания тип сила, то тогава точките на противниковия супергерой се удвояват и отново се сравнява силата на супергероите. В случай, че типовете сили съвпадат и супергероят на нападнатия играч е в атакуващ режим, се сравнява силата на супергероите. Победеният супергерой винаги бива унищожаван от колекцията на победения в битка играч. Сравняването на сила е както следва:

Ако супергероят на нападащия играч е с по-голяма сила от този на неговия опонент, то нападнатият играч губи пари с размер разликата на силата на супергероите, които се съревновават, а нападащият играч печели сума равна на същата разлика.

Ако супергероят на нападащия играч е с по-малко сила от този на нападнатия, то нападнатият печели сума z, а нападащият губи пари на стойност 2 пъти разликата на силите на супергероите, които се съревновават.

Ако супергероите са с равни сили, тогава нападнатия играч не променя и не губи пари, но нападащия губи сума k.

В случай, че нападащият играч напада супергерой, който е в дефанзивен режим, то тогава нападнатият не губи никакви пари (но може да изгуби героя си) и оценяването на победител е както в 2.
Играчите, освен чрез битки, получават и пари j периодично. Един период от време е един цикъл, в който всички играчи са влезли в системата. Ако един играч е влязъл в системата и по-късно отново е влязъл, то се счита, че потребителите, които не са влезли между първото и второто влизане на този играч, са решили да пропуснат хода си за периода.
При добавянето на нов играч той стартира със сума m.
Вие трябва да се погрижите за всички стойности, отбелязани чрез букви, както намерите за най-практично. Може някои да се задават от администраторите, може да са предефинирани (стига да са измислени по начин, по който играта да запазва смисъла си).
Всички имена са низове с произволна дължина, освен потребителското име, то трябва да е с максимална дължина 16 малки латински букви.
Паролите трябва да съдържат поне една главна буква, поне една малка и поне една цифра.
Бонус:
Направете възможност играчите да подобряват своите супергерои чрез заплащане на пари.

Примерен интерфейс:
>sign in as administrator
>Enter Username: Victor16
>Enter Password: ParolataNaVictor123
>Victor you have successfully logged in as administrator!

>add new player
>Enter Name: Ivan Ivanov
>Enter Username: Ivan40
>Enter Password: PassIvan40
>Player created successfully!

>delete player
>Enter username for deleted player: stancho
>Player stancho deleted successfully!

>log out
>Victor16 has logged out successfully!

>sign in as player
>Enter username: Ivan40
>Enter password: PassIvan40
>You have signed in successfully!

>show balance
>1000$

>show market
> 1. name: Iron Man price: 700$ type: Fire power: 1500
> 2. name: Aquaman price: 550$ type: Water power: 2000

>show players
> 1. Slayer300 2500$
	1.1. Super Man Earth
	1.2. Fire Man Fire
>2. Go6ko 3200$
	2.1. Bat Man Earth

>buy
>Enter Superhero name from the market you wish to buy: Iron Man
>Iron Man bought successfully!

>attack Slayer300
>Enter the superhero you want to attack with: Iron Man
>Enter the superhero you want to attack: Super Man
> Congratulations you have won! You have earned 300$!


>set to defense
>Enter the superhero you want to set to defense: Iron Man
> Iron Man set to defence successfully!

>buy
>You have reached your limit of operations for this round!

>log out
>You have logged out successfully!
