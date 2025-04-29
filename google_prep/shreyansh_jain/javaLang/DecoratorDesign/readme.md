Decorator Design Patterns

we have a base object with its features/properties f1

then to add additional wrap that object that add another feature on it and so on , it goes on adding

real time usecase 
Pizza Shop 

here on a pizza we can add mushroom ,extraVeggies , margreta, toppings etc

so we can have basePizza + extraCheese + Mushroom 
apart from this we can add exxtraCheese again

second use case is coffee machine
normal coffee + milk 


base car + ac + power steering + woofers + alloy wheels 

so why we need Decorator pattern,
It prevent from class explosion

so in general if we do normally , 
we have to do permutation of these cars to make class and it become tidious to manage more class 


at that time we use Decorator pattern to avoid Class Explosion



so how we made it

so here we have a base class
e.g. for Pizza case
we have a abstract class 
so whoever inherit it have to define those functions

initially we have base Pizzas
e.g. veg delight , maghretia

and on these 2 base class we decorate them 

Abstract classes are the classes  whose oject cannot be created , if methods are defined as abstract it means we have to implement those methods too

Decorator class has a and is a both relationship of type base class

