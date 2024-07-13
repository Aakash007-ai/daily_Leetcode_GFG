const express = require('express');
const http = require('http');

const app= express();
const server = http.createServer(app);

//implement middleeware to check whether JWT authentication token is valid or not

app.get('/' ,(req,resp)=>{
    const token = req.headers['authorization'];
    //verify token with jwt
    //if token is valid then send response
    
})

server.listen(()=>{
    console.log("server is running")
}, 3000)
