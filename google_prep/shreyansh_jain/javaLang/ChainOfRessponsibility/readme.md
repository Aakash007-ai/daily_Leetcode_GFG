ATM Machine/Vending Machine

Design Logger (Amazon) (when logger directly it is asked to use Chain of responsibility)

when a sender send request and he doesn't care who will receive its request
whenever client/send send request ,it then goes to first receiver,
if receiver1 does notfulfill its request it goes to next event -> then again -> then again
if anyone of them fulfill then it break the process

e.g. in atm machine we have a request withdraw 200
in ATM machine we have 3 handle
2000 handler 500 handler 200handler

first it goes to 2000 handler it goes to 500 then it goes to next
if anyone of them can't handle it return it can't handle

we have a client that make a request

and this request is handled by handler/reciever/processor which is calling itself if request does not get fulfilled
so this handler will be a abstract class which constructor linked to next request, via constructor injection , it takes in next handler

so during main object creation , we have to linked all handler sequentilly via constructor injection
so we have to make a main abstract class and basis on that we create some concrete class
which get linked by passing object in constructor
