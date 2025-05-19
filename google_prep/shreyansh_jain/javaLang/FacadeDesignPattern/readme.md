whenever we want to hide the system complexity from client

e.g. behind the scene , facade interacting with the system
but it is not mandatory, client can access inside system method too,

facade take the responsibility of creation of objects as it has that object and on constructor instantion it create new object

and via methods it expose only those methods which are required
internaaly it implement those methods implemented by that object

so order facade has all the system objects
and on constructor we just initialise them

and in methods we want to expose we just expose them

it can be possisble Facade using Facade

Facade vs Proxy

in Facade -> client is calling Facade -> Facade is calling internal objects

inProxy -> client is calling Proxy and Proxy is calling Actual Objects
e.g. we have a Actual Object interface,
and Proxy object is a and Actual Object also is a relationship of that interface
and ProxyClass has a relatinoship of that object

so in Proxy, it take carre of one object

---

Facade vs Adapter
in Adapter client and object interfacea are not comapatible we have to make them compatabile
