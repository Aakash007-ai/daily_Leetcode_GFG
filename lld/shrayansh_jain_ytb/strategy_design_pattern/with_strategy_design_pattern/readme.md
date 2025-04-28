case study
when base class have some properties and child class inherit them and sometime they have to modify that property , but there are multiple child class which wants same property 

so we update same method with same strategy to it.  this include duplication of that code in multiple base case.

to resolve this we use strategy pattern, where we define a BaseStrategy interface and define strategies we need (e.g. in our case we need normal Strategy, sports strategy, or passenger strategy)

and in our base class we use has a relationship i.e. Vehicle class has strategy interface object and receive extended strategy class's object in constructor 

, so in this way we reduce duplicacy 