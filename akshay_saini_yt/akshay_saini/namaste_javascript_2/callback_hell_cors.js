// //callback hell
// console.log("Hello")
// setTimeout(()=>{console.log("John")},0)
// console.log("Wick")



//callback hell , calling callback :- nested multiple callback
/*
importance of callback hell

asynchronous programming exist because of call back

issues with callback 
callback hell (multiple nested callback code become unmaintainable)

inversion of control 
we give control of our code to other code whether it will run or not 
*/



// CORS
/*
  CROSS ORIGIN Resource origin
  To share resource between browsers
  mechanism that include extra header to tell the specific web app can share resource with other web app
  and they have different web origins

  When user makes a request to external api
  cross-origin request blocked: The same origin policy disallows reading the remote source at
  https://some-url


  by origin (domain name)  A
  e.g. domain name A is trying to call domain name B
  or any other port or any other protocol
*/

/*  https://developer.mozilla.org/en-US/docs/Web/HTTP/CORS
    origin1     origin2

    a preflight call first/option call is made before actual http call

    then B send response along with additional headers

    then actual call is made

    Header set by server
    Accept-Control-Allow-origin: * //means anyone can access that
    Accept-Control-Allow-Methods : GET/PUT/POST

    there are 2 type of preflight calls
*/